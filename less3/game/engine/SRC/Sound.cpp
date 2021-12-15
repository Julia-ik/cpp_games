//
// Created by lilu on 08.12.2021.
//
#include "Sound.h"
#include "AudioManager.h"
#include <string>
#include <stdexcept>
#include <map>

namespace
{
    static void audio_callback(void* userdata, uint8_t* stream, int len)
    {

        auto audioManager = static_cast<AudioManager*>(userdata);

        SDL_memset(stream, 0, len);

            //TODO: check is playing or pause
            //TODO: looping

            auto amount = audioManager->_buffers[audioManager->_currentSound].size -
                    audioManager->_buffers[audioManager->_currentSound].current_pos;
            if ( amount > len )
            {
                amount = len;
            }

            SDL_MixAudioFormat(stream,
                               audioManager->_buffers[audioManager->_currentSound].start +
                                       audioManager->_buffers[audioManager->_currentSound].current_pos,
                               AUDIO_S16LSB,
                               amount,
                               SDL_MIX_MAXVOLUME*audioManager->volume);

        audioManager->_buffers[audioManager->_currentSound].current_pos += amount;

            if (audioManager->shouldLoop &&
            audioManager->_buffers[audioManager->_currentSound].current_pos >=
                    audioManager->_buffers[audioManager->_currentSound].size)
            {
                audioManager->_buffers[audioManager->_currentSound].current_pos = 0;
            }
    }
}

Sound::Sound(std::string_view filename, AudioManager * audioManager, std::string name)
:_name(name), _audioManager(audioManager)
{
    SDL_RWops* file = SDL_RWFromFile(filename.data(), "rb");
    if (file == nullptr)
    {
        throw std::runtime_error(std::string(filename) + "doesn't exist");
    }

    SDL_AudioSpec audioSpecFromFile{};
    const int32_t auto_delete_file            = 1;
    _buf                                = nullptr;
    uint32_t      sample_buffer_len_from_file = 0;


    SDL_AudioSpec* audio_spec = SDL_LoadWAV_RW(file,
                                               auto_delete_file,
                                               &audioSpecFromFile,
                                               &_buf,
                                               &sample_buffer_len_from_file);

    if (audio_spec == nullptr)
    {
        throw std::runtime_error(std::string(filename) + " can't parse and load audio samples from file");
    }


    const int32_t allow_changes = 0;
    const char*   device_name       = nullptr;
    const int32_t is_capture_device = 0;


    AudioBuf buf;
    buf.start = _buf;
    buf.size = sample_buffer_len_from_file;
    buf.current_pos = 0;

    audioManager->_buffers[_name] = buf;
    //audioManager->_currentSound = name;



    audioSpecFromFile.callback = audio_callback;
    audioSpecFromFile.userdata = audioManager;
    audioSpecFromFile.channels = 2;
    audioSpecFromFile.samples = 1024;


    SDL_AudioSpec returned{};
    _audio_device_id = SDL_OpenAudioDevice(
            device_name, is_capture_device, &audioSpecFromFile,
            &returned, allow_changes);
    if (_audio_device_id == 0)
    {
        throw std::runtime_error("Can't open Audio Device");
    }


    if (audioSpecFromFile.format != returned.format ||
        audioSpecFromFile.channels != returned.channels || audioSpecFromFile.freq != returned.freq)
    {
        throw std::runtime_error("Audio Device doesn't support our format");
    }

    SDL_PauseAudioDevice(_audio_device_id, SDL_TRUE);

}
void Sound::play()
{
    //SDL_PauseAudioDevice(_audio_device_id, SDL_TRUE);
    _audioManager->_currentSound = _name;
    SDL_PauseAudioDevice(_audio_device_id, SDL_FALSE);
}
void Sound::pause()
{

    SDL_PauseAudioDevice(_audio_device_id, SDL_TRUE);
}
void Sound::stop()
{
    SDL_PauseAudioDevice(_audio_device_id, SDL_TRUE);
    _audioManager->_buffers[_name].current_pos = 0;

    //SDL_CloseAudio();
    //SDL_FreeWAV(_buf);
}

void Sound::volumePlus()
{
    if(_audioManager->volume < 1)
    {
        _audioManager->volume+=0.01f;
    }

}
void Sound::volumeMinus()
{
    if(_audioManager->volume > 0)
    {
        _audioManager->volume-=0.01f;
    }

}
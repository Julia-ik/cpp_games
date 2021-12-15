//
// Created by lilu on 08.12.2021.
//
#include "Sound.h"
#include "AudioManager.h"
#include <string>
#include <stdexcept>
#include <map>


Sound::Sound(std::string_view filename, AudioManager * audioManager, std::string name)
:_name(name), _audioManager(audioManager)
{
    SDL_RWops* file = SDL_RWFromFile(filename.data(), "rb");
    if (file == nullptr)
    {
        throw std::runtime_error(std::string(filename) + "doesn't exist");
    }


    const int32_t auto_delete_file            = 1;
    _buf                                = nullptr;
    uint32_t      sample_buffer_len_from_file = 0;


    SDL_AudioSpec* audio_spec = SDL_LoadWAV_RW(file,
                                               auto_delete_file,
                                               &_audioManager->audioSpecFromFile,
                                               &_buf,
                                               &sample_buffer_len_from_file);

    if (audio_spec == nullptr)
    {
        throw std::runtime_error(std::string(filename) + " can't parse and load audio samples from file");
    }

    AudioBuf buf;
    buf.start = _buf;
    buf.size = sample_buffer_len_from_file;
    buf.current_pos = 0;

    audioManager->_buffers[_name] = buf;

    SDL_PauseAudioDevice(_audioManager->_audio_device_id, SDL_TRUE);

}
void Sound::play()
{
    //SDL_PauseAudioDevice(_audio_device_id, SDL_TRUE);
    _audioManager->_currentSound = _name;
    SDL_PauseAudioDevice(_audioManager->_audio_device_id, SDL_FALSE);
}
void Sound::pause()
{

    SDL_PauseAudioDevice(_audioManager->_audio_device_id, SDL_TRUE);
}
void Sound::stop()
{
    SDL_PauseAudioDevice(_audioManager->_audio_device_id, SDL_TRUE);
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
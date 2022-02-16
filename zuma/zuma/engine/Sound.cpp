//
// Created by lilu on 13/02/2022.
//

#include "Sound.h"
#include <string>
#include <stdexcept>


Sound::Sound(std::string_view filename, SoundManager * soundManager, std::string name)
        :_name(name), _soundManager(soundManager)
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
                                               &_soundManager->audioSpecFromFile,
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

    _soundManager->_buffers[_name] = buf;

    SDL_PauseAudioDevice(_soundManager->_audio_device_id, SDL_TRUE);

}
void Sound::play()
{
    _soundManager->_currentSound = _name;
    SDL_PauseAudioDevice(_soundManager->_audio_device_id, SDL_FALSE);
}
void Sound::pause()
{
    SDL_PauseAudioDevice(_soundManager->_audio_device_id, SDL_TRUE);
}
void Sound::stop()
{
    SDL_PauseAudioDevice(_soundManager->_audio_device_id, SDL_TRUE);
    _soundManager->_buffers[_name].current_pos = 0;
}

void Sound::volumePlus()
{
    if(_soundManager->volume < 1)
    {
        _soundManager->volume+=0.01f;
    }

}
void Sound::volumeMinus()
{
    if(_soundManager->volume > 0)
    {
        _soundManager->volume-=0.01f;
    }

}
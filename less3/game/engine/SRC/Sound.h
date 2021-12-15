//
// Created by lilu on 08.12.2021.
//

#ifndef GAME_SOUND_H
#define GAME_SOUND_H
#include <string>
#include "SDL_audio.h"
#include "AudioManager.h"


class Sound
{
public:
    SDL_AudioDeviceID _audio_device_id;
    uint8_t* _buf;
    std::string _name;
    AudioManager * _audioManager;
    Sound(std::string_view filename, AudioManager * audioManager, std::string name);
    void play();
    void pause();
    void stop();

    bool isPlaying = false;
    void volumePlus();
    void volumeMinus();


private:
};



#endif //GAME_SOUND_H

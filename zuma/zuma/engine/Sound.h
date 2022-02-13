//
// Created by lilu on 13/02/2022.
//

#ifndef ZUMA_SOUND_H
#define ZUMA_SOUND_H


#include <cstdint>
#include <string>
#include "SoundManager.h"

class Sound
{
public:

    uint8_t* _buf;
    std::string _name;
    SoundManager *_soundManager;
    Sound(std::string_view filename, SoundManager *_soundManager, std::string name);
    void play();
    void pause();
    void stop();

    bool isPlaying = false;
    void volumePlus();
    void volumeMinus();


private:
};




#endif //ZUMA_SOUND_H

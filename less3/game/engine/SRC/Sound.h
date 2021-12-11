//
// Created by lilu on 08.12.2021.
//

#ifndef GAME_SOUND_H
#define GAME_SOUND_H
#include <string>


class Sound
{
public:
    Sound(std::string_view filename);
    void PlaySound(char *file);


};



#endif //GAME_SOUND_H

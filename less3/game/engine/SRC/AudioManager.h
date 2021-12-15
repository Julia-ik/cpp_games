//
// Created by lilu on 14/12/2021.
//

#ifndef GAME_AUDIOMANAGER_H
#define GAME_AUDIOMANAGER_H
#include <string>
#include "SDL_audio.h"
#include <vector>

#include <memory>
#include <map>

namespace
{
    struct AudioBuf {
        uint8_t *start = nullptr;
        size_t size = 0;
        size_t current_pos = 0;
    };
    enum State {playing, paused};
}
class AudioManager {
public:
    std::map<std::string, AudioBuf> _buffers;
    std::string _currentSound = "theme";
    float volume = 0.25f;
    bool shouldLoop = true;
    void initAudioDevice();
};


#endif //GAME_AUDIOMANAGER_H

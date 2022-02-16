//
// Created by lilu on 13/02/2022.
//

#ifndef ZUMA_SOUNDMANAGER_H
#define ZUMA_SOUNDMANAGER_H


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
class SoundManager {
public:
    std::map<std::string, AudioBuf> _buffers;
    std::string _currentSound = "theme";
    SDL_AudioDeviceID _audio_device_id;
    SDL_AudioSpec audioSpecFromFile{};
    SDL_AudioSpec audioSpec{};
private:
    const int32_t allow_changes = 0;
    const char*   device_name       = nullptr;
    const int32_t is_capture_device = 0;
    SDL_AudioSpec returned{};

public:
    mutable float volume = 0.25f;
    bool shouldLoop = true;
    void createAudioDevice();
    void initAudioSpec();
    void checkFormat();

    void init();
};



#endif //ZUMA_SOUNDMANAGER_H

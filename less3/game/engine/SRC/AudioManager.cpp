//
// Created by lilu on 14/12/2021.
//

#include "AudioManager.h"
#include <stdexcept>
#include <iostream>

namespace {
    static void audioCallback(void *userdata, uint8_t *stream, int len) {
        auto audioManager = static_cast<AudioManager *>(userdata);

        SDL_memset(stream, 0, len);

        //TODO: check is playing or pause
        //TODO: looping
        auto amount = audioManager->_buffers[audioManager->_currentSound].size -
                      audioManager->_buffers[audioManager->_currentSound].current_pos;
        if (amount > len) {
            amount = len;
        }

        SDL_MixAudioFormat(stream,
                           audioManager->_buffers[audioManager->_currentSound].start +
                           audioManager->_buffers[audioManager->_currentSound].current_pos,
                           AUDIO_S16LSB,
                           amount,
                           SDL_MIX_MAXVOLUME * audioManager->volume);

        audioManager->_buffers[audioManager->_currentSound].current_pos += amount;

        if (audioManager->shouldLoop &&
            audioManager->_buffers[audioManager->_currentSound].current_pos >=
            audioManager->_buffers[audioManager->_currentSound].size) {
            audioManager->_buffers[audioManager->_currentSound].current_pos = 0;
        }
    }
}

void AudioManager::init()
{
    initAudioSpec();
    createAudioDevice();
}

void AudioManager::initAudioSpec()
{
    audioSpec.callback = audioCallback;
    audioSpec.userdata = this;
    audioSpec.channels = 2;
    audioSpec.samples = 1024;
    audioSpec.freq = 22050;
    audioSpec.format = 32784;
}
void AudioManager::createAudioDevice()
{

    _audio_device_id = SDL_OpenAudioDevice(
            device_name, is_capture_device, &audioSpec,
            &returned, allow_changes);
    if (_audio_device_id == 0)
    {
        throw std::runtime_error("Can't open Audio Device");
    }

    checkFormat();
}

void AudioManager::checkFormat()
{
    if (audioSpec.format != returned.format ||
        audioSpec.channels != returned.channels || audioSpec.freq != returned.freq)
    {

        throw std::runtime_error("Audio Device doesn't support our format");
    }
}
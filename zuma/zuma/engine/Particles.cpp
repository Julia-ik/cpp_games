//
// Created by lilu on 08/02/2022.
//

#include "Particles.h"
#include "ParticleBuffer.h"
#include "Engine.h"
#include "Shader.h"
#include "Uniforms.h"

#include <glm/gtx/vector_angle.hpp>

#include <random>

Particles::Particles(const Engine &engine)
        : _engine(engine)
{
    _command.program = engine._renderer->createProgram("particles");

    _screenSizeUniform = _command.program->createVec2Uniform("uScreenSize",_command.program);
    _resolutionUniform = _command.program->createVec2Uniform("uResolutionSize",_command.program);
    _timeUniform = _command.program->createFloatUniform("uTime",_command.program);


    _command._screenSizeUniform = _screenSizeUniform;
    _command._timeUniform = _timeUniform;
    _command._resolutionUniform = _resolutionUniform;


    _resolutionUniform->onActivate = [=]()
    {
        _resolutionUniform->value = _engine._renderer->getRenderResolution();
    };
//TODO включить в апдейт
}

void Particles::update(float delta)
{
    _timeUniform->value += delta;

    if (_dynamicMode)
    {
        _lastGenTime += delta;
        _totalTime += delta;

        if (_lastGenTime >= _freq && _totalTime < _lifeTime)
        {
            auto genCount = std::min(_count, _lastGenTime / _freq);
            _lastGenTime = 0;
            auto tempPos = (getTransform() * glm::vec3(1.0));
            glm::vec2 startPos(tempPos);

            for (size_t i = 0; i < genCount; ++i)
            {
                static std::mt19937 gen{};
                static std::normal_distribution<float> angleGen(0, 360);
                static std::normal_distribution<float> velGen(1, 500);

                ParticleBuffer::ParticleData particle;
                particle.pos = startPos;

                auto vector = glm::rotate(glm::vec2{1.0f, 0.0f}, glm::radians(angleGen(gen)));
                auto speed = velGen(gen);

                particle.velocity = vector * speed;
                particle._color = glm::vec4(1.0, 1.0, 1.0, 1.0);
                particle.phase = _timeUniform->value;

                auto particleBuffer = std::static_pointer_cast<ParticleBuffer>(_command.vertexBuffer);
                particleBuffer->addData(particle);
            }
        }
    }
}

void Particles::visitSelf()
{
    const auto& win = _engine.window;
    _screenSizeUniform->value = _engine.scene.getScale();
    _command.mask = _renderMask;

    _engine._renderer->addCommand(_command);
}

void Particles::start(size_t count)
{
    _timeUniform->value = 0;

    std::vector<ParticleBuffer::ParticleData> particles;
    particles.reserve(count);

    auto tempPos = (getTransform() * glm::vec3(1.0));
    glm::vec2 startPos(tempPos);

    static std::mt19937 gen{};
    static std::normal_distribution<float> angleGen(0, 360);
    static std::normal_distribution<float> velGen(1, 500);

    for (size_t i = 0; i < count; ++i)
    {
        ParticleBuffer::ParticleData particle;
        particle.pos = startPos;

        auto vector = glm::rotate(glm::vec2{1.0f, 0.0f}, glm::radians(angleGen(gen)));
        auto speed = velGen(gen);

        particle.velocity = vector * speed;
        particle._color = glm::vec4(1.0, 1.0, 0.0, 1.0);

        particles.push_back(particle);
    }

    //_command.vertexBuffer = _engine._renderer->createParticleBuffer(std::move(particles));
}

void Particles::start(size_t count, float freq, float lifeTime)
{
    _count = count;
    //_command.vertexBuffer = _engine._renderer->createParticleBuffer(count);
    _dynamicMode = true;
    _freq = freq;
    _lastGenTime = 0;
    _totalTime = 0;
    _lifeTime = lifeTime;
    _timeUniform->value = 0;
}

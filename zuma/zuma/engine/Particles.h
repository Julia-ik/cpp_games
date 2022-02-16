//
// Created by lilu on 08/02/2022.
//

#ifndef ZUMA_PARTICLES_H
#define ZUMA_PARTICLES_H

#include "Node.h"
#include "Renderer.h"

class GlTextureUniform;
class GlMat3Uniform;
class GlVec2Uniform;

class Particles: public Node
{
public:
    Particles(const Engine &engine);

    void start(size_t count);
    void start(size_t count, float freq, float lifeTime);

    void update(float delta);
    void updateSelf(float delta) override;

protected:
    void visitSelf() override;

private:
    Renderer::Command _command;

    std::shared_ptr<GlVec2Uniform> _resolutionUniform;
    std::shared_ptr<GlFloatUniform>  _timeUniform;

    std::shared_ptr<GlVec2Uniform> _screenSizeUniform;
    std::shared_ptr<GlMat3Uniform>  _transformUniform;
    std::shared_ptr<GlTextureUniform>  _textureUniform;

    bool _dynamicMode = false;
    float _freq = 0;
    float _lifeTime = 0;
    float _lastGenTime = 0;
    float _totalTime = 0;
    float _count = 0;
    const Engine &_engine;
};
#endif //ZUMA_PARTICLES_H

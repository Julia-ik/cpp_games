//
// Created by lilu on 02/01/2022.
//

#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#include <vector>
#include <string_view>
#include <memory>
#include <unordered_map>
#include <optional>
#include "Texture.h"
#include "ResourceLoader.h"
#include <MeshData.h>
#include <Bitmap.h>
#include "Shader.h"


class VertexBuffer;
class Engine;

class Renderer
{
public:
    virtual ~Renderer() = default;

    struct Command
    {
        std::shared_ptr<VertexBuffer>  vertexBuffer;
        std::shared_ptr<Shader> program;
        std::shared_ptr<Texture> texture;
        glm::mat4 transform;

        std::optional<glm::vec4> scissor;

        struct sub_t
        {
            size_t num;
            size_t offset;
        };

        std::optional<sub_t> sub;
    };

    void addCommand(Command command) const
    {
        _commands.push_back(std::move(command));
    }

    void draw();

    std::shared_ptr<VertexBuffer> createVertexBuffer(MeshData data) const;
    std::shared_ptr<Texture> createTexture(Bitmap bitmap) const;
    std::shared_ptr<Shader> createProgram(std::string_view name) const;


    explicit Renderer(const Engine &engine);

protected:
    mutable std::vector<Command> _commands;
    const Engine &_engine;
};

#endif //GAME_RENDERER_H

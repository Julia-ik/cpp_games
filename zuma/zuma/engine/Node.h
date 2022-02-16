//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_NODE_H
#define ZUMA_NODE_H

#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <optional>

class Node :public std::enable_shared_from_this<Node> {
public:

    float _turnSpeed=0.0;
    bool isLeft = false;
    bool isRight = false;
    mutable int refInd = 0;
    mutable int childrefInd = 0;
    glm::vec4 _color = {1,1,1,1};

    virtual ~Node() = default;

    void visit();
    void update(float delta);

    friend class  EventManager;

    void addNode(std::shared_ptr<Node> node, int zOrder);

    void removeNode(std::shared_ptr<Node> node);

    void removeFromParent();

    std::shared_ptr<Node> getParent();

    const glm::vec2 &getPosition() const;

    void setPosition(const glm::vec2 &position);

    const glm::vec2 &getScale() const;

    void setScale(const glm::vec2 &scale);

    glm::float32 getRotation() const;

    void setRotation(float rotation);

    const glm::vec2 &getAnchor() const;

    std::vector<std::shared_ptr<Node>> &getNodes();

    void setAnchor(const glm::vec2 &anchor);

    glm::mat3 getTransform();

    static bool comparor (std::shared_ptr<Node> i,std::shared_ptr<Node> j)
    {
        return (i->_zOrder<j->_zOrder);
    }


protected:
    virtual void visitSelf() {};
    virtual void updateSelf(float delta) {};


    mutable std::shared_ptr<Node> _parent;
    mutable std::vector<std::shared_ptr<Node>> _nodes;

    glm::vec2 _position = glm::vec2(0.0f);
    glm::vec2 _scale = glm::vec2(1.0f);
    glm::vec2 _anchor = glm::vec2(0.5f);
    glm::float32 _rotation = 0.0f;
    std::uint32_t _renderMask{0x0};



public:
    std::optional<glm::mat3> _transform;
    mutable int _zOrder=0;
    glm::vec2 _contentSize = glm::vec2(0.0f);

    uint32_t getRenderMask() const;
    void setRenderMask(uint32_t renderMask);

    void removeNodeByInd(int i);
};

#endif //ZUMA_NODE_H

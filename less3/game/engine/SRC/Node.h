//
// Created by lilu on 03.12.2021.
//

#ifndef GAME_NODE_H
#define GAME_NODE_H
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <optional>

class Node :public std::enable_shared_from_this<Node> {
public:


    float _speed=0.0;
    float _turnSpeed=0.0;
    bool isLeft = false;
    bool isRight = false;
    bool isMovingForward=false;
    bool isMovingBack =false;

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


    std::shared_ptr<Node> _parent;
    std::vector<std::shared_ptr<Node>> _nodes;

    glm::vec2 _position = glm::vec2(0.0f);
    glm::vec2 _scale = glm::vec2(1.0f);
    glm::vec2 _anchor = glm::vec2(0.5f);
    glm::float32 _rotation = 0.0f;



public:
    std::optional<glm::mat3> _transform;
    int _zOrder=0;
    glm::vec2 _contentSize = glm::vec2(0.0f);
};



#endif //GAME_NODE_H

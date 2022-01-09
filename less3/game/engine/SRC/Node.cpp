//
// Created by lilu on 03.12.2021.
//

#include "Node.h"
#include "glm/gtx/matrix_transform_2d.hpp"
#include <vector>
#include "glm/glm.hpp"
#include <algorithm>

void Node::addNode(std::shared_ptr<Node> node, int zOrder)
{

    if (node != nullptr)
    {
        if(node->_parent != nullptr)
        {
            node->_parent = shared_from_this();
        }
        node->_zOrder = zOrder;
        _nodes.push_back(std::move(node));
       std::sort(_nodes.begin(), _nodes.end(), comparor);
    }
}

void Node::removeNode(std::shared_ptr<Node> node)
{
    int index;
    for(int i=0; i<_nodes.size(); i++ ){
        if(_nodes[i] == node){
            index = i;
        }
    }
    _nodes.erase(_nodes.begin() + index);
}

void Node::removeFromParent()
{
    _parent->removeNode(shared_from_this());
}

std::shared_ptr<Node> Node::getParent()
{
    return _parent;
}

void Node::visit()
{

    for(int i = 0; i<_nodes.size();i++)
    {
        if(_zOrder >_nodes[i]->_zOrder)
        {
            _nodes[i]->visit();
        }
    }
    this -> visitSelf();

    for(int i = 0; i<_nodes.size();i++)
    {
        if(_zOrder <=_nodes[i]->_zOrder)
        {
            _nodes[i]->visit();
        }
    }

}

void Node::update(float delta)
{
    for(int i = 0; i<_nodes.size();i++)
    {
        if(_zOrder >_nodes[i]->_zOrder)
        {
            _nodes[i]->update(delta);
        }
    }
    this -> updateSelf(delta);

    for(int i = 0; i<_nodes.size();i++)
    {
        if(_zOrder <=_nodes[i]->_zOrder)
        {
            _nodes[i]->update(delta);
        }
    }

}

const glm::vec2 &Node::getPosition() const
{
    return _position;
}

std::vector<std::shared_ptr<Node>> &Node::getNodes()
{
    return _nodes;
}

void Node::setPosition(const glm::vec2 &position)
{
    _transform = std::nullopt;
    _position = position;
}

const glm::vec2 &Node::getScale() const
{
    return _scale;
}

void Node::setScale(const glm::vec2 &scale)
{
    _transform = std::nullopt;
    _scale = scale;
}

glm::float32 Node::getRotation() const
{
    return _rotation;
}

void Node::setRotation(float rotation)
{
    _transform = std::nullopt;
    _rotation = rotation;
}

glm::mat3 Node::getTransform()
{
    if (_transform)
    {
        return _parent ? (getParent()->getTransform() * *_transform) : *_transform;
    }
    else
    {
        glm::mat3 model(1.0f);

        model = glm::translate(model, _position);  // сначала выполняем перемещение (преобразования таковы: первым происходит масштабирование, затем поворот, а в конце - перенос; обратный порядок)

        model = glm::translate(model, glm::vec2(_anchor.x * _contentSize.x,
                                                _anchor.y* _contentSize.y)); // перемещаем точку начала поворота в центр прямоугольника

        model = glm::rotate(model, glm::radians(_rotation)); // затем производим поворот
        model = glm::translate(model, -glm::vec2(_anchor.x * _contentSize.x,
                                                 _anchor.y* _contentSize.y)); // возвращаем точку поворота в исходную позицию

        model = glm::scale(model, glm::vec2(_contentSize)); // последним выполняется масштабирование

        _transform = model;
        return _parent ? (getParent()->getTransform() * model) : model;
    }
}

const glm::vec2 &Node::getAnchor() const
{
    return _anchor;
}

void Node::setAnchor(const glm::vec2 &anchor)
{
    _transform = std::nullopt;
    _anchor = anchor;
}

//
// Created by lilu on 16/01/2022.
//

#include "Node.h"
#include "glm/gtx/matrix_transform_2d.hpp"
#include <vector>
#include "glm/glm.hpp"
#include <algorithm>
#include <cstdio>

void Node::addNode(std::shared_ptr<Node> node, int zOrder)
{
    if (node != nullptr)
    {
        if(node->_parent != nullptr)
        {
            node->_parent = shared_from_this();
        }
        node->_zOrder = zOrder;
        childrefInd++;
        node->refInd = childrefInd;
        _nodes.push_back(std::move(node));
        std::sort(_nodes.begin(), _nodes.end(), comparor);

    }
}

void Node::removeNode(std::shared_ptr<Node> node)
{
    int index;
    for(int i=0; i<_nodes.size(); i++ ){
        if(_nodes[i]->refInd == node->refInd){
            index = i;
        }
    }
    _nodes.erase(_nodes.begin() + index);
}

void Node::removeNodeByInd( int k)
{
    int index;
    for(int i=0; i<_nodes.size(); i++ ){
        if(_nodes[i]->refInd == k &&_nodes[i]->_zOrder !=1  &&_nodes[i]->_zOrder!=10
        && _nodes[i]->_zOrder !=2)
        {
            index = i;
            _nodes[i]->getNodes().clear();
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
        if(_zOrder <=_nodes[i]->_zOrder) {
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

        model = glm::translate(model, _position);

        model = glm::translate(model, glm::vec2(_anchor.x * _contentSize.x,
                                                _anchor.y* _contentSize.y));

        model = glm::rotate(model, glm::radians(_rotation));
        model = glm::translate(model, -glm::vec2(_anchor.x * _contentSize.x,
                                                 _anchor.y* _contentSize.y));

        model = glm::scale(model, glm::vec2(_contentSize));

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
uint32_t Node::getRenderMask() const
{
    return _renderMask;
}
void Node::setRenderMask(uint32_t renderMask)
{
    _renderMask = renderMask;
}
/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GraphicalElements.cpp
*/

#include <vector3d.h>
#include "GraphicalElements.h"
#include "../includes/GraphicalElements.hpp"

void GraphicalElements::setPosition(irr::core::vector3df& _position)
{
    // TODO - implement GraphicalElements::setPosition
    throw "Not yet implemented";
}

void GraphicalElements::setScale(irr::f32 _scale)
{
    // TODO - implement GraphicalElements::setScale
    throw "Not yet implemented";
}

void GraphicalElements::setMesh(irr::scene::IAnimatedMesh* _mesh)
{
    // TODO - implement GraphicalElements::setMesh
    throw "Not yet implemented";
}

irr::scene::IAnimatedMesh* GraphicalElements::getMesh()
{
    // TODO - implement GraphicalElements::getMesh
    throw "Not yet implemented";
}

irr::f32 GraphicalElements::getScale()
{
    // TODO - implement GraphicalElements::getScale
    throw "Not yet implemented";
}

const irr::core::vector3df& GraphicalElements::getPosition()
{
    // TODO - implement GraphicalElements::getPosition
    throw "Not yet implemented";
}

void GraphicalElements::setPosition(irr::core::vector3df& _position)
{
    // TODO - implement GraphicalElements::setPosition
    throw "Not yet implemented";
}

void GraphicalElements::setScale(irr::f32 _scale)
{
    // TODO - implement GraphicalElements::setScale
    throw "Not yet implemented";
}

void GraphicalElements::setMesh(irr::scene::IAnimatedMesh* _mesh)
{
    // TODO - implement GraphicalElements::setMesh
    throw "Not yet implemented";
}

const irr::core::vector3d<float> &GraphicalElements::getRotation() const
{
    return _rotation;
}

void GraphicalElements::setRotation(const irr::core::vector3d<float> &rotation)
{
    _rotation = rotation;
}

bool GraphicalElements::isCollide() const
{
    return _canCollide;
}

void GraphicalElements::setCollide(bool canCollide)
{
    _canCollide = canCollide;
}

GraphicalElements::GraphicalElements(const irr::core::vector3df &position, const irr::core::vector3df &rotation, irr::f32 scale, bool collide) :
                                                                                            _scale(scale),
                                                                                           _position(position),
                                                                                           _rotation(rotation),
                                                                                           _collide(collide)
{}
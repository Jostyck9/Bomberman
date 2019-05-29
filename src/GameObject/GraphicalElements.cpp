/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GraphicalElements.cpp
*/

#include <GraphicalElements.hpp>

GraphicalElements::GraphicalElements(const irr::core::vector3df &position, const irr::core::vector3df &rotation, irr::f32 scale, bool collide) :
                                    _scale(scale),
                                    _position(position),
                                    _rotation(rotation),
                                    _collide(collide)
{}

const irr::core::vector3df &GraphicalElements::getRotation() const
{
    return _rotation;
}

void GraphicalElements::setRotation(const irr::core::vector3df &rotation)
{
    // TODO - set on the mesh the rotation
    _rotation = rotation;
}

bool GraphicalElements::isCollide() const
{
    return _collide;
}

void GraphicalElements::setCollide(bool canCollide)
{
    _collide = canCollide;
}

const irr::scene::IAnimatedMesh* GraphicalElements::getMesh() const
{
    return (_mesh);
}

void GraphicalElements::setMesh(irr::scene::ISceneManager* smgr, std::string &meshPath, std::string texture)
{
    (void)smgr;
    (void)meshPath;
    (void)texture;
    // TODO - implement GraphicalElements::setMesh
    throw "Not yet implemented";
}

void GraphicalElements::setMesh(irr::scene::ISceneManager* smgr, meshType_t type, std::string &texture)
{
    (void)smgr;
    (void)type;
    (void)texture;
    // TODO - implement GraphicalElements::setMesh
    throw "Not yet implemented";
}

const std::string &GraphicalElements::getMeshPath() const
{
    return (_meshPath);
}

void GraphicalElements::setMeshPath(const std::string &meshPath)
{
    _meshPath = meshPath;
    // TODO - implement GraphicalElements::setMesh
    throw "Not yet implemented";
}

irr::f32 GraphicalElements::getScale()
{
    return (_scale);
}

void GraphicalElements::setScale(irr::f32 scale)
{
    _scale = scale;
    // TODO  set scale on the mesh
    throw "Not yet implemented";
}

const irr::core::vector3df& GraphicalElements::getPosition()
{
    return (_position);
}

void GraphicalElements::setPosition(irr::core::vector3df& position)
{
    _position = position;
    // TODO - implement GraphicalElements::setPosition
    throw "Not yet implemented";
}
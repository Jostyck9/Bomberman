/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GraphicalElements.cpp
*/

#include "GraphicalElements.hpp"
#include <string>
#include <iostream>

GraphicalElements::GraphicalElements(const irr::core::vector3df &position, const irr::core::vector3df &rotation, irr::f32 scale, bool collide) :
                                    _mesh(nullptr),
                                    _node(nullptr),
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
    _rotation = rotation;
    if (_node)
        _node->setRotation(rotation);
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

void GraphicalElements::setMesh(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, std::vector<std::string> texture, std::string &meshPath)
{
    this->_mesh = smgr->getMesh(meshPath.data());
    _node = smgr->addAnimatedMeshSceneNode(this->_mesh);
    if (_node) {
        _node->setScale(irr::core::vector3df(5,5,5));
        _node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
        _node->setMD2Animation(irr::scene::EMAT_STAND);
        for (irr::u16 i = 0; i < texture.size(); i++)
            _node->setMaterialTexture(i, driver->getTexture(texture[i].data()));
        _node->setPosition(irr::core::vector3df(_position.X, _position.Y, 0));
    }
}

void GraphicalElements::setMesh(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, meshType_t type, std::string &mesh, std::vector<std::string> texture)
{
    if (type == CUBE) {
        std::cout << mesh << std::endl;
        this->_mesh = smgr->getMesh(mesh.data());
        _node = smgr->addAnimatedMeshSceneNode(this->_mesh);
        if (_node) {
            _node->setScale(irr::core::vector3df(0.068,0.068,0.068));
            _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            _node->setMD2Animation(irr::scene::EMAT_STAND);
            for (irr::u16 i = 0; i < texture.size(); i++)
                _node->setMaterialTexture(i, driver->getTexture(texture[i].data()));
            _node->setPosition(irr::core::vector3df(_position.X, _position.Y, 0));
        }
    }
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
    //TODO chage scale into a vector3f
    _scale = scale;
    // _node->setScale(scale);
}

const irr::core::vector3df& GraphicalElements::getPosition()
{
    return (_position);
}

void GraphicalElements::setPosition(irr::core::vector3df& position)
{
    _position = position;
    if (_node)
        _node->setPosition(position);
}
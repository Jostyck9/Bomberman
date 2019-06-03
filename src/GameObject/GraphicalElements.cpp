/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GraphicalElements.cpp
*/

#include <iostream>
#include "GraphicalElements.hpp"
#include <string>
#include <iostream>

irr::scene::IMetaTriangleSelector *GraphicalElements::_allSelectors = nullptr;

GraphicalElements::GraphicalElements(const irr::core::vector3df &position, const irr::core::vector3df &rotation, irr::f32 scale, bool collide) :
                                    _mesh(nullptr),
                                    _node(nullptr),
                                    _scale(scale),
                                    _position(position),
                                    _rotation(rotation),
                                    _collide(collide),
                                    _selector(nullptr),
                                    _selectorWorld(nullptr)
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
        // _node->setScale(irr::core::vector3df(5,5,5));
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setMD2Animation(irr::scene::EMAT_STAND);
        for (irr::u16 i = 0; i < texture.size(); i++)
            _node->setMaterialTexture(i, driver->getTexture(texture[i].data()));
        std::cout << "posX : " << _position.X << "posY : " << _position.Y << std::endl;
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

irr::core::vector3df GraphicalElements::getScale()
{
    return (_scale);
}

void GraphicalElements::setScale(irr::core::vector3df scale)
{
    //TODO chage scale into a vector3f
    _scale = scale;
    _node->setScale(scale);
}

const irr::core::vector3df& GraphicalElements::getPosition()
{
    if (_node)
        return (_node->getPosition());
    return (_position);
}

void GraphicalElements::setPosition(irr::core::vector3df& position)
{
    _position = position;
    if (_node)
        _node->setPosition(position);
}

bool GraphicalElements::createSelectorWorld(irr::scene::ISceneManager* smgr)
{
    irr::u32 size = 0;

    if (smgr == nullptr || _allSelectors == nullptr || _node == nullptr)
        return (false);
    if (_selectorWorld) {
        _selectorWorld->drop();
        _selectorWorld = nullptr;
    }
    _selectorWorld = smgr->createMetaTriangleSelector();
    if (_selectorWorld == nullptr)
        return (false);
    if (_selector == nullptr) {
        _selector = smgr->createTriangleSelector(_node);
    }
    if (_selector == nullptr)
        return (false);
    _node->setTriangleSelector(_selector);
    _allSelectors->addTriangleSelector(_selector);
    size = _allSelectors->getSelectorCount();
    for (irr::u32 i = 0; i < size; i++) {
        if (_allSelectors->getSelector(i) == _selector)
            continue;
        _selectorWorld->addTriangleSelector(_allSelectors->getSelector(i));
    }
    return (true);
}

bool GraphicalElements::addColision(irr::scene::ISceneManager* smgr, irr::core::vector3df sphere, irr::core::vector3df translation)
{
    irr::scene::ISceneNodeAnimator* anim = nullptr;

    _boxColision = sphere;
    _translationColision = translation;
    if (!smgr)
        return (false);
    if (!_allSelectors)
        _allSelectors = smgr->createMetaTriangleSelector();
    if (!_allSelectors)
        return (false);
    if (!createSelectorWorld(smgr))
        return (false);
    anim = smgr->createCollisionResponseAnimator(
            _selectorWorld, _node, sphere,
            irr::core::vector3df(0, 0, 0), translation);
    if (!anim)
        return (false);
    _node->addAnimator(anim);
    anim->drop();
    return (false);
}

bool GraphicalElements::updateColision(irr::scene::ISceneManager* smgr)
{
    irr::scene::ISceneNodeAnimator* anim = nullptr;

    if (!_collide)
        return (true);
    if (!createSelectorWorld(smgr))
        return (false);
    anim = smgr->createCollisionResponseAnimator(
            _selectorWorld, _node, _boxColision,
            irr::core::vector3df(0, 0, 0), _translationColision);
    if (!anim)
        return (false);
    _node->addAnimator(anim);
    anim->drop();
    return (true);
}
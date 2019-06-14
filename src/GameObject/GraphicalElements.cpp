/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GraphicalElements.cpp
*/

#include <iostream>
#include <string>
#include "GraphicalElements.hpp"
#include "PlayerController.hpp"

irr::scene::IMetaTriangleSelector *GraphicalElements::_allSelectors = nullptr;

GraphicalElements::GraphicalElements(irr::IrrlichtDevice *device, const irr::core::vector3df &position, const irr::core::vector3df &rotation, irr::core::vector3df scale) :
                                    _device(device),
                                    _mesh(nullptr),
                                    _node(nullptr),
                                    _scale(scale),
                                    _position(position),
                                    _rotation(rotation),
                                    _selector(nullptr),
                                    _selectorWorld(nullptr),
                                    _anim(nullptr)
{}

GraphicalElements::~GraphicalElements()
{
    if (_selectorWorld) {
        _selectorWorld->drop();
    }
    if (_allSelectors && _selector) {
        _allSelectors->removeTriangleSelector(_selector);
    }
    if (_node) {
        _node->removeAnimators();
        _node->remove();
    }
}

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

const irr::scene::IAnimatedMeshSceneNode* GraphicalElements::getNode() const
{
    return (_node);
}

const irr::scene::IAnimatedMesh* GraphicalElements::getMesh() const
{
    return (_mesh);
}

void GraphicalElements::setMesh(std::vector<std::string> texture, std::string &meshPath, irr::s32 id)
{
    irr::scene::ISceneManager* smgr = nullptr;
    irr::video::IVideoDriver* driver = nullptr;

    if (!_device)
        return;
    smgr = _device->getSceneManager();
    driver = _device->getVideoDriver();
    _mesh = smgr->getMesh(meshPath.data());
    _node = smgr->addAnimatedMeshSceneNode(this->_mesh);
    if (_node) {
        _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        _node->setID(id);
        for (irr::u16 i = 0; i < texture.size(); i++)
            _node->setMaterialTexture(i, driver->getTexture(texture[i].c_str()));
        _node->setPosition(irr::core::vector3df(_position.X, _position.Y, _position.Z));
    }
}

const std::string &GraphicalElements::getMeshPath() const
{
    return (_meshPath);
}

void GraphicalElements::setMeshPath(const std::string &meshPath)
{
    if (_node)
        _node->drop();
    _meshPath = meshPath;
}

irr::core::vector3df GraphicalElements::getScale()
{
    return (_scale);
}

void GraphicalElements::setScale(irr::core::vector3df scale)
{
    _scale = scale;
    if (_node)
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

bool GraphicalElements::createSelectorWorld()
{
    irr::u32 size = 0;
    irr::scene::ISceneManager* smgr = nullptr;

    if (!_device)
        return (false);
    smgr = _device->getSceneManager();
    if (smgr == nullptr || _allSelectors == nullptr || _node == nullptr)
        return (false);
    if (_selectorWorld) {
        _selectorWorld->drop();
        _selectorWorld = nullptr;
    }
    _selectorWorld = smgr->createMetaTriangleSelector();
    if (_selectorWorld == nullptr)
        return (false);
    if (_selector == nullptr)
        return (false);
    _node->setTriangleSelector(_selector);

    size = _allSelectors->getSelectorCount();
    for (irr::u32 i = 0; i < size; i++) {
        if (_allSelectors->getSelector(i) == _selector)
            continue;
        _selectorWorld->addTriangleSelector(_allSelectors->getSelector(i));
    }
    return (true);
}

bool GraphicalElements::addColision()
{
    irr::scene::ISceneManager* smgr = nullptr;

    if (!_device || !_node)
        return (false);
    smgr = _device->getSceneManager();
    if (!smgr)
        return (false);
    if (!_allSelectors)
        _allSelectors = smgr->createMetaTriangleSelector();
    if (!_allSelectors)
        return (false);

    _selector = smgr->createOctreeTriangleSelector(_mesh, _node);
    _allSelectors->addTriangleSelector(_selector);
    _node->setTriangleSelector(_selector);
    return (true);
}

bool GraphicalElements::addColisionResponse(irr::core::vector3df sphere, irr::core::vector3df translation)
{
    irr::scene::ISceneNodeAnimator* anim = nullptr;
    irr::scene::ISceneManager* smgr = nullptr;

    if (!_device)
        return (false);
    smgr = _device->getSceneManager();
    if (!smgr)
        return (false);
    _boxColision = sphere;
    _translationColision = translation;
    if (_selector == nullptr && !addColision())
        return (false);

    if (!createSelectorWorld())
        return (false);
    anim = smgr->createCollisionResponseAnimator(
            _selectorWorld, _node, sphere,
            irr::core::vector3df(0, 0, 20), translation);
    if (!anim)
        return (false);
    _node->addAnimator(anim);
    anim->drop();
    return (true);
}

bool GraphicalElements::updateColision()
{
    irr::scene::ISceneNodeAnimator* anim = nullptr;
    irr::scene::ISceneManager* smgr = nullptr;

    if (!_device)
        return (false);
    smgr = _device->getSceneManager();
    if (!createSelectorWorld())
        return (false);
    anim = smgr->createCollisionResponseAnimator(
            _selectorWorld, _node, _boxColision,
            irr::core::vector3df(0, 0, 20), _translationColision);
    if (!anim)
        return (false);
    _node->removeAnimators();
    _node->addAnimator(anim);
    anim->drop();
    return (true);
}

irr::scene::ISceneNode *GraphicalElements::getFrontObj(irr::f32 distance, irr::s32 id)
{
    irr::scene::ISceneNode *res = NULL;
    irr::core::vector3df intersection;
    irr::core::vector3df positionEnd;
    irr::core::triangle3df hitTriangle;
    irr::core::line3d<irr::f32> ray;
    irr::f32 rotation = 0;
    irr::scene::ISceneCollisionManager *collMan = nullptr;

    if (!_device)
        return (nullptr);
    collMan = _device->getSceneManager()->getSceneCollisionManager();
    if (!collMan || !_node)
        return (nullptr);
    rotation = _node->getRotation().Z;
    if (rotation == PlayerController::rotation_e::RIGHT) {
        positionEnd = irr::core::vector3df(1, 0, 0);
    } else if (rotation == PlayerController::rotation_e::LEFT) {
        positionEnd = irr::core::vector3df(-1, 0, 0);
    } else if (rotation == PlayerController::rotation_e::UP) {
        positionEnd = irr::core::vector3df(0, 1, 0);
    } else if (rotation == PlayerController::rotation_e::DOWN) {
        positionEnd = irr::core::vector3df(0, -1, 0);
    } else
        return (nullptr);
    ray.start = _node->getPosition();
    // TODO remove the start.X and start.Y modification when the mesh is at the right position
    ray.start.X += 2.5;
    ray.start.Y += 2.5;
    ray.end = ray.start + (positionEnd).normalize() * distance;
    // std::cout << "x: " << ray.start.X << " y: " << ray.start.Y << " x: " << ray.end.X << " y: " << ray.end.Y << std::endl;
    res = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, hitTriangle, id);
    if (res)
        return (res);
    ray.start.Z += 0.5;
    ray.end.Z += 0.5;
    res = collMan->getSceneNodeAndCollisionPointFromRay(ray, intersection, hitTriangle, id);
    if (res)
        return (res);
    return (NULL);
}

void GraphicalElements::setAnimation(bool anim)
{
    if (_node)
        _node->setLoopMode(anim);
}

void GraphicalElements::setFrame(irr::u16 begin, irr::u16 end)
{
    if (_node)
        _node->setFrameLoop(begin, end);
}

void GraphicalElements::getFrame()
{
    std::cout << _node->getFrameNr() << std::endl;
}

void GraphicalElements::setCurrFrame(irr::u16 frame)
{
    if (_node)
        _node->setCurrentFrame(frame);
}

void GraphicalElements::setSpeed(irr::u16 speed)
{
    if (_node)
        _node->setAnimationSpeed(speed);
}
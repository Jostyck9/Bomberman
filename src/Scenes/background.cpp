/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** background.cpp
*/

#include <iostream>
#include "background.hpp"

Background::Background(irr::IrrlichtDevice* device, MyEventReceiver &receiver) : AScene(device, receiver)
{
    createBackGround();
}    

void Background::createBackGround()
{
    camera = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 3, -5), irr::core::vector3df(0,0,0));
    scene::IAnimatedMeshSceneNode * menu_map = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Engine Room/room.obj"));
    scene::IAnimatedMeshSceneNode* anms = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Bomb-omb/model.dae"));
    anms->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    anms->setPosition(core::vector3df(0,-0.2,0));
    anms->setScale(core::vector3df(0.01,0.01,0.01));
    anms->setRotation(core::vector3df(0,180,0));
    menu_map->setRotation(core::vector3df(0,-34,0));
    menu_map->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    scene::ISceneNodeAnimator* anim =
            _sceneManager->createFlyCircleAnimator(core::vector3df(0,2,1), 3.2f);
        if (anim)
        {
            camera->addAnimator(anim);
            anim->drop();
        }
}

void Background::display()
{
    if (!_device->run()) {
        return;
    }
    _driver->beginScene(true, true, video::SColor(255,100,101,140));
    _sceneManager->drawAll();
    // _driver->endScene();
}

IScene* Background::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    return (this);
}
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
    //Decor(device, "./assets/meshs/Bomb-omb/bomb.b3d", irr::core::vector3df(0,-0.2,0), irr::core::vector3df(0,145,0), irr::core::vector3df(1,1,1));
}

Background::~Background()
{
    if (menu_map)
        menu_map->remove();
    if (anms)
        anms->remove();
    // camera->remove();
}

void Background::createBackGround()
{
    camera = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 3, -5), irr::core::vector3df(0,0,0));
    menu_map = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Engine_Room/room.obj"));
    anms = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Bomb-omb/bomb.b3d"));
    if (anms) {
        anms->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        anms->setPosition(core::vector3df(0,-0.2,0));
        anms->setScale(core::vector3df(1,1,1));
        anms->setRotation(core::vector3df(0,145,0));
    }
    if (!menu_map) {
        menu_map->setRotation(core::vector3df(0,-34,0));
        menu_map->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

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
}

IScene* Background::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    return (this);
}
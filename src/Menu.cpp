/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.cpp
*/

#include <iostream>
#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice* device) : AScene(device), _map(10)
{
    Camera camera(device->getSceneManager(), irr::core::vector3df(0, 30, 30), irr::core::vector3df(0, 0, 0));

    this->setCamera(camera);
}

IScene* Menu::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    std::cout << "x : " << this->getCamera().getCameraPosition().X << " y : " << this->getCamera().getCameraPosition().X << std::endl;
    return (this);
}

IScene* Menu::handleEvent()
{
    return (this);
}

void Menu::display()
{
    if (!_device->run()) {
        return;
    }
    _driver->beginScene(true, true, video::SColor(255,100,101,140));
    _sceneManager->drawAll();
    // guienv->drawAll();
    _driver->endScene();
}
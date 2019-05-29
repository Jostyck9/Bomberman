/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Game.cpp
*/

#include <iostream>
#include "Game.hpp"

Game::Game(irr::IrrlichtDevice* device) : AScene(device), _map(device, 10)//, _player(device, NULL, "./assets/meshs/Mario.obj", 1, 1)
{
    Camera camera(device->getSceneManager(), irr::core::vector3df(-5, 90, 100), irr::core::vector3df(-5, 100, 0));
    std::vector<std::string> textures;
    std::string path = "./assets/meshs/Bomb/ItmBombhei.obj";
    irr::u16 valx = 10;
    irr::u16 valy = 40;

    // textures.push_back("./assets/meshs/Mario/body.png");
    // textures.push_back("./assets/meshs/Mario/eye1.png");
    // // textures.pushback("./assets/meshs/Mario/eye2.png");
    // // textures.pushback("./assets/meshs/Mario/eye3.png");
    // // textures.pushback("./assets/meshs/Mario/eye4.png");
    // textures.push_back("./assets/meshs/Mario/face.png");
    // textures.push_back("./assets/meshs/Mario/fire.png");
    // textures.push_back("./assets/meshs/Mario/glove.png");
    // textures.push_back("./assets/meshs/Mario/hair.png");
    // textures.push_back("./assets/meshs/Mario/hat.png");
    // textures.push_back("./assets/meshs/Mario/pupil.png");
    Player *p1 = new Player(device, textures, path, valx, valy);
    _map.addToMap(0, 0, p1);
    this->setCamera(camera);
}

IScene* Game::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    return (this);
}

IScene* Game::handleEvent()
{
    return (this);
}

void Game::display()
{
    if (!_device->run()) {
        return;
    }
    _driver->beginScene(true, true, video::SColor(255,100,101,140));
    _sceneManager->drawAll();
    // guienv->drawAll();
    _driver->endScene();
}
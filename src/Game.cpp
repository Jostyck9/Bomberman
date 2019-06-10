/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Game.cpp
*/

#include <iostream>
#include "Game.hpp"
#include "Save.hpp"

Game::Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver) : AScene(device, receiver), _map(device, 21)//, _player(device, NULL, "./assets/meshs/Mario.obj", 1, 1)
{
    Camera camera(device->getSceneManager(), irr::core::vector3df(100, 60, -160), irr::core::vector3df(100, 90, 0));
    std::vector<std::string> textures;
    std::string path = "./assets/meshs/Bomb/ItmBombhei.obj";
    irr::s16 valx = 17;
    irr::s16 valy = 15;

    Player *p1 = new Player(device, textures, path, valx, valy);
    _map.addToMap(1, 1, p1);
    _map.updateColision();
    this->setCamera(camera);
}

void Game::updateObj(GameObject *obj)
{
    Player *current = nullptr;

    if (!obj)
        return;
    if (obj->getType() == GameObject::PLAYER) {
        current = dynamic_cast<Player *>(obj);
        current->update(_events);
    }
}

IScene* Game::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    boost::multi_array<std::vector<GameObject*>, 2> &map = _map.getMap();
    for (irr::u16 x = 0; x < _map.getSize(); x++) {
        for (irr::u16 y = 0; y < _map.getSize(); y++) {
            for (auto &it : map[x][y]) {
                updateObj(it);
            }
        }
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
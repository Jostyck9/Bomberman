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
    irr::s16 valx = 12.5;
    irr::s16 valy = 12.5;

    std::shared_ptr<Player> p1(new Player(device, textures, path, valx, valy));
    _map.addToMap(1, 1, p1);
    _map.updateColision();
    this->setCamera(camera);
}

void Game::updateObj(std::shared_ptr<GameObject> obj)
{
    std::shared_ptr<Player> current = nullptr;

    if (!obj)
        return;
    if (obj->getType() == GameObject::PLAYER) {
        current = std::dynamic_pointer_cast<Player>(obj);
        current->update(_events);
        updateMapFromPlayer(current);
    }
}

void Game::updateMapFromPlayer(std::shared_ptr<Player> current)
{
    irr::u16 x1 = 0;
    irr::u16 y1 = 0;

    for (irr::u16 i = 0; i < this->_map.getSize(); i++) {
        for (irr::u16 k = 0; k < this->_map.getSize(); k++) {
            for (irr::u16 x = 0; x < this->_map.getMap()[i][k].size(); x++) {
                if (current == _map.getMap()[i][k].at(x)) {
                    x1 = current->getPlayerController().getDisplayInfo().getPosition().X;
                    y1 = current->getPlayerController().getDisplayInfo().getPosition().Y;
                    if (x1 != i) {
                        current->getPlayerController().setPosition(irr::core::vector3df(current->getPlayerController().getPosition().X, y1,0));
                        _map.addToMap(x1 / 10, k, current);
                        _map.delToMap(i, k, current);
                    }
                    if (y1 != k) {
                        current->getPlayerController().setPosition(irr::core::vector3df(x1, current->getPlayerController().getPosition().Y, 0));
                        _map.addToMap(i, y1 / 10, current);
                        _map.delToMap(i, k, current);
                    }
                }
            }
        }
    }
}

IScene* Game::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    for (irr::u16 x = 0; x < _map.getSize(); x++) {
        for (irr::u16 y = 0; y < _map.getSize(); y++) {
            for (auto &it : _map.getMap()[x][y]) {
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
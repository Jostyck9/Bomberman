/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Game.cpp
*/

#include <iostream>
#include "Explosion.hpp"
#include "Game.hpp"
#include "Bomb.hpp"
#include "Save.hpp"
#include "NonPlayer.hpp"

Game::Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, std::string save) : AScene(device, receiver),
                                                                    _ground(device, "./assets/meshs/Stade/stade.b3d", irr::core::vector3df(100, -5, 5), irr::core::vector3df(-90, 0, 0), irr::core::vector3df(1.5, 1.5, 1.5)),
                                                                    _map(device, save, 21)
{
    _ground.addColision();
    Camera camera(device->getSceneManager(), irr::core::vector3df(100, 60, -160), irr::core::vector3df(100, 90, 0));
    std::vector<std::string> textures;
    std::string path = "./assets/meshs/Luigi/luigiV3.b3d";
    // std::string path = "./assets/meshs/Peach/pitchv3.b3d";
    std::shared_ptr<Player> p1(new Player(device, textures, path, 1, 1));
    if (p1) {
        _map.addToMap(1, 1, p1);
    }
    std::shared_ptr<NonPlayer> p2(new NonPlayer(device, _map, textures, path, 1, _map.getSize() - 2));
    if (p2) {
        _map.addToMap(1, _map.getSize() - 2, p2);
    }
    _map.updateColision();
    this->setCamera(camera);
}

void Game::updateObj(std::shared_ptr<GameObject> obj, std::vector<irr::s32> &idToDel, std::vector<irr::s32> &idToMove)
{
    std::shared_ptr<Player> current = nullptr;
    std::shared_ptr<NonPlayer> currentIA = nullptr;
    std::shared_ptr<Bomb> currentBomb = nullptr;
    std::shared_ptr<Explosion> currentExplosion = nullptr;

    if (!obj)
        return;
    if (obj->getType() == GameObject::PLAYER) {
        current = std::dynamic_pointer_cast<Player>(obj);
        current->update(_map, idToDel, _events);
        idToMove.push_back(obj->getID());
    } else if (obj->getType() == GameObject::NONPLAYER) {
        currentIA = std::dynamic_pointer_cast<NonPlayer>(obj);
        currentIA->update(_map, idToDel);
        idToMove.push_back(obj->getID());
    } else if (obj->getType() == GameObject::BOMB) {
        currentBomb = std::dynamic_pointer_cast<Bomb>(obj);
        currentBomb->update(_map, idToDel);
    } else if (obj->getType() == GameObject::EXPLOSION) {
        currentExplosion = std::dynamic_pointer_cast<Explosion>(obj);
        currentExplosion->update(_map, idToDel);
    }
}

void Game::deleteObj(std::vector<irr::s32> &idToDel)
{
    for (auto &it : idToDel) {
        _map.delToMap(it);
    }
    if (!idToDel.empty())
        _map.updateColision();
}

IScene* Game::update()
{
    std::vector<irr::s32> idToDel;
    std::vector<irr::s32> idToMove;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    for (irr::u16 x = 0; x < _map.getSize(); x++) {
        for (irr::u16 y = 0; y < _map.getSize(); y++) {
            for (auto &it : _map.getMap()[x][y]) {
                updateObj(it, idToDel, idToMove);
            }
        }
    }
    updatePosition(idToMove);
    deleteObj(idToDel);

    _events.resetKeys();
    return (this);
}

void Game::updatePosition(std::vector<irr::s32> &idToMove)
{
    std::shared_ptr<GameObject> current(nullptr);

    for (auto &it : idToMove) {
        current = _map.getObject(it);
        if (current && (current->getType() == GameObject::objectType_s::PLAYER || current->getType() == GameObject::objectType_s::NONPLAYER))
            updateMapFromPlayer(std::dynamic_pointer_cast<ACharacter>(current));
    }
}

irr::core::vector2df Game::worldToMap(irr::s16 x, irr::s16 y, irr::u16 size)
{
    irr::core::vector2df res(0, -1);
    irr::s16 bornX = -5;
    irr::s16 bornY = -5;

    for (;res.X < size; res.X++) {
        if (x > bornX + (10 * res.X) && x <= bornX + (10 * (res.X + 1))) {
            break;
        }
    }
    for (;res.Y < size; res.Y++) {
        if (y > bornX + (10 * res.Y) && y <= bornX + (10 * (res.Y + 1))) {
            break;
        }
    }
    return (res);
}

void Game::updateMapFromPlayer(std::shared_ptr<ACharacter> current)
{
    irr::core::vector2df newPos;
    irr::u16 x1 = 0;
    irr::u16 y1 = 0;

    for (irr::u16 i = 0; i < this->_map.getSize(); i++) {
        for (irr::u16 k = 0; k < this->_map.getSize(); k++) {
            for (irr::u16 x = 0; x < this->_map.getMap()[i][k].size(); x++) {
                if (current == _map.getMap()[i][k].at(x)) {
                    x1 = current->getDisplayInfo().getPosition().X;
                    y1 = current->getDisplayInfo().getPosition().Y;
                    if (!((i * 10) - 5 < x1 && x1 <= (i * 10) + 5)) {
                        newPos = worldToMap(x1, y1, _map.getSize());
                        _map.addToMap(newPos.X, newPos.Y, current);
                        _map.delToMap(i, k, current);
                        return;
                    }
                    if (!((k * 10) - 5 < y1 && y1 <= (k * 10) + 5)) {
                        newPos = worldToMap(x1, y1, _map.getSize());
                        _map.addToMap(newPos.X, newPos.Y, current);
                        _map.delToMap(i, k, current);
                        return;
                    }
                }
            }
        }
    }
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
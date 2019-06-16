/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Game.cpp
*/

#include <iostream>
#include "BomberException.hpp"
#include "MapWrapper.hpp"
#include "Explosion.hpp"
#include "Game.hpp"
#include "Bomb.hpp"
#include "Save.hpp"
#include "NonPlayer.hpp"
#include "Menu_game.hpp"

Game::Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, character character) : AScene(device, receiver),
                                                                    _ground(device, "./assets/meshs/Stade/stade.b3d", irr::core::vector3df(100, -5, 5), irr::core::vector3df(-90, 0, 0), irr::core::vector3df(1.5, 1.5, 1.5)),
                                                                    _map(device, "", 21),
                                                                    _sound()
{
    creationOfDecor();
    _ground.addColision();
    Camera camera(device->getSceneManager(), irr::core::vector3df(100, 60, -160), irr::core::vector3df(100, 90, 0));
    std::vector<std::string> textures;
    _sound.playGameMusic();
    std::string pathLuigi = "./assets/meshs/Luigi/luigi.b3d";
    std::string pathMario = "./assets/meshs/Mario/mario.b3d";
    std::string pathPeach = "./assets/meshs/Peach/peach.b3d";
    std::string pathToad = "./assets/meshs/Toad/toad.b3d";
    if (character.Luigi == character::Player1 || character.Luigi == character::Player2) {
        std::shared_ptr<Player> p1(new Player(device, textures, pathLuigi, 1, _map.getSize() - 2, Map::character_t::luigi));
        if (character.Luigi == character::Player2) {
            p1->getPlayerController().getKeyMap().setLeft(irr::KEY_LEFT);
            p1->getPlayerController().getKeyMap().setRight(irr::KEY_RIGHT);
            p1->getPlayerController().getKeyMap().setForward(irr::KEY_UP);
            p1->getPlayerController().getKeyMap().setBackward(irr::KEY_DOWN);
            p1->getPlayerController().getKeyMap().setAction(irr::KEY_RETURN);
        }
        if (p1)
            _map.addToMap(1, _map.getSize() - 2, p1);
    }
    if (character.Luigi == character::IA) {
        std::shared_ptr<NonPlayer> p1(new NonPlayer(device, _map, textures, pathLuigi, 1, _map.getSize() - 2, Map::character_t::luigi));
        if (p1)
            _map.addToMap(1, _map.getSize() - 2, p1);
    }
    if (character.Mario == character::Player1 || character.Mario == character::Player2) {
        std::shared_ptr<Player> p1(new Player(device, textures, pathMario, _map.getSize() - 2, _map.getSize() - 2, Map::character_t::mario));
        if (character.Mario == character::Player2) {
            p1->getPlayerController().getKeyMap().setLeft(irr::KEY_LEFT);
            p1->getPlayerController().getKeyMap().setRight(irr::KEY_RIGHT);
            p1->getPlayerController().getKeyMap().setForward(irr::KEY_UP);
            p1->getPlayerController().getKeyMap().setBackward(irr::KEY_DOWN);
            p1->getPlayerController().getKeyMap().setAction(irr::KEY_RETURN);
        }
        if (p1)
            _map.addToMap(_map.getSize() - 2, _map.getSize() - 2, p1);
    }
    if (character.Mario == character::IA) {
        std::shared_ptr<NonPlayer> p1(new NonPlayer(device, _map, textures, pathMario, _map.getSize() - 2, _map.getSize() - 2, Map::character_t::mario));
        if (p1)
            _map.addToMap(_map.getSize() - 2, _map.getSize() - 2, p1);
    }
    if (character.Peach == character::Player1 || character.Peach == character::Player2) {
        std::shared_ptr<Player> p1(new Player(device, textures, pathPeach, _map.getSize() - 2, 1, Map::character_t::peach));
        if (character.Peach == character::Player2) {
            p1->getPlayerController().getKeyMap().setLeft(irr::KEY_LEFT);
            p1->getPlayerController().getKeyMap().setRight(irr::KEY_RIGHT);
            p1->getPlayerController().getKeyMap().setForward(irr::KEY_UP);
            p1->getPlayerController().getKeyMap().setBackward(irr::KEY_DOWN);
            p1->getPlayerController().getKeyMap().setAction(irr::KEY_RETURN);
        }
        if (p1)
            _map.addToMap(_map.getSize() - 2, 1, p1);
    }
    if (character.Peach == character::IA) {
        std::shared_ptr<NonPlayer> p1(new NonPlayer(device, _map, textures, pathPeach, _map.getSize() - 2, 1, Map::character_t::peach));
        if (p1)
            _map.addToMap(_map.getSize() - 2, 1, p1);
    }
    if (character.Toad == character::Player1 || character.Toad == character::Player2) {
        std::shared_ptr<Player> p1(new Player(device, textures, pathToad, 1, 1, Map::character_t::toad));
        if (character.Toad == character::Player2) {
            p1->getPlayerController().getKeyMap().setLeft(irr::KEY_LEFT);
            p1->getPlayerController().getKeyMap().setRight(irr::KEY_RIGHT);
            p1->getPlayerController().getKeyMap().setForward(irr::KEY_UP);
            p1->getPlayerController().getKeyMap().setBackward(irr::KEY_DOWN);
            p1->getPlayerController().getKeyMap().setAction(irr::KEY_RETURN);
        }
        if (p1)
            _map.addToMap(1, 1, p1);
    }
    if (character.Toad == character::IA) {
        std::shared_ptr<NonPlayer> p1(new NonPlayer(device, _map, textures, pathToad, 1, 1, Map::character_t::toad));
        if (p1)
            _map.addToMap(1, 1, p1);
    }
    _map.updateColision();
    this->setCamera(camera);
}

Game::Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, std::string save) : AScene(device, receiver),
                                                                                       _ground(device, "./assets/meshs/Stade/stade.b3d", irr::core::vector3df(100, -5, 5), irr::core::vector3df(-90, 0, 0), irr::core::vector3df(1.5, 1.5, 1.5)),
                                                                                       _map(device, save, 21),
                                                                                       _sound()
{
    _ground.addColision();
    _sound.playGameMusic();
    Camera camera(device->getSceneManager(), irr::core::vector3df(100, 60, -160), irr::core::vector3df(100, 90, 0));
    _map.updateColision();
    this->setCamera(camera);
}

Game::~Game()
{
    _sound.stopMe();
}

void Game::updateObj(std::shared_ptr<GameObject> obj, std::vector<irr::s32> &idToDel, std::vector<irr::s32> &idToMove, std::vector<MapWrapper> &objToAdd)
{
    std::shared_ptr<Player> current = nullptr;
    std::shared_ptr<NonPlayer> currentIA = nullptr;
    std::shared_ptr<Bomb> currentBomb = nullptr;
    std::shared_ptr<Explosion> currentExplosion = nullptr;

    if (!obj)
        return;
    if (obj->getType() == GameObject::PLAYER) {
        current = std::dynamic_pointer_cast<Player>(obj);
        current->update(_map, idToDel, objToAdd,_events);
        idToMove.push_back(obj->getID());
    } else if (obj->getType() == GameObject::NONPLAYER) {
        currentIA = std::dynamic_pointer_cast<NonPlayer>(obj);
        currentIA->update(_map, idToDel, objToAdd);
        idToMove.push_back(obj->getID());
    } else if (obj->getType() == GameObject::BOMB) {
        currentBomb = std::dynamic_pointer_cast<Bomb>(obj);
        currentBomb->update(_map, idToDel, objToAdd);
    } else if (obj->getType() == GameObject::EXPLOSION) {
        currentExplosion = std::dynamic_pointer_cast<Explosion>(obj);
        currentExplosion->update(_map, idToDel, objToAdd);
    }
}

void Game::addObj(std::vector<MapWrapper> &objToAdd)
{
    for (auto &it : objToAdd) {
        _map.addToMap(it.getPos().X, it.getPos().Y, it.getObj());
    }
    if (!objToAdd.empty())
        _map.updateColision();
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
    std::vector<MapWrapper> objToAdd;
    IScene *next = NULL;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    try {
        for (irr::u16 x = 0; x < _map.getSize(); x++) {
            for (irr::u16 y = 0; y < _map.getSize(); y++) {
                for (auto &it : _map.getMap()[x][y]) {
                    updateObj(it, idToDel, idToMove, objToAdd);
                }
            }
        }
        updatePosition(idToMove);
        deleteObj(idToDel);
        addObj(objToAdd);
    } catch (bomberException &e) {
        std::cerr << e.getPart() << " : " << e.what() << std::endl;
        delete this;
        return (nullptr);
    }

    if (_events.IsKeyReleased(irr::KEY_ESCAPE)) {
        next = new Menu_game(_device, _events, _map, this, _sound);
        return (next);
    }
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

//Decor::Decor(device, mesh, pos, rotation, scale)

void Game::creationOfDecor()
{
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/Cardboar_ Bush/bushboard.obj", irr::core::vector3df(-30, 150, -15), irr::core::vector3df(90, 180, 10), irr::core::vector3df(0.25, 0.25, 0.25))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/Cardboar_ Bush/bushboard.obj", irr::core::vector3df(220, 110, -15), irr::core::vector3df(90, 180, -15), irr::core::vector3df(0.20, 0.20, 0.20))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/N64_Tree/n64tree.obj", irr::core::vector3df(-40, 70, -15), irr::core::vector3df(90, 180, 0), irr::core::vector3df(1, 1, 1))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/N64_Tree/n64tree.obj", irr::core::vector3df(220, 30, -15), irr::core::vector3df(90, 180, 0), irr::core::vector3df(1.1, 1.1, 1.1))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/Cardboard_Goomba/cardboardgoomba.obj", irr::core::vector3df(-22, 105, -15), irr::core::vector3df(90, 180, 35), irr::core::vector3df(0.2, 0.2, 0.2))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/Sling_Star/Sling_Star.b3d", irr::core::vector3df(250, 80, -15), irr::core::vector3df(120, 190, 0), irr::core::vector3df(3, 3, 3))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/Sling_Star/Sling_Star.b3d", irr::core::vector3df(-20, 20, -15), irr::core::vector3df(120, 160, 0), irr::core::vector3df(3, 3, 3))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/Cardboard_Goomba/cardboardgoomba.obj", irr::core::vector3df(240, 55, -15), irr::core::vector3df(90, 180, -45), irr::core::vector3df(0.2, 0.2, 0.2))));
    _allDecors.push_back(std::shared_ptr<Decor>(new Decor(_device, "./assets/meshs/Decor/Cardboard_Goomba/cardboardgoomba.obj", irr::core::vector3df(220, 150, -15), irr::core::vector3df(90, 180, -10), irr::core::vector3df(0.2, 0.2, 0.2))));
}
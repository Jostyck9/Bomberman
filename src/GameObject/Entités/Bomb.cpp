/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Bomb.cpp
*/

#include <iostream>
#include "Explosion.hpp"
#include "Bomb.hpp"
#include "Wall.hpp"

Bomb::Bomb(irr::IrrlichtDevice* device, ACharacter& character, irr::u16 radius, irr::core::vector2df &posMap) : PrintableObject(device), _radius(radius), _posMap(posMap), _parentCharacter(character), _sound()
{
    irr::core::vector3df pos((posMap.X * 10), (posMap.Y * 10), 0);
    std::vector<std::string> path_text;
    std::string path_mesh = "./assets/meshs/Bomb-omb/BombAnimated.b3d";

    _sound.playPutBomb();
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setScale(irr::core::vector3df(5,5,5));
    this->getDisplayInfo().setRotation(irr::core::vector3df(90,180,180));
    this->getDisplayInfo().addColision();
    this->getDisplayInfo().setAnimation(true);
}

Bomb::~Bomb()
{
    _sound.playExplosionBomb();
    // std::cout << "BOOOUUUMMM" << std::endl;
}

irr::u16 Bomb::getRadius()
{
    return (_radius);
}

void Bomb::setRadius(irr::u16 radius)
{
    _radius = radius;
}

void Bomb::createExplosion(Map &map, std::vector<MapWrapper> &objToAdd, irr::core::vector2di position)
{
    if (position.X < 0 || position.X >= map.getSize() || position.Y < 0 || position.Y >= map.getSize())
        return;
    
    MapWrapper current(position.X, position.Y, std::shared_ptr<Explosion>(new Explosion(_device, position.X, position.Y)));
    if (current.getObj()) {
        objToAdd.push_back(current);
        // map.addToMap(position.X, position.Y, current);
    }
}

void Bomb::detectDestroyWall(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, irr::core::vector2di dir)
{
    irr::s16 size = map.getSize();
    boost::multi_array<std::vector<std::shared_ptr<GameObject>>, 2> &cellMap = map.getMap();
    irr::s16 posX = 0;
    irr::s16 posY = 0;

    for (irr::u16 i = 1; i <= _radius; i++) {
        posX = _posMap.X + (dir.X * i);
        posY = _posMap.Y + (dir.Y * i);
        if (posX <= 0 || posX >= size - 1)
            return;
        if (posY <= 0 || posY >= size - 1)
            return;
        for (auto &it : cellMap[posX][posY]) {
            if (it->getType() == GameObject::objectType_s::WALL) {
                std::shared_ptr<Wall> currentWall = std::dynamic_pointer_cast<Wall>(it);
                if (currentWall->isBreakable()) {
                    idToDel.push_back(currentWall->getID());
                    currentWall->createPowerUp(_device, map, posX, posY);
                    // createExplosion(map, irr::core::vector2di(posX, posY));
                }
                return;
            }
        }
        createExplosion(map, objToAdd, irr::core::vector2di(posX, posY));
    }
}

Bomb::Action_e Bomb::update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, bool forcedExplosion)
{
    if (!myTimer.isTimeElapsed(2) && !forcedExplosion)
        return (Action_e::NOTHING);
    idToDel.push_back(getID());

    detectDestroyWall(map, idToDel, objToAdd, irr::core::vector2di(0, 1));
    detectDestroyWall(map, idToDel, objToAdd, irr::core::vector2di(0, -1));
    detectDestroyWall(map, idToDel, objToAdd, irr::core::vector2di(1, 0));
    detectDestroyWall(map, idToDel, objToAdd, irr::core::vector2di(-1, 0));
    createExplosion(map, objToAdd, irr::core::vector2di(_posMap.X, _posMap.Y));
    _parentCharacter.getStats().setNbrBomb(_parentCharacter.getStats().getNbrBomb() + 1);
    return (Action_e::DELETE);
}

ACharacter& Bomb::getParentCharacter()
{
    return (_parentCharacter);
}

GameObject::objecType_t Bomb::getType()
{
    return BOMB;
}

// void Bomb::setParentCharacter(ACharacter& character)
// {
//     _parentCharacter = character;
// }

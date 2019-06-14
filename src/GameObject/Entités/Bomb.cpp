/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Bomb.cpp
*/

#include <iostream>
#include "Bomb.hpp"
#include "Wall.hpp"

Bomb::Bomb(irr::IrrlichtDevice* device, ACharacter& character, irr::u16 radius, irr::core::vector2df &posMap) : PrintableObject(device), _radius(radius), _posMap(posMap), _parentCharacter(character)
{
    irr::core::vector3df pos((posMap.X * 10) - 1, (posMap.Y * 10) + 4, 0);
    std::vector<std::string> path_text;
    std::string path_mesh = "./assets/meshs/Bomb-omb/Bomb.b3d";

    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setScale(irr::core::vector3df(5,5,5));
    this->getDisplayInfo().setRotation(irr::core::vector3df(90,180,180));
    this->getDisplayInfo().addColision();
}

Bomb::~Bomb()
{
    std::cout << "BOOOUUUMMM" << std::endl;
}

irr::u16 Bomb::getRadius()
{
    return (_radius);
}

void Bomb::setRadius(irr::u16 radius)
{
    _radius = radius;
}

void Bomb::detectDestroyWall(Map &map, std::vector<irr::s32> &idToDel, irr::core::vector2di dir)
{
    irr::s16 size = map.getSize();
    boost::multi_array<std::vector<std::shared_ptr<GameObject>>, 2> &cellMap = map.getMap();

    for (irr::u16 i = 1; i <= _radius; i++) {
        if (_posMap.X + (dir.X * i) <= 0 || _posMap.X + (dir.X * i) >= size - 1)
            return;
        if (_posMap.Y + (dir.Y * i) <= 0 || _posMap.Y + (dir.Y * i) >= size - 1)
            return;
        for (auto &it : cellMap[_posMap.X + (dir.X * i)][_posMap.Y + (dir.Y * i)]) {
            if (it->getType() == GameObject::objectType_s::WALL) {
                std::shared_ptr<Wall> currentWall = std::dynamic_pointer_cast<Wall>(it);
                if (currentWall->isBreakable()) {
                    idToDel.push_back(currentWall->getID());
                    currentWall->createPowerUp(_device, map, _posMap.X + (dir.X * i), _posMap.Y + (dir.Y * i));
                }
                return;
            }
        }
    }
}

Bomb::Action_e Bomb::update(Map &map, std::vector<irr::s32> &idToDel)
{
    if (!myTimer.isTimeElapsed(3))
        return (Action_e::NOTHING);
    idToDel.push_back(getID());

    detectDestroyWall(map, idToDel, irr::core::vector2di(0, 1));
    detectDestroyWall(map, idToDel, irr::core::vector2di(0, -1));
    detectDestroyWall(map, idToDel, irr::core::vector2di(1, 0));
    detectDestroyWall(map, idToDel, irr::core::vector2di(-1, 0));
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

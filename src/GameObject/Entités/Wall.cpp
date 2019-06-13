/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Wall.cpp
*/

#include <memory>
#include <iostream>
#include "Wall.hpp"
#include "SpeedUp.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include "WallPass.hpp"

Wall::Wall(irr::IrrlichtDevice *device, std::string mesh, std::vector<std::string> texture, irr::u16 x, irr::u16 y, bool isBreakable) : PrintableObject(device), _isBreakable(isBreakable), _life(1)
{
    irr::core::vector3df pos(x * 10, y * 10, 0);

    // std::cout << "x : " << pos.X << " y : " << pos.Y << std::endl;
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(texture, mesh, GameObject::WALL);
    // this->getDisplayInfo().addColisionResponse(irr::core::vector3df(2, 2, 2));
    this->getDisplayInfo().addColision();
    this->getDisplayInfo().setScale(irr::core::vector3df(0.068,0.068,0.068));
}

Wall::~Wall()
{
}

void Wall::createPowerUp(irr::IrrlichtDevice *device, Map &map, irr::u16 x, irr::u16 y)
{
    irr::u16 nb = std::rand() % 10;

    if (nb == 0) {
        std::shared_ptr<GameObject> newSpeedUp(new SpeedUp(device));
        map.addToMap(x, y, newSpeedUp);
    }
    if (nb == 1) {
        std::shared_ptr<GameObject> newFireUp(new FireUp(device));
        map.addToMap(x, y, newFireUp);
    }
    if (nb == 2) {
        std::shared_ptr<GameObject> newBombUp(new BombUp(device));
        map.addToMap(x, y, newBombUp);
    }
    if (nb == 3) {
        std::shared_ptr<GameObject> newSpeedUp(new WallPass(device));
        map.addToMap(x, y, newSpeedUp);
    }
}

bool Wall::isBreakable()
{
    return _isBreakable;
}

GameObject::objecType_t Wall::getType()
{
    return WALL;
}
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Wall.cpp
*/

#include <iostream>
#include "Wall.hpp"
#include "SpeedUp.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include "WallPass.hpp"

Wall::Wall(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, std::string texture, irr::u16 x, irr::u16 y, bool isBreakable) : _isBreakable(isBreakable), _life(1)
{
    irr::core::vector3df pos(x * 10, y * 10, 0);

    std::cout << "x : " << pos.X << " y : " << pos.Y << std::endl;
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(smgr, driver, GraphicalElements::meshType_t::CUBE, texture);
}

Wall::Wall(irr::u16 x, irr::u16 y, bool isBreakable) : _isBreakable(isBreakable), _life(1)
{

}

Wall::~Wall()
{
}

void Wall::createPowerUp(Map *map, irr::u16 x, irr::u16 y)
{
    irr::u16 nb = std::rand() % 10;

    if (nb == 0) {
        SpeedUp *newSpeedUp = new SpeedUp;
        map->addToMap(x, y, newSpeedUp);
    }
    if (nb == 1) {
        FireUp *newFireUp = new FireUp;
        map->addToMap(x, y, newFireUp);
    }
    if (nb == 2) {
        BombUp *newBombUp = new BombUp;
        map->addToMap(x, y, newBombUp);
    }
    if (nb == 3) {
        WallPass *newSpeedUp = new WallPass;
        map->addToMap(x, y, newSpeedUp);
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
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Wall.cpp
*/

#include <iostream>
#include "Wall.hpp"

Wall::Wall(irr::IrrlichtDevice *device, std::string mesh, std::vector<std::string> texture, irr::u16 x, irr::u16 y, bool isBreakable) : PrintableObject(device), _isBreakable(isBreakable), _life(1)
{
    irr::core::vector3df pos(x * 10, y * 10, 0);

    std::cout << "x : " << pos.X << " y : " << pos.Y << std::endl;
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(texture, mesh, GameObject::WALL);
    this->getDisplayInfo().addColision(irr::core::vector3df(2, 2, 2));
    this->getDisplayInfo().setScale(irr::core::vector3df(0.068,0.068,0.068));
}
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Wall.cpp
*/

#include <iostream>
#include "Wall.hpp"

Wall::Wall(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, std::string mesh, std::vector<std::string> texture, irr::u16 x, irr::u16 y, bool isBreakable) : _isBreakable(isBreakable), _life(1)
{
    irr::core::vector3df pos(x * 10, y * 10, 0);

    std::cout << "x : " << pos.X << " y : " << pos.Y << std::endl;
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(smgr, driver, GraphicalElements::meshType_t::CUBE, mesh, texture);
    this->getDisplayInfo().addColision(smgr, irr::core::vector3df(2, 2, 2));
}

Wall::Wall(irr::u16 x, irr::u16 y, bool isBreakable) : _isBreakable(isBreakable), _life(1)
{

}
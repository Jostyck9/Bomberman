/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Wall.cpp
*/

#include "Wall.hpp"

Wall::Wall(std::string& texture, bool irr::u16 x, irr::u16 y, isBreakable) : _isBreakable(isBreakable), _life(1)
{
    this->getDisplayInfo().setMesh(NULL, GraphicalElements::meshType_t::CUBE, texture);
}

Wall::Wall(irr::u16 x, irr::u16 y, bool isBreakable) : _isBreakable(isBreakable), _life(1)
{

}
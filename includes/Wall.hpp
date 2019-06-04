/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Wall.hpp
*/

#ifndef WALL_HPP
#define WALL_HPP

#include "PrintableObject.hpp"
#include "Life.hpp"

class Wall : public PrintableObject
{
private:
    bool _isBreakable;
    Life _life;

public:
    // IItem* createRandomItem();

    Wall(irr::IrrlichtDevice *device, std::string mesh, std::vector<std::string> text, irr::u16 x, irr::u16 y, bool isBreakable = true);
};

#endif

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

    Wall(bool isBreakable = true);
    Wall(std::string& texture, bool isBreakable = true);
};

#endif

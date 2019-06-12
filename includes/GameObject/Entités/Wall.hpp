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
#include "Map.hpp"

class Wall : public PrintableObject
{
private:
    bool _isBreakable;
    Life _life;
    irr::core::vector3df _pos;

public:
    // IItem* createRandomItem();

    Wall(irr::IrrlichtDevice *device, std::string mesh, std::vector<std::string> text, irr::u16 x, irr::u16 y, bool isBreakable = true);
    ~Wall();

    void createPowerUp(irr::IrrlichtDevice *device, Map &map, irr::u16 x, irr::u16 y);
    bool isBreakable();
    objecType_t getType() override;

    irr::core::vector3df getPos();
    void setPos(irr::core::vector3df);
};

#endif

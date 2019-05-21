/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Bomb.hpp
*/

#ifndef BOMB_HPP
#define BOMB_HPP

class Bomb
{

private:
    GraphicalElements _displayInfo;
    irr::u16 _radius;
    ACharacter& _parentCharacter;

public:
    Bomb(ACharacter& character, irr::u16 radius);

    void update();

    GraphicalElements& getDisplayInfo();

    irr::u16 getRadius();

    void setRadius(irr::u16 _radius);

    ACharacter& getParentCharacter();

    void setParentCharacter(ACharacter& _parentCharacter);
};

#endif

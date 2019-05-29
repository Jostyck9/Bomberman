/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Bomb.hpp
*/

#ifndef BOMB_HPP
#define BOMB_HPP

#include "ACharacter.hpp"
#include "PrintableObject.hpp"

class Bomb : public PrintableObject
{
private:
    irr::u16 _radius;
    ACharacter& _parentCharacter;

public:
    Bomb(ACharacter& character, irr::u16 radius);

    irr::u16 getRadius();
    void setRadius(irr::u16 _radius);
    void update();

    ACharacter& getParentCharacter();
    // void setParentCharacter(ACharacter& _parentCharacter);
};

#endif

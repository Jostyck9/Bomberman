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
#include "Timer.hpp"

class Bomb : public PrintableObject
{
private:
    Timer myTimer;
    irr::u16 _radius;
    ACharacter& _parentCharacter;

public:
    Bomb(irr::IrrlichtDevice* device, ACharacter& character, irr::u16 radius);
    ~Bomb();

    irr::u16 getRadius();
    void setRadius(irr::u16 _radius);
    void update(Map &map);
    objecType_t getType() override;
    ACharacter& getParentCharacter();
};

#endif

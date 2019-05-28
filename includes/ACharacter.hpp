/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** ACharacter.hpp
*/

#ifndef ACHARACTER_HPP
#define ACHARACTER_HPP

#include "PrintableObject.hpp"

class ACharacter : public PrintableObject
{
private:
    GraphicalElements _displayInfo;
    CharacterStats _stats;

public:
    Bomb* putBomb(irr::IrrlichtDevice* device);
    bool virtual_action();
    bool move(int irr::core::vector3df);
    bool isAlive();
    void setAlive(bool _alive);
    GraphicalElements& getDisplayInfo();
    CharacterStats& getStats();
};

#endif

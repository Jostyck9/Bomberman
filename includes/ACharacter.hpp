/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** ACharacter.hpp
*/

#ifndef ACHARACTER_HPP
#define ACHARACTER_HPP

class ACharacter
{

private:
    boolean _alive;
    GraphicalElements _displayInfo;
    CharacterStats _stats;

public:
    Bomb* putBomb(irr::IrrlichtDevice* device);

    boolean virtual_action();

    boolean move(int irr::core::vector3df);

    boolean isAlive();

    void setAlive(boolean _alive);

    GraphicalElements& getDisplayInfo();

    CharacterStats& getStats();
};

#endif

/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** ACharacter.hpp
*/

#ifndef ACHARACTER_HPP
#define ACHARACTER_HPP

#include <irrlicht/irrlicht.h>
#include <Bomb.hpp>
#include <GraphicalElements.hpp>
#include <CharacterStats.hpp>

class ACharacter
{

private:
    bool _alive;
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

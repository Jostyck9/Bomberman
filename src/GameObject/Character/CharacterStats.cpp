/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** CharacterStats.cpp
*/

#include <iostream>
#include "CharacterStats.hpp"

CharacterStats::CharacterStats() : _passThrough(false), _bombRadius(1), _nbrBomb(1), _speed(1)
{
}

bool CharacterStats::getPassThrough()
{
    return this->_passThrough;
}

void CharacterStats::setPassThrough(bool _passThrough)
{
    this->_passThrough = _passThrough;
}

irr::u16 CharacterStats::getBombRadius()
{
    return this->_bombRadius;
}

void CharacterStats::setBombRadius(irr::u16 _bombRadius)
{
    this->_bombRadius = _bombRadius;
}

irr::u16 CharacterStats::getNbrBomb()
{
    return this->_nbrBomb;
}

void CharacterStats::setNbrBomb(irr::u16 _nbrBomb)
{
    this->_nbrBomb = _nbrBomb;
}

irr::f32 CharacterStats::getSpeed()
{
    return this->_speed;
}

void CharacterStats::setSpeed(irr::f32 _speed)
{
    this->_speed = _speed;
}
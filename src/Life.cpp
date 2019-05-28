/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Life.cpp
*/

#include "Life.hpp"

Life::Life(irr::s16 life) : _life(life)
{
}

Life::~Life()
{
}

const irr::s16 Life::getLife() const
{
    return (_life);
}

void Life::setLife(irr::s16 life)
{
    _life = life;
}

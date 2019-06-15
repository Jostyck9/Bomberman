/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Explosion.cpp
*/

#include "Explosion.hpp"

Explosion::Explosion(irr::IrrlichtDevice *device) : PrintableObject(device)
{
}

Explosion::~Explosion()
{
}

GameObject::objecType_t Explosion::getType()
{
    return (GameObject::objectType_s::EXPLOSION);
}

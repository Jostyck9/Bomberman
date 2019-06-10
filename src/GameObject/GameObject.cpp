/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GameObject.cpp
*/

#include "GameObject.hpp"
#include "BomberException.hpp"

GameObject::GameObject(irr::IrrlichtDevice *device)
{
    if (!device)
        throw bomberException("Invalid device", "GameObject");
    _device = device;
}

GameObject::objecType_t GameObject::getType()
{
    return UNKNOWN;
}

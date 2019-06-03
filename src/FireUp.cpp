/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** FireUp.cpp
*/

#include "FireUp.hpp"

bool FireUp::applyEffect(ACharacter &player)
{
    player.getStats().setBombRadius(player.getStats().getBombRadius() + 1);
    return true;
}

GameObject::objecType_t FireUp::getType()
{
    return FIREUP;
}
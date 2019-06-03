/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "WallPass.hpp"

bool WallPass::applyEffect(ACharacter &player)
{
    player.getStats().setPassThrough(true);
    return true;
}

GameObject::objecType_t WallPass::getType()
{
    return WALLPASS;
}
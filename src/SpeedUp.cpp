/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "SpeedUp.hpp"

bool SpeedUp::applyEffect(ACharacter &player)
{
    player.getStats().setSpeed(player.getStats().getSpeed() + 1);
    return true;
}

GameObject::objecType_t SpeedUp::getType()
{
    return SPEEDUP;
}
/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "SpeedUp.hpp"

SpeedUp::SpeedUp(irr::IrrlichtDevice* device) : AItem(device)
{
}

bool SpeedUp::applyEffect(ACharacter &player)
{
    player.getStats().setSpeed(player.getStats().getSpeed() + 1);
    return true;
}

GameObject::objecType_t SpeedUp::getType()
{
    return SPEEDUP;
}
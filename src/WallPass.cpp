/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "WallPass.hpp"

WallPass::WallPass(irr::IrrlichtDevice* device) : AItem(device)
{
}

bool WallPass::applyEffect(ACharacter &player)
{
    player.getStats().setPassThrough(true);
    return true;
}

GameObject::objecType_t WallPass::getType()
{
    return WALLPASS;
}
/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombUp.cpp
*/

#include "BombUp.hpp"

BombUp::BombUp(irr::IrrlichtDevice* device) : AItem(device)
{
}

bool BombUp::applyEffect(ACharacter &player)
{
    player.getStats().setNbrBomb(player.getStats().getNbrBomb() + 1);
    return true;
}

GameObject::objecType_t BombUp::getType()
{
    return BOMBUP;
}
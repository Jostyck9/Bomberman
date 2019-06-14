/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** AItem.cpp
*/

#include "AItem.hpp"

AItem::AItem(irr::IrrlichtDevice* device) : PrintableObject(device)
{
}

irr::core::vector3df AItem::getPosWorld()
{
    return (this->_posWorld);
}

irr::core::vector3df AItem::getPosMap()
{
    return (this->_posMap);
}

void AItem::setPosWorld(irr::core::vector3df posW)
{
    this->_posWorld = posW;
}

void AItem::setPosMap(irr::core::vector3df posM)
{
    this->_posMap = posM;
}
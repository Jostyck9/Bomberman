/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** PrintableObject.cpp
*/

#include "PrintableObject.hpp"

PrintableObject::PrintableObject(irr::IrrlichtDevice* device, irr::core::vector3df position) : _displayInfo(device)
{
    _displayInfo.setPosition(position);
}

GameObject::objecType_t PrintableObject::getType()
{
    return (PRINTABLE_OBJ);
}

GraphicalElements &PrintableObject::getDisplayInfo()
{
    return (_displayInfo);
}

void PrintableObject::updateColision()
{
    getDisplayInfo().updateColision();
}
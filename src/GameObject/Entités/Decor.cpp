/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Decor.cpp
*/

#include "Decor.hpp"

Decor::Decor(irr::IrrlichtDevice* device, std::string mesh, irr::core::vector3df pos, irr::core::vector3df rotation, irr::core::vector3df scale) : PrintableObject(device)
{
    std::vector<std::string> path_text;

    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(path_text, mesh);
    this->getDisplayInfo().setScale(scale);
    this->getDisplayInfo().setRotation(rotation);
}

Decor::~Decor()
{
}

void Decor::addColision()
{
    this->getDisplayInfo().addColision();
}

void Decor::setScale(irr::core::vector3df scale)
{
    this->getDisplayInfo().setScale(scale);
}

void Decor::setPosition(irr::core::vector3df position)
{
    this->getDisplayInfo().setPosition(position);
}

void Decor::setRotation(irr::core::vector3df rotation)
{
    this->getDisplayInfo().setRotation(rotation);
}
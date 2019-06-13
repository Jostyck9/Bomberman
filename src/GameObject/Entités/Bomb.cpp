/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Bomb.cpp
*/

#include <iostream>
#include "Bomb.hpp"

Bomb::Bomb(irr::IrrlichtDevice* device, ACharacter& character, irr::u16 radius, irr::core::vector2df &posMap) : PrintableObject(device), _radius(radius), _parentCharacter(character)
{
    irr::core::vector3df pos((posMap.X * 10) - 1, (posMap.Y * 10) + 4, 0);
    std::vector<std::string> path_text;
    std::string path_mesh = "./assets/meshs/Bomb/ItmBombhei.obj";

    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setScale(irr::core::vector3df(1.3,1.3,1.3));
    this->getDisplayInfo().setRotation(irr::core::vector3df(90,180,0));
    this->getDisplayInfo().addColision();
}

Bomb::~Bomb()
{
    std::cout << "BOOOUUUMMM" << std::endl;
}

irr::u16 Bomb::getRadius()
{
    return (_radius);
}

void Bomb::setRadius(irr::u16 radius)
{
    _radius = radius;
}

Bomb::Action_e Bomb::update(Map &map, std::vector<irr::s32> &idToDel)
{
    (void)map;
    if (!myTimer.isTimeElapsed(3))
        return (Action_e::NOTHING);
    idToDel.push_back(getID());
    _parentCharacter.getStats().setNbrBomb(_parentCharacter.getStats().getNbrBomb() + 1);
    return (Action_e::DELETE);
}

ACharacter& Bomb::getParentCharacter()
{
    return (_parentCharacter);
}

GameObject::objecType_t Bomb::getType()
{
    return BOMB;
}

// void Bomb::setParentCharacter(ACharacter& character)
// {
//     _parentCharacter = character;
// }

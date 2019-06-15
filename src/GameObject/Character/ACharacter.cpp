/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** ACharacter.cpp
*/

#include <iostream>
#include "ACharacter.hpp"

ACharacter::ACharacter(irr::IrrlichtDevice* device) : PrintableObject(device), _stats(), _score(), _life(), _controller(this->getDisplayInfo(), *this)
{
}

CharacterStats &ACharacter::getStats()
{
    return (_stats);
}

Score &ACharacter::getScore()
{
    return (_score);
}

Life &ACharacter::getLife()
{
    return (_life);
}

PlayerController &ACharacter::getPlayerController()
{
    return (_controller);
}

GameObject::objecType_t ACharacter::getType()
{
    return (GameObject::ACHARACTER);
}

void ACharacter::applyDammage(std::vector<irr::s32> &idToDel, irr::s16 dammage)
{
    getLife().setLife(getLife().getLife() - dammage);

    if (getLife().getLife() <= 0) {
        std::cout << "YOU HAVE DIED" << std::endl;
    }
}
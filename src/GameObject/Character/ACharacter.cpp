/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** ACharacter.cpp
*/

#include <iostream>
#include "ACharacter.hpp"

ACharacter::ACharacter(irr::IrrlichtDevice* device, character_t character) : PrintableObject(device), _stats(), _score(), _life(), _controller(this->getDisplayInfo(), *this), _character(character)
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
        idToDel.push_back(getID());
    }
}

ACharacter::character_t ACharacter::getCharacter() const
{
    return _character;
}

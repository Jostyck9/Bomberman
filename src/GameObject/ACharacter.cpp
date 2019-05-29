/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** ACharacter.cpp
*/

#include "ACharacter.hpp"

ACharacter::ACharacter() : _stats(), _score(), _life(), _controller(this->getDisplayInfo())
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
    return (GameObject::PLAYER);
}
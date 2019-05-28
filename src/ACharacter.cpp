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
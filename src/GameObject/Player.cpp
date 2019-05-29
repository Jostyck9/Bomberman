/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Player.cpp
*/


#include "Player.hpp"

void Player::update(MyEventReceiver event)
{
    this->getPlayerController().action(event);
}
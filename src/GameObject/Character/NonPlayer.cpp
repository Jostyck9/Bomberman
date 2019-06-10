/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** NonPlayer.cpp
*/


#include "NonPlayer.hpp"

NonPlayer::NonPlayer(irr::IrrlichtDevice *device, Map &map) : ACharacter(device), _ia(map, *this)
{

}

void NonPlayer::update(MyEventReceiver event)
{
    (void)event;
    //TODO with IA
}
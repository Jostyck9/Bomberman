/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** NonPlayer.cpp
*/


#include "NonPlayer.hpp"

NonPlayer::NonPlayer(Map &map) : _ia(map, *this)
{

}

void NonPlayer::update(MyEventReceiver event)
{
    (void)event;
    //TODO with IA
}
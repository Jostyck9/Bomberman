/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ACharacter.hpp"

class Player : public ACharacter
{
public:
    void update(MyEventReceiver event = MyEventReceiver()) override;
};

#endif

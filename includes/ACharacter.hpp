/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** ACharacter.hpp
*/

#ifndef ACHARACTER_HPP
#define ACHARACTER_HPP

#include "PrintableObject.hpp"
#include "PlayerController.hpp"
#include "CharacterStats.hpp"
#include "Score.hpp"
#include "Life.hpp"

class ACharacter : public PrintableObject
{
private:
    CharacterStats _stats;
    Score _score;
    Life _life;
    PlayerController _controller;

public:
    ACharacter(irr::IrrlichtDevice* device);
    virtual ~ACharacter() = default;

    CharacterStats &getStats();
    Score &getScore();
    Life &getLife();
    PlayerController &getPlayerController();
    virtual void update(MyEventReceiver event = MyEventReceiver()) = 0;

    GameObject::objecType_t getType();
};

#endif

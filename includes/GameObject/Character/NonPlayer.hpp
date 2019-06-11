/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** NonPlayer.hpp
*/

#ifndef NONPLAYER_HPP
#define NONPLAYER_HPP

#include "ACharacter.hpp"
#include "BotIA.hpp"

class NonPlayer : public ACharacter
{
private:
    BotIA _ia;
public:
    NonPlayer(irr::IrrlichtDevice *device, Map &map);
    void update(MyEventReceiver event = MyEventReceiver()) override;

    GameObject::objecType_t getType() override;
};

#endif

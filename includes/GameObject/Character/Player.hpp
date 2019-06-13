/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ACharacter.hpp"
#include "Map.hpp"
#include <vector>

class Player : public ACharacter
{
private:
    irr::IrrlichtDevice* _device;
public:
    void update(Map &map, MyEventReceiver event = MyEventReceiver()) override;

    Player(irr::IrrlichtDevice*, std::vector<std::string>, std::string&, irr::s16, irr::s16);

    GameObject::objecType_t getType() override;
};

#endif

/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "ACharacter.hpp"
#include "Map.hpp"
#include "MapWrapper.hpp"

class Player : public ACharacter
{
private:
public:
    void update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, MyEventReceiver event = MyEventReceiver()) override;

    Player(irr::IrrlichtDevice*, std::vector<std::string>, std::string&, irr::s16, irr::s16, Map::character_t character);
    ~Player();

    GameObject::objecType_t getType() override;
};

#endif

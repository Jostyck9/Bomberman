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
#include "MapWrapper.hpp"

class NonPlayer : public ACharacter
{
private:
    BotIA _ia;
public:
    NonPlayer(irr::IrrlichtDevice *device, Map &map, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y, ACharacter::character_t character);
    ~NonPlayer();
    void update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, MyEventReceiver event = MyEventReceiver()) override;

    GameObject::objecType_t getType() override;
};

#endif

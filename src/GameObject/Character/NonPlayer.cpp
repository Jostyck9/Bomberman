/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** NonPlayer.cpp
*/


#include "NonPlayer.hpp"

NonPlayer::NonPlayer(irr::IrrlichtDevice *device, Map &map, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y) : ACharacter(device), _ia(map, std::shared_ptr<ACharacter>(this))
{
    irr::core::vector3df pos(pos_x, pos_y, 0);
    irr::core::vector3df pos_r(pos_x / 10, pos_y / 10, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getPlayerController().setPosition(pos_r);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(90,180,0));
    this->getDisplayInfo().addColision(irr::core::vector3df(2, 2, 2));
}

void NonPlayer::update(Map &map, std::vector<irr::s32> &idToDel, MyEventReceiver event)
{
    this->getPlayerController().action(event, getStats().getSpeed());
}

GameObject::objecType_t NonPlayer::getType()
{
    return (GameObject::objectType_s::NONPLAYER);
}
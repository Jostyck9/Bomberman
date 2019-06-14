/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** NonPlayer.cpp
*/

#include <iostream>
#include "NonPlayer.hpp"

NonPlayer::NonPlayer(irr::IrrlichtDevice *device, Map &map, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y) : ACharacter(device), _ia(map, *this)
{
    irr::core::vector3df pos(pos_x * 10, pos_y * 10, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setScale(irr::core::vector3df(5, 5, 5));
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,0,0));
    this->getDisplayInfo().addColisionResponse(irr::core::vector3df(3, 3, 4));
}

void NonPlayer::update(Map &map, std::vector<irr::s32> &idToDel, MyEventReceiver event)
{
    _ia.getAction(event);
    std::cout << "z1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_Z) << std::endl;
    std::cout << "q1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_Q) << std::endl;
    std::cout << "s1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_S) << std::endl;
    std::cout << "d1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_D) << std::endl;
    std::cout << "space1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_SPACE) << std::endl << std::endl;
    this->getPlayerController().action(_device, event, map, getStats().getSpeed());
}

GameObject::objecType_t NonPlayer::getType()
{
    return (GameObject::objectType_s::NONPLAYER);
}
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Player.cpp
*/

#include <iostream>
#include "Player.hpp"

Player::Player(irr::IrrlichtDevice* device, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y) : ACharacter(device)
{
    _device = device;
    irr::core::vector3df pos(pos_x, pos_y, 0);
    irr::core::vector3df pos_r(pos_x / 10, pos_y / 10, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getPlayerController().setPosition(pos_r);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(90,180,0));
    this->getDisplayInfo().setScale(irr::core::vector3df(1.5,1.5,1.5));
    this->getDisplayInfo().addColisionResponse(irr::core::vector3df(3, 3, 4));
}

void Player::update(Map &map, MyEventReceiver event)
{
    this->getPlayerController().action(_device, event, map, 1);
    // irr::core::vector3df pos = this->getDisplayInfo().getPosition();
    // irr::u16 valx = dynamic_cast<irr::u16>(pos.X) / 10;
    // irr::u16 valy = dynamic_cast<irr::u16>(pos.Y) / 10;
//    this->getDisplayInfo().setFrame(0, 60);
    // if (getDisplayInfo().getFrontObj(4, GameObject::ITEM) != nullptr)
    //     std::cout << "ok" << std::endl;
}

GameObject::objecType_t Player::getType()
{
    return (GameObject::objectType_s::PLAYER);
}
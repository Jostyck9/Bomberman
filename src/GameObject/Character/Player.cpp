/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Player.cpp
*/

#include <iostream>
#include "AItem.hpp"
#include "Player.hpp"
#include "Wall.hpp"

Player::Player(irr::IrrlichtDevice* device, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y) : ACharacter(device)
{
    _device = device;
    irr::core::vector3df pos(pos_x * 10, pos_y * 10, 0);
    // irr::core::vector3df pos_r(pos_x / 10, pos_y / 10, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setScale(irr::core::vector3df(5, 5, 5));
    // this->getPlayerController().setPosition(pos_r);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,0,0));
    this->getDisplayInfo().addColisionResponse(irr::core::vector3df(3, 3, 4));
    std::cerr << getDisplayInfo().getPosition().X << " " << getDisplayInfo().getPosition().Y << " " << getDisplayInfo().getPosition().Z << std::endl;
}

void Player::update(Map &map, std::vector<irr::s32> &idToDel, MyEventReceiver event)
{
    irr::scene::ISceneNode *node = NULL;
    std::shared_ptr<GameObject> obj = nullptr;
    irr::core::vector3df newPos;

    // irr::core::vector3df pos = this->getDisplayInfo().getPosition();
    // irr::u16 valx = dynamic_cast<irr::u16>(pos.X) / 10;
    // irr::u16 valy = dynamic_cast<irr::u16>(pos.Y) / 10;
//    this->getDisplayInfo().setFrame(0, 60);
    std::cerr << getDisplayInfo().getPosition().X << " " << getDisplayInfo().getPosition().Y << " " << getDisplayInfo().getPosition().Z << std::endl;
    node = getDisplayInfo().getFrontObj(4, GameObject::ITEM);
    if (node != nullptr) {
        obj = map.getObject(node);
        if (obj) {
            std::dynamic_pointer_cast<AItem>(obj)->applyEffect(*this);
            idToDel.push_back(obj->getID());
        }
    }
    if (getStats().getPassThrough()) {
        node = getDisplayInfo().getFrontObj(2, GameObject::WALL);
        if (node) {
            obj = map.getObject(node);
            if (obj && std::dynamic_pointer_cast<Wall>(obj)->isBreakable()) {
                newPos = std::dynamic_pointer_cast<Wall>(obj)->getDisplayInfo().getPosition();
                newPos.Y += 3;
                newPos.Z = -20;
                getDisplayInfo().setPosition(newPos);
                getStats().setPassThrough(false);
                std::cout << "WALLPASS" << std::endl;
            }
        }
    }
    this->getPlayerController().action(_device, event, map, getStats().getSpeed());
}

GameObject::objecType_t Player::getType()
{
    return (GameObject::objectType_s::PLAYER);
}
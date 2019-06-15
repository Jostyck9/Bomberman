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
    // _device = device;
    irr::core::vector3df pos(pos_x * 10, pos_y * 10, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setScale(irr::core::vector3df(5, 5, 5));
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,0,0));
    this->getDisplayInfo().addColisionResponse(irr::core::vector3df(3, 3, 4));
}

void Player::update(Map &map, std::vector<irr::s32> &idToDel, MyEventReceiver event)
{
    bool update = true;
    irr::scene::ISceneNode *node = NULL;
    std::shared_ptr<GameObject> obj = nullptr;
    irr::core::vector3df newPos;

    node = getDisplayInfo().getFrontObj(4, GameObject::ITEM);
    if (node != nullptr) {
        obj = map.getObject(node);
        if (obj) {
            std::dynamic_pointer_cast<AItem>(obj)->applyEffect(*this);
            idToDel.push_back(obj->getID());
        }
    }
    if (getStats().getPassThrough()) {
        node = getDisplayInfo().getFrontObj(4, GameObject::WALL);
        if (node) {
            obj = map.getObject(node);
            if (obj && std::dynamic_pointer_cast<Wall>(obj)->isBreakable()) {
                newPos = std::dynamic_pointer_cast<Wall>(obj)->getDisplayInfo().getPosition();
                newPos.Z = -16;
                getDisplayInfo().setPosition(newPos);
                std::cout << getDisplayInfo().getPosition().X << " " << getDisplayInfo().getPosition().Y << std::endl;
                getStats().setPassThrough(false);
                update = false;
                std::cout << "WALLPASS" << std::endl;
            }
        }
    }
    if (update)
        this->getPlayerController().action(_device, event, map, getStats().getSpeed());
}

GameObject::objecType_t Player::getType()
{
    return (GameObject::objectType_s::PLAYER);
}
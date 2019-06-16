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

Player::Player(irr::IrrlichtDevice* device, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y, Map::character_t character) : ACharacter(device, character)
{
    _device = device;
    irr::core::vector3df pos(pos_x * 10 - 1, pos_y * 10 - 1, -1);
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setScale(irr::core::vector3df(5, 5, 5));
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,0,0));
    this->getDisplayInfo().addColisionResponse(irr::core::vector3df(4, 4, 4));
}

Player::~Player()
{
    getSound().playSoundDefeat();
}

void Player::update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, MyEventReceiver event)
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
            getSound().playPowerUpEffect();
            idToDel.push_back(obj->getID());
        }
    }
    if (getStats().getPassThrough()) {
        node = getDisplayInfo().getFrontObj(5, GameObject::WALL);
        if (node) {
            obj = map.getObject(node);
            if (obj && std::dynamic_pointer_cast<Wall>(obj)->isBreakable()) {
                newPos = std::dynamic_pointer_cast<Wall>(obj)->getDisplayInfo().getPosition();
                newPos.Z = -16;
                getDisplayInfo().setPosition(newPos);
                getStats().setPassThrough(false);
                update = false;
            }
        }
    }
    if (update)
        this->getPlayerController().action(_device, event, map, objToAdd, getStats().getSpeed());
}

GameObject::objecType_t Player::getType()
{
    return (GameObject::objectType_s::PLAYER);
}
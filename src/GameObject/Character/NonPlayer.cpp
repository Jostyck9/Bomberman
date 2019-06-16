/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** NonPlayer.cpp
*/

#include <iostream>
#include "NonPlayer.hpp"
#include "Wall.hpp"
#include "AItem.hpp"

NonPlayer::NonPlayer(irr::IrrlichtDevice *device, Map &map, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y, Map::character_t character) : ACharacter(device, character), _ia(device, map, *this)
{
    irr::core::vector3df pos(pos_x * 10, pos_y * 10, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setScale(irr::core::vector3df(5, 5, 5));
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,0,0));
    this->getDisplayInfo().addColisionResponse(irr::core::vector3df(4, 4, 4));
}

NonPlayer::~NonPlayer()
{
    getSound().playSoundDefeat();
}

void NonPlayer::update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, MyEventReceiver event)
{
    irr::scene::ISceneNode *node = NULL;
    std::shared_ptr<GameObject> obj = nullptr;
    irr::core::vector3df newPos;

    node = getDisplayInfo().getFrontObj(5, GameObject::ITEM);
    if (node != nullptr) {
        obj = map.getObject(node);
        if (obj) {
            std::dynamic_pointer_cast<AItem>(obj)->applyEffect(*this);
            getSound().playPowerUpEffect();
            idToDel.push_back(obj->getID());
        }
    }
    _ia.getAction(event);

    irr::core::vector3df pos = getDisplayInfo().getPosition();
    irr::core::vector2df posMap = map.getPosition(getID());
    if (event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_Z)) {
        pos.X = posMap.X * 10;
    }
    if (event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_Q)) {
        pos.Y = posMap.Y * 10;
    }
    if (event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_S)) {
        pos.X = posMap.X * 10;
    }
    if (event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_D)) {
        pos.Y = posMap.Y * 10;
    }
    getDisplayInfo().setPosition(pos);

    this->getPlayerController().action(_device, event, map, objToAdd, getStats().getSpeed());
}

GameObject::objecType_t NonPlayer::getType()
{
    return (GameObject::objectType_s::NONPLAYER);
}
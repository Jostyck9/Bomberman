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

NonPlayer::NonPlayer(irr::IrrlichtDevice *device, Map &map, std::vector<std::string> path_text, std::string &path_mesh, irr::s16 pos_x, irr::s16 pos_y) : ACharacter(device), _ia(map, *this)
{
    irr::core::vector3df pos(pos_x * 10, pos_y * 10, 0);
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setScale(irr::core::vector3df(5, 5, 5));
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,0,0));
    this->getDisplayInfo().addColisionResponse(irr::core::vector3df(4, 4, 4));
}

void NonPlayer::update(Map &map, std::vector<irr::s32> &idToDel, MyEventReceiver event)
{
/*    if ((int)getDisplayInfo().getPosition().X % 10 != 5) {
        irr::core::vector3df pos = getDisplayInfo().getPosition();
        pos.X = (int)pos.X / 10 * 10;
        getDisplayInfo().setPosition(pos);
    }
    if ((int)getDisplayInfo().getPosition().Y % 10 != 5) {
        irr::core::vector3df pos = getDisplayInfo().getPosition();
        pos.Y = (int)pos.Y / 10 * 10;
        getDisplayInfo().setPosition(pos);
    }*/
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
    _ia.getAction(event);

    // std::cout << "IA POS X = " << getDisplayInfo().getPosition().X << " || Y = " << getDisplayInfo().getPosition().Y << std::endl;
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
    // std::cout << "IA POS AFTER X = " << getDisplayInfo().getPosition().X << " || Y = " << getDisplayInfo().getPosition().Y << std::endl;
    getDisplayInfo().setPosition(pos);

/*    std::cout << "z1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_Z) << std::endl;
    std::cout << "q1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_Q) << std::endl;
    std::cout << "s1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_S) << std::endl;
    std::cout << "d1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_KEY_D) << std::endl;
    std::cout << "space1 : " << event.IsKeyDown(irr::EKEY_CODE::KEY_SPACE) << std::endl << std::endl;*/
    this->getPlayerController().action(_device, event, map, getStats().getSpeed());
}

GameObject::objecType_t NonPlayer::getType()
{
    return (GameObject::objectType_s::NONPLAYER);
}
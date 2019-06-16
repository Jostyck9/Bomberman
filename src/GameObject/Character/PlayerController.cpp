/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** PlayerController.cpp
*/

#include <iostream>
#include <memory>
#include "Bomb.hpp"
#include "ACharacter.hpp"
#include "PlayerController.hpp"
#include "BomberException.hpp"

PlayerController::PlayerController(irr::IrrlichtDevice *device, GraphicalElements &displayInfos, GameObject &player) : _device(device), _displayInfo(displayInfos), _player(player), myTimer(device)
{
}

PlayerController::PlayerController(irr::IrrlichtDevice *device, KeyMap keyMap, GraphicalElements &displayInfos, GameObject &player) : _device(device), _displayInfo(displayInfos), _player(player), myTimer(device)
{
    _keyMap = keyMap;
}

PlayerController::~PlayerController()
{
}

KeyMap &PlayerController::getKeyMap()
{
    return (_keyMap);
}

void PlayerController::setKeyMap(KeyMap &keyMap)
{
    _keyMap = keyMap;
}

GraphicalElements &PlayerController::getDisplayInfo()
{
    return (_displayInfo);
}

void PlayerController::action(irr::IrrlichtDevice *device, MyEventReceiver &events, Map &map, std::vector<MapWrapper> &objToAdd, irr::u16 speed)
{
    bool checker = false;

    if (events.IsKeyDown(_keyMap.getBackward())) {
        setRotation(irr::EKA_MOVE_BACKWARD);
        move(irr::EKA_MOVE_BACKWARD, speed);
        checker = true;
    }
    if (events.IsKeyDown(_keyMap.getForward())) {
        setRotation(irr::EKA_MOVE_FORWARD);
        move(irr::EKA_MOVE_FORWARD, speed);
        checker = true;
    }
    if (events.IsKeyDown(_keyMap.getLeft())) {
        setRotation(irr::EKA_STRAFE_LEFT);
        move(irr::EKA_STRAFE_LEFT, speed);
        checker = true;
    }
    if (events.IsKeyDown(_keyMap.getRight())) {
        setRotation(irr::EKA_STRAFE_RIGHT);
        move(irr::EKA_STRAFE_RIGHT, speed);
        checker = true;
    }
    if (checker == true) {
        this->getDisplayInfo().setAnimation(true);
        this->getDisplayInfo().setSpeed(60);
    }else {
        this->getDisplayInfo().setCurrFrame(0);
        this->getDisplayInfo().setAnimation(false);
    }
    if (events.IsKeyReleased(_keyMap.getAction())) {
        createBomb(device, map, objToAdd);
    }
    myTimer.restartClock();
}

void PlayerController::createBomb(irr::IrrlichtDevice *device, Map &map, std::vector<MapWrapper> &objToAdd)
{
    ACharacter &player = reinterpret_cast<ACharacter&>(_player);
    irr::f32 rotation = player.getDisplayInfo().getRotation().Z;
    irr::core::vector2df posMap = map.getPosition(player.getID());
    bool canPut = true;

    if (rotation == PlayerController::rotation_e::RIGHT) {
        posMap.X += 1;
    } else if (rotation == PlayerController::rotation_e::LEFT) {
        posMap.X -= 1;
    } else if (rotation == PlayerController::rotation_e::UP) {
        posMap.Y += 1;
    } else {
        posMap.Y -= 1;
    }
    try {
        const std::vector<std::shared_ptr<GameObject>> &cell = map.getCellObject(posMap.X, posMap.Y);
        if (!cell.empty())
            canPut = false;
    } catch (bomberException &e) {}
    if (!canPut)
        return;

    if (player.getStats().getNbrBomb() == 0)
        return;
    player.getStats().setNbrBomb(player.getStats().getNbrBomb() - 1);

    try {
        MapWrapper bomb(posMap.X, posMap.Y, std::shared_ptr<GameObject>(new Bomb(device, player, player.getStats().getBombRadius(), posMap)));
        if (bomb.getObj()) {
            objToAdd.push_back(bomb);
            // map.addToMap(posMap.X, posMap.Y, bomb);
            // map.updateColision();
        }
    } catch (bomberException &e){
        player.getStats().setNbrBomb(player.getStats().getNbrBomb() + 1);
    }
}

void PlayerController::setRotation(irr::EKEY_ACTION action)
{
    irr::core::vector3df rotation = _displayInfo.getRotation();

    switch (action)
    {
    case irr::EKA_MOVE_BACKWARD:
        rotation.Z = rotation_e::DOWN;
        break;
    
    case irr::EKA_MOVE_FORWARD:
        rotation.Z = rotation_e::UP;
        break;
    
    case irr::EKA_STRAFE_LEFT:
        rotation.Z = rotation_e::LEFT;
        break;

    case irr::EKA_STRAFE_RIGHT:
        rotation.Z = rotation_e::RIGHT;
        break;
    default:
        return;
    }
    _displayInfo.setRotation(rotation);
}

void PlayerController::move(irr::EKEY_ACTION action, irr::u16 speed)
{
    irr::core::vector3df position = _displayInfo.getPosition();
    irr::s16 offset = 20;
    irr::f32 frameDeltaTime = myTimer.getElapsedTime();
    irr::f32 toAdd = 0;

    toAdd = (offset + speed) * frameDeltaTime;
    if (toAdd >= 9)
        toAdd = 9;
    switch (action)
    {
    case irr::EKA_MOVE_BACKWARD:
        position.Y -= toAdd;
        break;
    
    case irr::EKA_MOVE_FORWARD:
        position.Y += toAdd;
        break;
    
    case irr::EKA_STRAFE_LEFT:
        position.X -= toAdd;
        break;

    case irr::EKA_STRAFE_RIGHT:
        position.X += toAdd;
        break;
    default:
        return;
    }
    _displayInfo.setPosition(position);
}

void PlayerController::setPosition(irr::core::vector3df pos)
{
    _pos = pos;
}

irr::core::vector3df PlayerController::getPosition()
{
    return(_pos);
}
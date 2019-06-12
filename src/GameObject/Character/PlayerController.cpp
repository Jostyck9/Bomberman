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

PlayerController::PlayerController(GraphicalElements &displayInfos, GameObject &player) : _displayInfo(displayInfos), _player(player)
{
}

PlayerController::PlayerController(KeyMap keyMap, GraphicalElements &displayInfos, GameObject &player) : _displayInfo(displayInfos), _player(player)
{
    _keyMap = keyMap;
}

PlayerController::~PlayerController()
{
}

const KeyMap &PlayerController::getKeyMap() const
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

void PlayerController::action(irr::IrrlichtDevice *device, MyEventReceiver &events, Map &map, irr::u16 speed)
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
        createBomb(device, map);
    }
}

void PlayerController::createBomb(irr::IrrlichtDevice *device, Map &map)
{
    ACharacter &player = reinterpret_cast<ACharacter&>(_player);
    std::shared_ptr<Bomb> bomb(new Bomb(device, player, player.getStats().getBombRadius()));

    map.addToMap(2, 1, bomb);
    map.updateColision();
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
    irr::s16 offset = 1;

    switch (action)
    {
    case irr::EKA_MOVE_BACKWARD:
        position.Y -= offset * speed;
        break;
    
    case irr::EKA_MOVE_FORWARD:
        position.Y += offset * speed;
        break;
    
    case irr::EKA_STRAFE_LEFT:
        position.X -= offset * speed;
        break;

    case irr::EKA_STRAFE_RIGHT:
        position.X += offset * speed;
        break;
    default:
        return;
    }
    // std::cout << "x: " << position.X << "Y: " << position.Y << std::endl;
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
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** PlayerController.cpp
*/

#include "PlayerController.hpp"

PlayerController::PlayerController(GraphicalElements &displayInfos) : _displayInfo(displayInfos)
{
}

PlayerController::PlayerController(KeyMap keyMap, GraphicalElements &displayInfos) : _displayInfo(displayInfos)
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

void PlayerController::action(MyEventReceiver &events)
{
    //TODO action
    (void)events;
    throw "Not implemented yet";
}
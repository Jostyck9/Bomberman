/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** PlayerController.hpp
*/

#ifndef PLAYER_CONTROLLER_HPP
#define PLAYER_CONTROLLER_HPP

#include "GraphicalElements.hpp"
#include "MyEventReceiver.hpp"
#include "KeyMap.hpp"

class PlayerController
{
private:
    KeyMap _keyMap;
    GraphicalElements &_displayInfo;

    void setRotation(irr::EKEY_ACTION action);
    void move(irr::EKEY_ACTION action, irr::u16 speed);

public:
    PlayerController(GraphicalElements &displayInfos);
    PlayerController(KeyMap keyMap, GraphicalElements &displayInfos);
    ~PlayerController();

    const KeyMap &getKeyMap() const;
    void setKeyMap(KeyMap &keyMap);

    GraphicalElements &getDisplayInfo();

    void action(MyEventReceiver &events, irr::u16 speed = 1);
};

#endif // !PLAYER_CONTROLLER_HPP
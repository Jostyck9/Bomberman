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
#include "GameObject.hpp"
#include "Map.hpp"
#include "Timer.hpp"

class PlayerController
{
public:
    enum rotation_e {
        UP = -180,
        DOWN = 0,
        LEFT = -90,
        RIGHT = 90
    };

private:
    KeyMap _keyMap;
    GraphicalElements &_displayInfo;
    GameObject &_player;
    irr::core::vector3df _pos;
    Timer myTimer;

    void setRotation(irr::EKEY_ACTION action);
    void move(irr::EKEY_ACTION action, irr::u16 speed);

public:
    PlayerController(GraphicalElements &displayInfos, GameObject &player);
    PlayerController(KeyMap keyMap, GraphicalElements &displayInfos, GameObject &player);
    ~PlayerController();

    const KeyMap &getKeyMap() const;
    void setKeyMap(KeyMap &keyMap);

    GraphicalElements &getDisplayInfo();

    void action(irr::IrrlichtDevice *device, MyEventReceiver &events, Map &map, irr::u16 speed = 1);
    void setPosition(irr::core::vector3df);
    irr::core::vector3df getPosition();

    void createBomb(irr::IrrlichtDevice *device, Map &map);
};

#endif // !PLAYER_CONTROLLER_HPP
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** PlayerController.hpp
*/

#ifndef PLAYER_CONTROLLER_HPP
#define PLAYER_CONTROLLER_HPP

#include "GraphicalElements.hpp"

class PlayerController
{
private:
    irr::SKeyMap _keyMap[5];
    GraphicalElements &_displayInfo;

public:
    PlayerController(GraphicalElements &displayInfos);
    PlayerController(irr::SKeyMap *_keyMap, GraphicalElements &displayInfos);
    ~PlayerController();
};

PlayerController::PlayerController(GraphicalElements &displayInfos) : _displayInfo(displayInfos)
{
    _keyMap[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
    _keyMap[0].KeyCode = irr::KEY_KEY_Z;        // w
    _keyMap[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
    _keyMap[1].KeyCode = irr::KEY_KEY_S;        // s
    _keyMap[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
    _keyMap[2].KeyCode = irr::KEY_KEY_Q;        // a
    _keyMap[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
    _keyMap[3].KeyCode = irr::KEY_KEY_D;        // d
    _keyMap[4].Action = irr::EKA_JUMP_UP;       // saut
    _keyMap[4].KeyCode = irr::KEY_SPACE;        // barre espace
}

PlayerController::PlayerController(irr::SKeyMap *keyMap, GraphicalElements &displayInfos) : _displayInfo(displayInfos)
{
    memcpy(_keyMap, keyMap, 5);
}

PlayerController::~PlayerController()
{
}


#endif // !PLAYER_CONTROLLER_HPP
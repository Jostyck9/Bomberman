/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** KeyMap.cpp
*/

#include "KeyMap.hpp"

KeyMap::KeyMap(irr::EKEY_CODE forward, irr::EKEY_CODE backward, irr::EKEY_CODE left, irr::EKEY_CODE right, irr::EKEY_CODE action, irr::EKEY_CODE pause) : _forward(forward), _backward(backward), _left(left), _right(right), _action(action), _pause(pause)
{
}

KeyMap::~KeyMap()
{
}

irr::EKEY_CODE KeyMap::getForward() const
{
    return (_forward);
}

void KeyMap::setForward(irr::EKEY_CODE forward)
{
    _forward = forward;
}

irr::EKEY_CODE KeyMap::getBackward() const
{
    return (_backward);
}

void KeyMap::setBackward(irr::EKEY_CODE backward)
{
    _backward = backward;
}

irr::EKEY_CODE KeyMap::getLeft() const
{
    return (_left);
}

void KeyMap::setLeft(irr::EKEY_CODE left)
{
    _left = left;
}

irr::EKEY_CODE KeyMap::getRight() const
{
    return (_right);
}

void KeyMap::setRight(irr::EKEY_CODE right)
{
    _right = right;
}

irr::EKEY_CODE KeyMap::getAction() const
{
    return (_action);
}

void KeyMap::setAction(irr::EKEY_CODE action)
{
    _action = action;
}

irr::EKEY_CODE KeyMap::getPause() const
{
    return (_pause);
}

void KeyMap::setPause(irr::EKEY_CODE pause)
{
    _pause = pause;
}
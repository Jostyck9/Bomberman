/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BotIA.cpp
*/

#include "BotIA.hpp"
#include "Wall.hpp"

BotIA::BotIA(Map &map, ACharacter &character) : _map(map), _character(character)
{
}

BotIA::~BotIA()
{
}

void BotIA::getAction(MyEventReceiver &event)
{
    if (escapeBomb(event, checkBomb()))
        return;
    if (breakWall(event))
        return;
    irr::u16 move = std::rand() / 4;
    if (move == 0)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
        if (move == 1)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
    if (move == 2)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
    if (move == 3)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
}

bool BotIA::breakWall(MyEventReceiver &event)
{
    irr::core::vector2df pos = _map.getPosition(_character.getID());

    if (pos.X - 1 >= 1 && (_map.getMap()[pos.X - 1][pos.Y].empty() || _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X - 1, pos.Y)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
            event.setKeyPressed(EKEY_CODE::KEY_SPACE);
            return true;
        }
    if  (pos.X + 1 < _map.getSize() && (_map.getMap()[pos.X + 1][pos.Y].empty() || _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X + 1, pos.Y)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
            event.setKeyPressed(EKEY_CODE::KEY_SPACE);
            return true;
        }
    if  (pos.Y - 1 >= 0 && (_map.getMap()[pos.X][pos.Y - 1].empty() || _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X, pos.Y - 1)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
            event.setKeyPressed(EKEY_CODE::KEY_SPACE);
            return true;
        }
    if  (pos.Y + 1 < _map.getSize() && (_map.getMap()[pos.X][pos.Y + 1].empty() || _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X, pos.Y + 1)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
            event.setKeyPressed(EKEY_CODE::KEY_SPACE);
            return true;
        }
    return false;
}

bool BotIA::checkWallAround(irr::u16 x, irr::u16 y)
{
    if  (y - 1 >= 0 && !_map.getMap()[x][y - 1].empty() && _map.getMap()[x][y - 1].at(0)->getType() == GameObject::objecType_t::WALL) {
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[x][y - 1].at(0))->isBreakable())
            return true;
    }
    if  (y + 1 >= 0 && !_map.getMap()[x][y + 1].empty() && _map.getMap()[x][y + 1].at(0)->getType() == GameObject::objecType_t::WALL) {
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[x][y + 1].at(0))->isBreakable())
            return true;
    }
    if  (x - 1 >= 0 && !_map.getMap()[x - 1][y].empty() && _map.getMap()[x - 1][y].at(0)->getType() == GameObject::objecType_t::WALL) {
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[x - 1][y].at(0))->isBreakable())
            return true;
    }
    if  (x + 1 >= 0 && !_map.getMap()[x + 1][y].empty() && _map.getMap()[x + 1][y].at(0)->getType() == GameObject::objecType_t::WALL) {
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[x + 1][y].at(0))->isBreakable())
            return true;
    }
    return false;
}

bool BotIA::escapeBomb(MyEventReceiver &event, BotIA::direction_t direction)
{
    irr::core::vector2df pos = _map.getPosition(_character.getID());

    if (direction == UNKNOWN)
        return false;
    if (direction == left) {
        if  (pos.Y - 1 >= 0 && (_map.getMap()[pos.X][pos.Y - 1].empty() || _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
        if  (pos.Y + 1 < _map.getSize() && (_map.getMap()[pos.X][pos.Y + 1].empty() || _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
        else
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
    }
    if (direction == right) {
        if  (pos.Y - 1 >= 0 && (_map.getMap()[pos.X][pos.Y - 1].empty() || _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
        if  (pos.Y + 1 < _map.getSize() && (_map.getMap()[pos.X][pos.Y + 1].empty() || _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
        else
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
    }
    if (direction == up) {
        if  (pos.X - 1 >= 0 && (_map.getMap()[pos.X - 1][pos.Y].empty() || _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
        if  (pos.X + 1 < _map.getSize() && (_map.getMap()[pos.X + 1][pos.Y].empty() || _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
        else
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
    }
    if (direction == down) {
        if  (pos.X - 1 >= 0 && (_map.getMap()[pos.X - 1][pos.Y].empty() || _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
        if  (pos.X + 1 < _map.getSize() && (_map.getMap()[pos.X + 1][pos.Y].empty() || _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
        else
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
    }
    return true;
}

BotIA::direction_t BotIA::checkBomb()
{
    irr::core::vector2df pos = _map.getPosition(_character.getID());
    for (irr::u16 i = 0; i < 3; i++) {
        if (pos.X - i >= 0 && _map.getMap()[pos.X - i][pos.Y].size() > 0 && _map.getMap()[pos.X - i][pos.Y].at(0)->getType() == GameObject::objecType_t::BOMB)
                return left;
        if (pos.X + i < _map.getSize() && _map.getMap()[pos.X + i][pos.Y].size() > 0 && _map.getMap()[pos.X + i][pos.Y].at(0)->getType() == GameObject::objecType_t::BOMB)
                return right;
        if (pos.Y - i >= 0 && _map.getMap()[pos.X][pos.Y - i].size() > 0 && _map.getMap()[pos.X][pos.Y - i].at(0)->getType() == GameObject::objecType_t::BOMB)
                return up;
        if (pos.Y + i < _map.getSize() && _map.getMap()[pos.X][pos.Y + i].size() > 0 && _map.getMap()[pos.X][pos.Y + i].at(0)->getType() == GameObject::objecType_t::BOMB)
                return down;
    }
    return UNKNOWN;
}
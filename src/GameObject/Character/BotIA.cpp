/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BotIA.cpp
*/

#include <iostream>

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
    if (escapeBomb(event, checkBomb())) {
        //std::cout << "ESCAPE BOMB" << std::endl;
        return;
    }
    if (findBestWay(event)) {
        //std::cout << "FIND BEST WAY" << std::endl;
        return;
    }
    if (breakWall(event)) {
        //std::cout << "BREAK WALL" << std::endl;
        return;
    }

    irr::core::vector2df pos = _map.getPosition(_character.getID());

    if (pos.X - 1 >= 1 && (_map.getMap()[pos.X - 1][pos.Y].empty() || _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
        event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
    else if (pos.X + 1 >= 1 && (_map.getMap()[pos.X + 1][pos.Y].empty() || _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
        event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
    else if  (pos.Y - 1 >= 0 && (_map.getMap()[pos.X][pos.Y - 1].empty() || _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() != GameObject::objecType_t::WALL))
        event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
    else if  (pos.Y + 1 >= 0 && (_map.getMap()[pos.X][pos.Y + 1].empty() || _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() != GameObject::objecType_t::WALL))
        event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
//    std::cout << "RANDOM MOVE" << std::endl;
}

bool BotIA::findBestWay(MyEventReceiver &event)
{
    irr::core::vector2df pos = _map.getPosition(_character.getID());

    irr::s16 up = wayValue(pos.X, pos.Y + 1, BotIA::direction_t::up, 1);
    irr::s16 down = wayValue(pos.X, pos.Y - 1, BotIA::direction_t::down, 1);
    irr::s16 right = wayValue(pos.X + 1, pos.Y, BotIA::direction_t::right, 1);
    irr::s16 left = wayValue(pos.X - 1, pos.Y, BotIA::direction_t::left, 1);


    std::cout << "up = " << up << " || down = " << down << " || left = " << left << " || right = " << right << std::endl;
    if (up < 5 && down < 5 && right < 5 && left < 5) {
 //       std::cout << "RECURSIF NICE" << std::endl;
        return false;
    }
    if (up >= left && up >= right && up >= down)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
    else if (left >= down && left >= right && left >= up)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
    else if (down >= left && down >= right && down >= up)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
    else if (right >= left && right >= down && right >= up)
        event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
    return true;
}

irr::s16 BotIA::wayValue(irr::u16 x, irr::u16 y, BotIA::direction_t dir, irr::u16 range)
{
//    std::cout << "Pos algo X = " << x << " || y = " << y << " || dir = " << dir << std::endl;
    irr::s16 up = -1;
    irr::s16 down = -1;
    irr::s16 left = -1;
    irr::s16 right = -1;

    if (x <= 0 || y >= _map.getSize() || range >= 6 || (!_map.getMap()[x][y].empty() && _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::WALL))
        return 0;
    if (!_map.getMap()[x][y].empty() && isInteresting(x, y))
        return (getPosValue(x, y) / range);
    if (dir != BotIA::direction_t::down)
        up = wayValue(x, y + 1, BotIA::direction_t::up, range + 1);
    if (dir != BotIA::direction_t::up)
        down = wayValue(x, y - 1, BotIA::direction_t::down, range + 1);
    if (dir != BotIA::direction_t::left)
        right = wayValue(x + 1, y, BotIA::direction_t::right, range + 1);
    if (dir != BotIA::direction_t::right)
        left = wayValue(x - 1, y, BotIA::direction_t::left, range + 1);

    if (up != -1 && up >= left && up >= right && up >= down)
        return up + (getPosValue(x, y) / range);
    //std::cout << "RECURSIF UP" << std::endl;
    if (left != -1 && left >= down && left >= right && left >= up)
        return left + (getPosValue(x, y) / range);
    //std::cout << "RECURSIF LEFT" << std::endl;
    if (down != -1 && down >= left && down >= right && down >= up)
        return down + (getPosValue(x, y) / range);
    //std::cout << "RECURSIF DOWN" << std::endl;
    if (right != -1 && right >= left && right >= down && right >= up)
        return right + (getPosValue(x, y) / range);
    //std::cout << "RECURSIF RIGHT" << std::endl;
    return getPosValue(x, y) / range;
}

irr::s16 BotIA::getPosValue(irr::u16 x, irr::u16 y)
{
    if (!_map.getMap()[x][y].empty() &&
        (_map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::BOMBUP ||
         _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::FIREUP ||
         _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::WALLPASS ||
         _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::SPEEDUP))
        return BotIA::objValue_t::POWERUP;
    if (!_map.getMap()[x][y].empty() &&
        (_map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::PLAYER ||
         _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::NONPLAYER))
        return BotIA::objValue_t::PLAYER;
    if (!_map.getMap()[x][y].empty() && (_map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::BOMB || _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::EXPLOSION))
        return BotIA::objValue_t::BOMB;
    return BotIA::objValue_t::OTHER;
}

bool BotIA::isInteresting(irr::u16 x, irr::u16 y)
{
    return (!_map.getMap()[x][y].empty() &&
            (_map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::BOMBUP ||
             _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::FIREUP ||
             _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::WALLPASS ||
             _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::SPEEDUP ||
             _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::PLAYER ||
             _map.getMap()[x][y].at(0)->getType() == GameObject::objecType_t::NONPLAYER));
}

bool BotIA::breakWall(MyEventReceiver &event)
{
    irr::core::vector2df pos = _map.getPosition(_character.getID());

    if (pos.X - 1 >= 1 && (_map.getMap()[pos.X - 1][pos.Y].empty() || _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X - 1, pos.Y)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
            event.setKeyReleased(EKEY_CODE::KEY_SPACE);
            return true;
        }
    if  (pos.X + 1 < _map.getSize() && (_map.getMap()[pos.X + 1][pos.Y].empty() || _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X + 1, pos.Y)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
            event.setKeyReleased(EKEY_CODE::KEY_SPACE);
            return true;
        }
    if  (pos.Y - 1 >= 0 && (_map.getMap()[pos.X][pos.Y - 1].empty() || _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X, pos.Y - 1)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
            event.setKeyReleased(EKEY_CODE::KEY_SPACE);
            return true;
        }
    if  (pos.Y + 1 < _map.getSize() && (_map.getMap()[pos.X][pos.Y + 1].empty() || _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() != GameObject::objecType_t::WALL))
        if (checkWallAround(pos.X, pos.Y + 1)) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
            event.setKeyReleased(EKEY_CODE::KEY_SPACE);
            return true;
        }
    if  (pos.Y - 1 >= 0 && !_map.getMap()[pos.X][pos.Y - 1].empty() && _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() == GameObject::objecType_t::WALL)
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[pos.X][pos.Y - 1].at(0))->isBreakable()) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
            return true;
        }
    if  (pos.Y + 1 >= 0 && !_map.getMap()[pos.X][pos.Y + 1].empty() && _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() == GameObject::objecType_t::WALL)
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[pos.X][pos.Y + 1].at(0))->isBreakable()) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
            return true;
        }
    if  (pos.X - 1 >= 0 && !_map.getMap()[pos.X - 1][pos.Y].empty() && _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() == GameObject::objecType_t::WALL)
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[pos.X - 1][pos.Y].at(0))->isBreakable()) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
            return true;
        }
    if  (pos.X + 1 >= 0 && !_map.getMap()[pos.X + 1][pos.Y].empty() && _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() == GameObject::objecType_t::WALL)
        if (std::dynamic_pointer_cast<Wall>(_map.getMap()[pos.X + 1][pos.Y].at(0))->isBreakable()) {
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
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

    // std::cout << "X = " << pos.X << " || Y = " << pos.Y << std::endl;
    if (direction == UNKNOWN)
        return false;
    if (direction == left) {
        if  (pos.Y - 1 >= 0 && (_map.getMap()[pos.X][pos.Y - 1].empty() || _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
        else if  (pos.Y + 1 < _map.getSize() && (_map.getMap()[pos.X][pos.Y + 1].empty() || _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
        else
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
    }
    if (direction == right) {
        if  (pos.Y - 1 >= 0 && (_map.getMap()[pos.X][pos.Y - 1].empty() || _map.getMap()[pos.X][pos.Y - 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_S);
        else if  (pos.Y + 1 < _map.getSize() && (_map.getMap()[pos.X][pos.Y + 1].empty() || _map.getMap()[pos.X][pos.Y + 1].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
        else
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
    }
    if (direction == up) {
        if  (pos.X - 1 >= 0 && (_map.getMap()[pos.X - 1][pos.Y].empty() || _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
        else if  (pos.X + 1 < _map.getSize() && (_map.getMap()[pos.X + 1][pos.Y].empty() || _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_D);
        else
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Z);
    }
    if (direction == down) {
        if  (pos.X - 1 >= 0 && (_map.getMap()[pos.X - 1][pos.Y].empty() || _map.getMap()[pos.X - 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
            event.setKeyPressed(EKEY_CODE::KEY_KEY_Q);
        else if  (pos.X + 1 < _map.getSize() && (_map.getMap()[pos.X + 1][pos.Y].empty() || _map.getMap()[pos.X + 1][pos.Y].at(0)->getType() != GameObject::objecType_t::WALL))
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
        if (pos.X - i >= 0 && _map.getMap()[pos.X - i][pos.Y].size() > 0 && (_map.getMap()[pos.X - i][pos.Y].at(0)->getType() == GameObject::objecType_t::BOMB || _map.getMap()[pos.X - i][pos.Y].at(0)->getType() == GameObject::objecType_t::EXPLOSION))
                return left;
        if (pos.X + i < _map.getSize() && _map.getMap()[pos.X + i][pos.Y].size() > 0 && (_map.getMap()[pos.X + i][pos.Y].at(0)->getType() == GameObject::objecType_t::BOMB || _map.getMap()[pos.X + i][pos.Y].at(0)->getType() == GameObject::objecType_t::EXPLOSION))
                return right;
        if (pos.Y - i >= 0 && _map.getMap()[pos.X][pos.Y - i].size() > 0 && (_map.getMap()[pos.X][pos.Y - i].at(0)->getType() == GameObject::objecType_t::BOMB || _map.getMap()[pos.X][pos.Y - i].at(0)->getType() == GameObject::objecType_t::EXPLOSION))
                return up;
        if (pos.Y + i < _map.getSize() && _map.getMap()[pos.X][pos.Y + i].size() > 0 && (_map.getMap()[pos.X][pos.Y + i].at(0)->getType() == GameObject::objecType_t::BOMB || _map.getMap()[pos.X][pos.Y + i].at(0)->getType() == GameObject::objecType_t::EXPLOSION))
                return down;
    }
    return UNKNOWN;
}
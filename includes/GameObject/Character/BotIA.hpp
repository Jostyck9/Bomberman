/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** BotIA.hpp
*/

#ifndef BOTIA_HPP_
#define BOTIA_HPP_

#include "ACharacter.hpp"
#include "Map.hpp"
#include "Timer.hpp"

class BotIA
{
public:
    enum direction_s {
        up,
        down,
        left,
        right,
        UNKNOWN
    };
    typedef direction_s direction_t;

    enum objValue_s {
        BOMB = -100,
        POWERUP = 50,
        PLAYER = 100,
        OTHER = 0
    };
    typedef objValue_s objValue_t;

    BotIA(Map &map, ACharacter &character);
    void getAction(MyEventReceiver &event);
    direction_t checkBomb();
    bool checkWallAround(irr::u16 x, irr::u16 y);
    bool escapeBomb(MyEventReceiver &event, direction_t direction);
    bool breakWall(MyEventReceiver &event);
    bool findBestWay(MyEventReceiver &event);
    irr::s16 wayValue(irr::u16 x, irr::u16 y, direction_t dir, irr::u16 range);
    bool isInteresting(irr::u16 x, irr::u16 y);
    irr::s16 getPosValue(irr::u16 x, irr::u16 y);
    ~BotIA();

private:
    Timer _clock;
    Map &_map;
    ACharacter &_character;
};

#endif // !BOTIA_HPP
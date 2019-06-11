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

    BotIA(Map &map, std::shared_ptr<ACharacter> character);
    void getAction(MyEventReceiver &event);
    direction_t checkBomb();
    bool checkWallAround(irr::u16 x, irr::u16 y);
    bool escapeBomb(MyEventReceiver &event, direction_t direction);
    bool breakWall(MyEventReceiver &event);
    ~BotIA();

private:
    Map &_map;
    std::shared_ptr<ACharacter> _character;
};

#endif // !BOTIA_HPP
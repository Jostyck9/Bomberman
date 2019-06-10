/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** BotIA.hpp
*/

#ifndef BOTIA_HPP_
#define BOTIA_HPP_

#include "GameObject.hpp"
#include "Map.hpp"

class BotIA
{
private:
    Map &_map;
    GameObject &_obj;

public:
    BotIA(Map &map, GameObject &obj);
    ~BotIA();
};

BotIA::BotIA(Map &map, GameObject &obj) : _map(map), _obj(obj)
{
}

BotIA::~BotIA()
{
}


#endif // !BOTIA_HPP
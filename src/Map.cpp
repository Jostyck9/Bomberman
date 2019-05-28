/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Map.cpp
*/

#include "Map.hpp"

Map::Map(irr::u16 width, irr::u16 heigh) : _map(boost::extents[width][heigh]), _width(width), _heigh(heigh)
{
}

Map::~Map()
{
}

void Map::addToMap(irr::u16 x, irr::u16 y, GameObject *obj)
{
    if (x >= _width || y >= _heigh || obj == nullptr)
        return;
    _map[x][y].push_back(obj);
}
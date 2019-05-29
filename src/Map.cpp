/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Map.cpp
*/

#include "Map.hpp"
#include "Wall.hpp"

Map::Map(irr::u16 width, irr::u16 heigh) : _map(boost::extents[width][heigh]), _width(width), _heigh(heigh)
{
}

Map::~Map()
{
}

void Map::setMap(std::vector<std::string> map)
{
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map.size(); j++) {
            if (map.at(i).at(j) == 'X') {
                Wall newWall(false);
                addToMap(i, j, dynamic_cast<GameObject*>(&newWall));
            }
            if (map.at(i).at(j) == 'o') {
                Wall newWall(true);
                addToMap(i, j, dynamic_cast<GameObject*>(&newWall));
            }
        }
    }
}

void Map::addToMap(irr::u16 x, irr::u16 y, GameObject *obj)
{
    if (x >= _width || y >= _heigh || obj == nullptr)
        return;
    _map[x][y].push_back(obj);
}
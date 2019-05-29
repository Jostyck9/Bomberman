/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Map.cpp
*/

#include "Map.hpp"
#include "Wall.hpp"

Map::Map(irr::u16 size) : _map(boost::extents[size][size]), _width(size), _heigh(size)
{
    genMap(size);
    setMap();
}

Map::~Map()
{
}

void Map::genMap(irr::u16 size)
{
    std::string str;

    if (size % 2 == 0)
        size++;
    for (int i = 0; i < size; i++)
        str += '_';
    for (int i = 0; i < size; i++)
        _mapGen.push_back(str);
/*    for (int i = 0; i < (size * size) / 4 * 3; i++)
        _mapGen.at(std::rand() % size).at(std::rand() % size) = 'X';
    for (int i = 0; i < (size * size) / 3 * 2; i++)
        _mapGen.at(std::rand() % size).at(std::rand() % size) = 'O';
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (_mapGen.at(i).at(j) != 'X' && _mapGen.at(i + 1).at(j) != 'X' &&
                _mapGen.at(i).at(j + 1) != 'X' && _mapGen.at(i + 1).at(j + 1) != 'X')
                _mapGen.at(i + rand() % 2).at(j + rand() % 2) = 'X';
        }
    }*/
    for (irr::u16 i = 0; i < (size * size) - size; i++)
        _mapGen.at(std::rand() % size).at(std::rand() % size) = 'O';
    for (irr::u16 i = 1; i < size; i = i + 2) {
        for (irr::u16 j = 1; j < size; j = j + 2) {
            _mapGen.at(i).at(j) = 'X';
        }
    }
    _mapGen.at(0).at(0) = '_';
    _mapGen.at(1).at(0) = '_';
    _mapGen.at(0).at(1) = '_';
    _mapGen.at(1).at(1) = 'X';
    _mapGen.at(size - 1).at(0) = '_';
    _mapGen.at(size - 1).at(1) = '_';
    _mapGen.at(size - 2).at(0) = '_';
    _mapGen.at(size - 2).at(1) = 'X';
    _mapGen.at(0).at(size - 1) = '_';
    _mapGen.at(1).at(size - 1) = '_';
    _mapGen.at(0).at(size - 2) = '_';
    _mapGen.at(1).at(size - 2) = 'X';
    _mapGen.at(size - 1).at(size - 1) = '_';
    _mapGen.at(size - 2).at(size - 1) = '_';
    _mapGen.at(size - 1).at(size - 2) = '_';
    _mapGen.at(size - 2).at(size - 2) = 'X';
}

void Map::setMap()
{
    for (irr::u16 i = 0; i < _mapGen.size(); i++) {
        for (irr::u16 j = 0; j < _mapGen.size(); j++) {
            if (_mapGen.at(i).at(j) == 'X') {
                Wall *newWall = new Wall(false, i, j);
                addToMap(i, j, newWall);
            }
            if (_mapGen.at(i).at(j) == 'o') {
                Wall *newWall = new Wall(true, i, j);
                addToMap(i, j, newWall);
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
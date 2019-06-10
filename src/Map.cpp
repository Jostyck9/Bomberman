/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Map.cpp
*/

#include <time.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <experimental/filesystem>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>

#include "Bomb.hpp"
#include "ACharacter.hpp"
#include "Map.hpp"
#include "SpeedUp.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include "WallPass.hpp"
#include "Wall.hpp"
#include "Player.hpp"

Map::Map(irr::IrrlichtDevice *device, irr::u16 size) : _device(device), _map(boost::extents[size][size]), _size(size)
{
    srand(time(NULL));
    genMap(_size);
    setMap();
}

Map::Map(irr::IrrlichtDevice *device, const std::string &save, irr::u16 size) : _device(device), _map(boost::extents[size][size]), _size(size)
{
    load(save);
}

Map::~Map()
{
}

void Map::genMap(irr::u16 size)
{
    std::string str;

    for (int i = 0; i < size; i++)
        str += '_';
    for (int i = 0; i < size; i++)
        _mapGen.push_back(str);
    for (irr::u16 i = 0; i < size * size / 4; i++) {
        irr::u16 x = std::rand() % (size / 2);
        irr::u16 y = std::rand() % (size / 2);
        _mapGen.at(x).at(y) = 'O';
        _mapGen.at(size - x - 1).at(y) = 'O';
        _mapGen.at(x).at(size - y - 1) = 'O';
        _mapGen.at(size - x - 1).at(size - y - 1) = 'O';
    }
    for (irr::u16 i = 2; i < size; i = i + 2) {
        for (irr::u16 j = 2; j < size; j = j + 2) {
            _mapGen.at(i).at(j) = 'X';
        }
    }
    for (irr::u16 i = 0; i < size; i++) {
        for (irr::u16 j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
                _mapGen.at(i).at(j) = 'X';
        }
    }
    _mapGen.at(1).at(1) = '_';
    _mapGen.at(2).at(1) = '_';
    _mapGen.at(1).at(2) = '_';
    _mapGen.at(2).at(2) = 'X';
    _mapGen.at(size - 2).at(1) = '_';
    _mapGen.at(size - 2).at(2) = '_';
    _mapGen.at(size - 3).at(1) = '_';
    _mapGen.at(size - 3).at(2) = 'X';
    _mapGen.at(1).at(size - 2) = '_';
    _mapGen.at(2).at(size - 2) = '_';
    _mapGen.at(1).at(size - 3) = '_';
    _mapGen.at(2).at(size - 3) = 'X';
    _mapGen.at(size - 2).at(size - 2) = '_';
    _mapGen.at(size - 3).at(size - 2) = '_';
    _mapGen.at(size - 2).at(size - 3) = '_';
    _mapGen.at(size - 3).at(size - 3) = 'X';
}

void Map::setMap()
{
    for (irr::u16 i = 0; i < _mapGen.size(); i++) {
        for (irr::u16 j = 0; j < _mapGen.size(); j++) {
            if (_mapGen.at(i).at(j) == 'X') {
                Wall *newWall = new Wall(_device->getSceneManager(), _device->getVideoDriver(), "./assets/textures/bricks.jpg", i, j, false);
                addToMap(i, j, newWall);
            }
            if (_mapGen.at(i).at(j) == 'O') {
                Wall *newWall = new Wall(_device->getSceneManager(), _device->getVideoDriver(), "./assets/textures/Brick_Block.png", i, j, true);
                addToMap(i, j, newWall);
            }
        }
    }
}

void Map::addToMap(irr::u16 x, irr::u16 y, GameObject *obj)
{
    if (x >= _size || y >= _size || obj == nullptr)
        return;
    _map[x][y].push_back(obj);
}

boost::multi_array<std::vector<GameObject*>, 2> &Map::getMap()
{
    return (_map);
}

irr::u16 Map::getSize() const
{
    return _size;
}

void Map::setDevice(irr::IrrlichtDevice *device)
{
    _device = device;
}

void Map::setSize(irr::u16 size)
{
    _size = size;
}

bool Map::save()
{
    std::ofstream file("save.txt", std::ios::out | std::ofstream::trunc);

    file << "<map>" << std::endl;
    for (irr::u16 i = 0; i < _size; i++) {
        for (irr::u16 j = 0; j < _size; j++) {
            file << "\t<cell>" << std::endl;
            file << "\t\t<x>" << i << "</x>" << std::endl;
            file << "\t\t<y>" << j << "</y>" << std::endl;
            for (irr::u16 k = 0; k < _map[i][j].size(); k++) {
                if (_map[i][j].at(k)->getType() == GameObject::WALL)
                    file << "\t\t<wall>" << dynamic_cast<Wall *>(_map[i][j].at(k))->isBreakable() << "</wall>" << std::endl;
                if (_map[i][j].at(k)->getType() == GameObject::SPEEDUP)
                    file << "\t\t<speedup>" << "</speedup>" << std::endl;
                if (_map[i][j].at(k)->getType() == GameObject::BOMBUP)
                    file << "\t\t<bombup>" << "</bombup>" << std::endl;
                if (_map[i][j].at(k)->getType() == GameObject::FIREUP)
                    file << "\t\t<fireup>" << "</fireup>" << std::endl;
                if (_map[i][j].at(k)->getType() == GameObject::WALLPASS)
                    file << "\t\t<wallpass>" << "</wallpass>" << std::endl;
                if (_map[i][j].at(k)->getType() == GameObject::PLAYER) {
                    file << "\t\t<player>" << std::endl;
                    file << "\t\t\t<nbrbomb>" << dynamic_cast<ACharacter *>(_map[i][j].at(k))->getStats().getNbrBomb() << "</nbrbomb>" <<std::endl;
                    file << "\t\t\t<bombradius>" << dynamic_cast<ACharacter *>(_map[i][j].at(k))->getStats().getBombRadius() << "</bombradius>" <<std::endl;
                    file << "\t\t\t<passthrough>" << dynamic_cast<ACharacter *>(_map[i][j].at(k))->getStats().getPassThrough() << "</passthrough>" <<std::endl;
                    file << "\t\t\t<speed>" << dynamic_cast<ACharacter *>(_map[i][j].at(k))->getStats().getSpeed() << "</speed>" <<std::endl;
                    file << "\t\t</player>" << std::endl;
                }
            }
            file << "\t</cell>" << std::endl;
        }
    }
    file << "</map>" << std::endl;
    return true;
}

bool Map::load(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        return false;
    using boost::property_tree::ptree;
    ptree pt;
    read_xml(file, pt);
    irr::u16 i;
    irr::u16 j;

    BOOST_FOREACH(ptree::value_type const& v, pt.get_child("map")) {
        if (v.first == "cell") {
            i = v.second.get<irr::u16>("x");
            j = v.second.get<irr::u16>("y");
            BOOST_FOREACH(ptree::value_type const& cell, v.second.get_child( "" )) {
                if (cell.first == "wall") {
                    if (!v.second.get<bool>("wall")) {
                        Wall *newWall = new Wall(_device->getSceneManager(), _device->getVideoDriver(), "./assets/textures/bricks.jpg", i, j, false);
                        addToMap(i, j, newWall);
                    }
                    else {
                        Wall *newWall = new Wall(_device->getSceneManager(), _device->getVideoDriver(), "./assets/textures/Brick_Block.png", i, j, true);
                        addToMap(i, j, newWall);
                    }
                }
                if (cell.first == "speedup") {
                    SpeedUp *newSpeedUp = new SpeedUp;
                    addToMap(i, j, newSpeedUp);
                }
                if (cell.first == "fireup") {
                    FireUp *newFireUp = new FireUp;
                    addToMap(i, j, newFireUp);
                }
                if (cell.first == "bombup") {
                    BombUp *newBombUp = new BombUp;
                    addToMap(i, j, newBombUp);
                }
                if (cell.first == "wallpass") {
                    WallPass *newSpeedUp = new WallPass;
                    addToMap(i, j, newSpeedUp);
                }
                if (cell.first == "Player") {
                    std::vector<std::string> textures;
                    std::string path = "./assets/meshs/Bomb/ItmBombhei.obj";
                    Player *player = new Player(_device, textures, path, i, j);
                    player->getStats().setPassThrough(cell.second.get<bool>("passthrough"));
                    player->getStats().setNbrBomb(cell.second.get<irr::u16>("nbrbomb"));
                    player->getStats().setBombRadius(cell.second.get<irr::u16>("bombradius"));
                    player->getStats().setSpeed(cell.second.get<irr::u16>("speed"));
                    addToMap(i, j, player);
                }
            }
        }
    }
    return true;
}
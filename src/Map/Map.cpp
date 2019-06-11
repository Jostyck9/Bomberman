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

#include "BomberException.hpp"
#include "Bomb.hpp"
#include "ACharacter.hpp"
#include "Map.hpp"
#include "SpeedUp.hpp"
#include "BombUp.hpp"
#include "FireUp.hpp"
#include "WallPass.hpp"
#include "Wall.hpp"
#include "Player.hpp"
#include "NonPlayer.hpp"

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
    std::vector<std::string> brkwall;
    std::vector<std::string> wall;

    brkwall.push_back("./assets/meshs/Brick_block/brick.png");
    wall.push_back("./assets/meshs/Strong_block/block.png");
    for (irr::u16 i = 0; i < _mapGen.size(); i++) {
        for (irr::u16 j = 0; j < _mapGen.size(); j++) {
            if (_mapGen.at(i).at(j) == 'X') {
                std::shared_ptr<GameObject> newWall(new Wall(_device, "./assets/meshs/Strong_block/Strong_Block.b3d", wall, i, j, false));
                addToMap(i, j, newWall);
            }
            if (_mapGen.at(i).at(j) == 'O') {
                std::shared_ptr<GameObject> newWall(new Wall(_device, "./assets/meshs/Brick_block/Brick_Block.b3d", brkwall, i, j, true));
                addToMap(i, j, newWall);
            }
        }
    }
}

void Map::addToMap(irr::u16 x, irr::u16 y, std::shared_ptr<GameObject> obj)
{
    if (x >= _size || y >= _size || obj == nullptr) {
        throw bomberException("Invalid parameter for adding on the map", "Map");
    }
    _map[x][y].push_back(obj);
}

void Map::delToMap(irr::u16 x, irr::u16 y, std::shared_ptr<GameObject> obj)
{
    int i = 0;

    if (x >= _size || y >= _size || obj == nullptr)
        return;
    for (auto &it : _map[x][y]) {
        if (it->getID() == obj->getID()) {
            _map[x][y].erase(_map[x][y].begin() + i);
            return;
        }
        i++;
    }
}

void Map::delToMap(irr::s32 id)
{
    for (irr::u16 x = 0; x < _map.size(); x++) {
        for (irr::u16 y = 0; y < _map.size(); y++) {
            for (irr::u16 i = 0; i < _map[x][y].size(); i++) {
                if (id == _map[x][y].at(i)->getID()) {
                    _map[x][y].erase(_map[x][y].begin() + i);
                    return;
                }
            }
        }
    } 
}

void Map::delToMap(std::shared_ptr<GameObject> obj)
{
    if (obj == nullptr)
        return;
    for (irr::u16 x = 0; x < _map.size(); x++) {
        for (irr::u16 y = 0; y < _map.size(); y++) {
            for (irr::u16 i = 0; i < _map[x][y].size(); i++) {
                if (obj->getID() == _map[x][y].at(i)->getID()) {
                    _map[x][y].erase(_map[x][y].begin() + i);
                    return;
                }
            }
        }
    } 
}

boost::multi_array<std::vector<std::shared_ptr<GameObject>>, 2> &Map::getMap()
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
                    file << "\t\t<wall>" <<  std::dynamic_pointer_cast<Wall>(_map[i][j].at(k))->isBreakable() << "</wall>" << std::endl;
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
                    file << "\t\t\t<nbrbomb>" << std::dynamic_pointer_cast<ACharacter>(_map[i][j].at(k))->getStats().getNbrBomb() << "</nbrbomb>" <<std::endl;
                    file << "\t\t\t<bombradius>" << std::dynamic_pointer_cast<ACharacter >(_map[i][j].at(k))->getStats().getBombRadius() << "</bombradius>" <<std::endl;
                    file << "\t\t\t<passthrough>" << std::dynamic_pointer_cast<ACharacter>(_map[i][j].at(k))->getStats().getPassThrough() << "</passthrough>" <<std::endl;
                    file << "\t\t\t<speed>" << std::dynamic_pointer_cast<ACharacter>(_map[i][j].at(k))->getStats().getSpeed() << "</speed>" <<std::endl;
                    file << "\t\t</player>" << std::endl;
                }
                if (_map[i][j].at(k)->getType() == GameObject::NONPLAYER) {
                    file << "\t\t<nonplayer>" << std::endl;
                    file << "\t\t\t<nbrbomb>" << std::dynamic_pointer_cast<ACharacter>(_map[i][j].at(k))->getStats().getNbrBomb() << "</nbrbomb>" <<std::endl;
                    file << "\t\t\t<bombradius>" << std::dynamic_pointer_cast<ACharacter >(_map[i][j].at(k))->getStats().getBombRadius() << "</bombradius>" <<std::endl;
                    file << "\t\t\t<passthrough>" << std::dynamic_pointer_cast<ACharacter>(_map[i][j].at(k))->getStats().getPassThrough() << "</passthrough>" <<std::endl;
                    file << "\t\t\t<speed>" << std::dynamic_pointer_cast<ACharacter>(_map[i][j].at(k))->getStats().getSpeed() << "</speed>" <<std::endl;
                    file << "\t\t</nonplayer>" << std::endl;
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
    std::vector<std::string> brkwall;
    std::vector<std::string> wall;

    brkwall.push_back("./assets/meshs/Brick_block/brick.png");
    wall.push_back("./assets/meshs/Strong_block/block.png");
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
                        std::shared_ptr<Wall> newWall(new Wall(_device, "./assets/meshs/Strong_block/Strong_Block.b3d", wall, i, j, false));
                        addToMap(i, j, newWall);
                    }
                    else {
                        std::shared_ptr<Wall> newWall(new Wall(_device, "./assets/meshs/Brick_block/Brick_Block.b3d", brkwall, i, j, true));
                        addToMap(i, j, newWall);
                    }
                }
                if (cell.first == "speedup") {
                    std::shared_ptr<SpeedUp> newSpeedUp(new SpeedUp(_device, i * 10, j * 10));
                    addToMap(i, j, newSpeedUp);
                }
                if (cell.first == "fireup") {
                    std::shared_ptr<FireUp> newFireUp(new FireUp(_device, i * 10, j * 10));
                    addToMap(i, j, newFireUp);
                }
                if (cell.first == "bombup") {
                    std::shared_ptr<BombUp> newBombUp(new BombUp(_device, i * 10, j * 10));
                    addToMap(i, j, newBombUp);
                }
                if (cell.first == "wallpass") {
                    std::shared_ptr<WallPass> newWallPass(new WallPass(_device, i * 10, j * 10));
                    addToMap(i, j, newWallPass);
                }
                if (cell.first == "player") {
                    std::vector<std::string> textures;
                    std::string path = "./assets/meshs/Bomb/ItmBombhei.obj";
                    std::shared_ptr<Player> player(new Player(_device, textures, path, i, j));
                    player->getStats().setPassThrough(cell.second.get<bool>("passthrough"));
                    player->getStats().setNbrBomb(cell.second.get<irr::u16>("nbrbomb"));
                    player->getStats().setBombRadius(cell.second.get<irr::u16>("bombradius"));
                    player->getStats().setSpeed(cell.second.get<irr::u16>("speed"));
                    addToMap(i, j, player);
                }
                if (cell.first == "nonplayer") {
                    std::vector<std::string> textures;
                    std::string path = "./assets/meshs/Bomb/ItmBombhei.obj";
                    std::shared_ptr<NonPlayer> player(new NonPlayer(_device, *this, textures, path, i, j));
                    player->getStats().setPassThrough(cell.second.get<bool>("passthrough"));
                    player->getStats().setNbrBomb(cell.second.get<irr::u16>("nbrbomb"));
                    player->getStats().setBombRadius(cell.second.get<irr::u16>("bombradius"));
                    player->getStats().setSpeed(cell.second.get<irr::u16>("speed"));
                    addToMap(i, j, player);
                }
            }
        }
    }
    return (true);
}

void Map::updateColision()
{
    irr::scene::ISceneManager* smgr = _device->getSceneManager();
    std::shared_ptr<PrintableObject> current(nullptr);

    if (!smgr)
        return;
    for (irr::u16 x = 0; x < getSize(); x++) {
        for (irr::u16 y = 0; y < getSize(); y++) {
            for (auto it : _map[x][y]) {
                if (it->getType() == GameObject::PLAYER) {
                    current = std::dynamic_pointer_cast<PrintableObject>(it);
                    if (current)
                        current->updateColision();
                }
            }
        }
    }
}

std::shared_ptr<GameObject> Map::getObject(irr::scene::ISceneNode *node)
{
    if (!node)
        return (nullptr);
    for (irr::u16 x = 0; x < getSize(); x++) {
        for (irr::u16 y = 0; y < getSize(); y++) {
            for (auto it : _map[x][y]) {
                if (std::dynamic_pointer_cast<PrintableObject>(it)->getDisplayInfo().getNode() == node) {
                    return (it);
                }
            }
        }
    }
    return (nullptr);
}

std::shared_ptr<GameObject> Map::getObject(irr::s32 id)
{
    for (irr::u16 x = 0; x < getSize(); x++) {
        for (irr::u16 y = 0; y < getSize(); y++) {
            for (auto it : _map[x][y]) {
                if (it->getID() == id) {
                    return (it);
                }
            }
        }
    }
    return (std::shared_ptr<GameObject>(nullptr));
}

irr::core::vector2df Map::getPosition(std::shared_ptr<GameObject> obj)
{
    irr::core::vector2df pos;

    for (irr::u16 x = 0; x < _size; x++) {
        for (irr::u16 y = 0; y < _size; y++) {
            for (auto &it : _map[x][y]) {
                if (obj == it) {
                    pos.X = x;
                    pos.Y = y;
                    return (pos);
                }
            }
        }
    }
    return (pos);
}

irr::core::vector2df Map::getPosition(irr::s32 id)
{
    irr::core::vector2df pos;

    for (irr::u16 x = 0; x < _size; x++) {
        for (irr::u16 y = 0; y < _size; y++) {
            for (auto &it : _map[x][y]) {
                if (id == it->getID()) {
                    pos.X = x;
                    pos.Y = y;
                    return (pos);
                }
            }
        }
    }
    return (pos);
}

const std::vector<std::shared_ptr<GameObject>> &Map::getCellObject(irr::u16 x, irr::u16 y) const
{
    if (x >= _size || y >= _size)
        throw bomberException("Invalid position", "Map");
    return (_map[x][y]);
}
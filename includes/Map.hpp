/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Map.hpp
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#ifdef _WIN64
    #include <irrlicht.h>
#else
    #include <irrlicht/irrlicht.h>
#endif

#include <boost/multi_array.hpp>
#include "GameObject.hpp"

class Map
{
private:
    irr::IrrlichtDevice *_device;
    boost::multi_array<std::vector<GameObject*>, 2> _map;
    std::vector<std::string> _mapGen;
    irr::u16 _size;

public:
    Map(irr::IrrlichtDevice *device, irr::u16 size);
    Map(irr::IrrlichtDevice *device, const std::string &save, irr::u16 size);
    ~Map();

    void genMap(irr::u16 size);
    void setMap();
    void addToMap(irr::u16 x, irr::u16 y, GameObject *obj);
    boost::multi_array<std::vector<GameObject*>, 2> &getMap();
    irr::u16 getSize() const;
    bool save();
    bool load(const std::string &filename);
    void setDevice(irr::IrrlichtDevice *device);
    void setSize(irr::u16 size);
};

#endif // !MAP_HPP_
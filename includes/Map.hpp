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
    irr::u16 _width;
    irr::u16 _heigh;

public:
    Map(irr::IrrlichtDevice *_device, irr::u16 size);
    ~Map();

    void genMap(irr::u16 size);
    void setMap();
    void addToMap(irr::u16 x, irr::u16 y, GameObject *obj);
    void delToMap(irr::u16 x, irr::u16 y, GameObject *obj);
    void updateColision();

    boost::multi_array<std::vector<GameObject*>, 2> &getMap();
    irr::core::vector2df getPosition(GameObject *);
    irr::u16 getWidth() const;
    irr::u16 getHeigh() const;
};

#endif // !MAP_HPP_
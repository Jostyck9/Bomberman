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
    boost::multi_array<std::vector<GameObject*>, 2> _map;
    irr::u16 _width;
    irr::u16 _heigh;

public:
    Map(irr::u16 width, irr::u16 heigh);
    ~Map();

    void addToMap(irr::u16 x, irr::u16 y, GameObject *obj);
};

#endif // !MAP_HPP_
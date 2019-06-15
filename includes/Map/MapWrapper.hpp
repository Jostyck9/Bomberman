/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** MapWrapper.hpp
*/

#ifndef MAP_WRAPPER_HPP__
#define MAP_WRAPPER_HPP__

#include <memory>
#include "GameObject.hpp"

class MapWrapper
{
private:
    irr::f32 _x;
    irr::f32 _y;
    std::shared_ptr<GameObject> _obj;

public:
    MapWrapper(irr::f32 x, irr::f32 y, std::shared_ptr<GameObject> obj);
    ~MapWrapper();

    void setPos(irr::f32 x, irr::f32 y);
    irr::core::vector2di getPos();

    void setObj(std::shared_ptr<GameObject> obj);
    std::shared_ptr<GameObject> getObj();
};

#endif
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** MapWrapper.cpp
*/

#include "MapWrapper.hpp"

MapWrapper::MapWrapper(irr::f32 x, irr::f32 y, std::shared_ptr<GameObject> obj) : _x(x), _y(y), _obj(obj)
{
}

MapWrapper::~MapWrapper()
{
}

void MapWrapper::setPos(irr::f32 x, irr::f32 y)
{
    _x = x;
    _y = y;
}

irr::core::vector2di MapWrapper::getPos()
{
    return (irr::core::vector2di(_x, _y));
}

void MapWrapper::setObj(std::shared_ptr<GameObject> obj)
{
    _obj = obj;
}

std::shared_ptr<GameObject> MapWrapper::getObj()
{
    return (_obj);
}

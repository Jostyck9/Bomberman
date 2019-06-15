/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Explosion.hpp
*/

#ifndef EXPLOSION_HPP_
#define EXPLOSION_HPP_

#include "Timer.hpp"
#include "Map.hpp"
#include "PrintableObject.hpp"
#include "MapWrapper.hpp"

class Explosion : public PrintableObject
{
private:
    Timer _myTimer;
    irr::s16 _index;
    irr::u16 _x;
    irr::u16 _y;

    void updateDammage(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd);

public:
    Explosion(irr::IrrlichtDevice *device, irr::u16 x, irr::u16 y);
    ~Explosion();

    void update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd);
    GameObject::objecType_t getType() override;
};

#endif // !EXPLOSION_HPP_
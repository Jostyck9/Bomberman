/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Bomb.hpp
*/

#ifndef BOMB_HPP
#define BOMB_HPP

#include "ACharacter.hpp"
#include "PrintableObject.hpp"
#include "Timer.hpp"

class Bomb : public PrintableObject
{
public:
    enum Action_e
    {
        NOTHING,
        DELETE
    };

private:
    Timer myTimer;
    irr::u16 _radius;
    irr::core::vector2df _posMap;

    ACharacter& _parentCharacter;

    void createExplosion(Map &map, std::vector<MapWrapper> &objToAdd, irr::core::vector2di position);
    void detectDestroyWall(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, irr::core::vector2di dir);

public:
    Bomb(irr::IrrlichtDevice* device, ACharacter& character, irr::u16 radius, irr::core::vector2df &posMap);
    ~Bomb();

    irr::u16 getRadius();
    void setRadius(irr::u16 _radius);
    Action_e update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, bool forcedExplosion = false);
    objecType_t getType() override;
    ACharacter& getParentCharacter();
};

#endif

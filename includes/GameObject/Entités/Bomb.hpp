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
    ACharacter& _parentCharacter;

public:
    Bomb(irr::IrrlichtDevice* device, ACharacter& character, irr::u16 radius, irr::core::vector2df &posMap);
    ~Bomb();

    irr::u16 getRadius();
    void setRadius(irr::u16 _radius);
    Action_e update(Map &map, std::vector<irr::s32> &idToDel);
    objecType_t getType() override;
    ACharacter& getParentCharacter();
};

#endif

/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** CharacterStats.hpp
*/

#ifndef CHARACTERSTATS_HPP
#define CHARACTERSTATS_HPP

#ifdef _WIN64
#include <irrlicht.h>
#else
#include <irrlicht/irrlicht.h>
#endif

class CharacterStats
{
private:
    bool _passThrough;
    irr::u16 _bombRadius;
    irr::u16 _nbrBomb;
    irr::f32 _speed;

public:
    bool getPassThrough();
    void setPassThrough(bool passThrough);

    irr::u16 getBombRadius();
    void setBombRadius(irr::u16 bombRadius);

    irr::u16 getNbrBomb();
    void setNbrBomb(irr::u16 nbrBomb);

    irr::f32 getSpeed();
    void setSpeed(irr::f32 speed);
};

#endif

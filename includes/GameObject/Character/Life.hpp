/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Life.hpp
*/

#ifndef LIFE_HPP_
#define LIFE_HPP_

#ifdef _WIN64
#include <irrlicht.h>
#else
#include <irrlicht/irrlicht.h>
#endif

class Life
{
private:
    irr::s16 _life;

public:
    Life(irr::s16 = 3);
    ~Life();

    irr::s16 getLife() const;
    void setLife(irr::s16 life);
};

#endif //LIFE_HPP_
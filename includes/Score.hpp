/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Score.hpp
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#ifdef _WIN64
#include <irrlicht.h>
#else
#include <irrlicht/irrlicht.h>
#endif

class Score
{
private:
    irr::s16 _score;

public:
    Score();
    ~Score();

    const irr::s16 getScore() const;
    void setScore(irr::s16);
};

#endif // !SCORE_HPP_
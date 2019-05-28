/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Score.cpp
*/

#include "Score.hpp"

Score::Score() : _score(0)
{
}

Score::~Score()
{
}

const irr::s16 Score::getScore() const
{
    return (_score);
}

void Score::setScore(irr::s16 score)
{
    _score = score;
}
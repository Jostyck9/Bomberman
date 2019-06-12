/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

Timer::Timer() : _begin(clock())
{
}

Timer::~Timer()
{
}

double Timer::getElapsedTime() const
{
    clock_t now = clock();
    double time_elapsed = 0;

    time_elapsed = double(now - _begin) / CLOCKS_PER_SEC;
    return (time_elapsed);
}

void Timer::restartClock()
{
    _begin = clock();
}

bool Timer::isTimeElapsed(double time) const
{
    clock_t now = clock();
    double time_elapsed = 0;

    time_elapsed = double(now - _begin) / CLOCKS_PER_SEC;
    return (time_elapsed >= time);
}

bool Timer::isTimeElapsedRestart(double time)
{
    clock_t now = clock();
    double time_elapsed = 0;

    time_elapsed = double(now - _begin) / CLOCKS_PER_SEC;
    if (time_elapsed >= time) {
        _begin = clock();
        return (true);
    }
    return (false);
}
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Time.hpp
*/

#ifndef TIMER_HPP__
#define TIMER_HPP__

#include <ctime>

class Timer
{
private:
    clock_t _begin;

public:
    Timer();
    ~Timer();

    double getElapsedTime() const;
    void restartClock();
    bool isTimeElapsed(double time) const;
    bool isTimeElapsedRestart(double time);
};

#endif // !TIMER_HPP__
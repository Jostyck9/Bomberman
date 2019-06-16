/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

Timer::Timer(irr::IrrlichtDevice *device) : _device(device), _start(0)
{
    if (_device) {
        _start = _device->getTimer()->getTime();
    }
}

Timer::~Timer()
{
}

irr::f32 Timer::getElapsedTime() const
{
    irr::f32 timeElapsed = 0;
    irr::u32 now = 0;

    if (!_device)
        return (0);
    now = _device->getTimer()->getTime();
    timeElapsed = (irr::f32)(now - _start) / 1000.f;
    return (timeElapsed);
}

void Timer::restartClock()
{
    if (_device) {
        _start = _device->getTimer()->getTime();
    }
}

bool Timer::isTimeElapsed(double time) const
{
    irr::u32 now = 0;
    irr::u32 timeElapsed = 0;

    if (!_device)
        return (false);
    now = _device->getTimer()->getTime();
    timeElapsed = (irr::f32)(now - _start) / 1000.f;
    return (timeElapsed >= time);
}

bool Timer::isTimeElapsedRestart(double time)
{
    irr::u32 now = 0;
    double timeElapsed = 0;

    if (!_device)
        return (0);
    now = _device->getTimer()->getTime();
    timeElapsed = (irr::f32)(now - _start) / 1000.f;
    if (timeElapsed >= time) {
        _start = _device->getTimer()->getTime();
        return (true);
    }
    return (false);
}
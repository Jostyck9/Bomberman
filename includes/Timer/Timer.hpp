/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Time.hpp
*/

#ifndef TIMER_HPP__
#define TIMER_HPP__

#ifdef _WIN64
    #include <IrrlichtDevice.h>
#else
    #include <irrlicht/IrrlichtDevice.h>
#endif

class Timer
{
private:
    irr::IrrlichtDevice *_device;
    irr::u32 _start;

public:
    Timer(irr::IrrlichtDevice *device);
    ~Timer();

    irr::f32 getElapsedTime() const;
    void restartClock();
    bool isTimeElapsed(double time) const;
    bool isTimeElapsedRestart(double time);
};

#endif // !TIMER_HPP__
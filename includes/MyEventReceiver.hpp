/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** MyEventReceiver.hpp
*/

#ifndef MYEVENTRECEIVER_HPP
#define MYEVENTRECEIVER_HPP

#include <irrlicht/irrlicht.h>

using namespace irr;


class MyEventReceiver : public IEventReceiver
{
public:
    // This is the one method that we have to implement
    bool OnEvent(const irr::SEvent& event);

    void resetKeys();

    // This is used to check whether a key is being held down
    bool IsKeyDown(irr::EKEY_CODE keyCode) const;
    bool IsKeyReleased(irr::EKEY_CODE keyCode) const;
    void setKeyPressed(irr::EKEY_CODE key);
    void setKeyReleased(irr::EKEY_CODE key);
    
    irr::s32 getButtonPressed();


    MyEventReceiver();

private:
    // We use this array to store the current state of each key
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
    bool KeyIsRealeased[KEY_KEY_CODES_COUNT];
    irr::s32 _buttonPressed;
};

#endif
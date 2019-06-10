/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** MyEventReceiver.cpp
*/

#include <iostream>
#include "MyEventReceiver.hpp"

MyEventReceiver::MyEventReceiver()
{
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

bool MyEventReceiver::OnEvent(const irr::SEvent& event)
{
    // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
        if (event.KeyInput.PressedDown == false) {
            KeyIsRealeased[event.KeyInput.Key] = true;
        }
    }
    return false;
}

void MyEventReceiver::resetKeys()
{
    for (irr::s16 i = 0; i < KEY_KEY_CODES_COUNT; i++) {
        KeyIsRealeased[i] = false;
    }
}

bool MyEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

bool MyEventReceiver::IsKeyReleased(irr::EKEY_CODE keyCode) const
{
    return KeyIsRealeased[keyCode];
}
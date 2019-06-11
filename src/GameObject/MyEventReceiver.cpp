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
    _buttonPressed = -1;
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

void MyEventReceiver::resetKeys()
{
    for (irr::s16 i = 0; i < KEY_KEY_CODES_COUNT; i++) {
        KeyIsRealeased[i] = false;
    }
    _buttonPressed = -1;
}

bool MyEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

bool MyEventReceiver::IsKeyReleased(irr::EKEY_CODE keyCode) const
{
    return KeyIsRealeased[keyCode];
}

irr::s32 MyEventReceiver::getButtonPressed()
{
    return (_buttonPressed);
}

void MyEventReceiver::setKeyPressed(irr::EKEY_CODE key)
{
    KeyIsDown[key] = true;
}

void MyEventReceiver::setKeyReleased(irr::EKEY_CODE key)
{
    KeyIsRealeased[key] = true;
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

    if (event.EventType == EET_GUI_EVENT) {
        if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
        {
            _buttonPressed = event.GUIEvent.Caller->getID();
        }
    }
    return false;
}
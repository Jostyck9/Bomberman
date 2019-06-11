/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** MyEventReceiver.cpp
*/

#include <iostream>
#include "MyEventReceiver.hpp"
#include "Game.hpp"

MyEventReceiver::MyEventReceiver()
{
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

bool MyEventReceiver::OnEvent(const irr::SEvent& event)
{
    // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	
    if (event.EventType == EET_GUI_EVENT)
		{
			s32 id = event.GUIEvent.Caller->getID();
			switch(event.GUIEvent.EventType)
			{
			case EGET_BUTTON_CLICKED:
				switch(id)
				{
				case GUI_QUIT:
				return true;

				case GUI_PLAY:
				return true;

				case GUI_LOAD:
				return true;

                case GUI_SETTINGS:	
				return true;

                case GUI_HOW_TO_PLAY:
					
				return true;

                case GUI_SCOREBOARD:
					
				return true;
                
				default:
					return false;
				}
			default:
				break;
			}
		}
	return false;
}

bool MyEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}
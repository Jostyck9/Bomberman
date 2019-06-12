/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.cpp
*/

#include <iostream>
#include "driverChoice.h"
#include "Menu.hpp"
#include "Game.hpp"
#include "settings.hpp"


Menu::Menu(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background) : AScene(device, receiver, camera), _background(background)
{
    guienv = device->getGUIEnvironment();
    button();
}

Menu::~Menu()
{
    play->remove();
    load->remove();
    settings->remove();
    how_play->remove();
    scoreboard->remove();
    quit->remove();
    
}

IScene* Menu::update()
{
    irr::s32 id = -1;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }

    id = _events.getButtonPressed();
    switch(id) {
        case GUI_QUIT:
            delete this;
            return (nullptr);

        case GUI_PLAY:
            //delete this;
            return (new Game(this->_device, this->_events));
            break;

        case GUI_LOAD:
            break;

        case GUI_SETTINGS:
            //delete this;
            return (new Settings(this->_device, this->_events, this->_background));

        case GUI_HOW_TO_PLAY:
            break;

        case GUI_SCOREBOARD:
            break;

        default:
            break;
    }
    _events.resetKeys();
    return (this);
}

void Menu::display()
{
    if (!_device->run()) {
        return;
    }
    _background->display();
    guienv->drawAll();
    _driver->endScene();
}

bool Menu::button()
{
    play = guienv->addButton(irr::core::rect<irr::s32>(280,30,370,50), 0, GUI_PLAY, L"Play");
    load = guienv->addButton(irr::core::rect<irr::s32>(280,70,370,90), 0, GUI_LOAD, L"Load");
    settings = guienv->addButton(irr::core::rect<irr::s32>(280,110,370,130), 0, GUI_SETTINGS, L"Settings");
    how_play = guienv->addButton(irr::core::rect<irr::s32>(280,150,370,170), 0, GUI_HOW_TO_PLAY, L"How To Play");
    scoreboard = guienv->addButton(irr::core::rect<irr::s32>(280,190,370,210), 0, GUI_SCOREBOARD, L"Scoreboard");
    quit = guienv->addButton(irr::core::rect<irr::s32>(280,230,370,250), 0, GUI_QUIT, L"Quit");
    return (true);
}

void Menu::setSkin(s32 alpha, irr::gui::IGUISkin * skin)
{
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_WINDOW);
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_BUTTON);
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_DEFAULT); //Font des Textes
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_MENU);
    // for (s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
	// {
	// 	video::SColor col = skin->getColor((EGUI_DEFAULT_COLOR)i);
	// 	col.setAlpha(alpha);
	// 	skin->setColor((EGUI_DEFAULT_COLOR)i, col);
	// }
}
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
    sizescreen = this->_driver->getScreenSize();
    button();
    tittle();
    setSkin();
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

void Menu::tittle()
{
    // title = guienv->addImage(_driver->getTexture("./assets/title.png"),
    //         irr::core::position2d<int>(300,-10));
    // title->setScaleImage(true);
}

bool Menu::button()
{
    play = guienv->addButton(irr::core::rect<irr::s32>(sizescreen.Width/4,sizescreen.Height/2,sizescreen.Width/3,sizescreen.Height/1.8), 0, GUI_PLAY, L"Play");
    load = guienv->addButton(irr::core::rect<irr::s32>(sizescreen.Width/4,480,sizescreen.Width/3,520), 0, GUI_LOAD, L"Load");
    settings = guienv->addButton(irr::core::rect<irr::s32>(800,400,940,440), 0, GUI_SETTINGS, L"Settings");
    how_play = guienv->addButton(irr::core::rect<irr::s32>(800,480,940,520), 0, GUI_HOW_TO_PLAY, L"How To Play");
    scoreboard = guienv->addButton(irr::core::rect<irr::s32>(1050,30,1190, 70), 0, GUI_SCOREBOARD, L"Scoreboard");
    quit = guienv->addButton(irr::core::rect<irr::s32>(560,640,700,680), 0, GUI_QUIT, L"Quit");
    return (true);
}

void Menu::setSkin()
{

    texture = this->_driver->getTexture("./assets/textures/button.png");
    play->setImage(texture);
    // play->setPressedImage();
    load->setImage(texture);
    settings->setImage(texture);
    how_play->setImage(texture);
    scoreboard->setImage(texture);
    quit->setImage(texture);
    play->setScaleImage(true);
    load->setScaleImage(true);
    settings->setScaleImage(true);
    how_play->setScaleImage(true);
    scoreboard->setScaleImage(true);
    quit->setScaleImage(true);

    // skin = guienv->getSkin();
	// font = guienv->getFont("./assets/myfont.xml");
	// if (font)
	// 	skin->setFont(font);

	// skin->setFont(guienv->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_WINDOW);
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_BUTTON);
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_DEFAULT); //Font des Textes
    // guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_MENU);
}
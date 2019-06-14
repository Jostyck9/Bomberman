/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.cpp
*/

#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"
#include "settings.hpp"
#include "How_play.hpp"
#include "Scoreboard.hpp"


Menu::Menu(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background) : AScene(device, receiver, false), _background(background)
{
    guienv = device->getGUIEnvironment();
    sizescreen = this->_driver->getScreenSize();
    device->setResizable(false);
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
    title->remove();

}

IScene* Menu::update()
{
    IScene *next = NULL;
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
        next = new Game(this->_device, this->_events);
            delete this;
            delete this->_background;
            return (next);
            break;

        case GUI_LOAD:
            break;

        case GUI_SETTINGS:
            next = new Settings(this->_device, this->_events, this->_background);
            delete this;
            return (next);

        case GUI_HOW_TO_PLAY:
            next = new How_Play(this->_device, this->_events, this->_background);
            delete this;
            return (next);

        case GUI_SCOREBOARD:
            next = new Scoreboard(this->_device, this->_events, this->_background);
            delete this;
            return (next);
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
    title = guienv->addImage(_driver->getTexture("./assets/meshs/Menu/BomberMario.png"),
            irr::core::position2d<int>(300,30));
    title->setScaleImage(true);
}

bool Menu::button()
{
    play = guienv->addButton(irr::core::rect<irr::s32>(300,400,440,440), 0, GUI_PLAY, L"Play");
    load = guienv->addButton(irr::core::rect<irr::s32>(300,480,440,520), 0, GUI_LOAD, L"Load");
    settings = guienv->addButton(irr::core::rect<irr::s32>(800,400,940,440), 0, GUI_SETTINGS, L"Settings");
    how_play = guienv->addButton(irr::core::rect<irr::s32>(800,480,940,520), 0, GUI_HOW_TO_PLAY, L"How To Play");
    scoreboard = guienv->addButton(irr::core::rect<irr::s32>(1150,30,1250, 70), 0, GUI_SCOREBOARD, L"Scoreboard");
    quit = guienv->addButton(irr::core::rect<irr::s32>(560,640,700,680), 0, GUI_QUIT, L"Quit");
    return (true);
}

void Menu::setSkin()
{
    texture = this->_driver->getTexture("./assets/textures/button.png");
    pressed = this->_driver->getTexture("./assets/textures/pressed.png");    
    play->setImage(texture);
    play->setScaleImage(true);
    play->setPressedImage(pressed);
    load->setImage(texture);
    load->setScaleImage(true);
    load->setPressedImage(pressed);
    settings->setImage(texture);
    settings->setScaleImage(true);
    settings->setPressedImage(pressed);
    how_play->setImage(texture);
    how_play->setScaleImage(true);
    how_play->setPressedImage(pressed);
    scoreboard->setImage(texture);
    scoreboard->setScaleImage(true);
    scoreboard->setPressedImage(pressed);
    quit->setImage(texture);
    quit->setScaleImage(true);

    // skin = guienv->getSkin();
	// font = guienv->getFont("./assets/myfont.xml");
	// if (font)
	// 	skin->setFont(font);

	// skin->setFont(guienv->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
}
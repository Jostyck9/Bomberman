/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.cpp
*/

#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"
#include "Settings.hpp"
#include "How_play.hpp"
#include "Scoreboard.hpp"
#include "Play.hpp"


Menu::Menu(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background, Sound sound) : AScene(device, receiver, false), _background(background), _sound(sound)
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
            next = new Play(this->_device, this->_events, this->_sound);
            delete _background;
            delete this;
            return (next);

        case GUI_LOAD:
            try {
                next = new Game(this->_device, this->_events, "save.txt");
            }
            catch (std::exception) {
                delete _background;
                _background = new Background(_device, _events);
                _device->getGUIEnvironment()->addMessageBox(
                Load_error.c_str(), L"No save can be load");
                break;
            }
            delete _background;
            delete this;
            return (next);

        case GUI_SETTINGS:
            next = new Settings(this->_device, this->_events, this->_background, this->_sound);
            delete this;
            return (next);

        case GUI_HOW_TO_PLAY:
            next = new How_Play(this->_device, this->_events, this->_background, this->_sound);
            delete this;
            return (next);

        case GUI_SCOREBOARD:
            next = new Scoreboard(this->_device, this->_events, this->_background, this->_sound);
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
    play = guienv->addButton(irr::core::rect<irr::s32>(300,390,440,440), 0, GUI_PLAY, L"");
    load = guienv->addButton(irr::core::rect<irr::s32>(300,470,440,520), 0, GUI_LOAD, L"");
    settings = guienv->addButton(irr::core::rect<irr::s32>(800,390,980,440), 0, GUI_SETTINGS, L"");
    how_play = guienv->addButton(irr::core::rect<irr::s32>(800,470,980,520), 0, GUI_HOW_TO_PLAY, L"");
    scoreboard = guienv->addButton(irr::core::rect<irr::s32>(1150,30,1250, 70), 0, GUI_SCOREBOARD, L"Scoreboard");
    quit = guienv->addButton(irr::core::rect<irr::s32>(560,630,700,680), 0, GUI_QUIT, L"");
    return (true);
}

void Menu::setSkin()
{
    texture = this->_driver->getTexture("./assets/textures/button.png");
    pressed = this->_driver->getTexture("./assets/textures/pressed.png");
    but_play = this->_driver->getTexture("./assets/meshs/Menu/Button/Play.png");
    but_play_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/Play_pressed.png");
    but_load = this->_driver->getTexture("./assets/meshs/Menu/Button/Load.png");
    but_load_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/Load_pressed.png");
    but_settings = this->_driver->getTexture("./assets/meshs/Menu/Button/Settings.png");
    but_settings_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/Settings_pressed.png");
    but_how = this->_driver->getTexture("./assets/meshs/Menu/Button/How.png");
    but_how_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/How_pressed.png");
    but_quit = this->_driver->getTexture("./assets/meshs/Menu/Button/Quit.png");
    but_quit_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/Quit_pressed.png");

    play->setImage(but_play);
    play->setScaleImage(true);
    play->setUseAlphaChannel(true);
    play->setDrawBorder(0);
    play->setPressedImage(but_play_pressed);
    load->setImage(but_load);
    load->setScaleImage(true);
    load->setPressedImage(but_load_pressed);
    load->setUseAlphaChannel(true);
    load->setDrawBorder(0);
    settings->setImage(but_settings);
    settings->setScaleImage(true);
    settings->setUseAlphaChannel(true);
    settings->setDrawBorder(0);
    settings->setPressedImage(but_settings_pressed);
    how_play->setImage(but_how);
    how_play->setScaleImage(true);
    how_play->setUseAlphaChannel(true);
    how_play->setDrawBorder(0);
    how_play->setPressedImage(but_how_pressed);
    scoreboard->setImage(texture);
    scoreboard->setScaleImage(true);
    // scoreboard->setPressedImage(pressed);
    quit->setImage(but_quit);
    quit->setScaleImage(true);
    quit->setUseAlphaChannel(true);
    quit->setDrawBorder(0);
    quit->setPressedImage(but_quit_pressed);

}
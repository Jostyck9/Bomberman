/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** settings.cpp
*/

#include "settings.hpp"

Settings::Settings(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background) : AScene(device, receiver, camera), _background(background)
{
    guienv = device->getGUIEnvironment();
    button();
}

IScene* Settings::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
}

void Settings::display()
{
    if (!_device->run()) {
        return;
    }
    _background->display();
    guienv->drawAll();
    _driver->endScene();
}

bool Settings::button()
{
    irr::gui::IGUIButton *load = guienv->addButton(irr::core::rect<irr::s32>(280,70,370,90), 0, GUI_LOAD, L"Load");
    irr::gui::IGUIButton *settings = guienv->addButton(irr::core::rect<irr::s32>(280,110,370,130), 0, GUI_SETTINGS, L"Settings");
    irr::gui::IGUIButton *how_play = guienv->addButton(irr::core::rect<irr::s32>(280,150,370,170), 0, GUI_HOW_TO_PLAY, L"How To Play");
    return (true);
}
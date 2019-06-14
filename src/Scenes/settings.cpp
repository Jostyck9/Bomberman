/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** settings.cpp
*/

#include <iostream>
#include "settings.hpp"
#include "Menu.hpp"

Settings::Settings(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background) : AScene(device, receiver, false), _background(background)
{
    guienv = device->getGUIEnvironment();
    print_image();
    button();
    sound();
    //std::cout << "" << edit_sound << std::endl;
}

Settings::~Settings()
{
    return_menu->remove();
    // but_sound->remove();
    // music->remove();
    cadre_menu->remove();
    edit_sound->remove();
}

IScene* Settings::update()
{
    IScene *next = NULL;
    irr::s32 id = -1;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }

    id = _events.getButtonPressed();
    switch(id) {
        case GUI_RETURN_MENU:
            next = new Menu(this->_device, this->_events, _background);
            delete this;
            return (next);

        case GUI_SOUND:
            print_box = edit_sound->getText();
            
            break;

        case GUI_MUSIC:
            break;

        default:
            break;
    }
    _events.resetKeys();
    return (this);
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
    return_menu = guienv->addButton(irr::core::rect<irr::s32>(20,20,160,60), 0, GUI_RETURN_MENU, L"Return");
    texture = this->_driver->getTexture("./assets/textures/button.png");
    return_menu->setImage(texture);
    return_menu->setScaleImage(true);
    but_sound = guienv->addButton(irr::core::rect<irr::s32>(280,70,370,90), 0, GUI_SOUND, L"Enter");
    // music = guienv->addButton(irr::core::rect<irr::s32>(280,110,370,130), 0, GUI_MUSIC, L"Settings");
    return (true);
}

void Settings::print_image()
{
    cadre_menu = guienv->addImage(_driver->getTexture("./assets/meshs/Menu/cadre_settings.png"),
            irr::core::position2d<int>(180,110));
}

void Settings::sound()
{
    edit_sound = guienv->addEditBox(L"Editable Text", irr::core::rect<s32>(550, 300, 600, 320));
    edit_sound->setDrawBorder(false);
    edit_sound->setText(L"100");
    edit_sound->setMax(3);
    // irr::gui::IGUISkin* skin = guienv->getSkin();
    // irr::gui::IGUIFont *test = guienv->getFont("./assets/haetten.ttf");
    // if (test)
	// 	skin->setFont(test);
    // skin->setFont(guienv->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    // edit_sound->setOverrideFont(test);
}
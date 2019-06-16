/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Settings.cpp
*/

#include <iostream>
#include "Settings.hpp"
#include "Menu.hpp"

Settings::Settings(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background, Sound Sendsound) : AScene(device, receiver, false), _background(background), _sound(Sendsound)
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
    but_sound->remove();
    // music->remove();
    cadre_menu->remove();
    edit_sound->remove();
    title->remove();
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
            next = new Menu(this->_device, this->_events, _background, this->_sound);
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
    return_menu = guienv->addButton(irr::core::rect<irr::s32>(20,20,160,60), 0, GUI_RETURN_MENU, L"");
    return_texture = this->_driver->getTexture("./assets/meshs/Menu/Button/Return.png");
    return_texture_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/Return_pressed.png");
    return_menu->setImage(return_texture);
    return_menu->setScaleImage(true);
    return_menu->setUseAlphaChannel(true);
    return_menu->setDrawBorder(0);
    return_menu->setPressedImage(return_texture_pressed);
    but_sound = guienv->addButton(irr::core::rect<irr::s32>(950,300,1050,320), 0, GUI_SOUND, L"Validate");
    return (true);
}

void Settings::print_image()
{
    cadre_menu = guienv->addImage(_driver->getTexture("./assets/meshs/Menu/cadre_settings.png"),
            irr::core::position2d<int>(180,110));
    title = guienv->addImage(_driver->getTexture("./assets/meshs/Menu/Text_settings.png"),
            irr::core::position2d<int>(680,160));
}

void Settings::sound()
{
    edit_sound = guienv->addEditBox(L"Editable Text", irr::core::rect<s32>(900, 300, 940, 320));
    edit_sound->setDrawBorder(false);
    edit_sound->setText(L"5");
    edit_sound->setMax(1);
    // irr::gui::IGUISkin* skin = guienv->getSkin();
    // irr::gui::IGUIFont *test = guienv->getFont("./assets/haetten.ttf");
    // if (test)
	// 	skin->setFont(test);
    // skin->setFont(guienv->getBuiltInFont(), irr::gui::EGDF_TOOLTIP);
    // edit_sound->setOverrideFont(test);
}
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** How_play.cpp
*/

#include "How_play.hpp"
#include "Menu.hpp"

How_Play::How_Play(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background) : AScene(device, receiver, false), _background(background)
{
    guienv = device->getGUIEnvironment();
    button();
    image();
}

How_Play::~How_Play()
{
    return_menu->remove();
    cadre->remove();
}

IScene* How_Play::update()
{
    IScene *next = NULL;
    irr::s32 id = -1;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }

    id = _events.getButtonPressed();
    switch(id) {
        case GUI_RETURN_HOW:
            next = new Menu(this->_device, this->_events, _background);
            delete this;
            return (next);

        default:
            break;
    }
    _events.resetKeys();
    return (this);
}

void How_Play::display()
{
    if (!_device->run()) {
        return;
    }
    _background->display();
    guienv->drawAll();
    _driver->endScene();
}

bool How_Play::button()
{
    return_menu = guienv->addButton(irr::core::rect<irr::s32>(20,20,160,60), 0, GUI_RETURN_HOW, L"");
    return_texture = this->_driver->getTexture("./assets/meshs/Menu/Button/Return.png");
    return_texture_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/Return_pressed.png");
    return_menu->setImage(return_texture);
    return_menu->setScaleImage(true);
    return_menu->setUseAlphaChannel(true);
    return_menu->setDrawBorder(0);
    return_menu->setPressedImage(return_texture_pressed);
    return (true);
}

void How_Play::image()
{
    cadre = guienv->addImage(_driver->getTexture("./assets/meshs/Menu/cadre.png"),
            irr::core::position2d<int>(230,180));
}
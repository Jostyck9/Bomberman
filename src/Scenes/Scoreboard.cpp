/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Scoreboard.cpp
*/

#include "Scoreboard.hpp"
#include "Menu.hpp"

Scoreboard::Scoreboard(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background) : AScene(device, receiver, false), _background(background)
{
    guienv = device->getGUIEnvironment();
    button();
    // image();
}

Scoreboard::~Scoreboard()
{
    return_menu->remove();
}

IScene* Scoreboard::update()
{
    IScene *next = NULL;
    irr::s32 id = -1;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }

    id = _events.getButtonPressed();
    switch(id) {
        case GUI_RETURN_SCORE:
            next = new Menu(this->_device, this->_events, _background);
            delete this;
            return (next);

        default:
            break;
    }
    _events.resetKeys();
    return (this);
}

void Scoreboard::display()
{
    if (!_device->run()) {
        return;
    }
    _background->display();
    guienv->drawAll();
    _driver->endScene();
}

bool Scoreboard::button()
{
    return_menu = guienv->addButton(irr::core::rect<irr::s32>(20,20,160,60), 0, GUI_RETURN_SCORE, L"Return");
    texture = this->_driver->getTexture("./assets/textures/button.png");
    return_menu->setImage(texture);
    return_menu->setScaleImage(true);
    return (true);
}
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Menu_game.cpp
*/

#include "Menu_game.hpp"

Menu_game::Menu_game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, Map &map) : AScene(device, receiver, false), _map(map)
{
    guienv = device->getGUIEnvironment();
    button();
    setSkinButton();
}

Menu_game::~Menu_game()
{
    resume->remove();
    save->remove();
    quit->remove();
    //cadre_menu->remove();
}

IScene* Menu_game::update()
{
    IScene *next = NULL;
    IScene *back = NULL;
    irr::s32 id = -1;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }

    id = _events.getButtonPressed();
    switch(id) {
        case GUI_RESUME:
            break;

        case GUI_SAVE:
            _map.save();
            // _device->getGUIEnvironment()->addMessageBox(
            //     Load_error.c_str(), L"Game Saved");
            break;

        case GUI_QUIT_GAME:
            back = new Background(_device, _events);
            next = new Menu(this->_device, this->_events, back);
            delete this;
            return (next);

        default:
            break;
    }
    _events.resetKeys();
    return (this);
}

void Menu_game::display()
{
    if (!_device->run()) {
        return;
    }
    
    guienv->drawAll();
    _driver->endScene();
}

bool Menu_game::button()
{
    resume = guienv->addButton(irr::core::rect<irr::s32>(550,290,690,340), 0, GUI_RESUME, L"");
    save = guienv->addButton(irr::core::rect<irr::s32>(550,370,690,420), 0, GUI_SAVE, L"");
    quit = guienv->addButton(irr::core::rect<irr::s32>(550,450,690,500), 0, GUI_QUIT_GAME, L"");
    return (true);
}

void Menu_game::setSkinButton()
{
    resume_texture = this->_driver->getTexture("./assets/meshs/Menu/Button/resume.png");
    resume_texture_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/resume_pressed.png");
    save_texture = this->_driver->getTexture("./assets/meshs/Menu/Button/save.png");
    save_texture_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/save_pressed.png");
    quit_texture = this->_driver->getTexture("./assets/meshs/Menu/Button/quit.png");
    quit_texture_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/quit_pressed.png");
    resume->setImage(resume_texture);
    resume->setScaleImage(true);
    resume->setUseAlphaChannel(true);
    resume->setDrawBorder(0);
    resume->setPressedImage(resume_texture_pressed);
    save->setImage(save_texture);
    save->setScaleImage(true);
    save->setUseAlphaChannel(true);
    save->setDrawBorder(0);
    save->setPressedImage(save_texture_pressed);
    quit->setImage(quit_texture);
    quit->setScaleImage(true);
    quit->setUseAlphaChannel(true);
    quit->setDrawBorder(0);
    quit->setPressedImage(quit_texture_pressed);

}
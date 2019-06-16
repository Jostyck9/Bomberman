/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Menu_game.cpp
*/

#include "Menu_game.cpp"

Menu_game::Menu_game(irr::IrrlichtDevice* device, MyEventReceiver &receiver) : AScene(device, receiver, false)
{
    button();
    setSkinButton();
}

Menu_game::~Menu_game()
{
    resume->remove();
    save->remove();
    quit->remove();
    cadre_menu->remove();
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
        case GUI_RESUME:

        case GUI_SAVE;
            _map.save();
            break;

        case GUI_QUIT_GAME:
            IScene *back(new Background(_device, _events));
            next = new Menu(this->_device, this->_events, back);
            delete this;
            delete _game;
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

bool button()
{
    resume = guienv->addButton(irr::core::rect<irr::s32>(300,390,440,440), 0, GUI_RESUME, L"");
    save = guienv->addButton(irr::core::rect<irr::s32>(300,470,440,520), 0, GUI_SAVE, L"");
    quit = guienv->addButton(irr::core::rect<irr::s32>(800,390,980,440), 0, GUI_QUIT_GAME, L"");
    return (true);
}

void setSkinButton()
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
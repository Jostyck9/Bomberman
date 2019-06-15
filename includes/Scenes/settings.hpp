/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** settings.hpp
*/

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "irrlicht/irrlicht.h"
#include "AScene.hpp"
#include "background.hpp"

enum
{
    GUI_RETURN_MENU,
    GUI_SOUND,
    GUI_MUSIC,
};

class Settings : public AScene
{
private:
    IScene *_background;
    irr::gui::IGUIEnvironment *guienv;
    irr::video::ITexture *return_texture;
    irr::gui::IGUIButton *return_menu;
    irr::gui::IGUIButton *but_sound;
    irr::gui::IGUIButton *music;
    irr::gui::IGUIImage *cadre_menu;
    irr::gui::IGUIImage *title;
    irr::gui::IGUIEditBox *edit_sound;
    const wchar_t *print_box;

public:
    Settings(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background);
    ~Settings();
    IScene* update() override;
    void display() override;
    bool button();
    void print_image();
    void sound();
    //void setSkin();
};

#endif
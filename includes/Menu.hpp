/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "irrlicht/irrlicht.h"
#include <IGUISkin.h>
#include "Camera.hpp"
#include "AScene.hpp"
#include "background.hpp"
#include "Sound.hpp"

enum
{
    GUI_QUIT = 101,
    GUI_PLAY,
    GUI_LOAD,
    GUI_SETTINGS,
    GUI_HOW_TO_PLAY,
    GUI_SCOREBOARD
};

class Menu : public AScene
{
private:
    irr::gui::IGUIEnvironment *guienv;
    irr::gui::IGUIStaticText *texte;
    irr::video::ITexture *texture;
    irr::video::ITexture *pressed;
    irr::video::ITexture *but_play;
    irr::video::ITexture *but_play_pressed;
    irr::video::ITexture *but_load;
    irr::video::ITexture *but_load_pressed;
    irr::video::ITexture *but_settings;
    irr::video::ITexture *but_settings_pressed;
    irr::video::ITexture *but_how;
    irr::video::ITexture *but_how_pressed;
    irr::video::ITexture *but_quit;
    irr::video::ITexture *but_quit_pressed;
    irr::gui::IGUIImage *title;
    irr::gui::IGUIButton *play;
    irr::gui::IGUIButton *load;
    irr::gui::IGUIButton *settings;
    irr::gui::IGUIButton *how_play;
    irr::gui::IGUIButton *scoreboard;
    irr::gui::IGUIButton *quit;
    irr::gui::IGUISkin* skin;
    irr::gui::IGUIFont* font;
    IScene *_background;
    irr::core::dimension2d<f32> sizescreen;
    irr::core::stringw Load_error;
    Sound sound;

public:
    Menu(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background);
    ~Menu();
    IScene* update() override;
    void display() override;
    bool button();
    void setSkin();
    void tittle();
};

#endif
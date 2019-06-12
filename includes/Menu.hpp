/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "irrlicht/irrlicht.h"
#include "Camera.hpp"
#include "AScene.hpp"
#include "background.hpp"

class Menu : public AScene
{
private:
    irr::gui::IGUIEnvironment *guienv;
    irr::gui::IGUIStaticText *texte;
    irr::gui::IGUIButton *bouton;
    irr::video::ITexture *image;
    irr::gui::IGUIButton *play;
    irr::gui::IGUIButton *load;
    irr::gui::IGUIButton *settings;
    irr::gui::IGUIButton *how_play;
    irr::gui::IGUIButton *scoreboard;
    irr::gui::IGUIButton *quit;
    IScene *_background;

public:
    Menu(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background);
    ~Menu();
    IScene* update() override;
    void display() override;
    bool button();
    void setSkin(s32 alpha, irr::gui::IGUISkin * skin);
};

#endif
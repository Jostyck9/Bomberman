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

class Settings : public AScene
{
private:
    irr::gui::IGUIEnvironment *guienv;
    irr::gui::IGUIStaticText *texte;
    irr::gui::IGUIButton *bouton;
    irr::video::ITexture *image;
    IScene *_background;

public:
    Settings(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background);
    IScene* update() override;
    void display() override;
    bool button();
    void setSkin(s32 alpha, irr::gui::IGUISkin * skin);
};

#endif
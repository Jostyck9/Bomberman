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
#include "Map.hpp"
#include "AScene.hpp"

class Menu : public AScene
{
private:
    irr::gui::IGUIEnvironment *guienv;
    irr::gui::IGUIStaticText *texte;
    irr::gui::IGUIButton *bouton;
    irr::video::ITexture *image;

public:
    Menu(irr::IrrlichtDevice* device);
    IScene* update() override;
    IScene* handleEvent() override;
    void display() override;
    void setSkin(s32 alpha, irr::gui::IGUISkin * skin);
    bool button();
    void play();
    IScene* quit();
    void createBackGround();
};

#endif
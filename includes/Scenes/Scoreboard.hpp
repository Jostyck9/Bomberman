/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Scoreboard.hpp
*/

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include "irrlicht/irrlicht.h"
#include "AScene.hpp"
#include "background.hpp"

enum
{
    GUI_RETURN_SCORE
};

class Scoreboard : public AScene
{
    private:
    IScene *_background;
    irr::gui::IGUIButton *return_menu;
    irr::gui::IGUIEnvironment *guienv;
    irr::video::ITexture *texture;
    irr::gui::IGUIImage *cadre;

    public:
    Scoreboard(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background);
    ~Scoreboard();
    IScene* update() override;
    void display() override;
    bool button();
    // void image();
};

#endif
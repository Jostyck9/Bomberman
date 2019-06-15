/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** How_play.hpp
*/

#ifndef HOW_PLAY_HPP
#define HOW_PLAY_HPP

#include "irrlicht/irrlicht.h"
#include "AScene.hpp"
#include "background.hpp"

enum
{
    GUI_RETURN_HOW
};

class How_Play : public AScene
{
    private:
    IScene *_background;
    irr::gui::IGUIButton *return_menu;
    irr::gui::IGUIEnvironment *guienv;
    irr::video::ITexture *return_texture;
    irr::video::ITexture *return_texture_pressed;
    irr::gui::IGUIImage *cadre;

    public:
    How_Play(irr::IrrlichtDevice* device, MyEventReceiver &receiver, IScene *background);
    ~How_Play();
    IScene* update() override;
    void display() override;
    bool button();
    void image();
};
#endif
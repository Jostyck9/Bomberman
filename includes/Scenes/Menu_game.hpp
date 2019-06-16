/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Menu_game.hpp
*/

#ifndef MENU_GAME_HPP
#define MENU_GAME_HPP

#include "irrlicht/irrlicht.h"
#include "AScene.hpp"
#include "Game.hpp"

enum
{
    GUI_RESUME,
    GUI_SAVE,
    GUI_QUIT_GAME
};

class Menu_game : public AScene
{
    public:
    Menu_game(irr::IrrlichtDevice* device, MyEventReceiver &receiver);
    ~Menu_game();
    IScene* update() override;
    void display() override;
    bool button();
    void setSkinButton();

    private:
    Game _game;
    irr::gui::IGUIEnvironment *guienv;
    irr::gui::IGUIImage *cadre_menu;
    irr::video::ITexture *resume_texture;
    irr::video::ITexture *save_texture;
    irr::video::ITexture *quit_texture;
    irr::gui::IGUIButton *resume;
    irr::gui::IGUIButton *save;
    irr::gui::IGUIButton *quit;
};

#endif
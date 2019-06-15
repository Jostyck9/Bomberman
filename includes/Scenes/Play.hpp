/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Play.hpp
*/

#ifndef PLAY_CPP
#define PLAY_CPP

#include "AScene.hpp"
#include "Menu.hpp"
#include "Camera.hpp"

enum
{
    GUI_RETURN_PLAY,
    GUI_START_GAME,
    GUI_IA,
    GUI_Player1,
    GUI_Player2
};

class Play : public AScene
{
    public:
    Play(irr::IrrlichtDevice* device, MyEventReceiver &receiver);
    ~Play();
    IScene* update() override;
    void display() override;
    void background_play();
    void IA();
    void Player1();
    void Player2();
    void Mesh();
    bool button();

    private:
    IScene *_background;
    irr::gui::IGUIButton *return_menu;
    irr::gui::IGUIButton *start_game;
    irr::gui::IGUIButton *IA_but;
    irr::gui::IGUIButton *Player1_but;
    irr::gui::IGUIButton *Player2_but;
    irr::gui::IGUIEnvironment *guienv;
    irr::video::ITexture *return_texture;
    irr::video::ITexture *but_start_game;
    irr::video::ITexture *IA_text;
    irr::video::ITexture *Player1_text;
    irr::video::ITexture *Player2_text;
    irr::gui::IGUIImage *background;
    scene::IAnimatedMeshSceneNode* Mario;
    scene::IAnimatedMeshSceneNode* Luigi;
    scene::IAnimatedMeshSceneNode* Toad;
    scene::IAnimatedMeshSceneNode* Peach;
    scene::ISceneNode* camera_play;
    scene::IAnimatedMeshSceneNode * menu_play;

};

#endif
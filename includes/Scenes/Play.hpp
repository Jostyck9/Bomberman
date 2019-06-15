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
    GUI_Mario_IA,
    GUI_Mario_Player1,
    GUI_Mario_Player2,
    GUI_Luigi_IA,
    GUI_Luigi_Player1,
    GUI_Luigi_Player2,
    GUI_Toad_IA,
    GUI_Toad_Player1,
    GUI_Toad_Player2,
    GUI_Peach_IA,
    GUI_Peach_Player1,
    GUI_Peach_Player2
};

struct character {

    enum type 
    {
        Player1,
        Player2,
        IA
    };

    int Mario;
    int Luigi;
    int Toad;
    int Peach;
};
typedef struct character character;

class Play : public AScene
{
    public:
    Play(irr::IrrlichtDevice* device, MyEventReceiver &receiver);
    ~Play();
    IScene* update() override;
    void display() override;
    void background_play();
    void Mario_IA();
    void Mario_Player1();
    void Mario_Player2();
    void Luigi_IA();
    void Luigi_Player1();
    void Luigi_Player2();
    void Toad_IA();
    void Toad_Player1();
    void Toad_Player2();
    void Peach_IA();
    void Peach_Player1();
    void Peach_Player2();
    void Mesh();
    bool button();

    private:
    IScene *_background;
    irr::gui::IGUIButton *return_menu;
    irr::gui::IGUIButton *start_game;
    irr::gui::IGUIButton *Mario_IA_but;
    irr::gui::IGUIButton *Mario_Player1_but;
    irr::gui::IGUIButton *Mario_Player2_but;
    irr::gui::IGUIButton *Luigi_IA_but;
    irr::gui::IGUIButton *Luigi_Player1_but;
    irr::gui::IGUIButton *Luigi_Player2_but;
    irr::gui::IGUIButton *Toad_IA_but;
    irr::gui::IGUIButton *Toad_Player1_but;
    irr::gui::IGUIButton *Toad_Player2_but;
    irr::gui::IGUIButton *Peach_IA_but;
    irr::gui::IGUIButton *Peach_Player1_but;
    irr::gui::IGUIButton *Peach_Player2_but;
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
    character _character;
};


#endif
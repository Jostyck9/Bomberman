/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Play.cpp
*/

#include <iostream>
#include "Play.hpp"
#include "Game.hpp"

Play::Play(irr::IrrlichtDevice* device, MyEventReceiver &receiver, Sound sound) : AScene(device, receiver), _sound(sound)
{
    guienv = device->getGUIEnvironment();
    Camera camera(device->getSceneManager(), irr::core::vector3df(-2.1, 1, 3.2), irr::core::vector3df(0, 0, 0));
    menu_play = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Engine_Room/room.obj"));
    menu_play->setRotation(core::vector3df(0,-34,0));
    menu_play->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    button();
    Mesh();
}

Play::~Play()
{
    start_game->remove();
    Mario->remove();
    Luigi->remove();
    Toad->remove();
    Peach->remove();
    menu_play->remove();
    _sound.stopMe();
    if (_character.Mario == 0)
        Mario_Player1_but->remove();
    if (_character.Mario == 1)
        Mario_Player2_but->remove();
    if (_character.Mario == 2)
        Mario_IA_but->remove();
    if (_character.Luigi == 0)
        Luigi_Player1_but->remove();
    if (_character.Luigi == 1)
        Luigi_Player2_but->remove();
    if (_character.Luigi == 2)
        Luigi_IA_but->remove();
    if (_character.Toad == 0)
        Toad_Player1_but->remove();
    if (_character.Toad == 1)
        Toad_Player2_but->remove();
    if (_character.Toad == 2)
        Toad_IA_but->remove();
    if (_character.Peach == 0)
        Peach_Player1_but->remove();
    if (_character.Peach == 1)
        Peach_Player2_but->remove();
    if (_character.Peach == 2)
        Peach_IA_but->remove();
}

IScene* Play::update()
{
    IScene *next = NULL;
    irr::s32 id = -1;

    if (!_device->run()) {
        delete this;
        return (nullptr);
    }

    id = _events.getButtonPressed();
    switch(id) {
        // case GUI_RETURN_PLAY:
        //     next = new Menu(this->_device, this->_events, _background);
        //     delete this;
        //     return (next);

        case GUI_START_GAME:
            next = new Game(this->_device, this->_events, _character);
            delete this;
            return (next);

        case GUI_Mario_IA:
            Mario_IA_but->remove();
            Mario_Player1();
            break;

        case GUI_Mario_Player1:
            Mario_Player1_but->remove();
            Mario_Player2();
            break;

        case GUI_Mario_Player2:
            Mario_Player2_but->remove();
            Mario_IA();
            break;
        
        case GUI_Luigi_IA:
            Luigi_IA_but->remove();
            Luigi_Player1();
            break;

        case GUI_Luigi_Player1:
            Luigi_Player1_but->remove();
            Luigi_Player2();
            break;

        case GUI_Luigi_Player2:
            Luigi_Player2_but->remove();
            Luigi_IA();
            break;

        case GUI_Toad_IA:
            Toad_IA_but->remove();
            Toad_Player1();
            break;

        case GUI_Toad_Player1:
            Toad_Player1_but->remove();
            Toad_Player2();
            break;

        case GUI_Toad_Player2:
            Toad_Player2_but->remove();
            Toad_IA();
            break;
        
        case GUI_Peach_IA:
            Peach_IA_but->remove();
            Peach_Player1();
            break;

        case GUI_Peach_Player1:
            Peach_Player1_but->remove();
            Peach_Player2();
            break;

        case GUI_Peach_Player2:
            Peach_Player2_but->remove();
            Peach_IA();
            break;

        default:
            break;
    }
    _events.resetKeys();
    return (this);
}

void Play::display()
{
    if (!_device->run()) {
        return;
    }
    _driver->beginScene(true, true, video::SColor(255,100,101,140));
    _sceneManager->drawAll();
    guienv->drawAll();
    _driver->endScene();
}

void Play::Mesh()
{
    Mario = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Mario/mario.b3d"));
    Mario->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Mario->setPosition(core::vector3df(1,0,2.2));
    Mario->setScale(core::vector3df(0.5,0.5,0.5));
    Mario->setRotation(core::vector3df(90,145,0));

    Luigi = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Luigi/luigi.b3d"));
    Luigi->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Luigi->setPosition(core::vector3df(-0.5,0,1.5));
    Luigi->setScale(core::vector3df(0.5,0.5,0.5));
    Luigi->setRotation(core::vector3df(90,145,0));

    Toad = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Toad/toad.b3d"));
    Toad->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Toad->setPosition(core::vector3df(-1.5,0,1));
    Toad->setScale(core::vector3df(0.3,0.3,0.3));
    Toad->setRotation(core::vector3df(90,145,0));

    Peach = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Peach/peach.b3d"));
    Peach->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Peach->setPosition(core::vector3df(-2.4,0,0.4));
    Peach->setScale(core::vector3df(0.8,0.8,0.8));
    Peach->setRotation(core::vector3df(90,145,0));
}

bool Play::button()
{
    Player1_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Player1.png");
    Player2_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Player2.png");
    IA_text = this->_driver->getTexture("./assets/meshs/Menu/Button/IA.png");
    Mario_Player1_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,290,540), 0, GUI_Mario_Player1, L"");
    Mario_Player1_but->setImage(Player1_text);
    Mario_Player1_but->setScaleImage(true);
    Mario_Player1_but->setUseAlphaChannel(true);
    Mario_Player1_but->setDrawBorder(0);
    Luigi_Player2_but = guienv->addButton(irr::core::rect<irr::s32>(480,500,620,540), 0, GUI_Luigi_Player2, L"");
    Luigi_Player2_but->setImage(Player2_text);
    Luigi_Player2_but->setScaleImage(true);
    Luigi_Player2_but->setUseAlphaChannel(true);
    Luigi_Player2_but->setDrawBorder(0);
    Toad_IA_but = guienv->addButton(irr::core::rect<irr::s32>(740,500,840,560), 0, GUI_Toad_IA, L"");
    Toad_IA_but->setImage(IA_text);
    Toad_IA_but->setScaleImage(true);
    Toad_IA_but->setUseAlphaChannel(true);
    Toad_IA_but->setDrawBorder(0);
    Peach_IA_but = guienv->addButton(irr::core::rect<irr::s32>(1000,500,1100,560), 0, GUI_Peach_IA, L"");
    Peach_IA_but->setImage(IA_text);
    Peach_IA_but->setScaleImage(true);
    Peach_IA_but->setUseAlphaChannel(true);
    Peach_IA_but->setDrawBorder(0);
    but_start_game = this->_driver->getTexture("./assets/meshs/Menu/Button/start_game.png");
    but_start_game_pressed = this->_driver->getTexture("./assets/meshs/Menu/Button/start_game_pressed.png");
    start_game = guienv->addButton(irr::core::rect<irr::s32>(500,650,730,710), 0, GUI_START_GAME, L"");
    start_game->setImage(but_start_game);
    start_game->setScaleImage(true);
    start_game->setUseAlphaChannel(true);
    start_game->setDrawBorder(0);
    start_game->setPressedImage(but_start_game_pressed);
    _character.Mario = _character.Player1;
    _character.Luigi = _character.Player2;
    _character.Toad = _character.IA;
    _character.Peach = _character.IA;
    return (true);
}

void Play::Mario_IA()
{
    IA_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Mario_IA.png");
    Mario_IA_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,250,560), 0, GUI_Mario_IA, L"");
    Mario_IA_but->setImage(IA_text);
    Mario_IA_but->setScaleImage(true);
    Mario_IA_but->setUseAlphaChannel(true);
    Mario_IA_but->setDrawBorder(0);
    _character.Mario = _character.IA;
}

void Play::Mario_Player1()
{
    Player1_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Mario_Player1.png");
    Mario_Player1_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,290,540), 0, GUI_Mario_Player1, L"");
    Mario_Player1_but->setImage(Player1_text);
    Mario_Player1_but->setScaleImage(true);
    Mario_Player1_but->setUseAlphaChannel(true);
    Mario_Player1_but->setDrawBorder(0);
    _character.Mario = _character.Player1;
}

void Play::Mario_Player2()
{
    Player2_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Mario_Player2.png");
    Mario_Player2_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,290,540), 0, GUI_Mario_Player2, L"");
    Mario_Player2_but->setImage(Player2_text);
    Mario_Player2_but->setScaleImage(true);
    Mario_Player2_but->setUseAlphaChannel(true);
    Mario_Player2_but->setDrawBorder(0);
    _character.Mario = _character.Player2;
}

void Play::Luigi_IA()
{
    IA_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Luigi_IA.png");
    Luigi_IA_but = guienv->addButton(irr::core::rect<irr::s32>(480,500,580,560), 0, GUI_Luigi_IA, L"");
    Luigi_IA_but->setImage(IA_text);
    Luigi_IA_but->setScaleImage(true);
    Luigi_IA_but->setUseAlphaChannel(true);
    Luigi_IA_but->setDrawBorder(0);
    _character.Luigi = _character.IA;
}

void Play::Luigi_Player1()
{
    Player1_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Luigi_Player1.png");
    Luigi_Player1_but = guienv->addButton(irr::core::rect<irr::s32>(480,500,620,540), 0, GUI_Luigi_Player1, L"");
    Luigi_Player1_but->setImage(Player1_text);
    Luigi_Player1_but->setScaleImage(true);
    Luigi_Player1_but->setUseAlphaChannel(true);
    Luigi_Player1_but->setDrawBorder(0);
    _character.Luigi = _character.Player1;
}

void Play::Luigi_Player2()
{
    Player2_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Luigi_Player2.png");
    Luigi_Player2_but = guienv->addButton(irr::core::rect<irr::s32>(480,500,620,540), 0, GUI_Luigi_Player2, L"");
    Luigi_Player2_but->setImage(Player2_text);
    Luigi_Player2_but->setScaleImage(true);
    Luigi_Player2_but->setUseAlphaChannel(true);
    Luigi_Player2_but->setDrawBorder(0);
    _character.Luigi = _character.Player2;
}

void Play::Toad_IA()
{
    IA_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Toad_IA.png");
    Toad_IA_but = guienv->addButton(irr::core::rect<irr::s32>(740,500,840,560), 0, GUI_Toad_IA, L"");
    Toad_IA_but->setImage(IA_text);
    Toad_IA_but->setScaleImage(true);
    Toad_IA_but->setUseAlphaChannel(true);
    Toad_IA_but->setDrawBorder(0);
    _character.Toad = _character.IA;
}

void Play::Toad_Player1()
{
    Player1_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Toad_Player1.png");
    Toad_Player1_but = guienv->addButton(irr::core::rect<irr::s32>(740,500,880,540), 0, GUI_Toad_Player1, L"");
    Toad_Player1_but->setImage(Player1_text);
    Toad_Player1_but->setScaleImage(true);
    Toad_Player1_but->setUseAlphaChannel(true);
    Toad_Player1_but->setDrawBorder(0);
    _character.Toad = _character.Player1;
}

void Play::Toad_Player2()
{
    Player2_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Toad_Player2.png");
    Toad_Player2_but = guienv->addButton(irr::core::rect<irr::s32>(740,500,880,540), 0, GUI_Toad_Player2, L"");
    Toad_Player2_but->setImage(Player2_text);
    Toad_Player2_but->setScaleImage(true);
    Toad_Player2_but->setUseAlphaChannel(true);
    Toad_Player2_but->setDrawBorder(0);
    _character.Toad = _character.Player2;
}


void Play::Peach_IA()
{
    IA_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Peach_IA.png");
    Peach_IA_but = guienv->addButton(irr::core::rect<irr::s32>(1000,500,1100,560), 0, GUI_Peach_IA, L"");
    Peach_IA_but->setImage(IA_text);
    Peach_IA_but->setScaleImage(true);
    Peach_IA_but->setUseAlphaChannel(true);
    Peach_IA_but->setDrawBorder(0);
    _character.Peach = _character.IA;
}

void Play::Peach_Player1()
{
    Player1_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Peach_Player1.png");
    Peach_Player1_but = guienv->addButton(irr::core::rect<irr::s32>(1000,500,1140,540), 0, GUI_Peach_Player1, L"");
    Peach_Player1_but->setImage(Player1_text);
    Peach_Player1_but->setScaleImage(true);
    Peach_Player1_but->setUseAlphaChannel(true);
    Peach_Player1_but->setDrawBorder(0);
    _character.Peach = _character.Player1;
}

void Play::Peach_Player2()
{
    Player2_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Peach_Player2.png");
    Peach_Player2_but = guienv->addButton(irr::core::rect<irr::s32>(1000,500,1140,540), 0, GUI_Peach_Player2, L"");
    Peach_Player2_but->setImage(Player2_text);
    Peach_Player2_but->setScaleImage(true);
    Peach_Player2_but->setUseAlphaChannel(true);
    Peach_Player2_but->setDrawBorder(0);
    _character.Peach = _character.Player2;
}
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Play.cpp
*/

#include "Play.hpp"
#include "Game.hpp"

Play::Play(irr::IrrlichtDevice* device, MyEventReceiver &receiver) : AScene(device, receiver)
{
    guienv = device->getGUIEnvironment();
    Camera camera(device->getSceneManager(), irr::core::vector3df(-2.1, 1, 3.2), irr::core::vector3df(0, 0, 0));
    menu_play = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Engine_Room/room.obj"));
    menu_play->setRotation(core::vector3df(0,-34,0));
    menu_play->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    //background_play();
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
    // camera_play->remove();
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
            next = new Game(this->_device, this->_events);
            delete this;
            return (next);

        case GUI_IA:
            IA_but->remove();
            Player1();
            break;

        case GUI_Player1:
            Player1_but->remove();
            Player2();
            break;

        case GUI_Player2:
            Player2_but->remove();
            IA();
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

void Play::IA()
{
    IA_text = this->_driver->getTexture("./assets/meshs/Menu/Button/IA.png");
    IA_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,290,540), 0, GUI_IA, L"");
    IA_but->setImage(IA_text);
    IA_but->setScaleImage(true);
    IA_but->setUseAlphaChannel(true);
    IA_but->setDrawBorder(0);
}

void Play::Player1()
{
    Player1_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Player1.png");
    Player1_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,290,540), 0, GUI_Player1, L"");
    Player1_but->setImage(Player1_text);
    Player1_but->setScaleImage(true);
    Player1_but->setUseAlphaChannel(true);
    Player1_but->setDrawBorder(0);
}

void Play::Player2()
{
    Player2_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Player2.png");
    Player2_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,290,540), 0, GUI_Player2, L"");
    Player2_but->setImage(Player2_text);
    Player2_but->setScaleImage(true);
    Player2_but->setUseAlphaChannel(true);
    Player2_but->setDrawBorder(0);
}

void Play::Mesh()
{
    Mario = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Mario/mario.b3d"));
    Mario->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Mario->setPosition(core::vector3df(1,0,2.2));
    Mario->setScale(core::vector3df(0.5,0.5,0.5));
    Mario->setRotation(core::vector3df(0,145,0));

    Luigi = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Luigi/luigi.b3d"));
    Luigi->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Luigi->setPosition(core::vector3df(-0.5,0,1.5));
    Luigi->setScale(core::vector3df(0.5,0.5,0.5));
    Luigi->setRotation(core::vector3df(0,145,0));

    Toad = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Toad/Toad.b3d"));
    Toad->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Toad->setPosition(core::vector3df(-1.5,0,1));
    Toad->setScale(core::vector3df(0.3,0.3,0.3));
    Toad->setRotation(core::vector3df(0,145,0));

    Peach = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Peach/pitchv2.b3d"));
    Peach->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    Peach->setPosition(core::vector3df(-2.4,0,0.4));
    Peach->setScale(core::vector3df(0.8,0.8,0.8));
    Peach->setRotation(core::vector3df(0,145,0));
}

bool Play::button()
{
    Player1_text = this->_driver->getTexture("./assets/meshs/Menu/Button/Player1.png");
    Player1_but = guienv->addButton(irr::core::rect<irr::s32>(150,500,290,540), 0, GUI_Player1, L"");
    Player1_but->setImage(Player1_text);
    Player1_but->setScaleImage(true);
    Player1_but->setUseAlphaChannel(true);
    Player1_but->setDrawBorder(0);
    return_texture = this->_driver->getTexture("./assets/meshs/Menu/Button/Return.png");
    but_start_game = this->_driver->getTexture("./assets/meshs/Menu/Button/Start.png");
    // return_menu = guienv->addButton(irr::core::rect<irr::s32>(20,20,160,60), 0, GUI_RETURN_PLAY, L"");
    // return_menu->setImage(return_texture);
    // return_menu->setScaleImage(true);
    // return_menu->setUseAlphaChannel(true);
    // return_menu->setDrawBorder(0);
    start_game = guienv->addButton(irr::core::rect<irr::s32>(550,650,730,710), 0, GUI_START_GAME, L"");
    start_game->setImage(but_start_game);
    start_game->setScaleImage(true);
    start_game->setUseAlphaChannel(true);
    start_game->setDrawBorder(0);
    return (true);
}

// void Play::background_play()
// {
//     camera_play = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 3, -5), irr::core::vector3df(0,0,0));
    
// }
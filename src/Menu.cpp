/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.cpp
*/

#include <iostream>
#include "driverChoice.h"
#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice* device) : AScene(device, _events)
{
    Camera camera(device->getSceneManager(), irr::core::vector3df(-100, -130, 90), irr::core::vector3df(0, 0, 0));
    guienv = device->getGUIEnvironment();
    
    createBackGround();
    button();
    this->setCamera(camera);
    //setSkin();
}

IScene* Menu::update()
{
    if (!_device->run()) {
        delete this;
        return (nullptr);
    }
    return (this);
}

IScene* Menu::handleEvent()
{
    return (this);
}

void Menu::createBackGround()
{
    // std::vector<std::string> texture;
    // irr::video::IVideoDriver* driver = _device->getVideoDriver();
    scene::ISceneNode* cam = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(100, 150, 400), irr::core::vector3df(20,30,500));
    scene::IAnimatedMeshSceneNode * menu_map = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/World 1/World 1 map.obj"));
    scene::IAnimatedMeshSceneNode* anms = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/meshs/Bomb/ItmBombhei.obj"));
    anms->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    anms->setPosition(core::vector3df(0,0,0));

    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/background.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/bridgeA.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/bridgeB.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/brock_w42.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/bushA.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/bushB.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/cannon.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/faultA.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/faultB.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/flower.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/groundA.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/groundB.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/groundC.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/mat_move0A.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/mat_move0B.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/mat_move10.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/mat_move11.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/m_waterB.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/m_waterC.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/m_waterZ.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/peachC_P.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/plant.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/sand.png");
    // texture.push_back("/home/fgru/TEK2/Projet/Indie/Bomberman/assets/meshs/World 1/shadow1.png");
    // for (irr::u16 i = 0; i < texture.size(); i++)
    //     menu_map->setMaterialTexture(i, driver->getTexture(texture[i].c_str()));
    // menu_map->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    scene::ISceneNodeAnimator* anim =
            _sceneManager->createFlyCircleAnimator(core::vector3df(0,0,30), 20.0f);
        if (anim)
        {
            cam->addAnimator(anim);
            anim->drop();
        }
}

void Menu::display()
{
    if (!_device->run()) {
        return;
    }
    _driver->beginScene(true, true, video::SColor(255,100,101,140));
    _sceneManager->drawAll();
    guienv->drawAll();
    _driver->endScene();
}

bool Menu::button()
{
    irr::gui::IGUIButton *play = guienv->addButton(irr::core::rect<irr::s32>(280,30,370,50), 0, GUI_PLAY, L"Play");
    irr::gui::IGUIButton *load = guienv->addButton(irr::core::rect<irr::s32>(280,70,370,90), 0, GUI_LOAD, L"Load");
    irr::gui::IGUIButton *settings = guienv->addButton(irr::core::rect<irr::s32>(280,110,370,130), 0, GUI_SETTINGS, L"Settings");
    irr::gui::IGUIButton *how_play = guienv->addButton(irr::core::rect<irr::s32>(280,150,370,170), 0, GUI_HOW_TO_PLAY, L"How To Play");
    irr::gui::IGUIButton *scoreboard = guienv->addButton(irr::core::rect<irr::s32>(280,190,370,210), 0, GUI_SCOREBOARD, L"Scoreboard");
    irr::gui::IGUIButton *quit = guienv->addButton(irr::core::rect<irr::s32>(280,230,370,250), 0, GUI_QUIT, L"Quit");
    return (true);
}

void Menu::play()
{
}

IScene* Menu::quit()
{
    delete(this);
    return(NULL);
}

// void Menu::setSkin(s32 alpha, irr::gui::IGUISkin * skin)
// {
//     guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_WINDOW);
//     guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_BUTTON);
//     guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_DEFAULT); //Font des Textes
//     guienv->getSkin()->setFont(guienv->(""), irr::gui::EGDF_MENU);
//     for (s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
// 	{
// 		video::SColor col = skin->getColor((EGUI_DEFAULT_COLOR)i);
// 		col.setAlpha(alpha);
// 		skin->setColor((EGUI_DEFAULT_COLOR)i, col);
// 	}
// }
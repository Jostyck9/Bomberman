/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** background.hpp
*/

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "irrlicht/irrlicht.h"
#include "AScene.hpp"

class Background : public AScene
{
    public:
    Background(irr::IrrlichtDevice* device, MyEventReceiver &receiver);
    ~Background();
    void createBackGround();
    IScene* update() override;
    void display() override;


    private:
    scene::ISceneNode* camera;
    scene::IAnimatedMeshSceneNode * menu_map;
    scene::IAnimatedMeshSceneNode* anms;
};

#endif
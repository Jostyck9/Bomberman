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
    void createBackGround();
    IScene* update() override;
    void display() override;


    private:
    irr::video::ITexture *image;
    scene::ISceneNode* camera;
};

#endif
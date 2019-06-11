/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** AScene.hpp
*/

#ifndef ASCENE_HPP
#define ASCENE_HPP

#include "IScene.hpp"
#include "Camera.hpp"
#include "MyEventReceiver.hpp"

class AScene : public IScene
{
protected:
    irr::IrrlichtDevice* _device;
    irr::scene::ISceneManager* _sceneManager;
    irr::video::IVideoDriver* _driver;
    Camera _camera;
    MyEventReceiver &_events;

public:
    AScene(irr::IrrlichtDevice* device, MyEventReceiver &_events);
    AScene(irr::IrrlichtDevice* device, MyEventReceiver &_events, Camera &camera);
    const Camera &getCamera();
    void setCamera(Camera &camera); 
};

#endif

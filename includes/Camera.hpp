/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Camera.hpp
*/

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <irrlicht/irrlicht.h>

class Camera
{
private:
    irr::scene::ISceneManager *_smgr;
    irr::core::vector3df _cameraPosition;
    irr::core::vector3df _cameraPointMire;
    irr::scene::ICameraSceneNode *_camera;

public:
    Camera(irr::scene::ISceneManager *smgr, irr::core::vector3df _cameraPosition = irr::core::vector3df(0, 0, 0), irr::core::vector3df _cameraPointMire = irr::core::vector3df(0, 0, 0));
    const irr::core::vector3df& getCameraPosition();
    const irr::core::vector3df& getCameraMirePoint();
    void setCameraPosition(irr::core::vector3df &);
    void setCameraMirePoint(irr::core::vector3df &);
};

#endif

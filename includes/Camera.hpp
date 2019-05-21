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
    irr::core::vector3df _cameraPosition;
    irr::core::vector3df _cameraPointMire;

public:
    Camera();
    Camera(irr::core::vector3df _cameraPosition, irr::core::vector3df _cameraPointMire);
    const irr::core::vector3df& getCameraPosition();
    const irr::core::vector3df& getCameraMirePoint();
};

#endif

/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

Camera::Camera(void)
{
}

Camera::Camera(irr::core::vector3df cameraPosition, irr::core::vector3df cameraPointMire) : _cameraPosition(cameraPosition), _cameraPointMire(cameraPointMire)
{
}

const irr::core::vector3df& Camera::getCameraPosition()
{
    return (this->_cameraPosition);
}

const irr::core::vector3df& Camera::getCameraMirePoint()
{
    return (this->_cameraPointMire);
}

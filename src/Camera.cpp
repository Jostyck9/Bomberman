/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

Camera::Camera(irr::scene::ISceneManager *smgr, irr::core::vector3df cameraPosition, irr::core::vector3df cameraPointMire) : _smgr(smgr), _cameraPosition(cameraPosition), _cameraPointMire(cameraPointMire)
{
    smgr->addCameraSceneNode(0, cameraPosition, cameraPointMire);
}

const irr::core::vector3df& Camera::getCameraPosition()
{
    return (this->_cameraPosition);
}

const irr::core::vector3df& Camera::getCameraMirePoint()
{
    return (this->_cameraPointMire);
}

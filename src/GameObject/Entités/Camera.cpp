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
    _camera = smgr->getActiveCamera();
}

Camera::Camera()
{
}

const irr::core::vector3df &Camera::getCameraPosition() const
{
    return (this->_cameraPosition);
}

const irr::core::vector3df &Camera::getCameraMirePoint() const
{
    return (this->_cameraPointMire);
}

void Camera::setCameraPosition(irr::core::vector3df &position)
{
    _cameraPosition = position;
    _camera->setPosition(position);
}

void Camera::setCameraMirePoint(irr::core::vector3df &point)
{
    _cameraPointMire = point;
    _camera->setTarget(point);
}
/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** AScene.cpp
*/

#include <iostream>
#include "AScene.hpp"

AScene::AScene(irr::IrrlichtDevice* device, Camera &camera) : _device(device), _sceneManager(nullptr), _driver(nullptr), _camera(camera)
{
    if (_device) {
        _sceneManager = _device->getSceneManager();
        if (_sceneManager) {
            _sceneManager->addCameraSceneNode(0, _camera.getCameraPosition(), _camera.getCameraMirePoint());
        }
        _driver = _device->getVideoDriver();
        _device->setEventReceiver(&_events);
    }
}

AScene::AScene(irr::IrrlichtDevice* device) : _device(device), _sceneManager(nullptr), _driver(nullptr), _camera(_device->getSceneManager())
{
    if (_device) {
        _sceneManager = _device->getSceneManager();
        _driver = _device->getVideoDriver();
    }
}

void AScene::setCamera(Camera &camera)
{
    irr::scene::ICameraSceneNode *current = nullptr;

    _camera = camera;
    if (_sceneManager) {
        current = _sceneManager->getActiveCamera();
        if (!current) {
            _sceneManager->addCameraSceneNode(0, _camera.getCameraPosition(), _camera.getCameraMirePoint());
        } else {
            current->setPosition(_camera.getCameraPosition());
            current->setTarget(_camera.getCameraMirePoint());
            // irr::core::vector3df position = current->getTarget();
            // std::cout << "x : " << position.X << " y : " << position.Y << " z : " << position.Z << std::endl;
        }
    }
}

const Camera &AScene::getCamera()
{
    return (this->_camera);
}
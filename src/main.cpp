/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** main.cpp
*/

#include <iostream>
#include <memory>
#include "Game.hpp"
#include "Sound.hpp"

int main(void)
{
    MyEventReceiver receiver;

    //open a window
    IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720), 16, false, false, false, &receiver);
    if (!device)
        return (84);
    IScene *scene(new Game(device, receiver));
    if (!scene) {
        device->drop();
        return (84);
    }
    device->setWindowCaption(L"BomberMario");
    while (scene) {
        scene->display();
        scene = scene->handleEvent();
        if (!scene)
            break;
        scene = scene->update();
    }
    device->drop();
    return (0);
}
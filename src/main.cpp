/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** main.cpp
*/

#include <iostream>
#include <memory>
#include <iostream>
#include "Menu.hpp"
#include "background.hpp"
#include "settings.hpp"
#include "Sound.hpp"

int main(void)
{
    MyEventReceiver receiver;

    //open a window
    IrrlichtDevice *device = createDevice(video::EDT_OPENGL, core::dimension2d<u32>(1280, 720), 16, false, false, false, &receiver);
    if (!device)
        return (84);
    IScene *back(new Background(device, receiver));
    IScene *scene(new Menu(device, receiver, back));
    if (!scene) {
        device->drop();
        return (84);
    }
    device->setWindowCaption(L"BomberMario");
    while (scene) {
        scene->display();
        if (!scene)
            break;
        scene = scene->update();
    }
    device->drop();
    return (0);
}
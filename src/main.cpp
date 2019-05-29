/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** main.cpp
*/

#include "Menu.hpp"

int main(void)
{
    MyEventReceiver receiver;

    //open a window
    IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE, core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
    if (!device)
        return (84);
    IScene *scene = new Menu(device);
    if (!scene) {
        device->drop();
        return (84);
    }

    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
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
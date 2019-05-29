/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "Camera.hpp"
#include "Map.hpp"
#include "AScene.hpp"

class Menu : public AScene
{
private:
    Map _map;

public:
    Menu(irr::IrrlichtDevice* device);
    IScene* update() override;
    IScene* handleEvent() override;
    void display() override;
};

#endif

/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Game.hpp
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "Camera.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "AScene.hpp"

class Game : public AScene
{
private:
    Map _map;

public:
    Game(irr::IrrlichtDevice* device);
    IScene* update() override;
    IScene* handleEvent() override;
    void display() override;
};

#endif

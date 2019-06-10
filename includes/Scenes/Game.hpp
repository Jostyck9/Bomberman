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
    void updateObj(GameObject *obj);
    void updateMapFromPlayer(Player *current);

public:
    Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver);
    IScene* update() override;
    IScene* handleEvent() override;
    void display() override;
};

#endif

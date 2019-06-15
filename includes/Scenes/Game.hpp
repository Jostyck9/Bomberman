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
#include "Decor.hpp"
#include "Sound.hpp"

class Game : public AScene
{
private:
    Decor _ground;
    Map _map;
    Sound sound;
    void deleteObj(std::vector<irr::s32> &idToDel);
    void updateObj(std::shared_ptr<GameObject> obj, std::vector<irr::s32> &idToDel, std::vector<irr::s32> &idToMove);
    void updateMapFromPlayer(std::shared_ptr<Player> current);
    void updatePosition(std::vector<irr::s32> &idToMove);

public:
    Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver);
    IScene* update() override;
    void display() override;
};

#endif

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
#include "Play.hpp"

class Game : public AScene
{
private:
    Decor _ground;
    Map _map;
    Sound _sound;
    void deleteObj(std::vector<irr::s32> &idToDel);
    void updateObj(std::shared_ptr<GameObject> obj, std::vector<irr::s32> &idToDel, std::vector<irr::s32> &idToMove);
    void updateMapFromPlayer(std::shared_ptr<ACharacter> current);
    void updatePosition(std::vector<irr::s32> &idToMove);
    irr::core::vector2df worldToMap(irr::s16 x, irr::s16 y, irr::u16 size);

public:
    Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, character character = {1, 1, 1, 1});
    Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, std::string save = "");
    ~Game();
    IScene* update() override;
    void display() override;
};

#endif

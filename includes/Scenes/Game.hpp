/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** Game.hpp
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "MapWrapper.hpp"
#include "Camera.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "AScene.hpp"
#include "Decor.hpp"

class Game : public AScene
{
private:
    Decor _ground;
    Map _map;
    void addObj(std::vector<MapWrapper> &objToAdd);
    void deleteObj(std::vector<irr::s32> &idToDel);
    void updateObj(std::shared_ptr<GameObject> obj, std::vector<irr::s32> &idToDel, std::vector<irr::s32> &idToMove, std::vector<MapWrapper> &objToAdd);
    void updateMapFromPlayer(std::shared_ptr<ACharacter> current);
    void updatePosition(std::vector<irr::s32> &idToMove);
    irr::core::vector2df worldToMap(irr::s16 x, irr::s16 y, irr::u16 size);

public:
    Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, std::string save = "");
    IScene* update() override;
    IScene* handleEvent() override;
    void display() override;
};

#endif

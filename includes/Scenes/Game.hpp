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
#include "Sound.hpp"
#include "Play.hpp"

class Game : public AScene
{
private:
    Decor _ground;
    Map _map;
    Sound _sound;
    Sound &_menu;
    std::vector<std::shared_ptr<Decor>> _allDecors;

    void deleteObj(std::vector<irr::s32> &idToDel);
    void addObj(std::vector<MapWrapper> &objs);
    void updateObj(std::shared_ptr<GameObject> obj, std::vector<irr::s32> &idToDel, std::vector<irr::s32> &idToMove, std::vector<MapWrapper> &objToAdd);
    void updateMapFromPlayer(std::shared_ptr<ACharacter> current);
    void updatePosition(std::vector<irr::s32> &idToMove);
    irr::core::vector2df worldToMap(irr::s16 x, irr::s16 y, irr::u16 size);
    void creationOfDecor();

public:
    Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, Sound &sound, character character = {1, 1, 1, 1});
    Game(irr::IrrlichtDevice* device, MyEventReceiver &receiver, Sound &sound, std::string save = "");
    ~Game();
    IScene* update() override;
    void display() override;
};

#endif

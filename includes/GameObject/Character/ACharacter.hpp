/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** ACharacter.hpp
*/

#ifndef ACHARACTER_HPP
#define ACHARACTER_HPP

#include "PrintableObject.hpp"
#include "PlayerController.hpp"
#include "CharacterStats.hpp"
#include "Score.hpp"
#include "Life.hpp"
#include "Map.hpp"
#include "Sound.hpp"

class ACharacter : public PrintableObject
{
private:
    CharacterStats _stats;
    Score _score;
    Life _life;
    PlayerController _controller;
    Sound _sound;

public:
    ACharacter(irr::IrrlichtDevice* device);
    virtual ~ACharacter() = default;

    CharacterStats &getStats();
    Sound &getSound();
    Score &getScore();
    Life &getLife();
    PlayerController &getPlayerController();
    void applyDammage(std::vector<irr::s32> &idToDel, irr::s16 dammage);
    virtual void update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, MyEventReceiver event = MyEventReceiver()) = 0;

    GameObject::objecType_t getType();
};

#endif

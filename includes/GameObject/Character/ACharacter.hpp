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

class ACharacter : public PrintableObject
{

public:

    enum character_s {
        luigi,
        mario,
        peach,
        toad,
        UNKNOWN
    };
    typedef character_s character_t;

    ACharacter(irr::IrrlichtDevice* device, character_t character);
    virtual ~ACharacter() = default;

    CharacterStats &getStats();
    Score &getScore();
    Life &getLife();
    PlayerController &getPlayerController();
    void applyDammage(std::vector<irr::s32> &idToDel, irr::s16 dammage);
    virtual void update(Map &map, std::vector<irr::s32> &idToDel, std::vector<MapWrapper> &objToAdd, MyEventReceiver event = MyEventReceiver()) = 0;
    character_t getCharacter() const;
    GameObject::objecType_t getType();

private:
    CharacterStats _stats;
    Score _score;
    Life _life;
    PlayerController _controller;
    character_t _character;
};

#endif

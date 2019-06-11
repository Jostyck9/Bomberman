/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** BombUp.hpp
*/

#ifndef BOMBUP_HPP
#define BOMBUP_HPP

#include "AItem.hpp"

class BombUp : public AItem
{
public:
    BombUp(irr::IrrlichtDevice* device);
    ~BombUp() = default;
    bool applyEffect(ACharacter& player) override;
    GameObject::objecType_t getType() override;
};

#endif

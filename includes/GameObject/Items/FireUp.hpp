/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** FireUp.hpp
*/

#ifndef FIREUP_HPP
#define FIREUP_HPP

#include "AItem.hpp"

class FireUp : public AItem
{
public:
    FireUp(irr::IrrlichtDevice* device, irr::u16 pos_x, irr::u16 pos_y);
    ~FireUp() = default;
    bool applyEffect(ACharacter& player) override;
    GameObject::objecType_t getType() override;
};

#endif

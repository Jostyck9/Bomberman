/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** AItem.hpp
*/

#ifndef AITEM_HPP
#define AITEM_HPP

#include <ACharacter.hpp>

class AItem : public PrintableObject
{
public:
    AItem(irr::IrrlichtDevice* device);
    virtual bool applyEffect(ACharacter& player) = 0;
};

#endif

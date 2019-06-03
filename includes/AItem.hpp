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
    virtual bool applyEffect(ACharacter& player) = 0;
};

#endif

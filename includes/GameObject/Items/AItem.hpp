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
private:
    irr::core::vector3df _posWorld;
    irr::core::vector3df _posMap;
public:
    AItem(irr::IrrlichtDevice* device);
    virtual bool applyEffect(ACharacter& player) = 0;

    irr::core::vector3df getPosWorld();
    irr::core::vector3df getPosMap();

    irr::core::vector3df setPosWorld(irr::core::vector3df);
    irr::core::vector3df setPosMap(irr::core::vector3df);
};

#endif

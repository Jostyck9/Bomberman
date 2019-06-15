/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Explosion.hpp
*/

#ifndef EXPLOSION_HPP_
#define EXPLOSION_HPP_

#include "PrintableObject.hpp"

class Explosion : public PrintableObject
{
private:
public:
    Explosion(irr::IrrlichtDevice *device, irr::u16 x, irr::u16 y);
    ~Explosion();

    GameObject::objecType_t getType() override;
};

#endif // !EXPLOSION_HPP_
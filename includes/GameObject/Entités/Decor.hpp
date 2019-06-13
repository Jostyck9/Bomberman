/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Decor.hpp
*/

#ifndef DECOR_HPP_
#define DECOR_HPP_

#include <string>
#include "PrintableObject.hpp"

class Decor : public PrintableObject
{
public:
    Decor(irr::IrrlichtDevice* device, std::string mesh, irr::core::vector3df pos = irr::core::vector3df(0, 0, 0), irr::core::vector3df rotation = irr::core::vector3df(0, 0, 0), irr::core::vector3df scale = irr::core::vector3df(1, 1, 1));
    ~Decor();

    void addColision();
    void setScale(irr::core::vector3df scale);
    void setPosition(irr::core::vector3df position);
    void setRotation(irr::core::vector3df rotation);
};

#endif // !DECOR_HPP_
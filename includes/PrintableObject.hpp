/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** PrintableObject.hpp
*/

#ifndef PRINTABLE_OBJECT_HPP_
#define PRINTABLE_OBJECT_HPP_

#include "GameObject.hpp"
#include "GraphicalElements.hpp"

class PrintableObject : public GameObject
{
private:
    GraphicalElements _displayInfo;

public:
    PrintableObject(irr::core::vector3df position = irr::core::vector3df(0, 0, 0));

    ~PrintableObject();

    GameObject::objecType_t getType();

protected:
    GraphicalElements &getDisplayInfo();
};

#endif // !PRINTABLE_OBJECT_HPP_
/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GameObject.hpp
*/

#ifndef BOMBERMAN_GAMEOBJECT_HPP
#define BOMBERMAN_GAMEOBJECT_HPP

class GameObject {
public:
    enum objectType_s {
        UNKNOWN
    };
    typedef objectType_s objecType_t;

    objecType_t getType();
};

#endif //BOMBERMAN_GAMEOBJECT_HPP

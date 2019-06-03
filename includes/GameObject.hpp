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
        PRINTABLE_OBJ,
        PLAYER,
        WALL,
        BOMB,
        SPEEDUP,
        BOMBUP,
        FIREUP,
        WALLPASS,
        UNKNOWN
    };
    typedef objectType_s objecType_t;

    virtual objecType_t getType();

    virtual ~GameObject() = default;
};

#endif //BOMBERMAN_GAMEOBJECT_HPP

/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GameObject.hpp
*/

#ifndef BOMBERMAN_GAMEOBJECT_HPP
#define BOMBERMAN_GAMEOBJECT_HPP

#ifdef _WIN64
    #include <IrrlichtDevice.h>
#else
    #include <irrlicht/IrrlichtDevice.h>
#endif

class GameObject {
public:
    enum objectType_s {
        PRINTABLE_OBJ,
        ACHARACTER,
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

    GameObject(irr::IrrlichtDevice *device);
    virtual ~GameObject() = default;

private:
    irr::IrrlichtDevice *_device;
};

#endif //BOMBERMAN_GAMEOBJECT_HPP

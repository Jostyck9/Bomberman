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
private:
    irr::s32 _id;

public:
    enum objectType_s {
        PRINTABLE_OBJ,
        ACHARACTER,
        PLAYER,
        NONPLAYER,
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

    irr::s32 getID();

protected:
    irr::IrrlichtDevice *_device;
};

#endif //BOMBERMAN_GAMEOBJECT_HPP

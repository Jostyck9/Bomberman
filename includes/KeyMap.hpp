/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** KeyMap.hpp
*/

#ifndef KEY_MAP_HPP_
#define KEY_MAP_HPP_

#ifdef _WIN64
	#include <irrlicht.h>
#else
	#include <irrlicht/irrlicht.h>
#endif

class KeyMap
{
private:
    irr::EKEY_CODE _forward;
    irr::EKEY_CODE _backward;
    irr::EKEY_CODE _left;
    irr::EKEY_CODE _right;
    irr::EKEY_CODE _action;
    irr::EKEY_CODE _pause;

public:
    KeyMap(irr::EKEY_CODE forward = irr::KEY_KEY_Z, irr::EKEY_CODE backward = irr::KEY_KEY_S, irr::EKEY_CODE left = irr::KEY_KEY_Q, irr::EKEY_CODE right = irr::KEY_KEY_D, irr::EKEY_CODE action = irr::KEY_SPACE, irr::EKEY_CODE pause = irr::KEY_ESCAPE);
    ~KeyMap();

    irr::EKEY_CODE getForward() const;
    void setForward(irr::EKEY_CODE);

    irr::EKEY_CODE getBackward() const;
    void setBackward(irr::EKEY_CODE);

    irr::EKEY_CODE getLeft() const;
    void setLeft(irr::EKEY_CODE);

    irr::EKEY_CODE getRight() const;
    void setRight(irr::EKEY_CODE);

    irr::EKEY_CODE getAction() const;
    void setAction(irr::EKEY_CODE);

    irr::EKEY_CODE getPause() const;
    void setPause(irr::EKEY_CODE);
};

#endif // !KEY_MAP_HPP_
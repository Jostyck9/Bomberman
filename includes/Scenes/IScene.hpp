/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** IScene.hpp
*/

#ifndef ISCENE_HPP
#define ISCENE_HPP

class IScene
{
public:
    virtual ~IScene() = default;

    virtual IScene* update() = 0;
    virtual void display() = 0;
};

#endif

/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Explosion.cpp
*/

#include "Explosion.hpp"

Explosion::Explosion(irr::IrrlichtDevice *device, irr::u16 x, irr::u16 y) : PrintableObject(device)
{
    std::string path_mesh = "./assets/meshs/Strong_block/Strong_Block.b3d";
    std::vector<std::string> path_text;
    irr::core::vector3df pos_world_tmp(x * 10, y * 10, 0);

    this->getDisplayInfo().setPosition(pos_world_tmp);
    this->getDisplayInfo().setMesh(path_text, path_mesh, GameObject::objecType_t::EXPLOSION);
    this->getDisplayInfo().setScale(irr::core::vector3df(0.068,0.068,0.04));
}

Explosion::~Explosion()
{
}

GameObject::objecType_t Explosion::getType()
{
    return (GameObject::objectType_s::EXPLOSION);
}

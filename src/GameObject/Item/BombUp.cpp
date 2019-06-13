/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** BombUp.cpp
*/

#include "BombUp.hpp"
#include <iostream>

BombUp::BombUp(irr::IrrlichtDevice* device, irr::u16 pos_x, irr::u16 pos_y) : AItem(device)
{
    std::string path_mesh = "./assets/meshs/Bullet Bill/model.obj";
    std::cout << "Yolo" << std::endl;
    std::vector<std::string> path_text;
    irr::core::vector3df pos_world_tmp(pos_x * 10, (pos_y * 10) + 4, 0);
    irr::core::vector3df pos_map_tmp(pos_x, pos_y, 0);
    this->setPosWorld(pos_world_tmp);
    this->setPosMap(pos_map_tmp);
    this->getDisplayInfo().setPosition(pos_world_tmp);
    this->getDisplayInfo().setMesh(path_text, path_mesh, GameObject::objecType_t::ITEM);
    this->getDisplayInfo().setScale(irr::core::vector3df(2, 2, 2));
    this->getDisplayInfo().setRotation(irr::core::vector3df(180, 70, 170));
    this->getDisplayInfo().addColision();
}

bool BombUp::applyEffect(ACharacter &player)
{
    player.getStats().setNbrBomb(player.getStats().getNbrBomb() + 1);
    return true;
}

GameObject::objecType_t BombUp::getType()
{
    return BOMBUP;
}
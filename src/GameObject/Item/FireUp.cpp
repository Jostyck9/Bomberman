/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** FireUp.cpp
*/

#include "FireUp.hpp"

FireUp::FireUp(irr::IrrlichtDevice* device, irr::u16 pos_x, irr::u16 pos_y) : AItem(device)
{
    std::string path_mesh = "./assets/meshs/Fire Flower/Flower.obj";
    std::vector<std::string> path_text;
    path_text.push_back("./assets/meshs/Fire Flower/fire.png");
    irr::core::vector3df pos_world_tmp(pos_x, pos_y + 3, 0);
    irr::core::vector3df pos_map_tmp(pos_x / 10, pos_y / 1, 5);
    this->setPosWorld(pos_world_tmp);
    this->setPosMap(pos_map_tmp);
    this->getDisplayInfo().setPosition(pos_world_tmp);
    this->getDisplayInfo().setMesh(path_text, path_mesh, GameObject::objecType_t::ITEM);
    this->getDisplayInfo().setScale(irr::core::vector3df(0.05, 0.05, 0.05));
    this->getDisplayInfo().setRotation(irr::core::vector3df(0, 180, 0));
    this->getDisplayInfo().addColision();
}

bool FireUp::applyEffect(ACharacter &player)
{
    player.getStats().setBombRadius(player.getStats().getBombRadius() + 1);
    return true;
}

GameObject::objecType_t FireUp::getType()
{
    return FIREUP;
}
/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "WallPass.hpp"

WallPass::WallPass(irr::IrrlichtDevice* device, irr::u16 pos_x, irr::u16 pos_y) : AItem(device)
{
    std::string path_mesh = "./assets/meshs/Power_Star/Power_Star.obj";
    std::vector<std::string> path_text;
    path_text.push_back("./assets/meshs/Power_Star/power.png");
    irr::core::vector3df pos_world_tmp(pos_x * 10, pos_y * 10, 0);
    irr::core::vector3df pos_map_tmp(pos_x, pos_y, 0);
    this->setPosWorld(pos_world_tmp);
    this->setPosMap(pos_map_tmp);
    this->getDisplayInfo().setPosition(pos_world_tmp);
    this->getDisplayInfo().setMesh(path_text, path_mesh, GameObject::objecType_t::ITEM);
    this->getDisplayInfo().setScale(irr::core::vector3df(0.06, 0.06, 0.10));
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,180,0));
    this->getDisplayInfo().addColision();
}

bool WallPass::applyEffect(ACharacter &player)
{
    player.getStats().setPassThrough(true);
    return true;
}

GameObject::objecType_t WallPass::getType()
{
    return WALLPASS;
}
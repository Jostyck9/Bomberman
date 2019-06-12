/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** SpeedUp.cpp
*/

#include "WallPass.hpp"

WallPass::WallPass(irr::IrrlichtDevice* device, irr::u16 pos_x, irr::u16 pos_y) : AItem(device)
{
    std::string path_mesh = "./assets/meshs/Power Star/Power Star.obj";
    std::vector<std::string> path_text;
    path_text.push_back("./assets/meshs/Power Star/power.png");
    path_text.push_back("./assets/meshs/Power Star/shine.png");
    irr::core::vector3df pos_world_tmp(pos_x, pos_y + 5, 0);
    irr::core::vector3df pos_map_tmp(pos_x / 10, pos_y / 1, 0);
    this->setPosWorld(pos_world_tmp);
    this->setPosMap(pos_map_tmp);
    this->getDisplayInfo().setPosition(pos_world_tmp);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setScale(irr::core::vector3df(0.06, 0.06, 0.06));
    this->getDisplayInfo().setRotation(irr::core::vector3df(0,180,0));
    this->getDisplayInfo().addColision(irr::core::vector3df(2, 2, 2));
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
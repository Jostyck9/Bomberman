/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Explosion.cpp
*/

#include <memory>
#include "ACharacter.hpp"
#include "Bomb.hpp"
#include "Explosion.hpp"

Explosion::Explosion(irr::IrrlichtDevice *device, irr::u16 x, irr::u16 y) : PrintableObject(device), _index(1), _x(x), _y(y)
{
    std::string path_mesh = "./assets/meshs/Wall/Wall.b3d";
    std::vector<std::string> path_text;
    irr::core::vector3df pos_world_tmp(x * 10, y * 10, 0);

    this->getDisplayInfo().setPosition(pos_world_tmp);
    this->getDisplayInfo().setMesh(path_text, path_mesh, GameObject::objecType_t::EXPLOSION);
    this->getDisplayInfo().setScale(irr::core::vector3df(5, 5, 7));
}

Explosion::~Explosion()
{
}

GameObject::objecType_t Explosion::getType()
{
    return (GameObject::objectType_s::EXPLOSION);
}

void Explosion::updateDammage(Map &map, std::vector<irr::s32> &idToDel)
{
    std::shared_ptr<ACharacter> character = nullptr;
    std::shared_ptr<Bomb> bomb = nullptr;
    std::vector<std::shared_ptr<GameObject>> &cell = map.getCellObject(_x, _y);

    for (auto &it : cell) {
        if (it->getType() == GameObject::PLAYER || it->getType() == GameObject::NONPLAYER) {
            character = std::dynamic_pointer_cast<ACharacter>(it);
            character->applyDammage(idToDel, 1);
        } else if (it->getType() == GameObject::BOMB) {
            bomb = std::dynamic_pointer_cast<Bomb>(it);
            bomb->update(map, idToDel, true);
        } else if (it->getType() == GameObject::SPEEDUP || 
                    it->getType() == GameObject::BOMBUP || 
                    it->getType() == GameObject::FIREUP || 
                    it->getType() == GameObject::WALLPASS) {
            idToDel.push_back(it->getID());
        }
    }
}

void Explosion::update(Map &map, std::vector<irr::s32> &idToDel)
{
    double limit_max = 1;
    irr::core::vector3df scale = getDisplayInfo().getScale();

    updateDammage(map, idToDel);
    if (scale.Z > 1)
        scale.Z -= 1;
    if (!_myTimer.isTimeElapsed(limit_max)) {
        if (_myTimer.isTimeElapsed(limit_max - (limit_max / _index))) {
            getDisplayInfo().setScale(scale);
            _index++;
        }
    } else {
        idToDel.push_back(getID());
    }
}
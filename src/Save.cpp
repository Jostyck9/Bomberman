/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Save.cpp
*/

#include <fstream>
#include <iostream>
#include <algorithm>
#include <experimental/filesystem>
#include <Wall.hpp>
#include <Bomb.hpp>
#include <ACharacter.hpp>

#include "Save.hpp"

bool Save::saveGame(Map map)
{
    std::ofstream file("save.txt", std::ios::out | std::ofstream::trunc);

    file << "<size>" << map.getSize() << "</size>" << std::endl;
    for (irr::u16 i = 0; i < map.getSize(); i++) {
        for (irr::u16 j = 0; j < map.getSize(); j++) {
            file << "<cell>" << std::endl;
            file << "\t<x>" << i << "</x>" << std::endl;
            file << "\t<y>" << j << "</y>" << std::endl;
            for (irr::u16 k = 0; k < map.getMap()[i][j].size(); k++) {
                if (map.getMap()[i][j].at(k)->getType() == GameObject::WALL)
                    file << "\t\t<wall>" << dynamic_cast<Wall *>(map.getMap()[i][j].at(k))->isBreakable() << "</wall>" << std::endl;
                if (map.getMap()[i][j].at(k)->getType() == GameObject::BOMB)
                    file << "\t\t<bomb>" << dynamic_cast<Bomb *>(map.getMap()[i][j].at(k))->getRadius() << "</bomb>" << std::endl;
                if (map.getMap()[i][j].at(k)->getType() == GameObject::SPEEDUP)
                    file << "\t\t<speedup>" << "</speedup>" << std::endl;
                if (map.getMap()[i][j].at(k)->getType() == GameObject::BOMBUP)
                    file << "\t\t<bombup>" << "</bombup>" << std::endl;
                if (map.getMap()[i][j].at(k)->getType() == GameObject::FIREUP)
                    file << "\t\t<fireup>" << "</fireup>" << std::endl;
                if (map.getMap()[i][j].at(k)->getType() == GameObject::WALLPASS)
                    file << "\t\t<wallpass>" << "</wallpass>" << std::endl;
                if (map.getMap()[i][j].at(k)->getType() == GameObject::PLAYER) {
                    file << "\t\t<player>" << std::endl;
                    file << "\t\t\t<nbrbomb>" << dynamic_cast<ACharacter *>(map.getMap()[i][j].at(k))->getStats().getNbrBomb() << "</nbrbomb>" <<std::endl;
                    file << "\t\t\t<bombradius>" << dynamic_cast<ACharacter *>(map.getMap()[i][j].at(k))->getStats().getBombRadius() << "</bombradius>" <<std::endl;
                    file << "\t\t\t<passthrough>" << dynamic_cast<ACharacter *>(map.getMap()[i][j].at(k))->getStats().getPassThrough() << "</passthrough>" <<std::endl;
                    file << "\t\t\t<speed>" << dynamic_cast<ACharacter *>(map.getMap()[i][j].at(k))->getStats().getSpeed() << "</speed>" <<std::endl;
                    file << "\t\t</player>" << std::endl;
                }
            }
            file << "</cell>" << std::endl;
        }

    }
}

Map* Save::loadGame(std::string file)
{

}
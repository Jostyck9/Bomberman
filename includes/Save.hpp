/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Save.hpp
*/

#ifndef BOMBERMAN_SAVE_HPP
#define BOMBERMAN_SAVE_HPP

#include "Map.hpp"

class Save
{
public:
    Save() = default;
    ~Save() = default;
    bool saveGame(Map map);
    Map *loadGame(std::string file);
private:
};


#endif //BOMBERMAN_SAVE_HPP

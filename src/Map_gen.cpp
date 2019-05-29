/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map_gen.cpp
*/

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::vector<std::string> mapGen(int size)
{
    std::vector<std::string> map;
    std::string str;

    if (size % 2 == 0)
        size++;
    for (int i = 0; i < size; i++)
            str += '_';
    for (int i = 0; i < size; i++)
            map.push_back(str);
/*    for (int i = 0; i < (size * size) / 4 * 3; i++)
        map.at(std::rand() % size).at(std::rand() % size) = 'X';
    for (int i = 0; i < (size * size) / 3 * 2; i++)
        map.at(std::rand() % size).at(std::rand() % size) = 'O';
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (map.at(i).at(j) != 'X' && map.at(i + 1).at(j) != 'X' &&
                map.at(i).at(j + 1) != 'X' && map.at(i + 1).at(j + 1) != 'X')
                map.at(i + rand() % 2).at(j + rand() % 2) = 'X';
        }
    }*/
    for (int i = 0; i < (size * size) - size; i++)
        map.at(std::rand() % size).at(std::rand() % size) = 'O';
    for (int i = 1; i < size; i = i + 2) {
        for (int j = 1; j < size; j = j + 2) {
            map.at(i).at(j) = 'X';
        }
    }
    map.at(0).at(0) = '_';
    map.at(1).at(0) = '_';
    map.at(0).at(1) = '_';
    map.at(1).at(1) = 'X';
    map.at(size - 1).at(0) = '_';
    map.at(size - 1).at(1) = '_';
    map.at(size - 2).at(0) = '_';
    map.at(size - 2).at(1) = 'X';
    map.at(0).at(size - 1) = '_';
    map.at(1).at(size - 1) = '_';
    map.at(0).at(size - 2) = '_';
    map.at(1).at(size - 2) = 'X';
    map.at(size - 1).at(size - 1) = '_';
    map.at(size - 2).at(size - 1) = '_';
    map.at(size - 1).at(size - 2) = '_';
    map.at(size - 2).at(size - 2) = 'X';
    for (int i = 0; i < size; i++)
        std::cout << map.at(i) << std::endl;
    return map;
}

int main(int ac, char **av)
{
    std::srand(std::time(0));
    mapGen(atoi(av[1]));
}
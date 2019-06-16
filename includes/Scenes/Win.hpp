/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Win.hpp
*/

#ifndef WIN_HPP__
#define WIN_HPP__

#include <memory>
#include <string>
#include "Decor.hpp"
#include "AScene.hpp"
#include "Map.hpp"
#include "Sound.hpp"
#include "Timer.hpp"

class Win : public AScene
{
private:
    std::vector<std::shared_ptr<Decor>> _mesh;
    scene::ISceneNode* _camera;
    Sound _sounds;
    Timer _myTimer;
    bool _played;
    Sound &_menuSound;

public:
    Win(irr::IrrlichtDevice *device, MyEventReceiver &receiver, Map::character_t winner, Sound &menuSound);
    ~Win();

    IScene* update() override;
    void display() override;
};

#endif // !WIN_HPP__
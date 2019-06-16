/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Win.cpp
*/

#include "background.hpp"
#include "Menu.hpp"
#include "Win.hpp"

Win::Win(irr::IrrlichtDevice *device, MyEventReceiver &receiver, Map::character_t winner, Sound &menuSound) : AScene(device, receiver), _camera(nullptr), _myTimer(device), _played(false), _menuSound(menuSound)
{
    std::string mesh_winner;
    scene::ISceneNodeAnimator* anim;
    // Camera camera(device->getSceneManager(), irr::core::vector3df(10, 0, 0), irr::core::vector3df(0, 0, 0));

    _camera = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(0, 3, -5), irr::core::vector3df(0,0,0));
    anim = _sceneManager->createFlyCircleAnimator(core::vector3df(0,2,1), 3.2f);
    if (anim)
    {
        _camera->addAnimator(anim);
        anim->drop();
    }

    switch (winner)
    {
    case Map::character_t::luigi :
        mesh_winner = "./assets/meshs/Luigi/luigi.b3d";
        break;
    case Map::character_t::mario :
        mesh_winner = "./assets/meshs/Mario/mario.b3d";
        break;
    case Map::character_t::peach :
        mesh_winner = "./assets/meshs/Peach/peach.b3d";
        break;
    case Map::character_t::toad :
        mesh_winner = "./assets/meshs/Toad/toad.b3d";
        break;
    default:
        mesh_winner = "./assets/meshs/Bomb-omb/BombAnimated.b3d";
        break;
    }
    if (!mesh_winner.empty()) {
        _mesh.push_back(std::shared_ptr<Decor>(new Decor(device, mesh_winner, core::vector3df(0,-0.2,0), irr::core::vector3df(90, 0, 0), irr::core::vector3df(0.5,0.5,0.5))));
        _mesh.push_back(std::shared_ptr<Decor>(new Decor(device, "./assets/meshs/Engine_Room/room.obj", irr::core::vector3df(0,-0.2,0), irr::core::vector3df(0,180,0))));
    }
}

IScene* Win::update()
{
    IScene *back;
    IScene *menu;

    if (!_device->run() || _events.IsKeyReleased(irr::EKEY_CODE::KEY_SPACE)) {
        delete this;
        return (nullptr);
    }
    if (!_played && _myTimer.isTimeElapsed(3)) {
        _sounds.playSoundWin();
        _played = true;
    }
    return (this);
}

void Win::display()
{
    if (!_device->run()) {
        return;
    }
    _driver->beginScene(true, true, video::SColor(255,100,101,140));
    _sceneManager->drawAll();
    _driver->endScene();
}

Win::~Win()
{
}
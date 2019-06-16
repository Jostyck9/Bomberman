/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Map.hpp
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#ifdef _WIN64
    #include <irrlicht.h>
#else
    #include <irrlicht/irrlicht.h>
#endif

#include <boost/multi_array.hpp>
#include "GameObject.hpp"

class Map
{
private:
    irr::IrrlichtDevice *_device;
    boost::multi_array<std::vector<std::shared_ptr<GameObject>>, 2> _map;
    std::vector<std::string> _mapGen;
    irr::u16 _size;

public:

    enum character_s {
        luigi,
        mario,
        peach,
        toad,
        UNKNOWN
    };
    typedef character_s character_t;

    Map(irr::IrrlichtDevice *device, const std::string &save, irr::u16 size);
    ~Map();

    void genMap(irr::u16 size);
    void setMap();
    void addToMap(irr::u16 x, irr::u16 y, std::shared_ptr<GameObject> obj);
    void delToMap(irr::u16 x, irr::u16 y, std::shared_ptr<GameObject> obj);
    void delToMap(std::shared_ptr<GameObject> obj);
    void delToMap(irr::s32 id);
    void updateColision();
    std::vector<std::shared_ptr<GameObject>> &getCellObject(irr::u16 x, irr::u16 y);
    std::shared_ptr<GameObject> getObject(irr::s32 id);
    std::shared_ptr<GameObject> getObject(irr::scene::ISceneNode *node);

    boost::multi_array<std::vector<std::shared_ptr<GameObject>>, 2> &getMap();
    irr::u16 getSize() const;
    bool save();
    bool load(const std::string &filename);
    void setDevice(irr::IrrlichtDevice *device);
    void setSize(irr::u16 size);
    Map::character_t checkWin();

    irr::core::vector2df getPosition(std::shared_ptr<GameObject>);
    irr::core::vector2df getPosition(irr::s32 id);
};

#endif // !MAP_HPP_
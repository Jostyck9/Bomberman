/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GraphicalElements.hpp
*/

#ifndef GRAPHICALELEMENTS_HPP
#define GRAPHICALELEMENTS_HPP

#ifdef _WIN64
    #include <irrlicht.h>
#else
    #include <irrlicht/irrlicht.h>
#endif

class GraphicalElements
{
private:
    irr::scene::IAnimatedMesh* _mesh;
    irr::f32 _scale;
    irr::core::vector3df _position;
    irr::core::vector3df _rotation;
    bool _collide;

public:
    GraphicalElements(const irr::core::vector3df &position, const irr::core::vector3df &rotation, irr::f32 scale, bool collide);
    const irr::core::vector3df &getRotation() const;
    void setRotation(const irr::core::vector3df &rotation);
    bool isCollide() const;
    void setCollide(bool canCollide);
    irr::scene::IAnimatedMesh* getMesh();
    irr::f32 getScale();
    const irr::core::vector3df& getPosition();
    void setPosition(irr::core::vector3df& _position);
    void setScale(irr::f32 _scale);
    void setMesh(irr::scene::IAnimatedMesh* _mesh);
};

#endif

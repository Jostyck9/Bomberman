/*
** EPITECH PROJECT, 2019
** Bomberman
** File description:
** GraphicalElements.hpp
*/

#ifndef GRAPHICALELEMENTS_HPP
#define GRAPHICALELEMENTS_HPP

#include <string>
#include <vector>

#ifdef _WIN64
    #include <irrlicht.h>
#else
    #include <irrlicht/irrlicht.h>
#endif

class GraphicalElements
{
private:
    irr::IrrlichtDevice *_device;
    irr::scene::IAnimatedMesh* _mesh;
    irr::scene::IAnimatedMeshSceneNode *_node;

    std::string _meshPath;
    irr::core::vector3df _scale;
    irr::core::vector3df _position;
    irr::core::vector3df _rotation;

    irr::scene::ITriangleSelector *_selector;
    irr::scene::IMetaTriangleSelector *_selectorWorld;
    static irr::scene::IMetaTriangleSelector *_allSelectors;

    irr::core::vector3df _boxColision;
    irr::core::vector3df _translationColision;

    bool createSelectorWorld();

public:

    enum meshType_e {
        CUBE
    };
    typedef enum meshType_e meshType_t;

public:
    GraphicalElements(irr::IrrlichtDevice *device, const irr::core::vector3df &position = irr::core::vector3df(0, 0, 0), const irr::core::vector3df &rotation = irr::core::vector3df(0, 0, 0), irr::core::vector3df scale = irr::core::vector3df(1, 1, 1));

    const irr::core::vector3df &getRotation() const;
    void setRotation(const irr::core::vector3df &rotation);

    const irr::scene::IAnimatedMesh* getMesh() const;
    void setMesh(std::vector<std::string>, std::string &meshPath, irr::s32 id = 0);

    const std::string &getMeshPath() const;
    void setMeshPath(const std::string &meshPath);

    irr::core::vector3df getScale();
    void setScale(irr::core::vector3df _scale);

    const irr::core::vector3df& getPosition();
    void setPosition(irr::core::vector3df& _position);

    bool addColision(irr::core::vector3df sphere, irr::core::vector3df translation = irr::core::vector3df(0, 0, 0));
    bool updateColision();

    irr::scene::ISceneNode *getFrontObj(irr::f32 distance, irr::s32 id = -1);
};

#endif

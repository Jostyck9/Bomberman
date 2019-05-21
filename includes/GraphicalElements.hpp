#ifndef GRAPHICALELEMENTS_HPP
#define GRAPHICALELEMENTS_HPP

class GraphicalElements
{

private:
    irr::scene::IAnimatedMesh* _mesh;
    irr::f32 _scale;
    irr::core::vector3df _position;

public:
    irr::scene::IAnimatedMesh* getMesh();

    irr::f32 getScale();

    const irr::core::vector3df& getPosition();

    void setPosition(irr::core::vector3df& _position);

    void setScale(irr::f32 _scale);

    void setMesh(irr::scene::IAnimatedMesh* _mesh);
};

#endif

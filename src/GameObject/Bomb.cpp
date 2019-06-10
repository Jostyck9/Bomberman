#include "Bomb.hpp"

Bomb::Bomb(irr::IrrlichtDevice* device, ACharacter& character, irr::u16 radius) : PrintableObject(device), _radius(radius), _parentCharacter(character)
{
    irr::core::vector3df pos = character.getDisplayInfo().getPosition();
    irr::f32 rotation = character.getDisplayInfo().getRotation().Z;
    std::vector<std::string> path_text;
    std::string path_mesh = "./assets/meshs/Bomb/ItmBombhei.obj";

    if (rotation == PlayerController::rotation_e::RIGHT) {
        pos.X += 10;
    } else if (rotation == PlayerController::rotation_e::LEFT) {
        pos.X -= 10;
    } else if (rotation == PlayerController::rotation_e::UP) {
        pos.Y += 10;
    } else {
        pos.Y -= 10;
    }
    this->getDisplayInfo().setPosition(pos);
    this->getDisplayInfo().setMesh(path_text, path_mesh);
    this->getDisplayInfo().setRotation(irr::core::vector3df(90,180,0));
    // this->getDisplayInfo().addColision(irr::core::vector3df(2, 2, 2));
}

irr::u16 Bomb::getRadius()
{
    return (_radius);
}

void Bomb::setRadius(irr::u16 radius)
{
    _radius = radius;
}

void Bomb::update()
{
    // TODO - implement Bomb::update
    throw "Not yet implemented";
}

ACharacter& Bomb::getParentCharacter()
{
    return (_parentCharacter);
}
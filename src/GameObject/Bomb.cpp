#include "Bomb.hpp"

Bomb::Bomb(ACharacter& character, irr::u16 radius) : _radius(radius), _parentCharacter(character)
{
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

GameObject::objecType_t Bomb::getType()
{
    return BOMB;
}

// void Bomb::setParentCharacter(ACharacter& character)
// {
//     _parentCharacter = character;
// }

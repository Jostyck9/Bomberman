#include "../../../.config/VisualParadigm/ws/teamwork_client/projects/Bomberman/CharacterStats.h"

void CharacterStats::set_bombRadius(irr::u16 _bombRadius)
{
    // TODO - implement CharacterStats::set_bombRadius
    throw "Not yet implemented";
}

void CharacterStats::set_nbrBomb(irr::u16 _nbrBomb)
{
    // TODO - implement CharacterStats::set_nbrBomb
    throw "Not yet implemented";
}

void CharacterStats::set_speed(irr::f32 _speed)
{
    // TODO - implement CharacterStats::set_speed
    throw "Not yet implemented";
}

void CharacterStats::set_score(irr::s16 _score)
{
    // TODO - implement CharacterStats::set_score
    throw "Not yet implemented";
}

boolean CharacterStats::get_passThrough()
{
    return this->_passThrough;
}

void CharacterStats::set_passThrough(boolean _passThrough)
{
    this->_passThrough = _passThrough;
}

irr::u16 CharacterStats::get_bombRadius()
{
    return this->_bombRadius;
}

void CharacterStats::set_bombRadius(irr::u16 _bombRadius)
{
    this->_bombRadius = _bombRadius;
}

irr::u16 CharacterStats::get_nbrBomb()
{
    return this->_nbrBomb;
}

void CharacterStats::set_nbrBomb(irr::u16 _nbrBomb)
{
    this->_nbrBomb = _nbrBomb;
}

irr::f32 CharacterStats::get_speed()
{
    return this->_speed;
}

void CharacterStats::set_speed(irr::f32 _speed)
{
    this->_speed = _speed;
}

irr::s16 CharacterStats::get_score()
{
    return this->_score;
}

void CharacterStats::set_score(irr::s16 _score)
{
    this->_score = _score;
}

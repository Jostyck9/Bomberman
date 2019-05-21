/*
** EPITECH PROJECT, 2018
** diagram
** File description:
** CharacterStats.hpp
*/

#ifndef CHARACTERSTATS_HPP
#define CHARACTERSTATS_HPP

class CharacterStats
{

private:
    boolean _passThrough;
    irr::u16 _bombRadius;
    irr::u16 _nbrBomb;
    irr::f32 _speed;
    irr::s16 _score;

public:
    boolean get_passThrough();

    void set_passThrough(boolean _passThrough);

    irr::u16 get_bombRadius();

    void set_bombRadius(irr::u16 _bombRadius);

    irr::u16 get_nbrBomb();

    void set_nbrBomb(irr::u16 _nbrBomb);

    irr::f32 get_speed();

    void set_speed(irr::f32 _speed);

    irr::s16 get_score();

    void set_score(irr::s16 _score);
};

#endif

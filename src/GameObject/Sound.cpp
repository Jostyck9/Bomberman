/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Sound.cpp
*/

#include "Sound.hpp"

Sound::Sound() : _loop(false), _sound(nullptr)
{
    _engine = createIrrKlangDevice();

    this->_sounds.push_back("./assets/Sounds/Musics/Bianco Hills - Super Mario Sunshine.wav");
    this->_sounds.push_back("./assets/Sounds/Musics/Super Bell Hill - Super Mario 3D World.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Coin.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Defeat.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Victory.wav");
    this->_sounds.push_back("");
    this->_sounds.push_back("");
    this->_sounds.push_back("");
}

void Sound::playMenuMusic()
{
    _sound = _engine->play3D(_sounds[1].c_str(), vec3df(0,0,0), true, false, true);
}

void Sound::playGameMusic()
{
    _sound = _engine->play3D(_sounds[0].c_str(), vec3df(0,0,0), true, false, true);
}

void Sound::playPutBomb()
{

}

void Sound::playExplosionBomb()
{

}

void Sound::playSoundWin()
{
    _sound = _engine->play3D(_sounds[4].c_str(), vec3df(0,0,0), false, false, true);
}

void Sound::playSoundDefeat()
{
    _sound = _engine->play3D(_sounds[3].c_str(), vec3df(0,0,0), false, false, true);
}

void Sound::playPowerUpEffet()
{
    _sound = _engine->play3D(_sounds[2].c_str(), vec3df(0,0,0), false, false, true);
}

void Sound::destroyMe()
{
    if (_sound)
        _sound->drop();
}
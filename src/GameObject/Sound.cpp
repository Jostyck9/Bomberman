/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Sound.cpp
*/

#include "Sound.hpp"

Sound::Sound() : _loop(false), _sound(nullptr)
{
    this->_engine = createIrrKlangDevice();

    this->_sounds.push_back("./assets/Sounds/Musics/Bianco Hills - Super Mario Sunshine.wav");
    this->_sounds.push_back("./assets/Sounds/Musics/Super Bell Hill - Super Mario 3D World.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Coin.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Defeat.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Victory.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Poup.wav");
    this->_sounds.push_back("./assets/Sounds/SoundEffects/Explosion.wav");
}

void Sound::playMenuMusic()
{
    this->_sound = this->_engine->play3D(this->_sounds[1].c_str(), vec3df(0,0,0), true, false, true);
}

void Sound::playGameMusic()
{
    this->_sound = this->_engine->play3D(this->_sounds[0].c_str(), vec3df(0,0,0), true, false, true);
}

void Sound::playPutBomb()
{
    this->_sound = this->_engine->play3D(this->_sounds[5].c_str(), vec3df(0,0,0), true, false, true);
}

void Sound::playExplosionBomb()
{
    this->_sound = this->_engine->play3D(this->_sounds[6].c_str(), vec3df(0,0,0), true, false, true);
}

void Sound::playSoundWin()
{
    this->_sound = this->_engine->play3D(this->_sounds[4].c_str(), vec3df(0,0,0), false, false, true);
}

void Sound::playSoundDefeat()
{
    this->_sound = this->_engine->play3D(this->_sounds[3].c_str(), vec3df(0,0,0), false, false, true);
}

void Sound::playPowerUpEffet()
{
    this->_sound = this->_engine->play3D(this->_sounds[2].c_str(), vec3df(0,0,0), false, false, true);
}

void Sound::stopMe()
{
    if (this->_sound)
        this->_sound->stop();
}

void Sound::destroyMe()
{
    if (this->_sound)
        this->_sound->drop();
}

void Sound::setVol(wchar_t vol)
{
    irr::u16 n = boost::lexical_cast<irr::u16>(vol);
    n = n * 10;
    this->_sound->setVolume(n);
}
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

Sound::Sound(const Sound& sound)
{
    this->_loop = sound.getLoop();
    this->_engine = sound.getEngine();
    this->_sound = sound.getISound();
    this->_sounds = sound.getSounds();
}

void Sound::playMenuMusic()
{
    if (_engine->isCurrentlyPlaying(this->_sounds[1].c_str()))
        return;
    this->_sound = this->_engine->play3D(this->_sounds[1].c_str(), vec3df(0,0,0), true, false, true);
    this->_sound->setVolume(0.5);
}

void Sound::playGameMusic()
{
    if (_engine->isCurrentlyPlaying(this->_sounds[0].c_str()))
        return;
    this->_sound = this->_engine->play3D(this->_sounds[0].c_str(), vec3df(0,0,0), true, false, true);
    this->_sound->setVolume(0.3);
}

void Sound::playPutBomb()
{
    if (_engine->isCurrentlyPlaying(this->_sounds[5].c_str()))
        return;
    this->_sound = this->_engine->play3D(this->_sounds[5].c_str(), vec3df(0,0,0), false, false, true);
    this->_sound->setVolume(1);
}

void Sound::playExplosionBomb()
{
    if (_engine->isCurrentlyPlaying(this->_sounds[6].c_str()))
        return;
    this->_sound = this->_engine->play3D(this->_sounds[6].c_str(), vec3df(0,0,0), false, false, true);
    this->_sound->setVolume(0.7);
}

void Sound::playSoundWin()
{
    if (_engine->isCurrentlyPlaying(this->_sounds[4].c_str()))
        return;
    this->_sound = this->_engine->play3D(this->_sounds[4].c_str(), vec3df(0,0,0), false, false, true);
}

void Sound::playSoundDefeat()
{
    if (_engine->isCurrentlyPlaying(this->_sounds[3].c_str()))
        return;
    this->_sound = this->_engine->play3D(this->_sounds[3].c_str(), vec3df(0,0,0), false, false, true);
    this->_sound->setVolume(0.3);
}

void Sound::playPowerUpEffect()
{
    if (_engine->isCurrentlyPlaying(this->_sounds[2].c_str()))
        return;
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
    irr::u16 n = boost::lexical_cast<irr::f32>(vol);
    n = n / 10;
    this->_sound->setVolume(n);
}

bool Sound::getLoop() const
{
    return (this->_loop);
}

ISoundEngine* Sound::getEngine() const
{
    return (this->_engine);
}

ISound* Sound::getISound() const
{
    return (this->_sound);
}

std::vector<std::string> Sound::getSounds() const
{
    return (this->_sounds);
}
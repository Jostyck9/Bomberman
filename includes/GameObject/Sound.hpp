/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Sound.hpp
*/

#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include <irrKlang.h>
#include <string>
#include <vector>

using namespace irrklang;

class Sound
{
    private:
        bool _loop;
        ISoundEngine *_engine;
        ISound* _sound;
        std::vector<std::string> _sounds;
    public:
        Sound();
        void playMenuMusic();
        void playGameMusic();
        void playPutBomb();
        void playExplosionBomb();
        void playSoundWin();
        void playSoundDefeat();
        void playPowerUpEffet();
        void destroyMe();
};

#endif //__SOUND_HPP__
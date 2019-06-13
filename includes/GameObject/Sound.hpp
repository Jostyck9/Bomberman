/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Sound.hpp
*/

#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#include <irrKlang.h>

using namespace irrklang;

class Sound
{
    private:
        bool _loop;
        ISoundEngine *engine;
        ISound* sound;
    public:
        Sound(std::string path);

        void startSound();
        void pauseSound();
        void stopSound();
        void setLoop(bool);
        bool getLoop();
};

#endif //__SOUND_HPP__
/*
** EPITECH PROJECT, 2018
** Bomberman
** File description:
** Sound.hpp
*/

#ifndef __SOUND_HPP__
#define __SOUND_HPP__

#ifdef _WIN64
    #include <IrrlichtDevice.h>
#else
    #include <irrlicht/IrrlichtDevice.h>
#endif

#include <boost/lexical_cast.hpp>
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
        Sound(const Sound&);
        void playMenuMusic();
        void playGameMusic();
        void playPutBomb();
        void playExplosionBomb();
        void playSoundWin();
        void playSoundDefeat();
        void playPowerUpEffect();
        void destroyMe();
        void setVol(wchar_t);
        void stopMe();
        bool getLoop() const;
        ISoundEngine* getEngine() const;
        ISound* getISound() const;
        std::vector<std::string> getSounds() const;
};

#endif //__SOUND_HPP__
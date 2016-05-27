/*!
 * \file audio.h
 * \class Audio
 * \brief Gestion des sons
 * \author Jérémie
 */

#ifndef AUDIO_H
#define AUDIO_H

#include <SFML/Audio.hpp>
#include <cassert>
#include <string>
#include "const.h"

class Audio
{
public:

    /*!
     * \brief load permet de charger une musique ou son a partir d'un fichier
     * \param filename
     */
    void load(std::string filename);

    /*!
     * \brief play
     */
    void play();

    /*!
     * \brief setPlayingOffset
     * \param timeOffset
     */
    void setPlayingOffset(sf::Time timeOffset);

    /*!
     * \brief setLoop
     */
    void setLoop();

    /*!
     * \brief stop
     */
    void stop();

    /*!
     * \brief pause
     */
    void pause();

    /*!
     * \brief setVolume
     * \param valeur du volume
     */
    void setVolume(int);

private:
    sf::Sound sound;
    sf::SoundBuffer buffer;/*!< Buffer utilisé pour charger le fichier son */

};

#endif //AUDIO_H

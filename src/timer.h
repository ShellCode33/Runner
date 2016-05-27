/*!
 * \file timer.h
 * \class Timer
 * \brief Classe permettant de créer un chrono simplement
 * \author Clément
 */

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
public:
    Timer(const unsigned long ms=0, bool start=false);
    ~Timer();
    void begin(); /*!< Lance le chrono */
    void reset(); /*!< Alias de begin() */
    bool isFinish() const; /*!< true -> timer terminé */
    unsigned long getDuration() const; /*!< Récupère depuis combien de temps le chrono a été lancé */
    void changeTimer(unsigned long ms); /*!< Permet de changer le temps du chrono */

private:
    unsigned long ms;
    std::chrono::high_resolution_clock::time_point begin_time; /*!< Mesure de temps de la std lib */

};

#endif // TIMER_H

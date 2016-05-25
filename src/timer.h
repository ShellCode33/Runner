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
    void begin();
    void reset(); /*!< Alias de begin() */
    bool isFinish() const;
    unsigned long getDuration() const;
    void changeTimer(unsigned long ms);

private:
    unsigned long ms;
    std::chrono::high_resolution_clock::time_point begin_time;

};

#endif // TIMER_H

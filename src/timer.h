#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer
{
public:
    Timer(const unsigned long ms=0);
    ~Timer();
    void begin();
    void reset(); /*!< Alias de begin() */
    bool isFinish() const;
    unsigned long getDuration() const;

private:
    const unsigned long ms;
    std::chrono::high_resolution_clock::time_point begin_time;

};

#endif // TIMER_H

#include "timer.h"

using namespace std;

Timer::Timer(const unsigned long ms, bool start) : ms(ms)
{
    if(start)
        begin();
}

Timer::~Timer()
{

}

void Timer::begin()
{
    this->begin_time = chrono::system_clock::now();
}

void Timer::reset()
{
    begin();
}

bool Timer::isFinish() const
{
    if(this->ms <= 0) //Timer infini si ms vaut 0 ou moins
        return false;

    auto diff = chrono::system_clock::now() - this->begin_time;
    auto msec = chrono::duration_cast<chrono::milliseconds>(diff);
    return msec.count() >= (int)this->ms;
}

unsigned long Timer::getDuration() const
{
    auto diff = chrono::system_clock::now() - this->begin_time;
    auto msec = chrono::duration_cast<chrono::milliseconds>(diff);
    return msec.count();
}

void Timer::changeTimer(unsigned long ms)
{
    this->ms = ms;
}

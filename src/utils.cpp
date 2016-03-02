#include "utils.h"

using namespace std;

Utils::Utils()
{

}

Utils::~Utils()
{

}

void Utils::log(const string text)
{
    time_t t = time(0);   // get time now
    struct tm * current_time = localtime(&t);

    cout << "[" << current_time->tm_hour << ":" << current_time->tm_min << ":" << current_time->tm_sec << "] " << text << endl;
}

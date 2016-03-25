#ifndef BONUS_H
#define BONUS_H

#include <utility>
#include <SFML/Graphics.hpp>
#include "movable.h"
#include "animation.h"
#include "utils.h"

class Bonus : public Animation
{
private:
    int relat_x;
    int relat_y;
public:
    Bonus(int ms = 0, int x = 0, int y = 0);
    ~Bonus();
    void setPositionRelat(const int x, const int y);
    std::pair<int, int> getPosition() const;
    void update();
    bool checkCollision(Movable &m);
};

#endif // BONUS_H

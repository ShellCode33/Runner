#ifndef MOVABLE_H
#define MOVABLE_H

class Movable
{
public:
    Movable();
    ~Movable();
    void setPosition(int x, int y);
    void move(int x, int y); //offset depuis la position initiale

private:
    int pos_x;
    int pos_y;

};

#endif // MOVABLE_H

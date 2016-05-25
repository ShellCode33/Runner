#ifndef HEART_H
#define HEART_H

#include "heart_model.h"
#include "heart_view.h"

class Heart
{
public:
    Heart(int relat_x, int relat_y, int width, int height);
    ~Heart();
    void update();
    HeartModel* getModel();
    HeartView* getView();

private:
    HeartModel model;
    HeartView view;

};


#endif
#pragma once
#include <vector>

#include "Point.hpp"

typedef std::vector<Point> ListePoint;
class Logic
{
    

    private:
        ListePoint points;
        int width, height;
    public:
        Logic(int width, int height);
        void addPoint(int x, int y);
        void printPoints();
        ListePoint getPoints();
        int getCurvePixel_y(int x);
};
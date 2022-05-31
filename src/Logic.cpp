#include <iostream>
#include <math.h>

#include "Logic.hpp"


Logic::Logic(int width, int height)
: width(width), height(height)
{
}

void Logic::addPoint(int x, int y)
{
    Point nouveau(x, y);
    points.push_back(nouveau);
}

void Logic::printPoints()
{
    std::cout << "Liste des points: " << std::endl;
    for(std::size_t i = 0; i < points.size(); i++)
    {
        std::cout << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
    }
    std::cout << std::endl;
}

ListePoint Logic::getPoints()
{
    return points;
}

int Logic::getCurvePixel_y(int x)
{
    int distances[points.size()];
    double coefficients[points.size()];
    
    for(std::size_t i = 0; i < points.size(); i++)
    {
        distances[i] = abs(x - points[i].getX());
        if(distances[i] == 0) return points[i].getY();
        coefficients[i] = pow((1/(double)distances[i]),2);
    }

    double nominateur = 0, denominateur = 0;
    int result;
    for(std::size_t i = 0; i < points.size(); i++)
    {
        nominateur += points[i].getY() * coefficients[i];
        denominateur += coefficients[i];
    }

    result = round(nominateur/denominateur);

    return result;
}
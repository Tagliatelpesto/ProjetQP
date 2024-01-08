#include "point.h"
#include <cmath>

namespace jeu
{

point::point(int x,int y): d_x{x},d_y{y}
{}

int point::x()
{
    return d_x;
}
int point::y()
{
    return d_y;
}
void point::deplaceDe(int x, int y)
{
    d_x +=x;
    d_y +=y;
}


void point::deplaceDe(point p)
{
    deplaceDe(p.x(), p.y());
}
void point::deplaceEn(int x, int y)
{
    d_x = x;
    d_y = y;
}
void point::deplaceEn(point p)
{
    deplaceEn(p.x(), p.y());
}

double point::distance(int x,int y)const
{
   return sqrt(pow(d_x - x, 2) + pow(d_y - y, 2));
}

double point::distance(point p)const
{
   return sqrt(pow(d_x - p.x(), 2) + pow(d_y - p.y(), 2));
}

point point::operator=(point p)
{
    d_x = p.x();
    d_y = p.y();
}

}

#include "point.h"
#include <cmath>

namespace jeu
{

point::point():d_x{0},d_y{0}
{}


point::point(int x,int y): d_x{x},d_y{y}
{}

point::point(const point &copie) : d_x(copie.d_x), d_y(copie.d_y)
{}

int point::x()const
{
    return d_x;
}
int point::y()const
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
    d_x = p.x();
    d_y = p.y();
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
bool point::operator !=(point p)
{
    return ( (p.x() != d_x) || (p.y() != d_y) );
}

}

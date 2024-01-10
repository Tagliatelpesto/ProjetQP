#include "element.h"
#include "point.h"
namespace jeu
{
element::element() : d_pos{0,0}
{}

element::element(const point pos) : d_pos{pos}
{}

void element::setPosition(const point &pos)
{
    d_pos.deplaceEn(pos);
}

point element::position()const
{
    return d_pos;
}

}

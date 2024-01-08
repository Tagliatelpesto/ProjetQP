#ifndef ELEMENT_H
#define ELEMENT_H
#include "point.h"

namespace jeu
{
class element
{
    public:
        element();
        element(const point pos);
    protected:
        point d_pos;
    private:

};
}
#endif // ELEMENT_H

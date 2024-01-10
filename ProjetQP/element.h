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
        virtual char affiche()const = 0;
        void setPosition(const point &pos);
        point position()const;
    protected:
        point d_pos;
    private:

};
}
#endif // ELEMENT_H

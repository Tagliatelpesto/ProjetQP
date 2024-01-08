#ifndef AMULETTE_H
#define AMULETTE_H
#include "point.h"
#include "element.h"

namespace jeu
{
class amulette : public element
{
    public:
        amulette(point &coord);
        bool etat()const;
        void change();

    private:
        bool d_etat;
};
}
#endif // AMULETTE_H

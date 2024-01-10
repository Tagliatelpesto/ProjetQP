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
        char affiche()const override;
    private:
        bool d_etat;
};
}
#endif // AMULETTE_H

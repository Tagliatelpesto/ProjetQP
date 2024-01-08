#include "amulette.h"

namespace jeu
{
amulette::amulette(point &coord) : element(coord), d_etat{true}
{}

bool amulette::etat()const
{
    return d_etat;
}

void amulette::change()
{
    d_etat =!d_etat;
}

}

#include "cellule.h"

namespace jeu
{
cellule::cellule(point &coord, bool infoPos) : element(coord), d_interieur{infoPos}
{}

bool cellule::estInterne()const
{
    return d_interieur;
}

bool cellule::estExterne()const
{
    return !d_interieur;
}

void cellule::change()
{
    d_interieur = !d_interieur;
}
}

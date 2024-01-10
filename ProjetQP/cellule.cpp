#include "cellule.h"

namespace jeu
{
cellule::cellule(point &pos, bool infoPos) : element(pos), d_interieur{infoPos}
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

char cellule::affiche()const
{
    if(estExterne())
        return ' ';
    else
        return '.';
}

}

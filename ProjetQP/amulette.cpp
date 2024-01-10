#include "amulette.h"

namespace jeu
{
amulette::amulette(point &coord) : element(coord), d_etat{true}
{}

char amulette::affiche()const
{
        return '&';
}

}

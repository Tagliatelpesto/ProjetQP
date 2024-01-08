#include "objetPortable.h"
namespace jeu
{

objetPortable::objetPortable(double solidite) : d_solidite{solidite} {}

double objetPortable::solidite() const
{
    return d_solidite;
}

void objetPortable::encaisse(double degats)
{
    if(degats > d_solidite)
    {
        d_solidite = 0.0;
    }
    else
    {
        d_solidite -= degats;
    }
}


void objetPortable::regenere(int montant)
{
    d_solidite += montant;
}

}

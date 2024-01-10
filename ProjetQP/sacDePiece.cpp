#include "sacDePiece.h"
#include <cstdlib>
#include <ctime>

namespace jeu
{

sacDePiece::sacDePiece(point &coord) : element(coord), d_montant{0}
{
    d_montant = rand()%10;
}

int sacDePiece::montant()const
{
    return d_montant;
}


void sacDePiece::fixe(int montant)
{
    d_montant = montant;
}


void sacDePiece::ajoute(int montant)
{
    d_montant +=montant;
}


char sacDePiece::affiche()const
{
    return '$';
}
}

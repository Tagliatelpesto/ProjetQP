#include "sacDePiece.h"
namespace jeu
{

sacDePiece::sacDePiece(point &coord, int montant) : element(coord), d_montant{montant}
{}

int sacDePiece::montant()const
{
    return d_montant;
}

bool sacDePiece::estVide()const
{
    return d_montant == 0;
}

void sacDePiece::diminue(int montant)
{
    if(montant > d_montant)
        d_montant = 0;
    else
        d_montant -= montant;
}

void sacDePiece::vide()
{
    d_montant = 0;
}

void sacDePiece::fixe(int montant)
{
    d_montant = montant;
}


void sacDePiece::ajoute(int montant)
{
    d_montant +=montant;
}

}

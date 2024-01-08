#include "personnage.h"
namespace jeu
{

personnage::personnage(const point pos, double vie, double force) : element(pos), d_vie{vie}, d_force{force} {}

double personnage::pointsDeForce() const
{
    return d_force;
}

double personnage::pointsDeVie() const
{
    return d_vie;
}


bool personnage::estEnVie() const
{
    return d_vie > 0.0;
}

void personnage::diminueVie(double degats)
{
    if(degats > d_vie)
        d_vie = 0.0;
    else
        d_vie -=degats;

}

bool personnage::deplacement(point p)
{
    d_pos = p;
}


void personnage::gauche()
{
    d_pos.deplaceDe(d_pos.x()-1,d_pos.y());
}
void personnage::droite()
{
    d_pos.deplaceDe(d_pos.x()+1,d_pos.y());
}
void personnage::haut()
{
    d_pos.deplaceDe(d_pos.x(),d_pos.y()+1);
}
void personnage::bas()
{
    d_pos.deplaceDe(d_pos.x()-1,d_pos.y()-1);
}


}

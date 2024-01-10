#include "personnage.h"
namespace jeu
{

personnage::personnage() :
     element(), d_vie{0}, d_force{0} {}

personnage::personnage(double vie, double force) :
     element(), d_vie{vie}, d_force{force} {}

personnage::personnage(const point pos, double vie, double force) :
     element(pos), d_vie{vie}, d_force{force} {}

double personnage::force() const
{
    return d_force;
}

double personnage::vie() const
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
    d_pos.deplaceDe(-1,0);
}
void personnage::droite()
{
    d_pos.deplaceDe(1,0);
}
void personnage::haut()
{
    d_pos.deplaceDe(0,1);
}
void personnage::bas()
{
    d_pos.deplaceDe(0,-1);
}

void personnage::setVie(int vie)
{
    d_vie=vie;
}

void personnage::setForce(int force)
{
    d_force=force;
}

void personnage::augmenteVie(int vie)
{
        d_vie +=vie;
}

void personnage::augmenteForce(int force)
{
        d_force +=force;
}

}

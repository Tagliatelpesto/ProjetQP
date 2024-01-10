#include <cstdlib>
#include <ctime>
#include "aventurier.h"
#include "point.h"
#include "objetPortable.h"
namespace jeu
{

aventurier::aventurier() :
    personnage(),d_bourse{0},d_epee{0},d_armure{0},d_amulette{0}
    {}

aventurier::aventurier(double vie, double force) :
    personnage(vie,force),d_bourse{0},d_epee{20.0},d_armure{20.0},d_amulette{0}
    {}

aventurier::aventurier(point &pos, double vie, double force) :
    personnage(pos,vie,force),d_bourse{0},d_epee{20.0},d_armure{20.0},d_amulette{0}
    {}

int aventurier::bourse() const
{
    return d_bourse;
}

double aventurier::infligeDegats(personnage &p)
{
    //Génération d'un nombre aléatoire entre 1 et 100 (total de 100 valeurs)
    int nombreAleat = std::rand() % 100;
    //Si le nombre généré se trouve dans la plage des 80 premières valeurs (probabilité de 80%)
    if(nombreAleat <= 80)
    {
        double degats = (d_epee.solidite() + force())*0.9;
        d_epee.encaisse(1);
        return p.estAttaque(degats);
    }
    return 0.0;
}


double aventurier::estAttaque(double degats)
{
    double degatsAbsorbesParArmure = 0.75*degats;
    //l'armure doit pouvoir encaisser la moitié des dégâts avec ses points de force;

    d_armure.encaisse(degatsAbsorbesParArmure/2);

    //Le reste est infligé à l'aventurier
    diminueVie(degats-degatsAbsorbesParArmure);
    return degats-degatsAbsorbesParArmure;
}

//Lorsque l'aventurier trouve un sac de pièces
void aventurier::obtientPieces(int montant)
{
    d_bourse += montant;
}


double aventurier::soliditeArmure() const
{
    return d_armure.solidite();
}

double aventurier::soliditeEpee() const
{
    return d_epee.solidite();
}

bool aventurier::regenereEpee(int montant)
{
    if(montant <= d_bourse)
    {
        d_epee.regenere(montant);
        d_bourse-=montant;
        return true;
    }
    return false;
}

bool aventurier::regenereArmure(int montant)
{
    if(montant <= d_bourse)
    {
        d_armure.regenere(montant);
        d_bourse-=montant;
        return true;
    }
    return false;
}

char aventurier::affiche()const
{
    if(d_amulette)
        return 'A';
    else
        return '@';
}
void aventurier::obtientAmulette()
{
    d_amulette = true;
}

bool aventurier::amulette()const
{
    return d_amulette;
}

}

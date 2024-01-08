#include <cstdlib>
#include <ctime>
#include "aventurier.h"
#include "point.h"
namespace jeu
{

aventurier::aventurier(const point &pos, double vie, double force, int bourse, const objetPortable &epee, const objetPortable& armure) :
    personnage(pos,vie,force), d_bourse{bourse}, d_epee{epee}, d_armure{armure} {}

int aventurier::bourse() const
{
    return d_bourse;
}

double aventurier::infligeDegats(personnage &p)
{
    //Génération d'un nombre aléatoire entre 1 et 100 (total de 100 valeurs)
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int nombreAleat = std::rand() % 100 +1;
    //Si le nombre généré se trouve dans la plage des 80 premières valeurs (probabilité de 80%)
    if(nombreAleat <= 80)
    {
        double degats = (d_epee.solidite() + pointsDeForce())*0.9;

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
        return true;
    }
    return false;
}

bool aventurier::regenereArmure(int montant)
{
    if(montant <= d_bourse)
    {
        d_armure.regenere(montant);
        return true;
    }
    return false;
}

}

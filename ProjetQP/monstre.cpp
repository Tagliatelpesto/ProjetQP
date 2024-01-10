#include "monstre.h"
#include <cstdlib>
#include <ctime>

namespace jeu
{
monstre::monstre() : personnage(), d_habilete(0.0), d_voyant(false) {}

monstre::monstre(point pos, double vie, double force, double habilete, bool voyant):
personnage{pos, vie, force}, d_habilete{habilete}, d_voyant{voyant}
{}

monstre::monstre(const monstre &copie) : personnage(copie), d_habilete(copie.d_habilete), d_voyant(copie.d_voyant) {}

int monstre::habilete()const
{
    return d_habilete;
}

double monstre::estAttaque(double force)
{
    diminueVie(force);
    return force;
}

double monstre::infligeDegats(personnage &p)
{
    int nombreAleat = std::rand() % 100;
    double degats = 0;
    //Si le nombre généré se trouve dans la plage des 80 premières valeurs (probabilité de 80%)
    if(nombreAleat <= d_habilete)
    {
        degats = force()*0.9;
        p.estAttaque(degats);
    }

    return degats;
}

bool monstre::voyant()const
{
    return d_voyant;
}

char monstre::affiche()const
{
    return '8';
}

}

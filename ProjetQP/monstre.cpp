#include "monstre.h"
#include <cstdlib>
#include <ctime>

namespace jeu
{
monstre::monstre(point pos, double vie, double force, double habilete): personnage{pos, vie, force}, d_habilete{habilete} {}

double monstre::estAttaque(double force)
{
    diminueVie(force);
    return force;
}

double monstre::infligeDegats(personnage &p)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int nombreAleat = std::rand() % 100 + 1;
    double degats = 0;
    //Si le nombre généré se trouve dans la plage des 80 premières valeurs (probabilité de 80%)
    if(nombreAleat <= d_habilete)
    {
        double degats = pointsDeForce()*0.9;
        p.estAttaque(degats);
    }
    return degats;
}

}

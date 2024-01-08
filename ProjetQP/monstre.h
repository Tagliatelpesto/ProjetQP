#ifndef MONSTRE_H
#define MONSTRE_H
#include "personnage.h"

namespace jeu
{

class monstre : public personnage
{
private:
    double d_habilete;

public:
    monstre(point pos, double vie, double force, double habilete);
    double estAttaque(double force) override;
    double infligeDegats(personnage &p) override;
};
}
#endif // MONSTRE_H

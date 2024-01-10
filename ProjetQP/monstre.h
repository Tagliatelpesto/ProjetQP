#ifndef MONSTRE_H
#define MONSTRE_H
#include "personnage.h"

namespace jeu
{

class monstre : public personnage
{

public:
    monstre();
    monstre(point pos, double vie, double force, double habilete,bool voyant);
    monstre(const monstre &copie);
    int habilete()const;
    double estAttaque(double force) override;
    double infligeDegats(personnage &p) override;
    bool voyant()const;
    char affiche()const override;
private:
    double d_habilete;
    bool d_voyant;
};
}
#endif // MONSTRE_H

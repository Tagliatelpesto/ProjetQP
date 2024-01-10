#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "personnage.h"
#include "objetPortable.h"

namespace jeu
{
class aventurier : public personnage
{
public:
    aventurier();
    aventurier(double vie, double force);
    aventurier(point &pos, double vie, double force);
    int bourse() const;
    double soliditeArmure() const;
    double soliditeEpee() const;
    void obtientPieces(int montant);
    double infligeDegats(personnage &p) override;
    double estAttaque(double force) override;
    bool regenereEpee(int montant);
    bool regenereArmure(int montant);
    char affiche()const override;
    void obtientAmulette();
    bool amulette()const;
private:
    int d_bourse;
    objetPortable d_epee;
    objetPortable d_armure;
    bool d_amulette;
};
}
#endif // AVENTURIER_H

#ifndef AVENTURIER_H
#define AVENTURIER_H
#include "personnage.h"
#include "objetPortable.h"

namespace jeu
{
class aventurier : public personnage
{
public:
    aventurier(const point &pos, double vie, double force, int bourse, const objetPortable& epee, const objetPortable& armure);
    int bourse() const;
    double soliditeArmure() const;
    double soliditeEpee() const;
    void obtientPieces(int montant);
    double infligeDegats(personnage &p) override;
    double estAttaque(double force) override;
    bool regenereEpee(int montant);
    bool regenereArmure(int montant);
private:
    int d_bourse;
    objetPortable d_epee;
    objetPortable d_armure;
};
}
#endif // AVENTURIER_H

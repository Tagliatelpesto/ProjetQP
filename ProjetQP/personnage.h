#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include "point.h"
#include "element.h"
using namespace std;
namespace jeu
{

class personnage : public element
{
public:
    personnage(const point pos,double vie, double force);
    virtual ~personnage() = default;
    double pointsDeVie() const;
    double pointsDeForce() const;
    bool estEnVie() const;
    void diminueVie(double degats);
    virtual double infligeDegats(personnage &p) = 0 ;
    virtual double estAttaque(double force) = 0;
    bool deplacement(point p);
    void gauche();
    void droite();
    void haut();
    void bas();
private:
    double d_vie;
    double d_force;
};

}
#endif // PERSONNAGE_H

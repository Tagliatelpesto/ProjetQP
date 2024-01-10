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
    personnage();
    personnage(double vie, double force);
    personnage(const point pos,double vie, double force);
    virtual ~personnage() = default;
    double vie() const;
    double force() const;
    bool estEnVie() const;
    void diminueVie(double degats);
    virtual double infligeDegats(personnage &p) = 0 ;
    virtual double estAttaque(double force) = 0;
    bool deplacement(point p);
    void gauche();
    void droite();
    void haut();
    void bas();
    void setForce(int force);
    void setVie(int vie);
    void augmenteVie(int vie);
    void augmenteForce(int force);
private:
    double d_vie;
    double d_force;
};

}
#endif // PERSONNAGE_H

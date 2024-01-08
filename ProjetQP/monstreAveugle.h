#ifndef MONSTREAVEUGLE_H
#define MONSTREAVEUGLE_H
#include "point.h"
#include "monstre.h"
namespace jeu
{
class monstreAveugle : public monstre
{
    public:
        monstreAveugle(point pos, double vie, double force, double habilete);
    protected:

    private:
};
}
#endif // MONSTREAVEUGLE_H

#ifndef MONSTREVOYANT_H
#define MONSTREVOYANT_H
#include "point.h"
#include "monstre.h"

namespace jeu
{
class monstreVoyant : public monstre
{
    public:
        monstreVoyant(point pos, double vie, double force, double habilete);
    protected:

    private:
};
}
#endif // MONSTREVOYANT_H

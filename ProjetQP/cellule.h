#ifndef CELLULE_H
#define CELLULE_H
#include "point.h"
#include "element.h"

namespace jeu
{
class cellule : public element
{
    public:
        cellule(point &coord, bool infoPos);
        bool estInterne()const;
        bool estExterne()const;
        void change();
    private:
        bool d_interieur;
};
}

#endif // CELLULE_H

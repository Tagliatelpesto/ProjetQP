#ifndef SACDEPIECE_H
#define SACDEPIECE_H
#include "element.h"
#include "point.h"
namespace jeu
{
class sacDePiece : public element
{
    public:
        sacDePiece(point &coord, int montant);
        int montant()const;
        bool estVide()const;
        void diminue(int montant);
        void vide();
        void fixe(int montant);
        void ajoute(int montant);
    private:
        int d_montant;
};
}
#endif // SACDEPIECE_H

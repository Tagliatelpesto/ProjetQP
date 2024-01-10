#ifndef SACDEPIECE_H
#define SACDEPIECE_H
#include "element.h"
#include "point.h"
namespace jeu
{
class sacDePiece : public element
{
    public:
        sacDePiece(point &coord);
        int montant()const;
        void fixe(int montant);
        void ajoute(int montant);
        char affiche()const override;
    private:
        int d_montant;
};
}
#endif // SACDEPIECE_H

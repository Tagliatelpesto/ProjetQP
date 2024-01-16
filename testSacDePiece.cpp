#include "doctest.h"
#include "sacDePiece.h"
#include "point.h"
#include <cstdlib>
#include <ctime>



namespace jeu
{
    TEST_CASE("Tests sur les sacs de pièces")
    {
        int montant{100};
        point pos(5,5);
        sacDePiece s1(pos);
        SUBCASE("La methode fixe ajuste le montant du sac en celui passe en parametre")
        {
           s1.fixe(montant);
           REQUIRE_EQ(s1.montant(),montant);
        }
        SUBCASE("La methode ajoute fait la somme du montant passe en parametre et celui du sac de pieces")
        {
            int montantInitial = s1.montant();
            s1.ajoute(montant);
            REQUIRE_EQ(s1.montant(),montant + montantInitial);
        }

    }

};

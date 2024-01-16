#include "doctest.h"
#include <cstdlib>
#include <ctime>
#include "aventurier.h"
#include "point.h"
#include "objetPortable.h"

using namespace jeu;


TEST_CASE("Tests de la classe aventurier")
{
    SUBCASE("Les aventuriers sont bien construits")
    {
        SUBCASE("Creation par defaut de l'aventurier")
        {
            aventurier a;
            REQUIRE_EQ(a.vie(),0);
            REQUIRE_EQ(a.force(),0);
            REQUIRE_EQ(a.bourse(),0);
            REQUIRE_EQ(a.soliditeEpee(),0);
            REQUIRE_EQ(a.soliditeArmure(),0);
            REQUIRE(!a.amulette());
        }
        SUBCASE("Creation d'un aventurier avec parametres specifiques")
        {
            point pos(1,1);
            double vie{150.0};
            double force{15.0};
            aventurier a(pos, vie, force);
            REQUIRE_EQ(a.vie(),vie);
            REQUIRE_EQ(a.force(),force);
            REQUIRE_EQ(a.bourse(),0);
            REQUIRE_EQ(a.soliditeEpee(),20.0);
            REQUIRE_EQ(a.soliditeArmure(),20.0);
            REQUIRE(!a.amulette());

        }
    }
    SUBCASE("Affichage de l'aventurier, changement si amulette obtenue")
    {
        aventurier a;
        char symbole = a.affiche();
        REQUIRE(symbole == '@');
        a.obtientAmulette();
        symbole = a.affiche();
        REQUIRE(symbole == 'A');
    }
    SUBCASE("Obtention de pieces par l'aventurier")
    {
        aventurier a;
        int solde = a.bourse();
        a.obtientPieces(50);
        REQUIRE_EQ(a.bourse(), solde + 50);
    }
    SUBCASE("Attaque et defense de l'aventurier")
    {
        SUBCASE("Attaque de l'aventurier")
        {
            aventurier attaquant;
            aventurier cible;
            double degats = attaquant.infligeDegats(cible);
            REQUIRE(degats >= 0.0);
            REQUIRE(cible.vie() < 100.0);
        }
        SUBCASE("Defense de l'aventurier")
        {
            aventurier attaque;
            aventurier defense;
            double degatsInfliges = 20.0;
            double degatsReels = defense.estAttaque(degatsInfliges);
            REQUIRE(degatsReels >= 0.0);
            REQUIRE(defense.vie() < 100.0);
        }
    }
}


















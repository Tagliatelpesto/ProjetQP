#include "monstre.h"
#include "aventurier.h"
#include <cstdlib>
#include <ctime>
#include "doctest.h"

namespace jeu
{
    TEST_CASE("Tests sur la classe monstre")
    {
        SUBCASE("Les monstres sont bien construits")
        {
            SUBCASE("Constructeur par défaut")
            {
                monstre m;
                REQUIRE_EQ(m.vie(), 0.0);
                REQUIRE_EQ(m.force(), 0.0);
                REQUIRE_EQ(m.habilete(), 0);
                REQUIRE(!m.voyant());
            }
            SUBCASE("Construction selon parametres specifiques")
            {
                point pos(1,1);
                double vie{150.0};
                double force{15.0};
                int habilete{10};
                monstre m(pos, vie, force, habilete, true);
                REQUIRE_EQ(m.vie(),vie);
                REQUIRE_EQ(m.force(),force);
                REQUIRE_EQ(m.habilete(),habilete);
                REQUIRE(m.voyant());
            }
        }
        SUBCASE("Affichage du monstre avec le bon caractere")
        {
            monstre m;
            char symbole = m.affiche();
            REQUIRE(symbole == '8');
        }
        SUBCASE("Attaques et défenses du monstre")
        {
            SUBCASE("Attaque du monstre")
            {
                monstre a;
                aventurier c;
                double degats = a.infligeDegats(c);
                REQUIRE(degats >= 0.0);
                REQUIRE(c.vie() < 100.0);
            }


            SUBCASE("Defense du monstre")
            {
                monstre attaque;
                aventurier defense;
                double degatsInfliges = 20.0;
                double degatsReels = attaque.estAttaque(degatsInfliges);
                REQUIRE_EQ(degatsReels, 20.0);
                REQUIRE(attaque.vie() < 100.0);
            }
        }


    }
/**








*/

};

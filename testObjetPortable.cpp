#include "doctest.h"
#include "objetPortable.h"


namespace jeu
{

    TEST_CASE("Tests sur la classe objetPortable")
    {
        int solidite = 100;
        objetPortable o1(solidite);
        SUBCASE("L'objet portable est construit correctement")
        {
            REQUIRE_EQ(o1.solidite(), solidite);
        }
        SUBCASE("La regeneration de l'objet portable somme le montant en parametre a sa solidite")
        {
            double soliditeDebut = o1.solidite();
            o1.regenere(50);
            double somme = soliditeDebut + 50;
            REQUIRE_EQ(o1.solidite(), somme);
        }
        SUBCASE("Tests sur les degats que peut subir l'objet portable")
        {
            objetPortable o1(100);
            SUBCASE("L'objet portable subit des degats superieurs a sa solidite")
            {
                double degats = 250;
                o1.encaisse(degats);
                REQUIRE_EQ(o1.solidite(), 0.0);
            }
            SUBCASE("L'objet portable subit des degats egaux a sa solidite")
            {
                double degats = o1.solidite();
                o1.encaisse(degats);
                REQUIRE_EQ(o1.solidite(), 0.0);
            }
            SUBCASE("L'objet portable subit des degats inferieurs a sa solidite")
            {
                double degats = 50;
                double soliditeAvantDegats = o1.solidite();
                o1.encaisse(degats);
                REQUIRE_EQ(o1.solidite(), soliditeAvantDegats - degats);
            }
        }
    }

};

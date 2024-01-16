#include "doctest.h"
#include "point.h"
#include <cmath>

namespace jeu
{
    TEST_CASE("Tests sur la classe point") {
        SUBCASE("Les points sont bien construits")
        {
            SUBCASE("Les coordonnees des points sont bonnes")
            {
                int x {10}, y {32};
                point p1 {x,y};
                REQUIRE_EQ( p1.x(), x);
                REQUIRE_EQ( p1.y(),y);
            }
            SUBCASE("Le constructeur par defaut donne un point de coordonnees nulles")
            {
                point p2{};
                REQUIRE_EQ(p2.x(),0);
                REQUIRE_EQ(p2.y(),0);
            }

        }
        SUBCASE("Déplacements de points")
        {
            int x {1}, y{2};
            SUBCASE("Test de la méthode deplaceDe")
            {
                point p(x, y);
                int plusX{3}, plusY{4};
                p.deplaceDe(plusX, plusY);
                REQUIRE_EQ(p.x(), x + plusX);
                REQUIRE_EQ(p.y(), y + plusY);
            }
            SUBCASE("Test de la méthode deplaceEn")
            {
                point p(x, y);
                int dX{3}, dY{4};
                p.deplaceEn(dX, dY);
                REQUIRE_EQ(p.x(), dX);
                REQUIRE_EQ(p.y(), dY);
            }

        }
        SUBCASE("Calculs de distances entre des points")
        {
            int x{1}, y{2};
            int d1{4}, d2{6};
            SUBCASE("Test de la méthode distance avec des coordonnées")
            {
                point p(x, y);
                REQUIRE_EQ(p.distance(d1, d2), 5.0);
            }

            SUBCASE("Test de la méthode distance avec un autre point")
            {
                point p1(x, y);
                point p2(d1, d2);
                REQUIRE_EQ(p1.distance(p2), 5.0);
            }

        }




}

};


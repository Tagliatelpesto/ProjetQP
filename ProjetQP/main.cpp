#include <iostream>
#include "element.h"
#include "jeuDonjon.h"
#include "aventurier.h"
#include "amulette.h"
#include "mur.h"
#include "monstre.h"
#include "sacDePiece.h"
#include "cellule.h"
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace jeu;
int main()
{
    jeuDonjon jD();
    jD.run();
}

#include "mur.h"
namespace jeu
{
mur::mur(point pos): element(pos)
{}

char mur::affiche()const
{
    return '#';
}

}

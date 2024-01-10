#ifndef MUR_H
#define MUR_H
#include "point.h"
#include "element.h"
namespace jeu
{

class mur: public element
{
    public:
        mur(point pos);
        char affiche()const override;
    protected:

    private:
};
}
#endif // MUR_H

#ifndef POINT_H
#define POINT_H

namespace jeu
{
class point
{
    public:
        point(int x,int y);
        int x();
        int y();
        void deplaceDe(int x, int y);
        void deplaceDe(point p);
        void deplaceEn(int x, int y);
        void deplaceEn(point p);
        double distance(point p)const;
        double distance(int x,int y)const;
        point operator =(point p);
    private:
        int d_x;
        int d_y;
};
}
#endif // POINT_H

#ifndef POINT_H
#define POINT_H

namespace jeu
{
class point
{
    public:
        point();
        point(int x,int y);
        point(const point &copie);
        int x()const;
        int y()const;
        void deplaceDe(int x, int y);
        void deplaceDe(point p);
        void deplaceEn(int x, int y);
        void deplaceEn(point p);
        double distance(point p)const;
        double distance(int x,int y)const;
        point operator =(point p);
        bool operator !=(point p);
    private:
        int d_x;
        int d_y;
};
}
#endif // POINT_H

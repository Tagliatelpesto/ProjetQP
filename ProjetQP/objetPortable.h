#ifndef OBJETPORTABLE_H
#define OBJETPORTABLE_H

namespace jeu
{
class objetPortable
{
public:
    objetPortable(double solidite);
    void encaisse(double degats);
    void regenere(int montant);
    double solidite() const;
private:
    double d_solidite;
};
}
#endif // OBJETPORTABLE_H

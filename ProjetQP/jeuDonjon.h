#ifndef JEUDONJON_H
#define JEUDONJON_H
#include <vector>
#include <memory>
#include "element.h"
#include "aventurier.h"
#include "monstre.h"
namespace jeu
{

class jeuDonjon
{
    public:
        jeuDonjon();
        jeuDonjon(std::string nomFichier);
        void afficheDonjon()const;
        void afficheAventurier()const;
        void afficheMonstre()const;
        void display()const;
        int colonnes()const;
        int lignes()const;
        int tourAventurier();
        int tourMonstres();
        void deplacementAventurier(point &PositionCase);
        int interactionAmulette(point &PositionCase);
        int interactionAventurierMonstre(point &PositionCase);
        int interactionMonstreAventurier(int i);
        int interactionSacDePiece(point &PositionCase);
        int interactionCaseVide(point &PositionCase);
        int interactionMonstreCaseVide(int i,const point &PositionCase);
        void MonstreAlentour(vector<monstre> &tabMonstreAlentour)const;
        void detruitMonstre(int vieMonstre,int i);
        int mouvementAventurier(point posTest);
        int choixMouvementAventurier(int choix);
        int mouvementMonstre(int i,point posTest);
        int choixMouvementMonstre(int i,int choix);
        int chercheMonstre(point &pos)const;
        int meilleureDirection(int i)const;
        void win()const;
        void loose()const;
        int menu()const;
        void menuSacDePiece();
        void afficheCommande()const;
        void run();

    private:
        std::vector<std::vector<std::unique_ptr<element>>> d_donjon;
        int d_lignes, d_colonnes;
        aventurier d_Aventurier;
        std::vector<monstre> d_tabMonstre;
        static constexpr int VIE_MONSTRE = 70;
        static constexpr int FORCE_MONSTRE = 40;
        static constexpr int HABILETE_MONSTRE = 90;
        static constexpr int VIE_AVENTURIER = 100;
        static constexpr int FORCE_AVENTURIER = 5;
};
}
#endif // JEUDONJON_H

#include "jeuDonjon.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "aventurier.h"
#include "amulette.h"
#include "mur.h"
#include "monstre.h"
#include "sacDePiece.h"
#include "cellule.h"
#include "point.h"
#include <random>
#include <ctime>
#include <conio.h>
#include <cmath>


namespace jeu
{
/////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION D'INITIALISATION
/////////////////////////////////////////////////////////////////////////////////////////////////////

jeuDonjon::jeuDonjon():d_Aventurier(VIE_AVENTURIER,FORCE_AVENTURIER)
{
    std::ifstream fIN("DefaultDonjon.txt");
    if (fIN)
    {
        int lignes,colonnes;
        fIN>>lignes>>colonnes;

        d_lignes = lignes;
        d_colonnes = colonnes;

        d_donjon.resize(lignes);

        for(int i = 0 ; i < lignes ; ++i)
        {
            d_donjon[i].resize(colonnes);
        }

        char elem;

        for(int i = 0 ; i<lignes ; ++i)
        {
            for(int j = 0 ; j < colonnes ; ++j)
            {
                fIN>>elem;
                point pos(i,j);
                switch (elem){
                    case '@':
                        d_Aventurier.setPosition(pos);
                        d_donjon[i][j] = std::make_unique<aventurier>(d_Aventurier);
                        break;
                    case '&':
                        d_donjon[i][j] = std::make_unique<amulette>(pos);
                        break;
                    case '8':
                        {
                        monstre mstr(pos,VIE_MONSTRE,FORCE_MONSTRE,HABILETE_MONSTRE,rand()%2);
                        d_donjon[i][j] = std::make_unique<monstre>(mstr);
                        d_tabMonstre.push_back(mstr);
                        break;
                        }
                    case '#':
                        d_donjon[i][j] = std::make_unique<mur>(pos);
                        break;
                    case '$':
                        d_donjon[i][j] = std::make_unique<sacDePiece>(pos);
                        break;
                    case ':':
                        d_donjon[i][j] = std::make_unique<cellule>(pos,0);
                        break;
                    case '.':
                        d_donjon[i][j] = std::make_unique<cellule>(pos,1);
                        break;
                    }
            }
        }
        fIN.close();
    }
}

jeuDonjon::jeuDonjon(string nomFichier) : d_Aventurier(VIE_AVENTURIER,FORCE_AVENTURIER)
{

    std::ifstream fIN(nomFichier+".txt");
    if (fIN)
    {
        int lignes,colonnes;
        fIN>>lignes>>colonnes;

        d_lignes = lignes;
        d_colonnes = colonnes;

        d_donjon.resize(lignes);

        for(int i = 0 ; i < lignes ; ++i)
        {
            d_donjon[i].resize(colonnes);
        }

        char elem;

        for(int i = 0 ; i<lignes ; ++i)
        {
            for(int j = 0 ; j < colonnes ; ++j)
            {
                fIN>>elem;
                point pos(i,j);

                switch (elem){
                    case '@':
                        d_Aventurier.setPosition(pos);
                        d_donjon[i][j] = std::make_unique<aventurier>(d_Aventurier);
                        break;
                    case '&':
                        d_donjon[i][j] = std::make_unique<amulette>(pos);
                        break;
                    case '8':
                        {
                        monstre mstr(pos,VIE_MONSTRE,FORCE_MONSTRE,HABILETE_MONSTRE,rand()%2);
                        d_donjon[i][j] = std::make_unique<monstre>(mstr);
                        d_tabMonstre.push_back(mstr);
                        break;
                        }
                    case '#':
                        d_donjon[i][j] = std::make_unique<mur>(pos);
                        break;
                    case '$':
                        d_donjon[i][j] = std::make_unique<sacDePiece>(pos);
                        break;
                    case ':':
                        d_donjon[i][j] = std::make_unique<cellule>(pos,0);
                        break;
                    case '.':
                        d_donjon[i][j] = std::make_unique<cellule>(pos,1);
                        break;
                    }
            }
        }
        fIN.close();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION D'INFORMATION
/////////////////////////////////////////////////////////////////////////////////////////////////////

int jeuDonjon::lignes()const
{
    return d_lignes;
}

int jeuDonjon::colonnes()const
{
    return d_colonnes;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION AVENTURIER
/////////////////////////////////////////////////////////////////////////////////////////////////////

int jeuDonjon::tourAventurier()
{
    char ch;
    std::cin>>ch; // Utilisation de _getch() pour capturer une touche
    return choixMouvementAventurier(ch);
}

void jeuDonjon::deplacementAventurier(point &PositionCase)
{
    point PositionAventurier(d_Aventurier.position());
    std::swap(d_donjon[PositionCase.x()][PositionCase.y()],d_donjon[PositionAventurier.x()][PositionAventurier.y()]);
    d_donjon[PositionAventurier.x()][PositionAventurier.y()] = std::make_unique<cellule>(PositionAventurier,true);
    d_Aventurier.setPosition(PositionCase);
}

int jeuDonjon::mouvementAventurier(point posTest)
{
    char elem = d_donjon[posTest.x()][posTest.y()]->affiche();

                switch (elem)
                    {
                    case '&':
                        return interactionAmulette(posTest);
                        break;

                    case '8':
                    {
                        return interactionAventurierMonstre(posTest);
                        break;
                    }
                    case '#':
                        return 0;
                        break;

                    case '$':
                        {
                        return interactionSacDePiece(posTest);
                        break;
                        }

                    case ':':
                        if(d_Aventurier.amulette())
                            return 2;
                        else
                            return 0;
                        break;

                    case '.':
                        return interactionCaseVide(posTest);
                        break;
                    }

}
int jeuDonjon::choixMouvementAventurier(int choix)
{
    switch(choix)
        {
            case 'z':
            { // Flèche haut

                if(d_Aventurier.position().x()-1 > 0)
                {
                    point posTest(d_Aventurier.position());
                    posTest.deplaceDe(-1,0);
                    return mouvementAventurier(posTest);
                }
                return 0;
                break;
            }
            case 's': // Flèche bas
            {
                if(d_Aventurier.position().x()+1 < d_donjon.size())
                {
                    point posTest(d_Aventurier.position());
                    posTest.deplaceDe(1,0);
                    return mouvementAventurier(posTest);
                }
                return 0;
                break;
            }

            case 'q': // Flèche gauche
                {
                if(d_Aventurier.position().y()-1 > 0)
                {
                    point posTest(d_Aventurier.position());
                    posTest.deplaceDe(0,-1);
                    return mouvementAventurier(posTest);
                }
                return 0;
                break;
            }
            case 'd': // Flèche droite
                if(d_Aventurier.position().y()+1 < d_donjon[0].size())
                {
                    point posTest(d_Aventurier.position());
                    posTest.deplaceDe(0,1);
                    return mouvementAventurier(posTest);
                }
                return 0;
                break;
            case '$': // Menu Sac de pieces
                menuSacDePiece();
                break;
            case 'L': // Quitter
                return -5;
                break;
        }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION MONSTRE
/////////////////////////////////////////////////////////////////////////////////////////////////////

int jeuDonjon::tourMonstres()
{
    for(int i = 0; i < d_tabMonstre.size() ; ++i)
    {
        int choix;
        if(d_tabMonstre[i].voyant())
        {
            choix = meilleureDirection(i);
            while(choixMouvementMonstre(i,choix) == 0 )
            {
                choix++;
                choix = choix%4;
            }
        }
        else
        {
            choix = rand()%4;
            while(choixMouvementMonstre(i,choix) == 0 )
            {
                choix++;
                choix = choix%4;
            }

        }
    }
}


int jeuDonjon::choixMouvementMonstre(int i,int choix)
{
    monstre mstr = d_tabMonstre[i];
        switch(choix)
        {
            case 0:
            { // Flèche haut

                if(mstr.position().x()-1 > 0)
                {
                    point posTest(mstr.position());
                    posTest.deplaceDe(-1,0);
                    return mouvementMonstre(i,posTest);
                }
                return 0;
                break;
            }
            case 1: // Flèche bas
            {
                if(mstr.position().x()+1 < d_donjon.size())
                {
                    point posTest(mstr.position());
                    posTest.deplaceDe(1,0);
                    return mouvementMonstre(i,posTest);
                }
                return 0;
                break;
            }

            case 2: // Flèche gauche
                {
                if(mstr.position().y()-1 > 0)
                {
                    point posTest(mstr.position());
                    posTest.deplaceDe(0,-1);
                    return mouvementMonstre(i,posTest);
                }
                return 0;
                break;
            }
            case 3: // Flèche droite
                if(mstr.position().y()+1 < d_donjon[0].size())
                {
                    point posTest(mstr.position());
                    posTest.deplaceDe(0,1);
                    return mouvementMonstre(i,posTest);
                }
                return 0;
                break;
            }
}

int jeuDonjon::mouvementMonstre(int i,point posTest)
{
    char elem = d_donjon[posTest.x()][posTest.y()]->affiche();

                switch (elem)
                    {

                    case '&':
                        return 0;
                        break;

                    case '@':
                    {
                        return interactionMonstreAventurier(i);
                        break;
                    }
                    case '#':
                        return 0;
                        break;

                    case '$':
                        {
                        return 0;
                        break;
                        }

                    case ':':
                            return 0;
                        break;

                    case '.':
                        return interactionMonstreCaseVide(i,posTest);
                        break;
                    }

}

int jeuDonjon::meilleureDirection(int i)const
{
    point pos = d_tabMonstre[i].position();
    pos.deplaceDe(-1,0);
    double distanceHaut = d_Aventurier.position().distance(pos);

    pos = d_tabMonstre[i].position();
    pos.deplaceDe(1,0);
    double distanceBas = d_Aventurier.position().distance(pos);

    pos = d_tabMonstre[i].position();
    pos.deplaceDe(0,-1);
    double distanceGauche = d_Aventurier.position().distance(pos);

    pos = d_tabMonstre[i].position();
    pos.deplaceDe(0,1);
    double distanceDroite = d_Aventurier.position().distance(pos);

    double minimum1 = std::min(distanceHaut,distanceDroite);
    double minimum2 = std::min(distanceGauche,distanceBas);
    double minimum = std::min(minimum1,minimum2);

    if(minimum == distanceHaut)
        return 0;
    if(minimum == distanceBas)
        return 1;
    if(minimum == distanceGauche)
        return 2;
    if(minimum == distanceDroite)
        return 3;

}

void jeuDonjon::MonstreAlentour(vector<monstre> &tabMonstreAlentour)const
{
    for(int i = 0 ; i < d_tabMonstre.size() ; ++i)
    {
        if(d_tabMonstre[i].position().distance(d_Aventurier.position()) < 5)
            tabMonstreAlentour.push_back(d_tabMonstre[i]);
    }
}

int jeuDonjon::chercheMonstre(point &pos)const
{
    int i = 0;
    int taille = d_tabMonstre.size();
    while( i<taille && d_tabMonstre[i].position() != pos )
    {
        ++i;
    }
    return i;
}

void jeuDonjon::detruitMonstre(int vieMonstre,int i)
{
    monstre temp = d_tabMonstre[i];
    d_tabMonstre[i] = d_tabMonstre.back();
    d_tabMonstre.back() = temp;
    d_tabMonstre.pop_back();

    d_Aventurier.augmenteVie(vieMonstre * 0.75);
    d_Aventurier.augmenteForce(vieMonstre * 0.25);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION INTERACTION
/////////////////////////////////////////////////////////////////////////////////////////////////////

int jeuDonjon::interactionAmulette(point &PositionCase)
{
    d_Aventurier.obtientAmulette();
    deplacementAventurier(PositionCase);
    return 1;
}

int jeuDonjon::interactionAventurierMonstre(point &PositionCase)
{
    int i = chercheMonstre(PositionCase);
    monstre mstr = d_tabMonstre[i];
    int vieMonstre = mstr.vie();
    while(d_Aventurier.estEnVie() && mstr.estEnVie())
    {
        d_Aventurier.infligeDegats(mstr);
        mstr.infligeDegats(d_Aventurier);
    }
    if(d_Aventurier.estEnVie())
    {
        deplacementAventurier(PositionCase);
        detruitMonstre(vieMonstre,i);
        return 1;
    }
    else
    {
        return -1;
    }

}

int jeuDonjon::interactionMonstreAventurier(int i)
{
    monstre mstr = d_tabMonstre[i];
    int vieMonstre = mstr.vie();
    point PositionMonstre(d_tabMonstre[i].position());
    d_donjon[PositionMonstre.x()][PositionMonstre.y()] = std::make_unique<cellule>(PositionMonstre,true);
    while(d_Aventurier.estEnVie() && mstr.estEnVie())
    {
        mstr.infligeDegats(d_Aventurier);
        d_Aventurier.infligeDegats(mstr);
    }
    if(d_Aventurier.estEnVie())
    {
        detruitMonstre(vieMonstre,i);
        return 1;
    }
    else
    {
        return -1;
    }

}

int jeuDonjon::interactionSacDePiece(point &PositionCase)
{
    sacDePiece* sdp = dynamic_cast<jeu::sacDePiece*>(d_donjon[PositionCase.x()][PositionCase.y()].get());
    d_Aventurier.obtientPieces(sdp->montant());
    deplacementAventurier(PositionCase);
    return 1;
}

int jeuDonjon::interactionCaseVide(point &PositionCase)
{
    deplacementAventurier(PositionCase);
    return 1;
}

int jeuDonjon::interactionMonstreCaseVide(int i,const point &PositionCase)
{
    monstre mstr = d_tabMonstre[i];
    point PositionMonstre(d_tabMonstre[i].position());
    std::swap(d_donjon[PositionCase.x()][PositionCase.y()],d_donjon[PositionMonstre.x()][PositionMonstre.y()]);
    d_donjon[PositionMonstre.x()][PositionMonstre.y()] = std::make_unique<cellule>(PositionMonstre,true);
    d_tabMonstre[i].setPosition(PositionCase);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//FONCTION D'AFFICHAGE
/////////////////////////////////////////////////////////////////////////////////////////////////////

void jeuDonjon::display()const
{
    system("cls");
    afficheCommande();
    afficheDonjon();
    afficheAventurier();
    afficheMonstre();

}

void jeuDonjon::afficheDonjon()const
{
        for(int i = 0 ; i<lignes() ; ++i)
        {
            std::cout<< endl <<std::setw(40) << ' ' ;
            for(int j = 0 ; j<colonnes() ; ++j)
            {
                std::cout<<setw(1)<<d_donjon[i][j]->affiche();
            }
        }
        cout<<endl;
}

void jeuDonjon::afficheAventurier()const
{
    for(int i = 0 ; i < 125 ; ++i)
            cout<<'_';
        cout<<endl<<std::setw(14)<<' '<<"AVENTURIER"<<endl;
        cout<<std::setw(5)<<' '<<"VIE : "<<d_Aventurier.vie();
        cout<<std::setw(5)<<' '<<"FORCE : "<<d_Aventurier.force();
        cout<<std::setw(5)<<' '<<"ARMURE : "<<d_Aventurier.soliditeArmure();
        cout<<std::setw(5)<<' '<<"EPEE : "<<d_Aventurier.soliditeEpee();
        cout<<std::setw(5)<<' '<<"BOURSE : "<<d_Aventurier.bourse();
        cout<<std::setw(5)<<' '<<"AMULETTE OBTENUE : ";
        if(d_Aventurier.amulette() == true)
            cout<<"OUI"<<endl;
        else
            cout<<"NON"<<endl;
        cout<<std::setw(5)<<' '<<"POSITION : ("<<d_Aventurier.position().x()<<" ; "<<d_Aventurier.position().y()<<')'<<endl;
        cout<<endl;
        for(int i = 0 ; i < 125 ; ++i)
            cout<<'_';
        cout<<endl;
}
void jeuDonjon::afficheMonstre()const
{
        vector<monstre> mstr;
        MonstreAlentour(mstr);
        for(int i = 0 ; i < mstr.size() ; ++i)
        {
            cout<<std::setw(14)<<' '<<"MONSTRE "<<i<<endl;
            cout<<std::setw(5)<<' '<<"VIE : "<<mstr[i].vie();
            cout<<std::setw(5)<<' '<<"FORCE : "<<mstr[i].force();
            cout<<std::setw(5)<<' '<<"HABILETE : "<<mstr[i].habilete();
            cout<<std::setw(5)<<' '<<"VOYANT : ";
        if(mstr[i].voyant() == true)
            cout<<"OUI"<<endl;
        else
            cout<<"NON"<<endl;
        cout<<std::setw(5)<<' '<<"POSITION : ("<<mstr[i].position().x()<<" ; "<<mstr[i].position().y()<<')'<<endl;
        cout<<endl;
        for(int i = 0 ; i < 125 ; ++i)
            cout<<'_';
        }
        cout<<endl;
}

void jeuDonjon::afficheCommande()const
{
    system("cls");
    cout<<"                HAUT : Z          "<<endl;
    cout<<" <- GAUCHE : Q   ||  DROITE : D ->"<<endl;
    cout<<"                BAS : S           "<<endl;
    cout<<"UTILISER SON OR : $ "<<endl;
    cout<<"QUITTER :  L"<<endl;
}

void jeuDonjon::win()const
{
    system("cls");
    for(int i = 0 ; i < 29 ; ++i)
        cout<<'_';
    cout<<endl<<'|'<<std::setw(5)<<' '<<" !!! VOUS AVEZ !!!"<<std::setw(5)<<'|'<<endl;
    cout<<endl<<'|'<<std::setw(5)<<' '<<" !!! GAGNE !!! "<<std::setw(8)<<'|'<<endl;
    for(int i = 0 ; i < 29 ; ++i)
        cout<<'_';
    cout<<endl;
}

void jeuDonjon::loose()const
{
    system("cls");
    for(int i = 0 ; i < 29 ; ++i)
        cout<<'_';
    cout<<endl<<'|'<<std::setw(5)<<' '<<" ??? VOUS AVEZ ???"<<std::setw(5)<<'|'<<endl;
    cout<<endl<<'|'<<std::setw(5)<<' '<<" ??? PERDU ??? "<<std::setw(8)<<'|'<<endl;
    for(int i = 0 ; i < 29 ; ++i)
        cout<<'_';
    cout<<endl;
}

int jeuDonjon::menu()const
{
    system("cls");
    int rez;
    cout<<"MENU :"<<endl<<endl;
    cout<<"(1) JOUER "<<endl;
    cout<<"(2) COMMANDE "<<endl;
    cout<<"(3) QUITTER "<<endl;
    cin>>rez;
    return rez;
}

void jeuDonjon::menuSacDePiece()
{
    int choixReparation,montant;
    cout<<"VOUS POSSEDEZ : "<<d_Aventurier.bourse()<<" PIECES"<<endl;
    cout<<"REPARER (1)ARMURE"<<endl<<"        (2)EPEE "<<endl<<"        (3)ANNULER "<<endl;
    cin>>choixReparation;
    while(choixReparation != 1 && choixReparation != 2 && choixReparation != 3)
        cin>>choixReparation;
    if(choixReparation == 3)
        return;
    else
        cout<<"CHOISISSEZ LE MONTANT A UTILISER : "<<endl;
        cin>>montant;
    if(choixReparation == 1)
        d_Aventurier.regenereArmure(montant);
    else
        d_Aventurier.regenereEpee(montant);
}

void jeuDonjon::run()
{
    srand(time(NULL));
    int choix = menu();
    while(choix != 3 && (choix == 1 || choix== 2))
    {
    if(choix == 1)
    {
        display();
        int test = 0;
        while(d_Aventurier.estEnVie() && test != -3 && test != 108)
        {
            test =tourAventurier();
            tourMonstres();
            display();
        }
        if(test == -3)
            win();
        else if(test = 108)
            choix = menu();
        else if( !d_Aventurier.estEnVie())
            loose();
    }
    else if(choix == 2)
    {
        afficheCommande();
        getch();
        choix = menu();
    }
}
}

}



#ifndef MODEL_H
#define MODEL_H

#include <QTableWidget>
#include <QMainWindow>

#include "decor.h"
#include "personnages.h"
#include "ressources.h"
#include "autre.h"
#include <QList>
#include <QGraphicsTextItem>

class Decor;
class Village;
class View;
class Foret1;
class Foret2;
class Foret3;
class Foret4;
class Foret5;
class Foret6;
class Foret7;

class Model
{
    private:
        Ressource *sacSalsepareilles = new Ressource("SalsePareilles");
        Ressource *sacBles = new Ressource("Bles");
        ChampBle *champBle = new ChampBle();
        Nourritures *sacPains = new Nourritures("Pains", 10);
        Nourritures *sacBaies = new Nourritures("Baies", 10);
        Nourritures *sacNoisettes = new Nourritures("Noisettes", 5);

        QList<PersoGentil *> *listSGentil = new QList<PersoGentil *>;
        QList<PersoMechant *> *listSMechant = new QList<PersoMechant *>;
        QList<QString> *listConseilGrandS = new QList<QString>;
        QList<QString> *listConseilSette = new QList<QString>;
        QList<Decor *> *listDecor = new QList<Decor *>;

        int villagePosX, villagePosY;

        bool message = false;

    public:
        Model();
        Village *setVillage(int x, int y, View *view);
        Foret1 *setForet1(int x, int y, View *view);
        Foret2 *setForet2(int x, int y, View *view);
        Foret3 *setForet3(int x, int y, View *view);
        Foret4 *setForet4(int x, int y, View *view);
        Foret5 *setForet5(int x, int y, View *view);
        Foret6 *setForet6(int x, int y, View *view);
        Foret7 *setForet7(int x, int y, View *view);

        QList<PersoGentil *> *getlistSGentil() {return this->listSGentil;}
        QList<PersoMechant *> *getlistSMechant() {return this->listSMechant;}

        Ressource *getSacSalsepareilles() {return sacSalsepareilles;}
        Ressource *getSacBles() {return sacBles;}
        ChampBle *getChampBle() {return this->champBle;}
        int getNumberWheatToRecolt() {return champBle->getNbBleARecolter();}
        void useWheat(int nbWheat) {this->getSacBles()->retirerRessource(nbWheat);}
        Nourritures *getSacPains() {return sacPains;}
        void makeBred(int nbBred) {this->getSacPains()->ajouterRessource(nbBred);}
        Nourritures *getSacBaies() {return sacBaies;}
        Nourritures *getSacNoisettes() {return sacNoisettes;}
        
        void actionPerso(int x, int y, int nbS);
        void addPersoGentil(PersoGentil *S) {listSGentil->append(S);}
        void addPersoMechant(PersoMechant *S) {listSMechant->append(S);}
        void addDecor(Decor *D) {listDecor->append(D);}
        int getNbSFree();
        QList<PersoGentil *> getPersoGentil() {return *listSGentil;}
        QList<PersoMechant *> getPersoMechant() {return *listSMechant;}
        QList<Decor *> getDecor() {return *listDecor;}

        int getVillagePosX() {return villagePosX;}
        int getVillagePosY() {return villagePosY;}

        bool getMessage() {return this->message;}
        void setMessage(bool message) {this->message = message;}
        QGraphicsTextItem *getMessageSette();
        QGraphicsTextItem *getMessageGrandS();
        Image *getImageBulleGrandS();
        Image *getImageBulleSette();
        Image *getImageGrandS();
        Image *getImageSette();

};

#endif // MODEL_H

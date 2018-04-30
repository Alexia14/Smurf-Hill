#ifndef MODEL_H
#define MODEL_H

#include <QTableWidget>
#include <QMainWindow>

#include "decor.h"
#include "personnages.h"
#include <QList>

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

        QList<PersoGentil *> *getlistSGentil() {return this->listSGentil;}

};

#endif // MODEL_H

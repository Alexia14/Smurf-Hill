#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "autre.h"
#include "view.h"
#include "model.h"

#include <QObject>
#include <QWidget>
#include <QGraphicsTextItem>
#include <QTimer>

//class Model;
class View;

class Controller: public QObject
{
    Q_OBJECT

    public slots:
        void gameLoop();

    private:

        Model *model;
        View *view;
        QTimer *timer;
        QTimer *timerBle;

    public:

        Controller(Model *model, View *view);
        void startGame(QString decor, QString persoGentil, QString persoMechant);
        void continueGame();
        void clickedOnMap(int x, int y);
        void actionPerso(int x, int y, int nbS);
        void sauvegarde();
        void sauverQuitter();

        int distanceEntrePersos(Perso *S, Perso *M);
        QPointF *getPointDecale(QPointF *pointOrigine, QPointF *pointSuivant);
        int getNbSFree();
        int getVillagePosX() {return this->model->getVillagePosX();}
        int getVillagePosY() {return this->model->getVillagePosY();}
        QList<PersoGentil *> getPersoGentil() {return this->model->getPersoGentil();}
        QList<PersoMechant *> getPersoMechant() {return this->model->getPersoMechant();}
        QList<Decor *> getDecor() {return this->model->getDecor();}

        bool isMessageDisplayed() {return this->model->getMessage();}
        void setMessageDisplayed(bool message) {this->model->setMessage(message);}
        QGraphicsTextItem *getMessageGrandS() {return this->model->getMessageGrandS();}
        QGraphicsTextItem *getMessageSette() {return this->model->getMessageSette();}
        Image *getImageBulleGrandS() {return this->model->getImageBulleGrandS();}
        Image *getImageBulleSette() {return this->model->getImageBulleSette();}
        Image *getImageGrandS() {return this->model->getImageGrandS();}
        Image *getImageSette() {return this->model->getImageSette();}
        void recoltWheat();
        int getNumberWheatToRecolt() {return this->model->getNumberWheatToRecolt();}
        int getNumberWheat() {return this->model->getSacBles()->getNombre();}
        void makeBred(int nbBred);

};


#endif // CONTROLLER_H

#include "view.h"
#include "controller.h"
#include "model.h"
#include "autre.h"
#include "personnages.h"
#include "decor.h"

#include <QMessageBox>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QFileDialog>
#include <QGraphicsView>
#include <QDateTime>
#include <QCoreApplication>
#include <QPointF>
#include <QtDebug>
#include <math.h>
#include <time.h>

Controller::Controller(Model *model, View *view): QObject(0) {
    this->model = model;
    this->view = view;
    this->view->setControl(this);
    timer = new QTimer;
    timerBle = new QTimer;
    //Q_ASSERT(timer == NULL);
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    connect(timerBle, SIGNAL(timeout()), this->model->getChampBle(), SLOT(ete()));
    /*game_loop();
    QTimer *timer = new QTimer();
    qDebug() << "Salut";
    timer->setInterval(16);
    qDebug() << connect(timer, SIGNAL(timeout()), this, SLOT(game_loop()));
    qDebug() << "Wesh";
    timer->start();*/

}

void Controller::startGame(QString decor, QString persoGentil, QString persoMechant) {
    QStringList listDecor = decor.split(" ");
    view->installScene();
    for (int i=0; i<listDecor.size()-1; i+=3) {
        if (listDecor[i] == "V") view->addVillage(this->model->setVillage(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
        else if(listDecor[i] == "F1") view->addForet1(this->model->setForet1(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
        else if(listDecor[i] == "F2") view->addForet2(this->model->setForet2(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
        else if(listDecor[i] == "F3") view->addForet3(this->model->setForet3(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
        else if(listDecor[i] == "F4") view->addForet4(this->model->setForet4(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
        else if(listDecor[i] == "F5") view->addForet5(this->model->setForet5(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
        else if(listDecor[i] == "F6") view->addForet6(this->model->setForet6(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
        else if(listDecor[i] == "F7") view->addForet7(this->model->setForet7(listDecor[i+1].toInt(), listDecor[i+2].toInt(), view));
    }

    QStringList listPersoGentil = persoGentil.split(" ");
    for (int i=0; i<listPersoGentil.size()-1; i+=4) {
        PersoGentil *S = new PersoGentil(listPersoGentil[i].toInt(), listPersoGentil[i+1].toInt(), listPersoGentil[i+2].toInt(), listPersoGentil[i+3].toInt());
        model->addPersoGentil(S);
        view->addPersoNormaux(S);
    }

    QStringList listPersoMechant = persoMechant.split(" ");
    for (int i=0; i<listPersoMechant.size()-1; i+=4) {
        PersoMechant *S = new PersoMechant(listPersoMechant[i].toInt(), listPersoMechant[i+1].toInt(), listPersoMechant[i+2].toInt(), listPersoMechant[i+3].toInt());
        model->addPersoMechant(S);
        view->addPersoNormaux(S);
    }

    this->timer->start(16);
    this->timerBle->start(1000);
}

void Controller::continueGame() {

    QString decor;
    QString persoGentil;
    QString persoMechant;
    QFile file("sauvegarde.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::about(view, "Erreur", "Impossible de lire le fichier de sauvegarde");
    }
    else {
        QTextStream flux(&file);
        QString date = flux.readLine();
        QMessageBox::information(view, "Date de sauvegarde", date);
        decor = flux.readLine();
        persoGentil = flux.readLine();
        persoMechant = flux.readLine();
    }
    file.close();
    startGame(decor, persoGentil, persoMechant);
    PersoMechant *S5 = new PersoMechant(400, 50, 0, 2);
    model->addPersoMechant(S5);
    view->addPersoNormaux(S5);


    this->timer->start(16);
    this->timerBle->start(1000);

}

void Controller::gameLoop() {

    for (PersoGentil *S : *this->model->getlistSGentil()) {

        if (S->hasAction()) {
            ActionMove* nextAction = dynamic_cast<ActionMove*>(S->getFirstAction());

            S->setPos(S->getPosX() + nextAction->getDepX(), S->getPosY() + nextAction->getDepY());
            //delete nextAction;
            S->removeFirstAction();

            QList<QGraphicsItem *> listCollision = S->getImagePerso()->collidingItems();

            for (QGraphicsItem * i : listCollision) {

                ImageDecor *itemDecor = dynamic_cast<ImageDecor *>(i);

                if (itemDecor) {

                    QPointF *pointDestination = S->getDestination();
                    S->removeAllActions();

                    QPointF *pointSuivant = new QPointF(S->getPosX(), S->getPosY());

                    //qDebug() << "point SUivant 1 [" << pointSuivant->x() << ";" << pointSuivant->y() << "]";

                    //S->setPos(S->getPosX() - nextAction->getDepX(), S->getPosY() - nextAction->getDepY());

                    QPointF *pointOrigine = new QPointF(S->getPosX()-nextAction->getDepX(), S->getPosY()-nextAction->getDepY());

                    //qDebug() << "point Origine [" << pointOrigine->x() << ";" << pointOrigine->y() << "]";

                    pointSuivant = this->getPointDecale(pointOrigine, pointSuivant);

                    //qDebug() << "point SUivant 2 [" << pointSuivant->x() << ";" << pointSuivant->y() << "]";

                    //delete nextAction;

                    S->setPos(pointSuivant->x(), pointSuivant->y());
                    S->moveTo(pointDestination->x(), pointDestination->y());

                }

            }

            // Regarder s'il n'y a pas collision

            for (PersoMechant *M : *this->model->getlistSMechant()) {

                if (distanceEntrePersos(S, M) < 100) {

                    S->removeAllActions();

                }

            }

            // Si oui retour en arrière et décallage
            // Puis on regarde les ennemis
        }

    }

    for (PersoMechant *S : *this->model->getlistSMechant()) {

    }

}

int Controller::distanceEntrePersos(Perso *S, Perso *M) {

    return sqrt(pow((S->getPosX() - M->getPosX()), 2) + pow((S->getPosY() - M->getPosY()), 2));

}

QPointF *Controller::getPointDecale(QPointF *pointOrigine, QPointF *pointSuivant) {

    QPointF *nouveauPoint = new QPointF;
    double rayon = sqrt(pow((pointOrigine->x() - pointSuivant->x()), 2) + pow((pointOrigine->y() - pointSuivant->y()), 2));

    nouveauPoint->setX(pointOrigine->x() + (rayon * sin(M_PI + (M_PI / 3))));
    nouveauPoint->setY(pointOrigine->y() + (rayon * cos(M_PI + (M_PI / 3))));

    return nouveauPoint;

}


void Controller::actionPerso(int x, int y, int nbS) {
    qDebug() << "Test";
    this->model->actionPerso(x, y, nbS);
}

int Controller::getNbSFree() {
    return this->model->getNbSFree();
}

void Controller::sauvegarde() {
    QFile file("sauvegarde.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::about(view, "Erreur", "Impossible de sauvegarder");
    }
    else {
        QTextStream flux(&file);
        flux << "Date de la derniere sauvegarde : " << QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss") << endl;

        QList<Decor *> listD = getDecor();
        for (int i=0; i<listD.size(); i++) {
            flux << listD.at(i)->getType() << " " << listD.at(i)->getPosX() << " " << listD.at(i)->getPosY() << " ";
        }
        flux << endl;
        QList<PersoGentil *> listPG = getPersoGentil();
        for (int i=0; i<listPG.size(); i++) {
            flux << listPG.at(i)->getPosX() << " " << listPG.at(i)->getPosY() << " " << listPG.at(i)->getPv() << " " << listPG.at(i)->getVitesse() << " ";
        }
        flux << endl;
        QList<PersoMechant *> listPM = getPersoMechant();
        for (int i=0; i<listPM.size(); i++) {
            flux << listPM.at(i)->getPosX() << " " << listPM.at(i)->getPosY() << " " << listPM.at(i)->getPv() << " " << listPM.at(i)->getVitesse() << " ";
        }
    }
    file.close();
}

void Controller::sauverQuitter() {
    sauvegarde();
    QCoreApplication::quit();

} 

void Controller::recoltWheat() {

    /*Ressource *wheats = this->model->getSacBles();
    wheats->ajouterRessource(this->model->nbBleARecolter);*/
    this->model->getChampBle()->recolter(this->model->getSacBles());

}

void Controller::makeBred(int nbBred) {

    this->model->useWheat(nbBred * 2);
    this->model->makeBred(nbBred);

}

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

Controller::Controller(Model *model, View *view) :
    view(view)
{
    this->model = model;
    view->setControl(this);
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
}

void Controller::actionPerso(int x, int y, int nbS) {
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

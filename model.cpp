#include "view.h"
#include "controller.h"
#include "model.h"
#include "decor.h"
#include "personnages.h"
#include <time.h>

Model::Model()
{
    this->listConseilGrandS->append("Je veille chaque jour à ce que \nmes petits Schtroumpfs ne \nmanquent de rien !");
    this->listConseilGrandS->append("Schtroumpfera bien qui \nSchtroumpfera le dernier !");
    this->listConseilGrandS->append("Aller en foret te permettra de \ntrouver de la nouriture \npour le village.");
    this->listConseilGrandS->append("Le blé permet au Schtroumpf \nBoulanger de faire du pain.");
    this->listConseilGrandS->append("La salsepareille est un élément \nessentiel de notre alimentation.");
    this->listConseilGrandS->append("Prend garde aux \nSchtroumpfs noirs !");
    this->listConseilGrandS->append("Ah non, Schtroumpf à Lunettes... \nNe recommence pas avec tes \nréflexions schtroumpfistes !");
    this->listConseilGrandS->append("Prend garde à la réserve \nde nourriture, l'hiver \napproche à grand schtroumpf.");

    this->listConseilSette->append("Schtroumpf journée pour \nune promenade !");
    this->listConseilSette->append("Le Schtroumpf Bricoleur sait \ntoujours comment nous aider.");
    this->listConseilSette->append("\"Comme le dit toujours \nle Grand Schtroumpf...\", \nPff il est schtroumpfement pénible \nle Schtroumpf à Lunette...");
    this->listConseilSette->append("Waou! Qu'il est fort\nle Schtroumpf Costaud !");
    this->listConseilSette->append("Des noix ! Toujours des noix ! \nJe me demande ce qu’il peut \nbien schtroumpfer \navec toutes ces noix ?...");
    this->listConseilSette->append("Schtroumpf Grognon, tu ne veux \npas schtroumpfer à la balle, \ntu ne veux pas schtroumpfer du \ngâteau ni de la musique ! \nTu n’aimes donc rien ?");
    this->listConseilSette->append("Schtroumpfs Boulanger, \nSchtroumpf Patissier, \nvous mettez du soleil dans \nle coeur des Schtroumpfs !");
    this->listConseilSette->append("Le chemin du village est un \nsecret bien schtroumpfé ! \nGargamel ne pourra pas nous trouver.");
}

Village *Model::setVillage(int x, int y, View *view) {
    this->villagePosX = x;
    this->villagePosY = y;
    Village *villageS = new Village("V", this->villagePosX, this->villagePosY, view);
    addDecor(villageS);
    return villageS;
}

Foret1 *Model::setForet1(int x, int y, View *view) {
    Foret1 *foretN = new Foret1("F1", x, y, view);
    addDecor(foretN);
    return foretN;
}

Foret2 *Model::setForet2(int x, int y, View *view) {
    Foret2 *foretN = new Foret2("F2", x, y, view);
    addDecor(foretN);
    return foretN;
}

Foret3 *Model::setForet3(int x, int y, View *view) {
    Foret3 *foretN = new Foret3("F3", x, y, view);
    addDecor(foretN);
    return foretN;
}

Foret4 *Model::setForet4(int x, int y, View *view) {
    Foret4 *foretN = new Foret4("F4", x, y, view);
    addDecor(foretN);
    return foretN;
}

Foret5 *Model::setForet5(int x, int y, View *view) {
    Foret5 *foretN = new Foret5("F5", x, y, view);
    addDecor(foretN);
    return foretN;
}

Foret6 *Model::setForet6(int x, int y, View *view) {
    Foret6 *foretN = new Foret6("F6", x, y, view);
    addDecor(foretN);
    return foretN;
}

Foret7 *Model::setForet7(int x, int y, View *view) {
    Foret7 *foretN = new Foret7("F7", x, y, view);
    addDecor(foretN);
    return foretN;
}


void Model::actionPerso(int x, int y, int nbS) {

    // On met à jour les distancePositionClicked de chaque S

    for (int i=0; i<listSGentil->size(); i++) {

        listSGentil->at(i)->setDistancePositionClicked(abs(x-listSGentil->at(i)->getPosX())/(listSGentil->at(i)->getVitesse()));
        if (abs(y-listSGentil->at(i)->getPosX())/(listSGentil->at(i)->getVitesse()) > listSGentil->at(i)->getDistancePositionClicked())
            listSGentil->at(i)->setDistancePositionClicked(abs(y-listSGentil->at(i)->getPosX())/(listSGentil->at(i)->getVitesse()));

    }

    // On duplique la liste de S qu'on va trier en fonction de leur DistancePositionClicked
    QList<PersoGentil *> *listSorted = listSGentil;

    for (int i=(listSorted->size()-1); i>0; i--) {

        for (int j=0; j<(i); j++) {

            if (listSorted->at(j+1)->getDistancePositionClicked() < listSorted->at(j)->getDistancePositionClicked()) {
                listSorted->swap(j+1,j);
            }

        }

    }

    /*for (int i=0; i<listSorted->size(); i++) {

        qDebug() << " i = " << i << " Distance : " << listSorted->at(i)->getDistancePositionClicked() <<
                    " pos (" << listSorted->at(i)->getPosX() << "," << listSorted->at(i)->getPosY() << ")";

    }*/

    // On va déplacer les nbS premier S les plus proche du clique

    int cptSLibre=0;
    int cptS=0;

    while (cptSLibre < nbS) {

        if (listSorted->at(cptS)->isFree()) {
            listSorted->at(cptS)->moveTo(x, y);
            cptSLibre++;
        }

        cptS++;
    }
}

int Model::getNbSFree() {

    int cptS=0;

    for (int i=0; i<listSGentil->size(); i++) {
        if (listSGentil->at(i)->isFree())
            cptS++;
    }

    return cptS;

}

QGraphicsTextItem * Model::getMessageGrandS() {

    int MIN = 0, MAX = listConseilGrandS->size()-1;
    //srand(time(NULL));
    int message = (rand() % (MAX - MIN + 1)) + MIN;
    QString texte = this->listConseilGrandS->at(message);

    QGraphicsTextItem *texteItem = new QGraphicsTextItem(texte);
    texteItem->setPos(this->villagePosX + 155, this->villagePosY - 80);
    return texteItem;

}

QGraphicsTextItem * Model::getMessageSette() {

    int MIN = 0, MAX = listConseilSette->size()-1;
    //srand(time(NULL));
    int message = (rand() % (MAX - MIN + 1)) + MIN;
    QString texte = this->listConseilSette->at(message);

    QGraphicsTextItem *texteItem = new QGraphicsTextItem(texte);
    texteItem->setPos(this->villagePosX + 200, this->villagePosY - 110);
    return texteItem;

}

Image * Model::getImageBulleGrandS() {

    Image *imageBulle = new Image("/Users/Alexia/Desktop/images/bulleText.png");
    imageBulle->setPos(this->villagePosX + 80, this->villagePosY - 190);

    return imageBulle;

}

Image * Model::getImageBulleSette() {

    Image *imageBulle = new Image(":/images/bulleText");
    imageBulle->setPos(this->villagePosX + 125, this->villagePosY - 210);

    return imageBulle;

}

Image * Model::getImageGrandS() {

    Image *imageGrandS = new Image(":/images/GrandS");
    imageGrandS->setPos(this->villagePosX + 370, this->villagePosY - 180);

    return imageGrandS;

}


Image * Model::getImageSette() {

    Image *imageBulle = new Image(":/images/Sette01");
    imageBulle->setPos(this->villagePosX + 370, this->villagePosY - 180);

    return imageBulle;

}

#include "decor.h"
#include "view.h"

Decor::Decor(QString type, int posX, int posY, View *view): QObject() {

    this->type = type;
    this->posX = posX;
    this->posY = posY;
    this->view = view;

}

Village::Village(QString type, int posX, int posY, View *view): Decor(type, posX, posY, view) {

    this->maison1 = new ImageDecor(":/images/maisonS1");
    this->maison2 = new ImageDecor(":/images/maisonS2");
    this->maison3 = new ImageDecor(":/images/maisonS3");
    this->maison4 = new ImageDecor(":/images/maisonS4");
    this->maison5 = new ImageDecor(":/images/maisonS5");
    this->maison6 = new ImageDecor(":/images/maisonS6");
    this->maison7 = new ImageDecor(":/images/maisonS7");
    this->maison8 = new ImageDecor(":/images/maisonS8");
    this->maison9 = new ImageDecor(":/images/maisonS9");
    this->grandS = new ImageDecor(":/images/grandS");
    this->maisonSette = new ImageDecor("://images/maisonSette");
    this->maisonSCostaud = new ImageDecor("://images/maisonSCostaud");
    this->maisonSMusicien = new ImageDecor("://images/maisonSMusicien");
    this->maisonSPaysan = new ImageDecor("://images/maisonSPaysan");
    this->moulinS = new ImageDecor("://images/moulinS");
    this->puits = new ImageDecor("://images/puits");
    this->arbre1 = new ImageDecor("://images/arbre_1");
    this->arbre2 = new ImageDecor("://images/arbre_1");

    connect(this->maisonSette, SIGNAL(clicked()), this->view, SLOT(displayMessageSette()));
    connect(this->grandS, SIGNAL(clicked()), this->view, SLOT(displayMessageGrandS()));
    connect(this->maisonSMusicien, SIGNAL(clicked()), this->view, SLOT(musique()));
    connect(this->maisonSPaysan, SIGNAL(clicked()), this->view, SLOT(displayActionPaysan()));
    connect(this->maisonSCostaud, SIGNAL(clicked()), this->view, SLOT(displayActionCostaud()));

    this->grandS->setPos(posX + 145, posY + 85);
    this->maison1->setPos(posX + 200, posY - 40);
    this->maison2->setPos(posX - 100, posY - 10);
    this->maison3->setPos(posX - 20, posY + 25);
    this->maison4->setPos(posX + 325, posY - 70);
    this->maison5->setPos(posX + 150, posY - 100);
    this->maison6->setPos(posX + 270, posY + 190);
    this->maison7->setPos(posX + 5, posY - 80);
    this->maison8->setPos(posX + 155, posY + 175);
    this->maison9->setPos(posX - 120, posY + 80);
    this->maisonSette->setPos(posX + 105, posY -10);
    this->maisonSCostaud->setPos(posX + 300, posY + 25);
    this->maisonSMusicien->setPos(posX, posY+ 125);
    this->maisonSPaysan->setPos(posX + 425, posY + 100);
    this->moulinS->setPos(posX + 470, posY - 55);
    this->puits->setPos(posX + 170, posY + 100);
    this->arbre1->setPos(posX + 320, posY + 170);
    this->arbre2->setPos(posX + 400, posY + 100);

}

Foret::Foret(QString type, int posX, int posY, View *view): Decor(type, posX, posY, view) {
    nbNoisette = 10;
    nbBaie = 0;
    nbBle = 0;

    this->noisette = new ImageDecor(":/images/noisette");
    this->baie = new ImageDecor(":/images/baie");
    this->ble = new ImageDecor(":/images/ble");
}

void Foret::onResourceWheatClicked() {this->view->onResourceWheatClicked(this->ble->pos(), nbBle);}
void Foret::onResourceAcornClicked() {this->view->onResourceAcornClicked(this->noisette->pos(), nbNoisette);}
void Foret::onResourceBayClicked() {this->view->onResourceBayClicked(this->baie->pos(), nbBaie);}

Foret1::Foret1(QString type, int posX, int posY, View *view): Foret(type, posX, posY, view) {
    this->arbre1 = new ImageDecor(":/images/arbre1");
    this->arbre2 = new ImageDecor(":/images/arbre1");
    this->arbre3 = new ImageDecor(":/images/arbre1");
    this->arbre4 = new ImageDecor(":/images/arbre6");
    this->arbre5 = new ImageDecor(":/images/arbre4");
    this->arbre6 = new ImageDecor(":/images/arbre6");
    this->arbre7 = new ImageDecor(":/images/arbre6");
    this->arbre8 = new ImageDecor(":/images/arbre2");
    this->arbre9 = new ImageDecor(":/images/arbre7");
    this->arbre10 = new ImageDecor(":/images/arbre2");
    this->arbre11 = new ImageDecor(":/images/arbre2");
    this->arbre12 = new ImageDecor(":/images/arbre2");
    this->arbre13 = new ImageDecor(":/images/arbre7");
    this->arbre14 = new ImageDecor(":/images/arbre6");
    this->arbre15 = new ImageDecor(":/images/arbre6");
    this->arbre16 = new ImageDecor(":/images/arbre7");
    this->arbre17 = new ImageDecor(":/images/arbre10");

    this->buisson1 = new ImageDecor(":/images/buisson1");
    this->buisson2 = new ImageDecor(":/images/buisson2");
    this->buissonbaies1 = new ImageDecor(":/images/buissonbaies");
    this->buissonbaies2 = new ImageDecor(":/images/buissonbaies");

    this->arbre1->setPos(posX - 35, posY - 35);
    this->arbre2->setPos(posX + 175, posY - 100);
    this->arbre3->setPos(posX + 45, posY + 60);
    this->arbre4->setPos(posX, posY);
    this->arbre5->setPos(posX + 155, posY - 55);
    this->arbre6->setPos(posX + 220, posY - 50);
    this->arbre7->setPos(posX - 30, posY + 55);
    this->arbre8->setPos(posX + 140, posY - 80);
    this->arbre9->setPos(posX - 100, posY + 10);
    this->arbre10->setPos(posX + 100, posY + 110);
    this->arbre11->setPos(posX + 120, posY + 110);
    this->arbre12->setPos(posX + 110, posY + 120);
    this->arbre13->setPos(posX + 250, posY - 30);
    this->arbre14->setPos(posX + 200, posY - 130);
    this->arbre15->setPos(posX + 250, posY - 100);
    this->arbre16->setPos(posX + 120, posY - 120);
    this->arbre17->setPos(posX - 100, posY - 50);

    this->buisson1->setPos(posX + 260, posY + 40);
    this->buisson2->setPos(posX + 15, posY + 140);
    this->buissonbaies1->setPos(posX + 170, posY - 10);
    this->buissonbaies2->setPos(posX + 10, posY + 110);

    this->noisette->setPos(posX + 125, posY - 25);
    this->baie->setPos(posX + 110, posY + 80);
    this->ble->setPos(posX + 220, posY + 30);

    connect(this->noisette, SIGNAL(clicked()), SLOT(onResourceAcornClicked()));
    connect(this->baie, SIGNAL(clicked()), SLOT(onResourceBayClicked()));
    connect(this->ble, SIGNAL(clicked()), SLOT(onResourceWheatClicked()));
}

Foret2::Foret2(QString type, int posX, int posY, View *view): Foret(type, posX, posY, view) {
    this->arbre01 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre02 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre03 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre04 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre05 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre06 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre07 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre1 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre2 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre3 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre4 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre5 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre6 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre7 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre8 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre9 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre10 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre11 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre12 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre13 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre14 = new Image("/Users/Alexia/Desktop/images/arbre9.png");

    this->buissonbaies1 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buisson1 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson2 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson3 = new Image("/Users/Alexia/Desktop/images/buisson1.png");

    this->arbre01->setPos(posX - 30, posY - 40);
    this->arbre02->setPos(posX - 80, posY - 20);
    this->arbre03->setPos(posX - 115, posY + 5);
    this->arbre04->setPos(posX - 140, posY + 40);
    this->arbre05->setPos(posX + 25, posY - 35);
    this->arbre06->setPos(posX + 70, posY - 20);
    this->arbre07->setPos(posX + 120, posY + 20);
    this->arbre1->setPos(posX, posY);
    this->arbre2->setPos(posX - 60, posY + 20);
    this->arbre3->setPos(posX + 100, posY);
    this->arbre4->setPos(posX - 90, posY + 40);
    this->arbre5->setPos(posX + 60, posY + 10);
    this->arbre6->setPos(posX + 160, posY + 40);
    this->arbre7->setPos(posX - 130, posY + 80);
    this->arbre8->setPos(posX - 80, posY + 90);
    this->arbre9->setPos(posX + 140, posY + 50);
    this->arbre10->setPos(posX - 80, posY + 90);
    this->arbre11->setPos(posX - 120, posY + 120);
    this->arbre12->setPos(posX + 160, posY + 70);
    this->arbre13->setPos(posX - 100, posY + 150);
    this->arbre14->setPos(posX - 70, posY + 170);

    this->buissonbaies1->setPos(posX + 105, posY + 85);
    this->buisson1->setPos(posX - 85, posY + 250);
    this->buisson2->setPos(posX + 160, posY + 160);
    this->buisson3->setPos(posX, posY + 90);

    this->noisette->setPos(posX + 50, posY + 90);
    this->baie->setPos(posX + 130, posY + 140);
    this->ble->setPos(posX, posY + 200);
}

Foret3::Foret3(QString type, int posX, int posY, View *view): Foret(type, posX, posY, view) {
    this->arbre01 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre02 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre1 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre1 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre2 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre3 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre4 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre5 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre6 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre7 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre8 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre9 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre10 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre11 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre12 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre13 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre14 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre15 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre16 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre17 = new Image("/Users/Alexia/Desktop/images/arbre6.png");

    this->buissonbaies1 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buissonbaies2 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buissonbaies3 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buisson1 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson2 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->souche1 = new Image("/Users/Alexia/Desktop/images/souche2.png");


    this->arbre01->setPos(posX - 110, posY - 50);
    this->arbre02->setPos(posX - 140, posY - 10);
    this->arbre1->setPos(posX - 60, posY - 90);
    this->arbre2->setPos(posX + 20, posY - 90);
    this->arbre3->setPos(posX + 300, posY - 90);
    this->arbre4->setPos(posX + 230, posY - 80);
    this->arbre5->setPos(posX + 260, posY - 50);
    this->arbre6->setPos(posX + 320, posY - 20);
    this->arbre7->setPos(posX, posY - 50);
    this->arbre8->setPos(posX + 50, posY - 40);
    this->arbre9->setPos(posX - 45, posY - 25);
    this->arbre10->setPos(posX, posY);
    this->arbre11->setPos(posX + 250, posY);
    this->arbre12->setPos(posX - 60, posY + 30);
    this->arbre13->setPos(posX - 30, posY + 45);
    this->arbre14->setPos(posX + 300, posY + 25);
    this->arbre15->setPos(posX + 230, posY + 40);
    this->arbre16->setPos(posX - 110, posY + 55);
    this->arbre17->setPos(posX - 60, posY + 80);

    this->buissonbaies1->setPos(posX + 220, posY - 25);
    this->buissonbaies2->setPos(posX + 10, posY + 80);
    this->buissonbaies3->setPos(posX - 140, posY + 50);
    this->buisson1->setPos(posX + 250, posY + 100);
    this->buisson2->setPos(posX + 300, posY + 110);
    this->souche1->setPos(posX + 15, posY + 140);

    this->noisette->setPos(posX - 5, posY + 160);
    this->baie->setPos(posX + 70, posY + 70);
    this->ble->setPos(posX + 250, posY + 120);
}

Foret4::Foret4(QString type, int posX, int posY, View *view): Foret(type, posX, posY, view) {
    this->arbre1 = new Image("/Users/Alexia/Desktop/images/arbreM1.png");
    this->arbre2 = new Image("/Users/Alexia/Desktop/images/arbreM4.png");
    this->arbre3 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre4 = new Image("/Users/Alexia/Desktop/images/arbreM2.png");
    this->arbre5 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre6 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre7 = new Image("/Users/Alexia/Desktop/images/arbreM2.png");
    this->arbre8 = new Image("/Users/Alexia/Desktop/images/arbreM1.png");
    this->arbre9 = new Image("/Users/Alexia/Desktop/images/arbreM1.png");
    this->arbre10 = new Image("/Users/Alexia/Desktop/images/arbreM1.png");

    this->arbre11 = new Image("/Users/Alexia/Desktop/images/arbreM4.png");
    this->arbre12 = new Image("/Users/Alexia/Desktop/images/arbreM5.png");
    this->arbre13 = new Image("/Users/Alexia/Desktop/images/arbreM5.png");
    this->arbre14 = new Image("/Users/Alexia/Desktop/images/arbreM1.png");
    this->arbre15 = new Image("/Users/Alexia/Desktop/images/arbreM4.png");
    this->arbre16 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre17 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre18 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre19 = new Image("/Users/Alexia/Desktop/images/arbreM5.png");
    this->arbre20 = new Image("/Users/Alexia/Desktop/images/arbreM5.png");

    this->arbre21 = new Image("/Users/Alexia/Desktop/images/arbreM4.png");
    this->arbre22 = new Image("/Users/Alexia/Desktop/images/arbreM2.png");
    this->arbre23 = new Image("/Users/Alexia/Desktop/images/arbreM1.png");
    this->arbre24 = new Image("/Users/Alexia/Desktop/images/arbreM1.png");
    this->arbre25 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");

    this->buissonbaies1 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buisson1 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->buisson2 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->buisson3 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson4 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->buisson5 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson6 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->buisson7 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->buisson8 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson9 = new Image("/Users/Alexia/Desktop/images/buisson2.png");

    this->arbre1->setPos(posX, posY);
    this->arbre2->setPos(posX + 200, posY - 40);
    this->arbre3->setPos(posX - 40, posY + 30);
    this->arbre4->setPos(posX + 175, posY + 25);
    this->arbre5->setPos(posX + 240, posY + 30);
    this->arbre6->setPos(posX + 10, posY + 50);
    this->arbre7->setPos(posX - 60, posY + 90);
    this->arbre8->setPos(posX + 200, posY + 60);
    this->arbre9->setPos(posX + 220, posY + 75);
    this->arbre10->setPos(posX + 250, posY + 65);

    this->arbre11->setPos(posX + 260, posY + 55);
    this->arbre12->setPos(posX + 185, posY + 105);
    this->arbre13->setPos(posX - 10, posY + 100);
    this->arbre14->setPos(posX + 250, posY + 130);
    this->arbre15->setPos(posX - 105, posY + 100);
    this->arbre16->setPos(posX + 200, posY + 150);
    this->arbre17->setPos(posX + 270, posY + 145);
    this->arbre18->setPos(posX + 220, posY + 160);
    this->arbre19->setPos(posX + 165, posY + 175);
    this->arbre20->setPos(posX + 200, posY + 195);

    this->arbre21->setPos(posX + 250, posY + 170);
    this->arbre22->setPos(posX + 150, posY + 230);
    this->arbre23->setPos(posX + 120, posY + 250);
    this->arbre24->setPos(posX + 150, posY + 270);
    this->arbre25->setPos(posX + 210, posY + 250);

    this->buissonbaies1->setPos(posX + 300, posY + 300);
    this->buisson1->setPos(posX - 10, posY + 140);
    this->buisson2->setPos(posX + 10, posY + 150);
    this->buisson3->setPos(posX + 250, posY + 160);
    this->buisson4->setPos(posX - 50, posY + 190);
    this->buisson5->setPos(posX - 20, posY + 200);
    this->buisson6->setPos(posX + 280, posY + 185);
    this->buisson7->setPos(posX + 310, posY + 190);
    this->buisson8->setPos(posX + 200, posY + 210);
    this->buisson9->setPos(posX + 250, posY + 310);

    this->noisette->setPos(posX + 50, posY + 160);
    this->baie->setPos(posX + 180, posY + 170);
    this->ble->setPos(posX - 40, posY + 230);
}

Foret5::Foret5(QString type, int posX, int posY, View *view): Foret(type, posX, posY, view) {
    this->arbre1 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre2 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre3 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre4 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre5 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre6 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre7 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre8 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre9 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre10 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre11 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre12 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre13 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre14 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre15 = new Image("/Users/Alexia/Desktop/images/arbre9.png");

    this->arbre16 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre17 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre18 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre19 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre20 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre21 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre22 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre23 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre24 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre25 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre26 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre27 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre28 = new Image("/Users/Alexia/Desktop/images/arbre8.png");
    this->arbre29 = new Image("/Users/Alexia/Desktop/images/arbre9.png");
    this->arbre30 = new Image("/Users/Alexia/Desktop/images/arbre9.png");

    this->buissonbaies1 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buissonbaies2 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");

    this->arbre1->setPos(posX, posY);
    this->arbre2->setPos(posX + 70, posY + 10);
    this->arbre3->setPos(posX + 150, posY);
    this->arbre4->setPos(posX - 60, posY + 20);
    this->arbre5->setPos(posX - 10, posY + 30);
    this->arbre6->setPos(posX + 200, posY + 20);
    this->arbre7->setPos(posX + 130, posY + 30);
    this->arbre8->setPos(posX + 60, posY + 30);
    this->arbre9->setPos(posX - 100, posY + 50);
    this->arbre10->setPos(posX - 50, posY + 65);
    this->arbre11->setPos(posX + 250, posY + 50);
    this->arbre12->setPos(posX + 175, posY + 65);
    this->arbre13->setPos(posX + 230, posY + 90);
    this->arbre14->setPos(posX - 140, posY + 75);
    this->arbre15->setPos(posX - 75, posY + 85);

    this->arbre16->setPos(posX - 80, posY + 300);
    this->arbre17->setPos(posX + 220, posY + 300);
    this->arbre18->setPos(posX - 20, posY + 320);
    this->arbre19->setPos(posX + 40, posY + 330);
    this->arbre20->setPos(posX + 165, posY + 325);
    this->arbre21->setPos(posX + 95, posY + 335);
    this->arbre22->setPos(posX + 260, posY + 320);
    this->arbre23->setPos(posX - 140, posY + 315);
    this->arbre24->setPos(posX - 90, posY + 340);
    this->arbre25->setPos(posX + 210, posY + 350);
    this->arbre26->setPos(posX + 140, posY + 370);
    this->arbre27->setPos(posX - 30, posY + 360);
    this->arbre28->setPos(posX + 50, posY + 370);
    this->arbre29->setPos(posX + 30, posY + 400);
    this->arbre30->setPos(posX + 120, posY + 400);

    this->buissonbaies1->setPos(posX + 130, posY + 100);
    this->buissonbaies2->setPos(posX + 160, posY + 425);
    this->noisette->setPos(posX + 160, posY + 330);
    this->baie->setPos(posX + 115, posY + 130);
    this->ble->setPos(posX, posY + 130);
}

Foret6::Foret6(QString type, int posX, int posY, View *view): Foret(type, posX, posY, view) {
    this->arbre1 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre2 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre3 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre4 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre5 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre6 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre7 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre8 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre9 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre10 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre11 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre12 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre13 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre14 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre15 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre16 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre17 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre18 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre19 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre20 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre21 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre22 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre23 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre24 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre25 = new Image("/Users/Alexia/Desktop/images/arbre7.png");
    this->arbre26 = new Image("/Users/Alexia/Desktop/images/arbre7.png");

    this->buissonbaies1 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buisson1 = new Image("/Users/Alexia/Desktop/images/buisson2.png");

    this->arbre1->setPos(posX, posY);
    this->arbre2->setPos(posX - 30, posY + 20);
    this->arbre3->setPos(posX + 50, posY + 30);
    this->arbre4->setPos(posX - 70, posY + 35);
    this->arbre5->setPos(posX - 15, posY + 50);
    this->arbre6->setPos(posX + 100, posY + 40);
    this->arbre7->setPos(posX - 130, posY + 60);
    this->arbre8->setPos(posX + 130, posY + 55);
    this->arbre9->setPos(posX + 170, posY + 90);
    this->arbre10->setPos(posX - 140, posY + 110);
    this->arbre11->setPos(posX - 120, posY + 140);
    this->arbre12->setPos(posX + 210, posY + 130);
    this->arbre13->setPos(posX + 150, posY + 140);
    this->arbre14->setPos(posX + 190, posY + 160);
    this->arbre15->setPos(posX + 100, posY + 200);
    this->arbre16->setPos(posX - 80, posY + 160);
    this->arbre17->setPos(posX - 50, posY + 200);
    this->arbre18->setPos(posX + 30, posY + 200);
    this->arbre19->setPos(posX - 10, posY + 220);
    this->arbre20->setPos(posX + 60, posY + 230);
    this->arbre21->setPos(posX - 50, posY + 230);
    this->arbre22->setPos(posX + 10, posY + 260);
    this->arbre23->setPos(posX + 90, posY + 250);
    this->arbre24->setPos(posX + 140, posY + 210);
    this->arbre25->setPos(posX + 170, posY + 220);
    this->arbre26->setPos(posX - 140, posY + 200);

    this->buissonbaies1->setPos(posX - 80, posY + 100);
    this->buisson1->setPos(posX + 60, posY + 110);
    this->noisette->setPos(posX - 60, posY + 300);
    this->baie->setPos(posX + 160, posY + 310);
    this->ble->setPos(posX + 80, posY + 310);
}

Foret7::Foret7(QString type, int posX, int posY, View *view): Foret(type, posX, posY, view) {
    this->arbre1 = new Image("/Users/Alexia/Desktop/images/arbre1.png");
    this->arbre2 = new Image("/Users/Alexia/Desktop/images/arbre1.png");
    this->arbre3 = new Image("/Users/Alexia/Desktop/images/arbre1.png");
    this->arbre4 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre5 = new Image("/Users/Alexia/Desktop/images/arbre2.png");
    this->arbre6 = new Image("/Users/Alexia/Desktop/images/arbre2.png");
    this->arbre7 = new Image("/Users/Alexia/Desktop/images/arbre2.png");
    this->arbre8 = new Image("/Users/Alexia/Desktop/images/arbre4.png");
    this->arbre9 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre10 = new Image("/Users/Alexia/Desktop/images/arbre1.png");
    this->arbre11 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre12 = new Image("/Users/Alexia/Desktop/images/arbre4.png");
    this->arbre13 = new Image("/Users/Alexia/Desktop/images/arbre4.png");
    this->arbre14 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre15 = new Image("/Users/Alexia/Desktop/images/arbre2.png");
    this->arbre16 = new Image("/Users/Alexia/Desktop/images/arbre2.png");
    this->arbre17 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre18 = new Image("/Users/Alexia/Desktop/images/arbre1.png");
    this->arbre19 = new Image("/Users/Alexia/Desktop/images/arbre4.png");
    this->arbre20 = new Image("/Users/Alexia/Desktop/images/arbreM3.png");
    this->arbre21 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre22 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre23 = new Image("/Users/Alexia/Desktop/images/arbre1.png");
    this->arbre24 = new Image("/Users/Alexia/Desktop/images/arbre1.png");
    this->arbre25 = new Image("/Users/Alexia/Desktop/images/arbre6.png");
    this->arbre26 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre27 = new Image("/Users/Alexia/Desktop/images/arbre10.png");
    this->arbre28 = new Image("/Users/Alexia/Desktop/images/arbre4.png");
    this->arbre29 = new Image("/Users/Alexia/Desktop/images/arbre4.png");
    this->arbre30 = new Image("/Users/Alexia/Desktop/images/arbre6.png");

    this->buissonbaies1 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buissonbaies2 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buissonbaies3 = new Image("/Users/Alexia/Desktop/images/buissonbaies.png");
    this->buisson1 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson2 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson3 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson4 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->buisson5 = new Image("/Users/Alexia/Desktop/images/buisson2.png");
    this->buisson6 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->buisson7 = new Image("/Users/Alexia/Desktop/images/buisson1.png");
    this->souche1 = new Image("/Users/Alexia/Desktop/images/souche2.png");
    this->souche2 = new Image("/Users/Alexia/Desktop/images/souche1.png");
    this->souche3 = new Image("/Users/Alexia/Desktop/images/souche2.png");

    this->arbre1->setPos(posX, posY);
    this->arbre2->setPos(posX + 80, posY);
    this->arbre3->setPos(posX - 20, posY + 30);
    this->arbre4->setPos(posX + 100, posY + 40);
    this->arbre5->setPos(posX + 65, posY + 70);
    this->arbre6->setPos(posX + 50, posY + 90);
    this->arbre7->setPos(posX + 90, posY + 100);
    this->arbre8->setPos(posX + 50, posY + 150);
    this->arbre9->setPos(posX - 10, posY + 85);
    this->arbre10->setPos(posX + 140, posY + 110);
    this->arbre11->setPos(posX + 190, posY + 135);
    this->arbre12->setPos(posX + 200, posY + 240);
    this->arbre13->setPos(posX + 120, posY + 250);
    this->arbre14->setPos(posX + 135, posY + 185);
    this->arbre15->setPos(posX + 160, posY + 250);
    this->arbre16->setPos(posX + 180, posY + 255);
    this->arbre17->setPos(posX + 290, posY + 200);
    this->arbre18->setPos(posX + 240, posY + 185);
    this->arbre19->setPos(posX + 240, posY + 300);
    this->arbre20->setPos(posX + 370, posY + 230);
    this->arbre21->setPos(posX + 330, posY + 250);
    this->arbre22->setPos(posX + 270, posY + 270);
    this->arbre23->setPos(posX + 435, posY + 240);
    this->arbre24->setPos(posX + 360, posY - 30);
    this->arbre25->setPos(posX + 300, posY - 10);
    this->arbre26->setPos(posX + 400, posY + 25);
    this->arbre27->setPos(posX + 350, posY + 40);
    this->arbre28->setPos(posX + 460, posY + 80);
    this->arbre29->setPos(posX + 490, posY + 110);
    this->arbre30->setPos(posX + 400, posY + 70);

    this->buissonbaies1->setPos(posX + 100, posY + 140);
    this->buissonbaies2->setPos(posX + 50, posY + 210);
    this->buissonbaies3->setPos(posX + 395, posY + 325);
    this->buisson1->setPos(posX + 90, posY + 185);
    this->buisson2->setPos(posX + 20, posY + 185);
    this->buisson3->setPos(posX + 240, posY + 270);
    this->buisson4->setPos(posX + 210, posY + 285);
    this->buisson5->setPos(posX + 430, posY);
    this->buisson6->setPos(posX + 460, posY + 25);
    this->buisson7->setPos(posX + 480, posY + 50);
    this->souche1->setPos(posX + 330, posY + 340);
    this->souche2->setPos(posX + 380, posY + 335);
    this->souche3->setPos(posX + 500, posY + 85);

    this->noisette->setPos(posX + 300, posY + 60);
    this->baie->setPos(posX + 250, posY + 150);
    this->ble->setPos(posX + 460, posY + 135);
}

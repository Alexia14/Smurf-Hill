#include "view.h"
#include "ui_view.h"
#include "controller.h"
#include "model.h"
#include "autre.h"

#include <QTableWidget>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMovie>
#include <QGraphicsProxyWidget>
#include <QPoint>
#include <QScrollBar>
#include <QGroupBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QTimer>
#include <QGraphicsRectItem>

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);

    for (int i=0; i<11; i++) {
        list_movies.append("/Users/Alexia/Desktop/images/movie"+QString::number(i));
    }

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(film()));
    timer->start(5000);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(600,550);
    scene->addText(QString("Schtroumpf-Hill : The Game"), QFont("Monotype Corsiva", 20));
}

View::~View() {
    delete ui;
}

void View::film() {
    scene->clear();
    if (cptMovie == 11)
        cptMovie = 0;
    QLabel *gif_anim = new QLabel();
    QMovie *movie = new QMovie(list_movies[cptMovie]);
    gif_anim->setMovie(movie);
    movie->start();
    scene->addWidget(gif_anim);

    cptMovie++;
}

void View::on_pushButton_clicked() { // Bouton Jouer
    timer->disconnect();
    QString listDecor = "V 600 600 F1 1000 200 F2 1500 100 F3 2000 100 F4 2500 350 F5 2000 750 F6 2500 900 F7 100 100 ";
    QString listPersoGentil = "0 0 0 10 50 0 0 10 50 50 0 2 100 50 0 2 ";
    QString listPersoMechant = "150 50 0 10 ";
    this->controller->startGame(listDecor, listPersoGentil, listPersoMechant);
}

void View::on_pushButton_2_clicked() { // Bouton Reprendre
    timer->disconnect();
    this->controller->continueGame();
}

void View::installScene() {

    this->menuDisplay = false;
    scene->clear(); // Supprime le chargement

    QMenu *menu = this->menuBar()->addMenu("Fichier");

    QAction *sauver = new QAction("Sauver", this);
    sauver = menu->addAction("Sauver");
    sauver->setShortcut(QKeySequence("Ctrl+S"));
    sauver->setToolTip("Sauvegarder la partie");
    connect(sauver, SIGNAL(triggered()), this, SLOT(sauvegarde()));

    QAction *SQ = new QAction("Sauver et Quitter", this);
    SQ = menu->addAction("Sauver et Quitter");
    SQ->setToolTip("Sauvegarder la partie et quitter le jeu");
    connect(SQ, SIGNAL(triggered()), this, SLOT(sq()));

    QAction *quitter = new QAction("Quitter", this);
    quitter = menu->addAction("Quitter");
    quitter->setShortcut(QKeySequence("Ctrl+Q"));
    quitter->setToolTip("Quitter le jeu");
    connect(quitter, SIGNAL(triggered()), this, SLOT(close()));

    this->setCentralWidget(ui->graphicsView);
    scene->setSceneRect(0,0,3000,2000); // make the scene 800x600 instead of infinity by infinity (default)
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    ui->graphicsView->setBackgroundBrush(QBrush(QImage("/Users/Alexia/Desktop/images/fond_herbe.png")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(1155,650);
    //QObject::connect(scene, SIGNAL(clicked()), this, SLOT(test));

}

void View::musique() {

    generique = !generique;
    if (generique == true) {
        this->player = new QMediaPlayer;
        this->player->setMedia(QUrl::fromLocalFile("/Users/Alexia/Desktop/images/generique.mp3"));
        this->player->setVolume(50);
        this->player->play();
    }
    else this->player->stop();
}

void View::addVillage(Village *village) {

    this->scene->addItem(village->getMoulinS());
    this->scene->addItem(village->getMaison7());
    this->scene->addItem(village->getMaison5());
    this->scene->addItem(village->getMaison1());
    this->scene->addItem(village->getMaison2());
    this->scene->addItem(village->getMaison3());
    this->scene->addItem(village->getMaison4());
    this->scene->addItem(village->getArbre1());
    this->scene->addItem(village->getMaison6());
    this->scene->addItem(village->getMaison8());
    this->scene->addItem(village->getMaison9());
    this->scene->addItem(village->getMaisonSette());
    this->scene->addItem(village->getMaisonSCostaud());
    this->scene->addItem(village->getMaisonSMusicien());
    this->scene->addItem(village->getMaisonSPaysan());
    this->scene->addItem(village->getGrandS());
    this->scene->addItem(village->getPuits());
    this->scene->addItem(village->getArbre2());

}

void View::addForet1(Foret1 *foret) {
    this->scene->addItem(foret->getNoisette());
    this->scene->addItem(foret->getBaie());

    this->scene->addItem(foret->getBuissonBaies1());
    this->scene->addItem(foret->getBuissonBaies2());

    this->scene->addItem(foret->getArbre16());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getArbre15());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getArbre17());
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getArbre15());

    this->scene->addItem(foret->getBuisson1());
    this->scene->addItem(foret->getBuisson2());

    this->scene->addItem(foret->getBle());
}

void View::addForet2(Foret2 *foret) {
    this->scene->addItem(foret->getArbre01());
    this->scene->addItem(foret->getArbre02());
    this->scene->addItem(foret->getArbre03());
    this->scene->addItem(foret->getArbre04());
    this->scene->addItem(foret->getArbre05());
    this->scene->addItem(foret->getArbre06());
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getBuisson3());
    this->scene->addItem(foret->getNoisette());

    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre07());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getBuissonBaies1());
    this->scene->addItem(foret->getBaie());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    this->scene->addItem(foret->getBuisson1());
    this->scene->addItem(foret->getBle());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getBuisson2());

}

void View::addForet3(Foret3 *foret) {
    this->scene->addItem(foret->getArbre01());
    this->scene->addItem(foret->getBuissonBaies3());
    this->scene->addItem(foret->getArbre02());
    this->scene->addItem(foret->getBuissonBaies1());
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre9());

    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getBaie());
    this->scene->addItem(foret->getBuissonBaies2());

    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    this->scene->addItem(foret->getSouche1());
    this->scene->addItem(foret->getNoisette());

    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getBuisson1());
    this->scene->addItem(foret->getBuisson2());
    this->scene->addItem(foret->getArbre15());
    this->scene->addItem(foret->getBle());

    this->scene->addItem(foret->getArbre16());
    this->scene->addItem(foret->getArbre17());
}

void View::addForet4(Foret4 *foret) {
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getBuisson1());
    this->scene->addItem(foret->getBuisson2());
    this->scene->addItem(foret->getNoisette());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getBuisson3());

    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getBuisson6());
    this->scene->addItem(foret->getBuisson7());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    this->scene->addItem(foret->getBuisson4());
    this->scene->addItem(foret->getBuisson5());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getArbre15());
    this->scene->addItem(foret->getBle());
    this->scene->addItem(foret->getBaie());
    this->scene->addItem(foret->getBuisson8());
    this->scene->addItem(foret->getArbre16());
    this->scene->addItem(foret->getArbre17());
    this->scene->addItem(foret->getArbre18());
    this->scene->addItem(foret->getArbre19());
    this->scene->addItem(foret->getArbre20());

    this->scene->addItem(foret->getArbre21());
    this->scene->addItem(foret->getBuisson9());
    this->scene->addItem(foret->getArbre22());
    this->scene->addItem(foret->getArbre23());
    this->scene->addItem(foret->getArbre24());
    this->scene->addItem(foret->getArbre25());
}

void View::addForet5(Foret5 *foret) {
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getBuissonBaies1());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getArbre15());

    this->scene->addItem(foret->getNoisette());
    this->scene->addItem(foret->getBle());
    this->scene->addItem(foret->getBaie());

    this->scene->addItem(foret->getArbre16());
    this->scene->addItem(foret->getArbre17());
    this->scene->addItem(foret->getArbre18());
    this->scene->addItem(foret->getArbre19());
    this->scene->addItem(foret->getArbre20());
    this->scene->addItem(foret->getArbre21());
    this->scene->addItem(foret->getArbre22());
    this->scene->addItem(foret->getArbre23());
    this->scene->addItem(foret->getArbre24());
    this->scene->addItem(foret->getArbre25());
    this->scene->addItem(foret->getBuissonBaies2());
    this->scene->addItem(foret->getArbre26());
    this->scene->addItem(foret->getArbre27());
    this->scene->addItem(foret->getArbre28());
    this->scene->addItem(foret->getArbre29());
    this->scene->addItem(foret->getArbre30());
}

void View::addForet6(Foret6 *foret) {
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getBuisson1());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getBuissonBaies1());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getArbre15());
    this->scene->addItem(foret->getArbre16());
    this->scene->addItem(foret->getArbre17());
    this->scene->addItem(foret->getArbre18());
    this->scene->addItem(foret->getArbre19());
    this->scene->addItem(foret->getArbre20());
    this->scene->addItem(foret->getArbre21());
    this->scene->addItem(foret->getNoisette());
    this->scene->addItem(foret->getBle());
    this->scene->addItem(foret->getBaie());
    this->scene->addItem(foret->getArbre22());
    this->scene->addItem(foret->getArbre23());
    this->scene->addItem(foret->getArbre24());
    this->scene->addItem(foret->getArbre25());
    this->scene->addItem(foret->getArbre26());
}

void View::addForet7(Foret7 *foret) {
    this->scene->addItem(foret->getArbre1());
    this->scene->addItem(foret->getArbre2());
    this->scene->addItem(foret->getArbre3());
    this->scene->addItem(foret->getArbre4());
    this->scene->addItem(foret->getArbre5());
    this->scene->addItem(foret->getArbre6());
    this->scene->addItem(foret->getArbre7());
    this->scene->addItem(foret->getArbre8());
    this->scene->addItem(foret->getBuissonbaies1());
    this->scene->addItem(foret->getArbre9());
    this->scene->addItem(foret->getBuisson1());
    this->scene->addItem(foret->getBuisson2());
    this->scene->addItem(foret->getBuissonbaies2());
    this->scene->addItem(foret->getArbre10());
    this->scene->addItem(foret->getBaie());
    this->scene->addItem(foret->getArbre11());
    this->scene->addItem(foret->getArbre12());
    this->scene->addItem(foret->getArbre13());
    this->scene->addItem(foret->getArbre14());
    this->scene->addItem(foret->getArbre15());
    this->scene->addItem(foret->getArbre16());
    this->scene->addItem(foret->getArbre17());
    this->scene->addItem(foret->getArbre18());
    this->scene->addItem(foret->getBuisson3());
    this->scene->addItem(foret->getBuisson4());
    this->scene->addItem(foret->getArbre19());
    this->scene->addItem(foret->getBuissonbaies3());
    this->scene->addItem(foret->getArbre20());
    this->scene->addItem(foret->getArbre21());
    this->scene->addItem(foret->getArbre22());
    this->scene->addItem(foret->getSouche1());
    this->scene->addItem(foret->getSouche2());
    this->scene->addItem(foret->getArbre23());
    this->scene->addItem(foret->getBuisson5());
    this->scene->addItem(foret->getBuisson6());
    this->scene->addItem(foret->getBuisson7());
    this->scene->addItem(foret->getSouche3());
    this->scene->addItem(foret->getArbre24());
    this->scene->addItem(foret->getNoisette());
    this->scene->addItem(foret->getArbre25());
    this->scene->addItem(foret->getArbre26());
    this->scene->addItem(foret->getArbre27());
    this->scene->addItem(foret->getArbre28());
    this->scene->addItem(foret->getArbre29());
    this->scene->addItem(foret->getArbre30());
    this->scene->addItem(foret->getBle());
}

void View::displayMessageSette() {

    if (!this->controller->isMessageDisplayed()) {

        this->bulleMessageS = this->controller->getImageBulleSette();
        this->scene->addItem(this->bulleMessageS);

        this->imageMessageS = this->controller->getImageSette();
        this->scene->addItem(this->imageMessageS);

        this->texteMessageS = this->controller->getMessageSette();
        this->scene->addItem(this->texteMessageS);

        connect(this->imageMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->bulleMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->texteMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));

    }

    this->controller->setMessageDisplayed(true);
}

void View::displayMessageGrandS() {

    if (!this->controller->isMessageDisplayed()) {

        this->bulleMessageS = this->controller->getImageBulleGrandS();
        this->scene->addItem(this->bulleMessageS);

        this->imageMessageS = this->controller->getImageGrandS();
        this->scene->addItem(this->imageMessageS);

        this->texteMessageS = this->controller->getMessageGrandS();
        this->scene->addItem(this->texteMessageS);

        connect(this->bulleMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->imageMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));
        connect(this->texteMessageS, SIGNAL(clicked()), this, SLOT(hideMessageS()));

    }

    this->controller->setMessageDisplayed(true);
}

void View::hideMessageS() {

    this->controller->setMessageDisplayed(false);

    this->scene->removeItem(this->texteMessageS);
    this->scene->removeItem(this->bulleMessageS);
    this->scene->removeItem(this->imageMessageS);

}

void View::addPersoNormaux(PersoNormaux *perso) {
    this->scene->addItem(perso->getImagePerso());
}

void View::mousePressEvent(QMouseEvent *event) {

    if (!this->menuDisplay) {

        QPointF pt = event->pos();

        QDialog * dial = new QDialog(this);
        dial->setWindowTitle("Choix");
        QGridLayout * l = new QGridLayout();
        //QGroupBox *gp = new QGroupBox(tr("Groupe Radio"));
        QSpinBox *nbS = new QSpinBox;
        nbS->setFocus();
        nbS->setMinimum(1);
        nbS->setMaximum(this->controller->getNbSFree());
        QRadioButton *b1 = new QRadioButton(tr("Radio 1"));
        b1->setChecked(true);
        QRadioButton *b2 = new QRadioButton(tr("Radio 2"));
        QRadioButton *b3 = new QRadioButton(tr("Radio 3"));
        QPushButton * ok = new QPushButton("Ok");
        connect(ok,SIGNAL(clicked()),dial,SLOT(accept()));
        QPushButton * cancel = new QPushButton("Annuler");
        connect(cancel,SIGNAL(clicked()),dial,SLOT(reject()));

        l->addWidget(nbS);
        l->addWidget(b1);
        l->addWidget(b2);
        l->addWidget(b3);
        l->addWidget(ok,5,0);
        l->addWidget(cancel,5,1);
        dial->setLayout(l);

        int result = dial->exec();

        if (result == QDialog::Accepted)
        {

            this->controller->actionPerso(pt.x() + ui->graphicsView->horizontalScrollBar()->value(),
                                          pt.y() + ui->graphicsView->verticalScrollBar()->value() - 17, nbS->value());
        }

        delete dial;
    }

}

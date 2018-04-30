#ifndef DECOR_H
#define DECOR_H

#include "autre.h"
#include "view.h"
#include <QtDebug>

class View;
class ImageDecor;

class Decor : public QObject
{

    Q_OBJECT

    public:

        Decor(QString type, int posX, int posY, View *view);

        QString getType() {return this->type;}
        int getPosX() {return this->posX;}
        int getPosY() {return this->posY;}

    private:

    protected:
        QString type;
        int posX;
        int posY;
        View *view;

};


class Village : public Decor
{

    Q_OBJECT

    public:

        Village(QString type, int posX, int posY, View *view);
        ImageDecor *getGrandS() {return this->grandS;}
        ImageDecor *getMaison1() {return this->maison1;}
        ImageDecor *getMaison2() {return this->maison2;}
        ImageDecor *getMaison3() {return this->maison3;}
        ImageDecor *getMaison4() {return this->maison4;}
        ImageDecor *getMaison5() {return this->maison5;}
        ImageDecor *getMaison6() {return this->maison6;}
        ImageDecor *getMaison7() {return this->maison7;}
        ImageDecor *getMaison8() {return this->maison8;}
        ImageDecor *getMaison9() {return this->maison9;}
        ImageDecor *getMaisonSette() {return this->maisonSette;}
        ImageDecor *getMaisonSCostaud() {return this->maisonSCostaud;}
        ImageDecor *getMaisonSPaysan() {return this->maisonSPaysan;}
        ImageDecor *getMaisonSMusicien() {return this->maisonSMusicien;}
        ImageDecor *getMoulinS() {return this->moulinS;}
        ImageDecor *getPuits() {return this->puits;}
        ImageDecor *getArbre1() {return this->arbre1;}
        ImageDecor *getArbre2() {return this->arbre2;}

    private:

        ImageDecor *maison1, *maison2, *maison3, *maison4, *maison5, *maison6, *maison7, *maison8, *maison9;
        ImageDecor *grandS, *maisonSette, *maisonSCostaud, *maisonSMusicien, *maisonSPaysan;
        ImageDecor *moulinS, *puits;
        ImageDecor *arbre1, *arbre2;

    public slots:
        void pixmapClicked() {qDebug() << "item clicked!";}

};

class Foret : public Decor
{

    Q_OBJECT

    public:

        Foret(QString type, int posX, int posY, View *view);

        ImageDecor *getNoisette() {return this->noisette;}
        ImageDecor *getBaie() {return this->baie;}
        ImageDecor *getBle() {return this->ble;}

    private:

    protected slots:
        void onResourceWheatClicked();
        void onResourceAcornClicked();
        void onResourceBayClicked();

    protected:

        ImageDecor *noisette, *baie, *ble;
        int nbNoisette, nbBaie, nbBle;
};

class Foret1 : public Foret
{

    Q_OBJECT

    public:

        Foret1(QString type, int posX, int posY, View *view);
        ImageDecor *getArbre1() {return this->arbre1;}
        ImageDecor *getArbre2() {return this->arbre2;}
        ImageDecor *getArbre3() {return this->arbre3;}
        ImageDecor *getArbre4() {return this->arbre4;}
        ImageDecor *getArbre5() {return this->arbre5;}
        ImageDecor *getArbre6() {return this->arbre6;}
        ImageDecor *getArbre7() {return this->arbre7;}
        ImageDecor *getArbre8() {return this->arbre8;}
        ImageDecor *getArbre9() {return this->arbre9;}
        ImageDecor *getArbre10() {return this->arbre10;}
        ImageDecor *getArbre11() {return this->arbre11;}
        ImageDecor *getArbre12() {return this->arbre12;}
        ImageDecor *getArbre13() {return this->arbre13;}
        ImageDecor *getArbre14() {return this->arbre14;}
        ImageDecor *getArbre15() {return this->arbre15;}
        ImageDecor *getArbre16() {return this->arbre16;}
        ImageDecor *getArbre17() {return this->arbre17;}

        ImageDecor *getBuisson1() {return this->buisson1;}
        ImageDecor *getBuisson2() {return this->buisson2;}
        ImageDecor *getBuissonBaies1() {return this->buissonbaies1;}
        ImageDecor *getBuissonBaies2() {return this->buissonbaies2;}

    private:
        ImageDecor *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8;
        ImageDecor *arbre9, *arbre10, *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17;
        ImageDecor *buisson1, *buisson2, *buissonbaies1, *buissonbaies2;
};

class Foret2 : public Foret
{

    Q_OBJECT

    public:

        Foret2(QString type, int posX, int posY, View *view);
        Image *getArbre01() {return this->arbre01;}
        Image *getArbre02() {return this->arbre02;}
        Image *getArbre03() {return this->arbre03;}
        Image *getArbre04() {return this->arbre04;}
        Image *getArbre05() {return this->arbre05;}
        Image *getArbre06() {return this->arbre06;}
        Image *getArbre07() {return this->arbre07;}
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}
        Image *getArbre11() {return this->arbre11;}
        Image *getArbre12() {return this->arbre12;}
        Image *getArbre13() {return this->arbre13;}
        Image *getArbre14() {return this->arbre14;}

        Image *getBuissonBaies1() {return this->buissonbaies1;}
        Image *getBuisson1() {return this->buisson1;}
        Image *getBuisson2() {return this->buisson2;}
        Image *getBuisson3() {return this->buisson3;}

    private:
        Image *arbre01, *arbre02, *arbre03, *arbre04, *arbre05, *arbre06, *arbre07;
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8, *arbre9, *arbre10;
        Image *arbre11, *arbre12, *arbre13, *arbre14;
        Image *buissonbaies1, *buisson1, *buisson2, *buisson3;
};

class Foret3 : public Foret
{

    Q_OBJECT

    public:

        Foret3(QString type, int posX, int posY, View *view);
        Image *getArbre01() {return this->arbre01;}
        Image *getArbre02() {return this->arbre02;}
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}
        Image *getArbre11() {return this->arbre11;}
        Image *getArbre12() {return this->arbre12;}
        Image *getArbre13() {return this->arbre13;}
        Image *getArbre14() {return this->arbre14;}
        Image *getArbre15() {return this->arbre15;}
        Image *getArbre16() {return this->arbre16;}
        Image *getArbre17() {return this->arbre17;}

        Image *getBuissonBaies1() {return this->buissonbaies1;}
        Image *getBuissonBaies2() {return this->buissonbaies2;}
        Image *getBuissonBaies3() {return this->buissonbaies3;}
        Image *getBuisson1() {return this->buisson1;}
        Image *getBuisson2() {return this->buisson2;}
        Image *getSouche1() {return this->souche1;}

    private:
        Image *arbre01, *arbre02;
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8, *arbre9;
        Image *arbre10, *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17;
        Image *buissonbaies1, *buissonbaies2, *buissonbaies3, *buisson1, *buisson2, *souche1;
};

class Foret4 : public Foret
{

    Q_OBJECT

    public:

        Foret4(QString type, int posX, int posY, View *view);
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}
        Image *getArbre11() {return this->arbre11;}
        Image *getArbre12() {return this->arbre12;}
        Image *getArbre13() {return this->arbre13;}
        Image *getArbre14() {return this->arbre14;}
        Image *getArbre15() {return this->arbre15;}
        Image *getArbre16() {return this->arbre16;}
        Image *getArbre17() {return this->arbre17;}
        Image *getArbre18() {return this->arbre18;}
        Image *getArbre19() {return this->arbre19;}
        Image *getArbre20() {return this->arbre20;}
        Image *getArbre21() {return this->arbre21;}
        Image *getArbre22() {return this->arbre22;}
        Image *getArbre23() {return this->arbre23;}
        Image *getArbre24() {return this->arbre24;}
        Image *getArbre25() {return this->arbre25;}

        Image *getBuissonBaies1() {return this->buissonbaies1;}
        Image *getBuisson1() {return this->buisson1;}
        Image *getBuisson2() {return this->buisson2;}
        Image *getBuisson3() {return this->buisson3;}
        Image *getBuisson4() {return this->buisson4;}
        Image *getBuisson5() {return this->buisson5;}
        Image *getBuisson6() {return this->buisson6;}
        Image *getBuisson7() {return this->buisson7;}
        Image *getBuisson8() {return this->buisson8;}
        Image *getBuisson9() {return this->buisson9;}

    private:
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8, *arbre9, *arbre10;
        Image *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17, *arbre18, *arbre19, *arbre20;
        Image *arbre21, *arbre22, *arbre23, *arbre24, *arbre25;
        Image *buissonbaies1, *buisson1, *buisson2, *buisson3, *buisson4, *buisson5, *buisson6, *buisson7, *buisson8, *buisson9;
};

class Foret5 : public Foret
{

    Q_OBJECT

    public:

        Foret5(QString type, int posX, int posY, View *view);
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}
        Image *getArbre11() {return this->arbre11;}
        Image *getArbre12() {return this->arbre12;}
        Image *getArbre13() {return this->arbre13;}
        Image *getArbre14() {return this->arbre14;}
        Image *getArbre15() {return this->arbre15;}

        Image *getArbre16() {return this->arbre16;}
        Image *getArbre17() {return this->arbre17;}
        Image *getArbre18() {return this->arbre18;}
        Image *getArbre19() {return this->arbre19;}
        Image *getArbre20() {return this->arbre20;}
        Image *getArbre21() {return this->arbre21;}
        Image *getArbre22() {return this->arbre22;}
        Image *getArbre23() {return this->arbre23;}
        Image *getArbre24() {return this->arbre24;}
        Image *getArbre25() {return this->arbre25;}
        Image *getArbre26() {return this->arbre26;}
        Image *getArbre27() {return this->arbre27;}
        Image *getArbre28() {return this->arbre28;}
        Image *getArbre29() {return this->arbre29;}
        Image *getArbre30() {return this->arbre30;}

        Image *getBuissonBaies1() {return this->buissonbaies1;}
        Image *getBuissonBaies2() {return this->buissonbaies2;}

    private:
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8, *arbre9, *arbre10;
        Image *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17, *arbre18, *arbre19, *arbre20;
        Image *arbre21, *arbre22, *arbre23, *arbre24, *arbre25, *arbre26, *arbre27, *arbre28, *arbre29, *arbre30;
        Image *buissonbaies1, *buissonbaies2;
};

class Foret6 : public Foret
{

    Q_OBJECT

    public:

        Foret6(QString type, int posX, int posY, View *view);
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}
        Image *getArbre11() {return this->arbre11;}
        Image *getArbre12() {return this->arbre12;}
        Image *getArbre13() {return this->arbre13;}
        Image *getArbre14() {return this->arbre14;}
        Image *getArbre15() {return this->arbre15;}
        Image *getArbre16() {return this->arbre16;}
        Image *getArbre17() {return this->arbre17;}
        Image *getArbre18() {return this->arbre18;}
        Image *getArbre19() {return this->arbre19;}
        Image *getArbre20() {return this->arbre20;}
        Image *getArbre21() {return this->arbre21;}
        Image *getArbre22() {return this->arbre22;}
        Image *getArbre23() {return this->arbre23;}
        Image *getArbre24() {return this->arbre24;}
        Image *getArbre25() {return this->arbre25;}
        Image *getArbre26() {return this->arbre26;}
        Image *getArbre27() {return this->arbre27;}
        Image *getArbre28() {return this->arbre28;}
        Image *getArbre29() {return this->arbre29;}
        Image *getArbre30() {return this->arbre30;}

        Image *getBuissonBaies1() {return this->buissonbaies1;}
        Image *getBuisson1() {return this->buisson1;}

    private:
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8, *arbre9, *arbre10;
        Image *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17, *arbre18, *arbre19, *arbre20;
        Image *arbre21, *arbre22, *arbre23, *arbre24, *arbre25, *arbre26, *arbre27, *arbre28, *arbre29, *arbre30;
        Image *buissonbaies1, *buisson1;
};

class Foret7 : public Foret
{

    Q_OBJECT

    public:

        Foret7(QString type, int posX, int posY, View *view);
        Image *getArbre1() {return this->arbre1;}
        Image *getArbre2() {return this->arbre2;}
        Image *getArbre3() {return this->arbre3;}
        Image *getArbre4() {return this->arbre4;}
        Image *getArbre5() {return this->arbre5;}
        Image *getArbre6() {return this->arbre6;}
        Image *getArbre7() {return this->arbre7;}
        Image *getArbre8() {return this->arbre8;}
        Image *getArbre9() {return this->arbre9;}
        Image *getArbre10() {return this->arbre10;}
        Image *getArbre11() {return this->arbre11;}
        Image *getArbre12() {return this->arbre12;}
        Image *getArbre13() {return this->arbre13;}
        Image *getArbre14() {return this->arbre14;}
        Image *getArbre15() {return this->arbre15;}
        Image *getArbre16() {return this->arbre16;}
        Image *getArbre17() {return this->arbre17;}
        Image *getArbre18() {return this->arbre18;}
        Image *getArbre19() {return this->arbre19;}
        Image *getArbre20() {return this->arbre20;}
        Image *getArbre21() {return this->arbre21;}
        Image *getArbre22() {return this->arbre22;}
        Image *getArbre23() {return this->arbre23;}
        Image *getArbre24() {return this->arbre24;}
        Image *getArbre25() {return this->arbre25;}
        Image *getArbre26() {return this->arbre26;}
        Image *getArbre27() {return this->arbre27;}
        Image *getArbre28() {return this->arbre28;}
        Image *getArbre29() {return this->arbre29;}
        Image *getArbre30() {return this->arbre30;}

        Image *getBuissonbaies1() {return this->buissonbaies1;}
        Image *getBuissonbaies2() {return this->buissonbaies2;}
        Image *getBuissonbaies3() {return this->buissonbaies3;}
        Image *getBuisson1() {return this->buisson1;}
        Image *getBuisson2() {return this->buisson2;}
        Image *getBuisson3() {return this->buisson3;}
        Image *getBuisson4() {return this->buisson4;}
        Image *getBuisson5() {return this->buisson5;}
        Image *getBuisson6() {return this->buisson6;}
        Image *getBuisson7() {return this->buisson7;}
        Image *getSouche1() {return this->souche1;}
        Image *getSouche2() {return this->souche2;}
        Image *getSouche3() {return this->souche3;}

    private:
        Image *arbre1, *arbre2, *arbre3, *arbre4, *arbre5, *arbre6, *arbre7, *arbre8, *arbre9, *arbre10;
        Image *arbre11, *arbre12, *arbre13, *arbre14, *arbre15, *arbre16, *arbre17, *arbre18, *arbre19, *arbre20;
        Image *arbre21, *arbre22, *arbre23, *arbre24, *arbre25, *arbre26, *arbre27, *arbre28, *arbre29, *arbre30;
        Image *buissonbaies1, *buissonbaies2, *buissonbaies3, *buisson1, *buisson2, *buisson3, *buisson4, *buisson5, *buisson6, *buisson7;
        Image *souche1, *souche2, *souche3;
};

#endif // DECOR_H

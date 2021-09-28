#include "mainwindow.h"
#include "ui_mainwindow.h"

bool isArticleCapitalised;
QString article;
int checker;
QString articleDeleted;
int misses;
int stopTwice;
int teemp;
int missStop;
int once;
int characters;
int stopErr;
QString text;
QString errStopS;

auto lHOne = new QGraphicsEllipseItem(9, 40, 25, 25);
auto lHTwo = new QGraphicsEllipseItem(35, 11, 25, 25);
auto lHThree = new QGraphicsEllipseItem(75, 0, 25, 25);
auto lHFour = new QGraphicsEllipseItem(116, 13, 25, 25);
auto lHFive = new QGraphicsEllipseItem(141, 69, 25, 25);

auto rHOne = new QGraphicsEllipseItem(12, 70, 25, 25);
auto rHTwo = new QGraphicsEllipseItem(33, 7, 25, 25);
auto rHThree = new QGraphicsEllipseItem(75, 0, 25, 25);
auto rHFour = new QGraphicsEllipseItem(117, 8, 25, 25);
auto rHFive = new QGraphicsEllipseItem(140, 40, 25, 25);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_Article->setReadOnly(true);
    ui->lineEdit_TextInput->setReadOnly(true);
    ui->lineEdit_TextInput->setStyleSheet("background-color: white; font-size: 20px;");

    QObject::connect(ui->pushButton_StartCourse,SIGNAL(clicked()),&getInfo,SLOT(start()), Qt::QueuedConnection);
    QObject::connect(&getInfo,SIGNAL(signalValueUpdated(const QString&)),ui->statusbar,SLOT(showMessage(const QString&)), Qt::QueuedConnection);

    QPixmap left(":/hands/handLeft.jpg");
    if (! ui->graphicsView_LeftHand->scene()) {
        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->graphicsView_LeftHand->setScene(scene);
    }
    ui->graphicsView_LeftHand->scene()->addPixmap(left);

    QPixmap right(":/hands/handRight.jpg");
    if (! ui->graphicsView_RightHand->scene()) {
        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->graphicsView_RightHand->setScene(scene);
    }
    ui->graphicsView_RightHand->scene()->addPixmap(right);
    ui->pushButton_StartCourse->setEnabled(false);

    rHOne->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHOne->setBrush(QColor(190, 230, 255));
    QPen penR1(QColor(190, 230, 255), 2); rHOne->setPen(penR1);
    ui->graphicsView_RightHand->scene()->addItem(rHOne);

    rHTwo->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHTwo->setBrush(QColor(0, 255, 255));
    QPen penR2(QColor(0, 255, 255), 2); rHTwo->setPen(penR2);
    ui->graphicsView_RightHand->scene()->addItem(rHTwo);

    rHThree->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHThree->setBrush(QColor(0, 255, 0));
    QPen penR3(QColor(0, 255, 0), 2); rHThree->setPen(penR3);
    ui->graphicsView_RightHand->scene()->addItem(rHThree);

    rHFour->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHFour->setBrush(QColor(255, 0, 0));
    QPen penR4(QColor(255, 0, 0), 2); rHFour->setPen(penR4);
    ui->graphicsView_RightHand->scene()->addItem(rHFour);

    rHFive->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHFive->setBrush(QColor(255, 170, 0));
    QPen penR5(QColor(255, 170, 0), 2); rHFive->setPen(penR5);
    ui->graphicsView_RightHand->scene()->addItem(rHFive);

    lHOne->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHOne->setBrush(QColor(255, 170, 0));
    QPen penL1(QColor(255, 170, 0), 2); lHOne->setPen(penL1);
    ui->graphicsView_LeftHand->scene()->addItem(lHOne);

    lHTwo->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHTwo->setBrush(QColor(255, 0, 0));
    QPen penL2(QColor(255, 0, 0), 2); lHTwo->setPen(penL2);
    ui->graphicsView_LeftHand->scene()->addItem(lHTwo);

    lHThree->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHThree->setBrush(QColor(0, 255, 0));
    QPen penL3(QColor(0, 255, 0), 2); lHThree->setPen(penL3);
    ui->graphicsView_LeftHand->scene()->addItem(lHThree);

    lHFour->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHFour->setBrush(QColor(0, 0, 255));
    QPen penL4(QColor(0, 0, 255), 2); lHFour->setPen(penL4);
    ui->graphicsView_LeftHand->scene()->addItem(lHFour);

    lHFive->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHFive->setBrush(QColor(190, 230, 255));
    QPen penL5(QColor(190, 230, 255), 2); lHFive->setPen(penL5);
    ui->graphicsView_LeftHand->scene()->addItem(lHFive);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_TextInput_textChanged(const QString &arg1)
{
    QString word = arg1;
    QString lastCharacter = arg1.back();
//    QString firstCharacter = arg1.front();
    QString articleIn = article;
    articleIn = article.front();
    QString articleHands;
    QString front;
    QString actualFront;
    stopTwice = 0;

    if (lastCharacter == " ")
    {
        ui->lineEdit_TextInput->setText("");
        word = "";
    }

    if (lastCharacter == articleIn)
    {
        missStop = 0;
        once = 0;
        characters = 0;
        stopErr = 0;
        errStopS = "";
        if (lastCharacter == " ")
        {
            article = article.simplified();
        } else {
            article.remove(0, 1);
        }
        ui->textEdit_Article->setText(article);

        if (actualFront == articleIn) {checker = 1;} else {checker = 0;}
        if (checker == 0) {
            front = articleDeleted.front();
            if (front == " ")
            {
                articleDeleted = articleDeleted.simplified();
                teemp = teemp + 1;
            } else {
                articleDeleted.remove(0, 1);
            }
            actualFront = articleDeleted.front();
        }
        ui->lineEdit_TextInput->setStyleSheet("background-color: white; font-size: 20px;");
    } else {
        if (missStop == 0) {
            misses = misses + 1;
            if (lastCharacter == " ") {teemp = teemp + 2;}
            missStop = 1;
            text = arg1;
            ui->lineEdit_TextInput->setStyleSheet("background-color: red; font-size: 20px;");
        }
    }

    if (missStop == 0) {
        if (article == "")
        {
            ui->lineEdit_TextInput->setText("");
            word = "";
            lastCharacter = "";
            articleIn = "";

            getInfo.stopRunning();
            ui->lineEdit_TextInput->setReadOnly(true);
            ui->menuCourses->setEnabled(true);
            ui->action_MakeCustomCourse->setEnabled(true);

            int mis = misses - teemp;
            QString miss = QString::number(mis);

            QMessageBox finished;

            finished.setWindowTitle("Course finished!");

            QString text = "You've finished the course!\n" + getInfo.getTime() + "\nMisses: " + miss;

            finished.setText(text);

            if (stopTwice == 0) {finished.exec(); stopTwice = 1;}

            ui->statusbar->showMessage("");
            article = "Please select a course!";
            ui->textEdit_Article->setText(article);
            ui->textEdit_Article->setAlignment(Qt::AlignCenter);
            misses = 0;
            teemp = 0;
        }
        if (actualFront.isUpper() == true) {isArticleCapitalised = true;}
        if (actualFront.isLower() == true) {isArticleCapitalised = false;}
        if (actualFront == " ") {isArticleCapitalised = false;}

        if (isArticleCapitalised == true) {
            ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);
            ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);
            ui->pushButton_Tilde->setText(mapColor.getTilde().toUpper());
            ui->pushButton_1->setText(mapColor.getN1().toUpper());
            ui->pushButton_2->setText(mapColor.getN2().toUpper());
            ui->pushButton_3->setText(mapColor.getN3().toUpper());
            ui->pushButton_4->setText(mapColor.getN4().toUpper());
            ui->pushButton_5->setText(mapColor.getN5().toUpper());
            ui->pushButton_6->setText(mapColor.getN6().toUpper());
            ui->pushButton_7->setText(mapColor.getN7().toUpper());
            ui->pushButton_8->setText(mapColor.getN8().toUpper());
            ui->pushButton_9->setText(mapColor.getN9().toUpper());
            ui->pushButton_0->setText(mapColor.getN0().toUpper());
            ui->pushButton_Minus->setText(mapColor.getMinus().toUpper());
            ui->pushButton_Equals->setText(mapColor.getEquals().toUpper());
            ui->pushButton_Backspace->setText(mapColor.getBackspace().toUpper());
            ui->pushButton_TAB->setText(mapColor.getTAB().toUpper());
            ui->pushButton_Q->setText(mapColor.getQ().toUpper());
            ui->pushButton_W->setText(mapColor.getW().toUpper());
            ui->pushButton_E->setText(mapColor.getE().toUpper());
            ui->pushButton_R->setText(mapColor.getR().toUpper());
            ui->pushButton_T->setText(mapColor.getT().toUpper());
            ui->pushButton_Y->setText(mapColor.getY().toUpper());
            ui->pushButton_U->setText(mapColor.getU().toUpper());
            ui->pushButton_I->setText(mapColor.getI().toUpper());
            ui->pushButton_O->setText(mapColor.getO().toUpper());
            ui->pushButton_P->setText(mapColor.getP().toUpper());
            ui->pushButton_LeftSquareBracket->setText(mapColor.getRightSquareBracket().toUpper());
            ui->pushButton_RightSquareBracket->setText(mapColor.getLeftSquareBracket().toUpper());
            ui->pushButton_Backslash->setText(mapColor.getBackslash().toUpper());
            ui->pushButton_CAPS->setText(mapColor.getCAPS().toUpper());
            ui->pushButton_A->setText(mapColor.getA().toUpper());
            ui->pushButton_S->setText(mapColor.getS().toUpper());
            ui->pushButton_D->setText(mapColor.getD().toUpper());
            ui->pushButton_F->setText(mapColor.getF().toUpper());
            ui->pushButton_G->setText(mapColor.getG().toUpper());
            ui->pushButton_H->setText(mapColor.getH().toUpper());
            ui->pushButton_J->setText(mapColor.getJ().toUpper());
            ui->pushButton_K->setText(mapColor.getK().toUpper());
            ui->pushButton_L->setText(mapColor.getL().toUpper());
            ui->pushButton_Semicolon->setText(mapColor.getSemicolon().toUpper());
            ui->pushButton_Apostrophe->setText(mapColor.getApostrophe().toUpper());
            ui->pushButton_Enter->setText(mapColor.getEnter().toUpper());
            ui->pushButton_LShift->setText(mapColor.getLShift().toUpper());
            ui->pushButton_Z->setText(mapColor.getZ().toUpper());
            ui->pushButton_X->setText(mapColor.getX().toUpper());
            ui->pushButton_C->setText(mapColor.getC().toUpper());
            ui->pushButton_V->setText(mapColor.getV().toUpper());
            ui->pushButton_B->setText(mapColor.getB().toUpper());
            ui->pushButton_N->setText(mapColor.getN().toUpper());
            ui->pushButton_M->setText(mapColor.getM().toUpper());
            ui->pushButton_Comma->setText(mapColor.getComma().toUpper());
            ui->pushButton_Period->setText(mapColor.getPeriod().toUpper());
            ui->pushButton_Slash->setText(mapColor.getSlash().toUpper());
            ui->pushButton_RShift->setText(mapColor.getRShift().toUpper());
            ui->pushButton_LCtrl->setText(mapColor.getLCtrl().toUpper());
            ui->pushButton_Super->setText(mapColor.getSuper().toUpper());
            ui->pushButton_LAlt->setText(mapColor.getLAlt().toUpper());
            ui->pushButton_RAlt->setText(mapColor.getRAlt().toUpper());
            ui->pushButton_Menu->setText(mapColor.getMenu().toUpper());
            ui->pushButton_RCtrl->setText(mapColor.getRCtrl().toUpper());

            articleHands = actualFront;
            articleHands = actualFront.toUpper();
        } else {
            ui->pushButton_1->setText(mapColor.getN1().toLower());
            ui->pushButton_2->setText(mapColor.getN2().toLower());
            ui->pushButton_3->setText(mapColor.getN3().toLower());
            ui->pushButton_4->setText(mapColor.getN4().toLower());
            ui->pushButton_5->setText(mapColor.getN5().toLower());
            ui->pushButton_6->setText(mapColor.getN6().toLower());
            ui->pushButton_7->setText(mapColor.getN7().toLower());
            ui->pushButton_8->setText(mapColor.getN8().toLower());
            ui->pushButton_9->setText(mapColor.getN9().toLower());
            ui->pushButton_0->setText(mapColor.getN0().toLower());
            ui->pushButton_Minus->setText(mapColor.getMinus().toLower());
            ui->pushButton_Equals->setText(mapColor.getEquals().toLower());
            ui->pushButton_Backspace->setText(mapColor.getBackspace().toLower());
            ui->pushButton_TAB->setText(mapColor.getTAB().toLower());
            ui->pushButton_Q->setText(mapColor.getQ().toLower());
            ui->pushButton_W->setText(mapColor.getW().toLower());
            ui->pushButton_E->setText(mapColor.getE().toLower());
            ui->pushButton_R->setText(mapColor.getR().toLower());
            ui->pushButton_T->setText(mapColor.getT().toLower());
            ui->pushButton_Y->setText(mapColor.getY().toLower());
            ui->pushButton_U->setText(mapColor.getU().toLower());
            ui->pushButton_I->setText(mapColor.getI().toLower());
            ui->pushButton_O->setText(mapColor.getO().toLower());
            ui->pushButton_P->setText(mapColor.getP().toLower());
            ui->pushButton_LeftSquareBracket->setText(mapColor.getRightSquareBracket().toLower());
            ui->pushButton_RightSquareBracket->setText(mapColor.getLeftSquareBracket().toLower());
            ui->pushButton_Backslash->setText(mapColor.getBackslash().toLower());
            ui->pushButton_CAPS->setText(mapColor.getCAPS().toLower());
            ui->pushButton_A->setText(mapColor.getA().toLower());
            ui->pushButton_S->setText(mapColor.getS().toLower());
            ui->pushButton_D->setText(mapColor.getD().toLower());
            ui->pushButton_F->setText(mapColor.getF().toLower());
            ui->pushButton_G->setText(mapColor.getG().toLower());
            ui->pushButton_H->setText(mapColor.getH().toLower());
            ui->pushButton_J->setText(mapColor.getJ().toLower());
            ui->pushButton_K->setText(mapColor.getK().toLower());
            ui->pushButton_L->setText(mapColor.getL().toLower());
            ui->pushButton_Semicolon->setText(mapColor.getSemicolon().toLower());
            ui->pushButton_Apostrophe->setText(mapColor.getApostrophe().toLower());
            ui->pushButton_Enter->setText(mapColor.getEnter().toLower());
            ui->pushButton_LShift->setText(mapColor.getLShift().toLower());
            ui->pushButton_Z->setText(mapColor.getZ().toLower());
            ui->pushButton_X->setText(mapColor.getX().toLower());
            ui->pushButton_C->setText(mapColor.getC().toLower());
            ui->pushButton_V->setText(mapColor.getV().toLower());
            ui->pushButton_B->setText(mapColor.getB().toLower());
            ui->pushButton_N->setText(mapColor.getN().toLower());
            ui->pushButton_M->setText(mapColor.getM().toLower());
            ui->pushButton_Comma->setText(mapColor.getComma().toLower());
            ui->pushButton_Period->setText(mapColor.getPeriod().toLower());
            ui->pushButton_Slash->setText(mapColor.getSlash().toLower());
            ui->pushButton_RShift->setText(mapColor.getRShift().toLower());
            ui->pushButton_LCtrl->setText(mapColor.getLCtrl().toLower());
            ui->pushButton_Super->setText(mapColor.getSuper().toLower());
            ui->pushButton_LAlt->setText(mapColor.getLAlt().toLower());
            ui->pushButton_RAlt->setText(mapColor.getRAlt().toLower());
            ui->pushButton_Menu->setText(mapColor.getMenu().toLower());
            ui->pushButton_RCtrl->setText(mapColor.getRCtrl().toLower());

            articleHands = actualFront;
            articleHands = actualFront.toLower();
        }
        ui->graphicsView_RightHand->scene()->removeItem(rHOne);
        ui->graphicsView_RightHand->scene()->removeItem(rHTwo);
        ui->graphicsView_RightHand->scene()->removeItem(rHThree);
        ui->graphicsView_RightHand->scene()->removeItem(rHFour);
        ui->graphicsView_RightHand->scene()->removeItem(rHFive);
        ui->graphicsView_LeftHand->scene()->removeItem(lHOne);
        ui->graphicsView_LeftHand->scene()->removeItem(lHTwo);
        ui->graphicsView_LeftHand->scene()->removeItem(lHThree);
        ui->graphicsView_LeftHand->scene()->removeItem(lHFour);
        ui->graphicsView_LeftHand->scene()->removeItem(lHFive);

        ui->pushButton_Tilde->setChecked(false);
        ui->pushButton_1->setChecked(false);
        ui->pushButton_2->setChecked(false);
        ui->pushButton_3->setChecked(false);
        ui->pushButton_4->setChecked(false);
        ui->pushButton_5->setChecked(false);
        ui->pushButton_6->setChecked(false);
        ui->pushButton_7->setChecked(false);
        ui->pushButton_8->setChecked(false);
        ui->pushButton_9->setChecked(false);
        ui->pushButton_0->setChecked(false);
        ui->pushButton_Minus->setChecked(false);
        ui->pushButton_Equals->setChecked(false);
        ui->pushButton_Backspace->setChecked(false);
        ui->pushButton_TAB->setChecked(false);
        ui->pushButton_Q->setChecked(false);
        ui->pushButton_W->setChecked(false);
        ui->pushButton_E->setChecked(false);
        ui->pushButton_R->setChecked(false);
        ui->pushButton_T->setChecked(false);
        ui->pushButton_Y->setChecked(false);
        ui->pushButton_U->setChecked(false);
        ui->pushButton_I->setChecked(false);
        ui->pushButton_O->setChecked(false);
        ui->pushButton_P->setChecked(false);
        ui->pushButton_LeftSquareBracket->setChecked(false);
        ui->pushButton_RightSquareBracket->setChecked(false);
        ui->pushButton_Backslash->setChecked(false);
        ui->pushButton_CAPS->setChecked(false);
        ui->pushButton_A->setChecked(false);
        ui->pushButton_S->setChecked(false);
        ui->pushButton_D->setChecked(false);
        ui->pushButton_F->setChecked(false);
        ui->pushButton_G->setChecked(false);
        ui->pushButton_H->setChecked(false);
        ui->pushButton_J->setChecked(false);
        ui->pushButton_K->setChecked(false);
        ui->pushButton_L->setChecked(false);
        ui->pushButton_Semicolon->setChecked(false);
        ui->pushButton_Apostrophe->setChecked(false);
        ui->pushButton_Enter->setChecked(false);
        ui->pushButton_LShift->setChecked(false);
        ui->pushButton_Z->setChecked(false);
        ui->pushButton_X->setChecked(false);
        ui->pushButton_C->setChecked(false);
        ui->pushButton_V->setChecked(false);
        ui->pushButton_B->setChecked(false);
        ui->pushButton_N->setChecked(false);
        ui->pushButton_M->setChecked(false);
        ui->pushButton_Comma->setChecked(false);
        ui->pushButton_Period->setChecked(false);
        ui->pushButton_Slash->setChecked(false);
        ui->pushButton_RShift->setChecked(false);
        ui->pushButton_LCtrl->setChecked(false);
        ui->pushButton_Super->setChecked(false);
        ui->pushButton_LAlt->setChecked(false);
        ui->pushButton_Space->setChecked(false);
        ui->pushButton_RAlt->setChecked(false);
        ui->pushButton_Menu->setChecked(false);
        ui->pushButton_LCtrl->setChecked(false);

        QString characterSearch;

        characterSearch = ui->pushButton_Tilde->text(); if (characterSearch == articleHands) {ui->pushButton_Tilde->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_1->text(); if (characterSearch == articleHands) {ui->pushButton_1->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_2->text(); if (characterSearch == articleHands) {ui->pushButton_2->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_3->text(); if (characterSearch == articleHands) {ui->pushButton_3->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_4->text(); if (characterSearch == articleHands) {ui->pushButton_4->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_5->text(); if (characterSearch == articleHands) {ui->pushButton_5->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_6->text(); if (characterSearch == articleHands) {ui->pushButton_6->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_7->text(); if (characterSearch == articleHands) {ui->pushButton_7->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_8->text(); if (characterSearch == articleHands) {ui->pushButton_8->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_9->text(); if (characterSearch == articleHands) {ui->pushButton_9->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_0->text(); if (characterSearch == articleHands) {ui->pushButton_0->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Minus->text(); if (characterSearch == articleHands) {ui->pushButton_Minus->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Equals->text(); if (characterSearch == articleHands) {ui->pushButton_Equals->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Backspace->text(); if (characterSearch == articleHands) {ui->pushButton_Backspace->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_TAB->text(); if (characterSearch == articleHands) {ui->pushButton_TAB->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Q->text(); if (characterSearch == articleHands) {ui->pushButton_Q->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_W->text(); if (characterSearch == articleHands) {ui->pushButton_W->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_E->text(); if (characterSearch == articleHands) {ui->pushButton_E->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_R->text(); if (characterSearch == articleHands) {ui->pushButton_R->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_T->text(); if (characterSearch == articleHands) {ui->pushButton_T->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_Y->text(); if (characterSearch == articleHands) {ui->pushButton_Y->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_U->text(); if (characterSearch == articleHands) {ui->pushButton_U->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_I->text(); if (characterSearch == articleHands) {ui->pushButton_I->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_O->text(); if (characterSearch == articleHands) {ui->pushButton_O->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_P->text(); if (characterSearch == articleHands) {ui->pushButton_P->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LeftSquareBracket->text(); if (characterSearch == articleHands) {ui->pushButton_LeftSquareBracket->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_RightSquareBracket->text(); if (characterSearch == articleHands) {ui->pushButton_RightSquareBracket->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Backslash->text(); if (characterSearch == articleHands) {ui->pushButton_Backslash->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_CAPS->text(); if (characterSearch == articleHands) {ui->pushButton_CAPS->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_A->text(); if (characterSearch == articleHands) {ui->pushButton_A->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_S->text(); if (characterSearch == articleHands) {ui->pushButton_S->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_D->text(); if (characterSearch == articleHands) {ui->pushButton_D->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_F->text(); if (characterSearch == articleHands) {ui->pushButton_F->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_G->text(); if (characterSearch == articleHands) {ui->pushButton_G->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_H->text(); if (characterSearch == articleHands) {ui->pushButton_H->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_J->text(); if (characterSearch == articleHands) {ui->pushButton_J->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_K->text(); if (characterSearch == articleHands) {ui->pushButton_K->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_L->text(); if (characterSearch == articleHands) {ui->pushButton_L->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Semicolon->text(); if (characterSearch == articleHands) {ui->pushButton_Semicolon->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Apostrophe->text(); if (characterSearch == articleHands) {ui->pushButton_Apostrophe->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Enter->text(); if (characterSearch == articleHands) {ui->pushButton_Enter->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LShift->text(); if (characterSearch == articleHands) {ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Z->text(); if (characterSearch == articleHands) {ui->pushButton_Z->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_X->text(); if (characterSearch == articleHands) {ui->pushButton_X->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_C->text(); if (characterSearch == articleHands) {ui->pushButton_C->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_V->text(); if (characterSearch == articleHands) {ui->pushButton_V->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_B->text(); if (characterSearch == articleHands) {ui->pushButton_B->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_N->text(); if (characterSearch == articleHands) {ui->pushButton_N->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_M->text(); if (characterSearch == articleHands) {ui->pushButton_M->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_Comma->text(); if (characterSearch == articleHands) {ui->pushButton_Comma->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_Period->text(); if (characterSearch == articleHands) {ui->pushButton_Period->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Slash->text(); if (characterSearch == articleHands) {ui->pushButton_Slash->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_RShift->text(); if (characterSearch == articleHands) {ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LCtrl->text(); if (characterSearch == articleHands) {ui->pushButton_LCtrl->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Super->text(); if (characterSearch == articleHands) {ui->pushButton_Super->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFive);}
        characterSearch = ui->pushButton_LAlt->text(); if (characterSearch == articleHands) {ui->pushButton_LAlt->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_RAlt->text(); if (characterSearch == articleHands) {ui->pushButton_RAlt->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Menu->text(); if (characterSearch == articleHands) {ui->pushButton_Menu->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHOne);}
        characterSearch = ui->pushButton_RCtrl->text(); if (characterSearch == articleHands) {ui->pushButton_RCtrl->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        if (actualFront == " ") {ui->pushButton_Space->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFive); ui->graphicsView_RightHand->scene()->addItem(rHOne);}
    } else {
        if (once == 0) {characters = text.count(); once = 1;}
        int currC = arg1.count();
        qDebug() << characters;
        qDebug() << currC;
        QString arg = text;
        if (stopErr == 0) {
            if (currC > characters)
            {
                arg.remove(1, 1); ui->lineEdit_TextInput->setText(arg);
            }
            if (currC < characters - 1)
            {
                arg.remove(1, 1); ui->lineEdit_TextInput->setText(arg);
                stopErr = 1;
                errStopS = arg;
            }
        } else {
            ui->lineEdit_TextInput->setText(errStopS);
        }
    }
    if (stopTwice == 1)
    {
        ui->graphicsView_RightHand->scene()->addItem(rHOne);
        ui->graphicsView_RightHand->scene()->addItem(rHTwo);
        ui->graphicsView_RightHand->scene()->addItem(rHThree);
        ui->graphicsView_RightHand->scene()->addItem(rHFour);
        ui->graphicsView_RightHand->scene()->addItem(rHFive);
        ui->graphicsView_LeftHand->scene()->addItem(lHOne);
        ui->graphicsView_LeftHand->scene()->addItem(lHTwo);
        ui->graphicsView_LeftHand->scene()->addItem(lHThree);
        ui->graphicsView_LeftHand->scene()->addItem(lHFour);
        ui->graphicsView_LeftHand->scene()->addItem(lHFive);
    }
}

void MainWindow::on_action_MakeCustomCourse_triggered()
{
    QString text = QInputDialog::getMultiLineText(0, "Set custom article", "Type in or paste an article.", "");
    if (text == "") {} else {        
        ui->graphicsView_RightHand->scene()->removeItem(rHOne);
        ui->graphicsView_RightHand->scene()->removeItem(rHTwo);
        ui->graphicsView_RightHand->scene()->removeItem(rHThree);
        ui->graphicsView_RightHand->scene()->removeItem(rHFour);
        ui->graphicsView_RightHand->scene()->removeItem(rHFive);
        ui->graphicsView_LeftHand->scene()->removeItem(lHOne);
        ui->graphicsView_LeftHand->scene()->removeItem(lHTwo);
        ui->graphicsView_LeftHand->scene()->removeItem(lHThree);
        ui->graphicsView_LeftHand->scene()->removeItem(lHFour);
        ui->graphicsView_LeftHand->scene()->removeItem(lHFive);

        article = text;
        articleDeleted = text;
        ui->textEdit_Article->setText(articleDeleted);
        ui->pushButton_StartCourse->setEnabled(true);

        QString articleIn;
        QString articleHands;
        articleIn = article.front();
        isArticleCapitalised = articleIn.isUpper();
        if (articleIn.isUpper() == true) {isArticleCapitalised = true;}
        if (articleIn.isLower() == true) {isArticleCapitalised = false;}
        if (articleIn == " ") {isArticleCapitalised = false;}

        if (isArticleCapitalised == true) {
            ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);
            ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);
            articleHands = articleIn.toUpper();
            ui->pushButton_Tilde->setText(mapColor.getTilde().toUpper());
            ui->pushButton_1->setText(mapColor.getN1().toUpper());
            ui->pushButton_2->setText(mapColor.getN2().toUpper());
            ui->pushButton_3->setText(mapColor.getN3().toUpper());
            ui->pushButton_4->setText(mapColor.getN4().toUpper());
            ui->pushButton_5->setText(mapColor.getN5().toUpper());
            ui->pushButton_6->setText(mapColor.getN6().toUpper());
            ui->pushButton_7->setText(mapColor.getN7().toUpper());
            ui->pushButton_8->setText(mapColor.getN8().toUpper());
            ui->pushButton_9->setText(mapColor.getN9().toUpper());
            ui->pushButton_0->setText(mapColor.getN0().toUpper());
            ui->pushButton_Minus->setText(mapColor.getMinus().toUpper());
            ui->pushButton_Equals->setText(mapColor.getEquals().toUpper());
            ui->pushButton_Backspace->setText(mapColor.getBackspace().toUpper());
            ui->pushButton_TAB->setText(mapColor.getTAB().toUpper());
            ui->pushButton_Q->setText(mapColor.getQ().toUpper());
            ui->pushButton_W->setText(mapColor.getW().toUpper());
            ui->pushButton_E->setText(mapColor.getE().toUpper());
            ui->pushButton_R->setText(mapColor.getR().toUpper());
            ui->pushButton_T->setText(mapColor.getT().toUpper());
            ui->pushButton_Y->setText(mapColor.getY().toUpper());
            ui->pushButton_U->setText(mapColor.getU().toUpper());
            ui->pushButton_I->setText(mapColor.getI().toUpper());
            ui->pushButton_O->setText(mapColor.getO().toUpper());
            ui->pushButton_P->setText(mapColor.getP().toUpper());
            ui->pushButton_LeftSquareBracket->setText(mapColor.getRightSquareBracket().toUpper());
            ui->pushButton_RightSquareBracket->setText(mapColor.getLeftSquareBracket().toUpper());
            ui->pushButton_Backslash->setText(mapColor.getBackslash().toUpper());
            ui->pushButton_CAPS->setText(mapColor.getCAPS().toUpper());
            ui->pushButton_A->setText(mapColor.getA().toUpper());
            ui->pushButton_S->setText(mapColor.getS().toUpper());
            ui->pushButton_D->setText(mapColor.getD().toUpper());
            ui->pushButton_F->setText(mapColor.getF().toUpper());
            ui->pushButton_G->setText(mapColor.getG().toUpper());
            ui->pushButton_H->setText(mapColor.getH().toUpper());
            ui->pushButton_J->setText(mapColor.getJ().toUpper());
            ui->pushButton_K->setText(mapColor.getK().toUpper());
            ui->pushButton_L->setText(mapColor.getL().toUpper());
            ui->pushButton_Semicolon->setText(mapColor.getSemicolon().toUpper());
            ui->pushButton_Apostrophe->setText(mapColor.getApostrophe().toUpper());
            ui->pushButton_Enter->setText(mapColor.getEnter().toUpper());
            ui->pushButton_LShift->setText(mapColor.getLShift().toUpper());
            ui->pushButton_Z->setText(mapColor.getZ().toUpper());
            ui->pushButton_X->setText(mapColor.getX().toUpper());
            ui->pushButton_C->setText(mapColor.getC().toUpper());
            ui->pushButton_V->setText(mapColor.getV().toUpper());
            ui->pushButton_B->setText(mapColor.getB().toUpper());
            ui->pushButton_N->setText(mapColor.getN().toUpper());
            ui->pushButton_M->setText(mapColor.getM().toUpper());
            ui->pushButton_Comma->setText(mapColor.getComma().toUpper());
            ui->pushButton_Period->setText(mapColor.getPeriod().toUpper());
            ui->pushButton_Slash->setText(mapColor.getSlash().toUpper());
            ui->pushButton_RShift->setText(mapColor.getRShift().toUpper());
            ui->pushButton_LCtrl->setText(mapColor.getLCtrl().toUpper());
            ui->pushButton_Super->setText(mapColor.getSuper().toUpper());
            ui->pushButton_LAlt->setText(mapColor.getLAlt().toUpper());
            ui->pushButton_RAlt->setText(mapColor.getRAlt().toUpper());
            ui->pushButton_Menu->setText(mapColor.getMenu().toUpper());
            ui->pushButton_RCtrl->setText(mapColor.getRCtrl().toUpper());
        }

        QString characterSearch;
        characterSearch = ui->pushButton_Tilde->text(); if (characterSearch == articleHands) {ui->pushButton_Tilde->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_1->text(); if (characterSearch == articleHands) {ui->pushButton_1->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_2->text(); if (characterSearch == articleHands) {ui->pushButton_2->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_3->text(); if (characterSearch == articleHands) {ui->pushButton_3->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_4->text(); if (characterSearch == articleHands) {ui->pushButton_4->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_5->text(); if (characterSearch == articleHands) {ui->pushButton_5->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_6->text(); if (characterSearch == articleHands) {ui->pushButton_6->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_7->text(); if (characterSearch == articleHands) {ui->pushButton_7->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_8->text(); if (characterSearch == articleHands) {ui->pushButton_8->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_9->text(); if (characterSearch == articleHands) {ui->pushButton_9->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_0->text(); if (characterSearch == articleHands) {ui->pushButton_0->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Minus->text(); if (characterSearch == articleHands) {ui->pushButton_Minus->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Equals->text(); if (characterSearch == articleHands) {ui->pushButton_Equals->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Backspace->text(); if (characterSearch == articleHands) {ui->pushButton_Backspace->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_TAB->text(); if (characterSearch == articleHands) {ui->pushButton_TAB->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Q->text(); if (characterSearch == articleHands) {ui->pushButton_Q->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_W->text(); if (characterSearch == articleHands) {ui->pushButton_W->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_E->text(); if (characterSearch == articleHands) {ui->pushButton_E->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_R->text(); if (characterSearch == articleHands) {ui->pushButton_R->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_T->text(); if (characterSearch == articleHands) {ui->pushButton_T->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_Y->text(); if (characterSearch == articleHands) {ui->pushButton_Y->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_U->text(); if (characterSearch == articleHands) {ui->pushButton_U->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_I->text(); if (characterSearch == articleHands) {ui->pushButton_I->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_O->text(); if (characterSearch == articleHands) {ui->pushButton_O->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_P->text(); if (characterSearch == articleHands) {ui->pushButton_P->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LeftSquareBracket->text(); if (characterSearch == articleHands) {ui->pushButton_LeftSquareBracket->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_RightSquareBracket->text(); if (characterSearch == articleHands) {ui->pushButton_RightSquareBracket->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Backslash->text(); if (characterSearch == articleHands) {ui->pushButton_Backslash->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_CAPS->text(); if (characterSearch == articleHands) {ui->pushButton_CAPS->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_A->text(); if (characterSearch == articleHands) {ui->pushButton_A->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_S->text(); if (characterSearch == articleHands) {ui->pushButton_S->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_D->text(); if (characterSearch == articleHands) {ui->pushButton_D->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_F->text(); if (characterSearch == articleHands) {ui->pushButton_F->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_G->text(); if (characterSearch == articleHands) {ui->pushButton_G->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_H->text(); if (characterSearch == articleHands) {ui->pushButton_H->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_J->text(); if (characterSearch == articleHands) {ui->pushButton_J->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_K->text(); if (characterSearch == articleHands) {ui->pushButton_K->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_L->text(); if (characterSearch == articleHands) {ui->pushButton_L->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Semicolon->text(); if (characterSearch == articleHands) {ui->pushButton_Semicolon->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Apostrophe->text(); if (characterSearch == articleHands) {ui->pushButton_Apostrophe->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Enter->text(); if (characterSearch == articleHands) {ui->pushButton_Enter->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LShift->text(); if (characterSearch == articleHands) {ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Z->text(); if (characterSearch == articleHands) {ui->pushButton_Z->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_X->text(); if (characterSearch == articleHands) {ui->pushButton_X->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_C->text(); if (characterSearch == articleHands) {ui->pushButton_C->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_V->text(); if (characterSearch == articleHands) {ui->pushButton_V->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_B->text(); if (characterSearch == articleHands) {ui->pushButton_B->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_N->text(); if (characterSearch == articleHands) {ui->pushButton_N->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_M->text(); if (characterSearch == articleHands) {ui->pushButton_M->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_Comma->text(); if (characterSearch == articleHands) {ui->pushButton_Comma->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_Period->text(); if (characterSearch == articleHands) {ui->pushButton_Period->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Slash->text(); if (characterSearch == articleHands) {ui->pushButton_Slash->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_RShift->text(); if (characterSearch == articleHands) {ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LCtrl->text(); if (characterSearch == articleHands) {ui->pushButton_LCtrl->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Super->text(); if (characterSearch == articleHands) {ui->pushButton_Super->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFive);}
        characterSearch = ui->pushButton_LAlt->text(); if (characterSearch == articleHands) {ui->pushButton_LAlt->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_RAlt->text(); if (characterSearch == articleHands) {ui->pushButton_RAlt->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Menu->text(); if (characterSearch == articleHands) {ui->pushButton_Menu->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHOne);}
        characterSearch = ui->pushButton_RCtrl->text(); if (characterSearch == articleHands) {ui->pushButton_RCtrl->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        }
}

void MainWindow::on_pushButton_StartCourse_clicked()
{
    ui->pushButton_StartCourse->setEnabled(false);
    ui->lineEdit_TextInput->setReadOnly(false);
    ui->menuCourses->setEnabled(false);
    ui->action_MakeCustomCourse->setEnabled(false);
    ui->lineEdit_TextInput->setFocus();
}

void MainWindow::on_action_ChangeKeyMapping_triggered()
{
    mapColor.setModal(true);
    if (mapColor.exec() == QDialog::Accepted)
    {
        //Layer 1
        QString tilde = mapColor.getTilde();            ui->pushButton_Tilde->setText(tilde);
        QString n1 = mapColor.getN1();                  ui->pushButton_1->setText(n1);
        QString n2 = mapColor.getN2();                  ui->pushButton_2->setText(n2);
        QString n3 = mapColor.getN3();                  ui->pushButton_3->setText(n3);
        QString n4 = mapColor.getN4();                  ui->pushButton_4->setText(n4);
        QString n5 = mapColor.getN5();                  ui->pushButton_5->setText(n5);
        QString n6 = mapColor.getN6();                  ui->pushButton_6->setText(n6);
        QString n7 = mapColor.getN7();                  ui->pushButton_7->setText(n7);
        QString n8 = mapColor.getN8();                  ui->pushButton_8->setText(n8);
        QString n9 = mapColor.getN9();                  ui->pushButton_9->setText(n9);
        QString n0 = mapColor.getN0();                  ui->pushButton_0->setText(n0);
        QString minus = mapColor.getMinus();            ui->pushButton_Minus->setText(minus);
        QString equals = mapColor.getEquals();          ui->pushButton_Equals->setText(equals);
        QString backspace = mapColor.getBackspace();    ui->pushButton_Backspace->setText(backspace);
        //Layer 2
        QString TAB = mapColor.getTAB();    ui->pushButton_TAB->setText(TAB);
        QString q = mapColor.getQ();        ui->pushButton_Q->setText(q);
        QString w = mapColor.getW();        ui->pushButton_W->setText(w);
        QString e = mapColor.getE();        ui->pushButton_E->setText(e);
        QString r = mapColor.getR();        ui->pushButton_R->setText(r);
        QString t = mapColor.getT();        ui->pushButton_T->setText(t);
        QString y = mapColor.getY();        ui->pushButton_Y->setText(y);
        QString u = mapColor.getU();        ui->pushButton_U->setText(u);
        QString i = mapColor.getI();        ui->pushButton_I->setText(i);
        QString o = mapColor.getO();        ui->pushButton_O->setText(o);
        QString p = mapColor.getP();        ui->pushButton_P->setText(p);
        QString leftSquareBracket = mapColor.getLeftSquareBracket();    ui->pushButton_LeftSquareBracket->setText(leftSquareBracket);
        QString rightSquareBracket = mapColor.getRightSquareBracket();  ui->pushButton_RightSquareBracket->setText(rightSquareBracket);
        QString backslash = mapColor.getBackslash();                    ui->pushButton_Backslash->setText(backslash);
        //Layer 3
        QString CAPS = mapColor.getCAPS();              ui->pushButton_CAPS->setText(CAPS);
        QString a = mapColor.getA();                    ui->pushButton_A->setText(a);
        QString s = mapColor.getS();                    ui->pushButton_S->setText(s);
        QString d = mapColor.getD();                    ui->pushButton_D->setText(d);
        QString f = mapColor.getF();                    ui->pushButton_F->setText(f);
        QString g = mapColor.getG();                    ui->pushButton_G->setText(g);
        QString h = mapColor.getH();                    ui->pushButton_H->setText(h);
        QString j = mapColor.getJ();                    ui->pushButton_J->setText(j);
        QString k = mapColor.getK();                    ui->pushButton_K->setText(k);
        QString l = mapColor.getL();                    ui->pushButton_L->setText(l);
        QString semicolon = mapColor.getSemicolon();    ui->pushButton_Semicolon->setText(semicolon);
        QString apostrophe = mapColor.getApostrophe();  ui->pushButton_Apostrophe->setText(apostrophe);
        QString enter = mapColor.getEnter();            ui->pushButton_Enter->setText(enter);
        //Layer 4
        QString LShift = mapColor.getLShift();      ui->pushButton_LShift->setText(LShift);
        QString z = mapColor.getZ();                ui->pushButton_Z->setText(z);
        QString x = mapColor.getX();                ui->pushButton_X->setText(x);
        QString c = mapColor.getC();                ui->pushButton_C->setText(c);
        QString v = mapColor.getV();                ui->pushButton_V->setText(v);
        QString b = mapColor.getB();                ui->pushButton_B->setText(b);
        QString n = mapColor.getN();                ui->pushButton_N->setText(n);
        QString m = mapColor.getM();                ui->pushButton_M->setText(m);
        QString comma = mapColor.getComma();        ui->pushButton_Comma->setText(comma);
        QString period = mapColor.getPeriod();      ui->pushButton_Period->setText(period);
        QString slash = mapColor.getSlash();        ui->pushButton_Slash->setText(slash);
        QString RShift = mapColor.getRShift();      ui->pushButton_RShift->setText(RShift);
        //Layer 5
        QString LCtrl = mapColor.getLCtrl();    ui->pushButton_LCtrl->setText(LCtrl);
        QString super = mapColor.getSuper();    ui->pushButton_Super->setText(super);
        QString LAlt = mapColor.getLAlt();      ui->pushButton_LAlt->setText(LAlt);
        QString space = mapColor.getSpace();    ui->pushButton_Space->setText(space);
        QString RAlt = mapColor.getRAlt();      ui->pushButton_RAlt->setText(RAlt);
        QString menu = mapColor.getMenu();      ui->pushButton_Menu->setText(menu);
        QString RCtrl = mapColor.getRCtrl();    ui->pushButton_RCtrl->setText(RCtrl);
    }
}

void MainWindow::on_action_CourseSelector_triggered()
{
    courses.setModal(true);
    if (courses.exec() == QDialog::Accepted)
    {
        ui->graphicsView_RightHand->scene()->removeItem(rHOne);
        ui->graphicsView_RightHand->scene()->removeItem(rHTwo);
        ui->graphicsView_RightHand->scene()->removeItem(rHThree);
        ui->graphicsView_RightHand->scene()->removeItem(rHFour);
        ui->graphicsView_RightHand->scene()->removeItem(rHFive);
        ui->graphicsView_LeftHand->scene()->removeItem(lHOne);
        ui->graphicsView_LeftHand->scene()->removeItem(lHTwo);
        ui->graphicsView_LeftHand->scene()->removeItem(lHThree);
        ui->graphicsView_LeftHand->scene()->removeItem(lHFour);
        ui->graphicsView_LeftHand->scene()->removeItem(lHFive);

        ui->pushButton_StartCourse->setEnabled(true);

        QString cArticle = courses.getArticle();
        articleDeleted = cArticle;
        article = cArticle;
        ui->textEdit_Article->setText(article);

        QString articleIn;
        QString articleHands;
        articleIn = article.front();
        isArticleCapitalised = articleIn.isUpper();
        if (articleIn == " ") {isArticleCapitalised = false;}

        if (isArticleCapitalised == true) {
            ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);
            ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);
            articleHands = articleIn.toUpper();
            ui->pushButton_Tilde->setText(mapColor.getTilde().toUpper());
            ui->pushButton_1->setText(mapColor.getN1().toUpper());
            ui->pushButton_2->setText(mapColor.getN2().toUpper());
            ui->pushButton_3->setText(mapColor.getN3().toUpper());
            ui->pushButton_4->setText(mapColor.getN4().toUpper());
            ui->pushButton_5->setText(mapColor.getN5().toUpper());
            ui->pushButton_6->setText(mapColor.getN6().toUpper());
            ui->pushButton_7->setText(mapColor.getN7().toUpper());
            ui->pushButton_8->setText(mapColor.getN8().toUpper());
            ui->pushButton_9->setText(mapColor.getN9().toUpper());
            ui->pushButton_0->setText(mapColor.getN0().toUpper());
            ui->pushButton_Minus->setText(mapColor.getMinus().toUpper());
            ui->pushButton_Equals->setText(mapColor.getEquals().toUpper());
            ui->pushButton_Backspace->setText(mapColor.getBackspace().toUpper());
            ui->pushButton_TAB->setText(mapColor.getTAB().toUpper());
            ui->pushButton_Q->setText(mapColor.getQ().toUpper());
            ui->pushButton_W->setText(mapColor.getW().toUpper());
            ui->pushButton_E->setText(mapColor.getE().toUpper());
            ui->pushButton_R->setText(mapColor.getR().toUpper());
            ui->pushButton_T->setText(mapColor.getT().toUpper());
            ui->pushButton_Y->setText(mapColor.getY().toUpper());
            ui->pushButton_U->setText(mapColor.getU().toUpper());
            ui->pushButton_I->setText(mapColor.getI().toUpper());
            ui->pushButton_O->setText(mapColor.getO().toUpper());
            ui->pushButton_P->setText(mapColor.getP().toUpper());
            ui->pushButton_LeftSquareBracket->setText(mapColor.getRightSquareBracket().toUpper());
            ui->pushButton_RightSquareBracket->setText(mapColor.getLeftSquareBracket().toUpper());
            ui->pushButton_Backslash->setText(mapColor.getBackslash().toUpper());
            ui->pushButton_CAPS->setText(mapColor.getCAPS().toUpper());
            ui->pushButton_A->setText(mapColor.getA().toUpper());
            ui->pushButton_S->setText(mapColor.getS().toUpper());
            ui->pushButton_D->setText(mapColor.getD().toUpper());
            ui->pushButton_F->setText(mapColor.getF().toUpper());
            ui->pushButton_G->setText(mapColor.getG().toUpper());
            ui->pushButton_H->setText(mapColor.getH().toUpper());
            ui->pushButton_J->setText(mapColor.getJ().toUpper());
            ui->pushButton_K->setText(mapColor.getK().toUpper());
            ui->pushButton_L->setText(mapColor.getL().toUpper());
            ui->pushButton_Semicolon->setText(mapColor.getSemicolon().toUpper());
            ui->pushButton_Apostrophe->setText(mapColor.getApostrophe().toUpper());
            ui->pushButton_Enter->setText(mapColor.getEnter().toUpper());
            ui->pushButton_LShift->setText(mapColor.getLShift().toUpper());
            ui->pushButton_Z->setText(mapColor.getZ().toUpper());
            ui->pushButton_X->setText(mapColor.getX().toUpper());
            ui->pushButton_C->setText(mapColor.getC().toUpper());
            ui->pushButton_V->setText(mapColor.getV().toUpper());
            ui->pushButton_B->setText(mapColor.getB().toUpper());
            ui->pushButton_N->setText(mapColor.getN().toUpper());
            ui->pushButton_M->setText(mapColor.getM().toUpper());
            ui->pushButton_Comma->setText(mapColor.getComma().toUpper());
            ui->pushButton_Period->setText(mapColor.getPeriod().toUpper());
            ui->pushButton_Slash->setText(mapColor.getSlash().toUpper());
            ui->pushButton_RShift->setText(mapColor.getRShift().toUpper());
            ui->pushButton_LCtrl->setText(mapColor.getLCtrl().toUpper());
            ui->pushButton_Super->setText(mapColor.getSuper().toUpper());
            ui->pushButton_LAlt->setText(mapColor.getLAlt().toUpper());
            ui->pushButton_RAlt->setText(mapColor.getRAlt().toUpper());
            ui->pushButton_Menu->setText(mapColor.getMenu().toUpper());
            ui->pushButton_RCtrl->setText(mapColor.getRCtrl().toUpper());
        } else {articleHands = articleIn;}
        QString characterSearch;
        characterSearch = ui->pushButton_Tilde->text(); if (characterSearch == articleHands) {ui->pushButton_Tilde->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_1->text(); if (characterSearch == articleHands) {ui->pushButton_1->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_2->text(); if (characterSearch == articleHands) {ui->pushButton_2->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_3->text(); if (characterSearch == articleHands) {ui->pushButton_3->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_4->text(); if (characterSearch == articleHands) {ui->pushButton_4->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_5->text(); if (characterSearch == articleHands) {ui->pushButton_5->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_6->text(); if (characterSearch == articleHands) {ui->pushButton_6->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_7->text(); if (characterSearch == articleHands) {ui->pushButton_7->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_8->text(); if (characterSearch == articleHands) {ui->pushButton_8->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_9->text(); if (characterSearch == articleHands) {ui->pushButton_9->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_0->text(); if (characterSearch == articleHands) {ui->pushButton_0->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Minus->text(); if (characterSearch == articleHands) {ui->pushButton_Minus->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Equals->text(); if (characterSearch == articleHands) {ui->pushButton_Equals->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Backspace->text(); if (characterSearch == articleHands) {ui->pushButton_Backspace->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_TAB->text(); if (characterSearch == articleHands) {ui->pushButton_TAB->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Q->text(); if (characterSearch == articleHands) {ui->pushButton_Q->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_W->text(); if (characterSearch == articleHands) {ui->pushButton_W->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_E->text(); if (characterSearch == articleHands) {ui->pushButton_E->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_R->text(); if (characterSearch == articleHands) {ui->pushButton_R->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_T->text(); if (characterSearch == articleHands) {ui->pushButton_T->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_Y->text(); if (characterSearch == articleHands) {ui->pushButton_Y->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_U->text(); if (characterSearch == articleHands) {ui->pushButton_U->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_I->text(); if (characterSearch == articleHands) {ui->pushButton_I->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_O->text(); if (characterSearch == articleHands) {ui->pushButton_O->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_P->text(); if (characterSearch == articleHands) {ui->pushButton_P->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LeftSquareBracket->text(); if (characterSearch == articleHands) {ui->pushButton_LeftSquareBracket->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_RightSquareBracket->text(); if (characterSearch == articleHands) {ui->pushButton_RightSquareBracket->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Backslash->text(); if (characterSearch == articleHands) {ui->pushButton_Backslash->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_CAPS->text(); if (characterSearch == articleHands) {ui->pushButton_CAPS->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_A->text(); if (characterSearch == articleHands) {ui->pushButton_A->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_S->text(); if (characterSearch == articleHands) {ui->pushButton_S->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_D->text(); if (characterSearch == articleHands) {ui->pushButton_D->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_F->text(); if (characterSearch == articleHands) {ui->pushButton_F->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_G->text(); if (characterSearch == articleHands) {ui->pushButton_G->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_H->text(); if (characterSearch == articleHands) {ui->pushButton_H->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_J->text(); if (characterSearch == articleHands) {ui->pushButton_J->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_K->text(); if (characterSearch == articleHands) {ui->pushButton_K->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_L->text(); if (characterSearch == articleHands) {ui->pushButton_L->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Semicolon->text(); if (characterSearch == articleHands) {ui->pushButton_Semicolon->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Apostrophe->text(); if (characterSearch == articleHands) {ui->pushButton_Apostrophe->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Enter->text(); if (characterSearch == articleHands) {ui->pushButton_Enter->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LShift->text(); if (characterSearch == articleHands) {ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Z->text(); if (characterSearch == articleHands) {ui->pushButton_Z->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
        characterSearch = ui->pushButton_X->text(); if (characterSearch == articleHands) {ui->pushButton_X->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
        characterSearch = ui->pushButton_C->text(); if (characterSearch == articleHands) {ui->pushButton_C->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
        characterSearch = ui->pushButton_V->text(); if (characterSearch == articleHands) {ui->pushButton_V->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_B->text(); if (characterSearch == articleHands) {ui->pushButton_B->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
        characterSearch = ui->pushButton_N->text(); if (characterSearch == articleHands) {ui->pushButton_N->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_M->text(); if (characterSearch == articleHands) {ui->pushButton_M->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
        characterSearch = ui->pushButton_Comma->text(); if (characterSearch == articleHands) {ui->pushButton_Comma->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHThree);}
        characterSearch = ui->pushButton_Period->text(); if (characterSearch == articleHands) {ui->pushButton_Period->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFour);}
        characterSearch = ui->pushButton_Slash->text(); if (characterSearch == articleHands) {ui->pushButton_Slash->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_RShift->text(); if (characterSearch == articleHands) {ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_LCtrl->text(); if (characterSearch == articleHands) {ui->pushButton_LCtrl->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_Super->text(); if (characterSearch == articleHands) {ui->pushButton_Super->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFive);}
        characterSearch = ui->pushButton_LAlt->text(); if (characterSearch == articleHands) {ui->pushButton_LAlt->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
        characterSearch = ui->pushButton_RAlt->text(); if (characterSearch == articleHands) {ui->pushButton_RAlt->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
        characterSearch = ui->pushButton_Menu->text(); if (characterSearch == articleHands) {ui->pushButton_Menu->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHOne);}
        characterSearch = ui->pushButton_RCtrl->text(); if (characterSearch == articleHands) {ui->pushButton_RCtrl->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);}
    }
}

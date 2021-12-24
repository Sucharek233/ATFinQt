#include "mainwindow.h"
#include "ui_mainwindow.h"

bool isArticleCapitalised;
QString article;
int checker;
QString articleDeleted;
QString ActualFront;

int misses;
int stopTwice;
int spaceMiss;
int missStop;
int once;
int characters;
int backspaceSpaceStop;

QString text;
QString textM;

QString theme;
QString setCStyleSheet;
QString finishedStyleSheet;

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

QGraphicsSvgItem *svgLeft;
QGraphicsSvgItem *svgRight;
QGraphicsSvgItem *svgLeftDark;
QGraphicsSvgItem *svgRightDark;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateColors();
    updateKeys();

    ui->textEdit_Article->setReadOnly(true);
    ui->lineEdit_TextInput->setReadOnly(true);
    ui->lineEdit_TextInput->setStyleSheet("background-color: white; font-size: 20px;");

    QObject::connect(ui->pushButton_StartCourse,SIGNAL(clicked()),&getInfo,SLOT(start()), Qt::QueuedConnection);
    QObject::connect(&getInfo,SIGNAL(signalValueUpdated(const QString&)),ui->statusbar,SLOT(showMessage(const QString&)), Qt::QueuedConnection);

    QGraphicsScene *sceneLeft = new QGraphicsScene(this);
    QGraphicsScene *sceneRight = new QGraphicsScene(this);
        ui->graphicsView_LeftHand->setScene(sceneLeft);
        ui->graphicsView_RightHand->setScene(sceneRight);

    ui->pushButton_StartCourse->setEnabled(false);

    svgLeft = new QGraphicsSvgItem(":/hands/handLeft.svg");
    svgRight = new QGraphicsSvgItem(":/hands/handRight.svg");
    svgLeftDark = new QGraphicsSvgItem(":/hands/handLeftDark.svg");
    svgRightDark = new QGraphicsSvgItem(":/hands/handRightDark.svg");

    lightMain();
}

void MainWindow::uncheck()
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
    ui->pushButton_RCtrl->setChecked(false);

}
void MainWindow::findChar()
{
    QString articleHands;
    ActualFront = articleDeleted.front();
    isArticleCapitalised = article.isUpper();

    if (ActualFront.isUpper() == true) {isArticleCapitalised = true;}
    if (ActualFront.isLower() == true) {isArticleCapitalised = false;}
    if (ActualFront == " ") {isArticleCapitalised = false;}

    if (ActualFront == keyMap.getTildeS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN1S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN2S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN3S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN4S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN5S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN6S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN7S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN8S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN9S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getN0S()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getMinusS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getEqualsS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getLeftSquareBracketS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getRightSquareBracketS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getBackslashS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getSemicolonS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getApostropheS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getCommaS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getPeriodS()) {isArticleCapitalised = true;}
    if (ActualFront == keyMap.getSlashS()) {isArticleCapitalised = true;}

    if (isArticleCapitalised == true) {
        ui->pushButton_Tilde->setText(keyMap.getTildeS());
        ui->pushButton_1->setText(keyMap.getN1S());
        ui->pushButton_2->setText(keyMap.getN2S());
        ui->pushButton_3->setText(keyMap.getN3S());
        ui->pushButton_4->setText(keyMap.getN4S());
        ui->pushButton_5->setText(keyMap.getN5S());
        ui->pushButton_6->setText(keyMap.getN6S());
        QString fixes;
        if (keyMap.getN7S() == "&") {fixes = "&&";} else {fixes = keyMap.getN7S();}
        ui->pushButton_7->setText(fixes);
        ui->pushButton_8->setText(keyMap.getN8S());
        ui->pushButton_9->setText(keyMap.getN9S());
        ui->pushButton_0->setText(keyMap.getN0S());
        ui->pushButton_Minus->setText(keyMap.getMinusS());
        ui->pushButton_Equals->setText(keyMap.getEqualsS());
        ui->pushButton_Backspace->setText(keyMap.getBackspaceS());
        ui->pushButton_TAB->setText(keyMap.getTABS());
        ui->pushButton_Q->setText(keyMap.getQS());
        ui->pushButton_W->setText(keyMap.getWS());
        ui->pushButton_E->setText(keyMap.getES());
        ui->pushButton_R->setText(keyMap.getRS());
        ui->pushButton_T->setText(keyMap.getTS());
        ui->pushButton_Y->setText(keyMap.getYS());
        ui->pushButton_U->setText(keyMap.getUS());
        ui->pushButton_I->setText(keyMap.getIS());
        ui->pushButton_O->setText(keyMap.getOS());
        ui->pushButton_P->setText(keyMap.getPS());
        ui->pushButton_LeftSquareBracket->setText(keyMap.getLeftSquareBracketS());
        ui->pushButton_RightSquareBracket->setText(keyMap.getRightSquareBracketS());
        ui->pushButton_Backslash->setText(keyMap.getBackslashS());
        ui->pushButton_CAPS->setText(keyMap.getCAPSS());
        ui->pushButton_A->setText(keyMap.getAS());
        ui->pushButton_S->setText(keyMap.getSS());
        ui->pushButton_D->setText(keyMap.getDS());
        ui->pushButton_F->setText(keyMap.getFS());
        ui->pushButton_G->setText(keyMap.getGS());
        ui->pushButton_H->setText(keyMap.getHS());
        ui->pushButton_J->setText(keyMap.getJS());
        ui->pushButton_K->setText(keyMap.getKS());
        ui->pushButton_L->setText(keyMap.getLS());
        ui->pushButton_Semicolon->setText(keyMap.getSemicolonS());
        ui->pushButton_Apostrophe->setText(keyMap.getApostropheS());
        ui->pushButton_Enter->setText(keyMap.getEnterS());
        ui->pushButton_LShift->setText(keyMap.getLShiftS());
        ui->pushButton_Z->setText(keyMap.getZS());
        ui->pushButton_X->setText(keyMap.getXS());
        ui->pushButton_C->setText(keyMap.getCS());
        ui->pushButton_V->setText(keyMap.getVS());
        ui->pushButton_B->setText(keyMap.getBS());
        ui->pushButton_N->setText(keyMap.getNS());
        ui->pushButton_M->setText(keyMap.getMS());
        ui->pushButton_Comma->setText(keyMap.getCommaS());
        ui->pushButton_Period->setText(keyMap.getPeriodS());
        ui->pushButton_Slash->setText(keyMap.getSlashS());
        ui->pushButton_RShift->setText(keyMap.getRShiftS());
        ui->pushButton_LCtrl->setText(keyMap.getLCtrlS());
        ui->pushButton_Super->setText(keyMap.getSuperS());
        ui->pushButton_LAlt->setText(keyMap.getLAltS());
        ui->pushButton_RAlt->setText(keyMap.getRAltS());
        ui->pushButton_Menu->setText(keyMap.getMenuS());
        ui->pushButton_RCtrl->setText(keyMap.getRCtrlS());

        articleHands = ActualFront;
        articleHands = ActualFront.toUpper();
    } else {
        ui->pushButton_1->setText(keyMap.getN1());
        ui->pushButton_2->setText(keyMap.getN2());
        ui->pushButton_3->setText(keyMap.getN3());
        ui->pushButton_4->setText(keyMap.getN4());
        ui->pushButton_5->setText(keyMap.getN5());
        ui->pushButton_6->setText(keyMap.getN6());
        ui->pushButton_7->setText(keyMap.getN7());
        ui->pushButton_8->setText(keyMap.getN8());
        ui->pushButton_9->setText(keyMap.getN9());
        ui->pushButton_0->setText(keyMap.getN0());
        ui->pushButton_Minus->setText(keyMap.getMinus());
        ui->pushButton_Equals->setText(keyMap.getEquals());
        ui->pushButton_Backspace->setText(keyMap.getBackspace());
        ui->pushButton_TAB->setText(keyMap.getTAB());
        ui->pushButton_Q->setText(keyMap.getQ());
        ui->pushButton_W->setText(keyMap.getW());
        ui->pushButton_E->setText(keyMap.getE());
        ui->pushButton_R->setText(keyMap.getR());
        ui->pushButton_T->setText(keyMap.getT());
        ui->pushButton_Y->setText(keyMap.getY());
        ui->pushButton_U->setText(keyMap.getU());
        ui->pushButton_I->setText(keyMap.getI());
        ui->pushButton_O->setText(keyMap.getO());
        ui->pushButton_P->setText(keyMap.getP());
        ui->pushButton_LeftSquareBracket->setText(keyMap.getLeftSquareBracket());
        ui->pushButton_RightSquareBracket->setText(keyMap.getRightSquareBracket());
        ui->pushButton_Backslash->setText(keyMap.getBackslash());
        ui->pushButton_CAPS->setText(keyMap.getCAPS());
        ui->pushButton_A->setText(keyMap.getA());
        ui->pushButton_S->setText(keyMap.getS());
        ui->pushButton_D->setText(keyMap.getD());
        ui->pushButton_F->setText(keyMap.getF());
        ui->pushButton_G->setText(keyMap.getG());
        ui->pushButton_H->setText(keyMap.getH());
        ui->pushButton_J->setText(keyMap.getJ());
        ui->pushButton_K->setText(keyMap.getK());
        ui->pushButton_L->setText(keyMap.getL());
        ui->pushButton_Semicolon->setText(keyMap.getSemicolon());
        ui->pushButton_Apostrophe->setText(keyMap.getApostrophe());
        ui->pushButton_Enter->setText(keyMap.getEnter());
        ui->pushButton_LShift->setText(keyMap.getLShift());
        ui->pushButton_Z->setText(keyMap.getZ());
        ui->pushButton_X->setText(keyMap.getX());
        ui->pushButton_C->setText(keyMap.getC());
        ui->pushButton_V->setText(keyMap.getV());
        ui->pushButton_B->setText(keyMap.getB());
        ui->pushButton_N->setText(keyMap.getN());
        ui->pushButton_M->setText(keyMap.getM());
        ui->pushButton_Comma->setText(keyMap.getComma());
        ui->pushButton_Period->setText(keyMap.getPeriod());
        ui->pushButton_Slash->setText(keyMap.getSlash());
        ui->pushButton_RShift->setText(keyMap.getRShift());
        ui->pushButton_LCtrl->setText(keyMap.getLCtrl());
        ui->pushButton_Super->setText(keyMap.getSuper());
        ui->pushButton_LAlt->setText(keyMap.getLAlt());
        ui->pushButton_RAlt->setText(keyMap.getRAlt());
        ui->pushButton_Menu->setText(keyMap.getMenu());
        ui->pushButton_RCtrl->setText(keyMap.getRCtrl());

        articleHands = ActualFront;
        articleHands = ActualFront.toLower();
    }

    QString characterSearch;
    QString fixes = ui->pushButton_7->text();
    if (fixes == "&&") {fixes = "&";}

    characterSearch = ui->pushButton_Tilde->text(); if (characterSearch == articleHands) {ui->pushButton_Tilde->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
    characterSearch = ui->pushButton_1->text(); if (characterSearch == articleHands) {ui->pushButton_1->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
    characterSearch = ui->pushButton_2->text(); if (characterSearch == articleHands) {ui->pushButton_2->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne); if (isArticleCapitalised == true) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}}
    characterSearch = ui->pushButton_3->text(); if (characterSearch == articleHands) {ui->pushButton_3->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
    characterSearch = ui->pushButton_4->text(); if (characterSearch == articleHands) {ui->pushButton_4->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
    characterSearch = ui->pushButton_5->text(); if (characterSearch == articleHands) {ui->pushButton_5->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
    characterSearch = ui->pushButton_6->text(); if (characterSearch == articleHands) {ui->pushButton_6->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
    characterSearch = ui->pushButton_7->text(); if (fixes == articleHands)           {ui->pushButton_7->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
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
    if (ActualFront == " ") {ui->pushButton_Space->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHFive); ui->graphicsView_RightHand->scene()->addItem(rHOne);}
    if (isArticleCapitalised == true) {
        ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);
        ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);
    }
}
void MainWindow::lightMain()
{
    theme = "light";
    ui->textEdit_Article->setStyleSheet("color: black; background: white; font-size: 20px;");
    centralWidget()->setAutoFillBackground(true);
    QPalette light = centralWidget()->palette();
    light.setColor(QPalette::Background, QColor(240, 240, 240));
    ui->centralwidget->setPalette(light);
    ui->statusbar->setStyleSheet("color: black; background-color: rgb(240, 240, 240); font-size: 20px;");
    ui->pushButton_StartCourse->setStyleSheet("QPushButton:enabled{color: black; background-color: rgb(244, 244, 244);}"
                                              "QPushButton:disabled{color: gray; background-color: rgb(244, 244, 244);}");
    ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white; font-size: 20px;");
    ui->menubar->setStyleSheet("QMenuBar {background-color: transparent; color: black;}"
                               "QMenuBar::selected {background-color: rgb(50, 150, 250); color: rgb(244, 244, 244);}");
    ui->graphicsView_LeftHand->setStyleSheet("background-color: white;");
    ui->graphicsView_RightHand->setStyleSheet("background-color: white;");
    QString menuStyles = "QMenu {background-color: white; border: 0.5px solid black;}"
                         "QMenu::item {color: black; background-color: transparent; padding: 2px 10px 2px 10px;}"
                         "QMenu::item:selected {color: white; background-color: rgb(0, 120, 215);}";
    ui->menuCourses->setStyleSheet(menuStyles);
    ui->menuMapping->setStyleSheet(menuStyles);
    ui->menuSlider->setStyleSheet(menuStyles);
    ui->menuThemes->setStyleSheet(menuStyles);
    setCStyleSheet = "QInputDialog {background-color: rgb(244, 244, 244);}"
                     "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                     "QPlainTextEdit {color: black; background-color: white; font-size: 14px;}"
                     "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 12px;}";
    finishedStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
                         "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                         "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";

    uncheck();
    ui->graphicsView_LeftHand->scene()->removeItem(svgLeftDark);
    ui->graphicsView_RightHand->scene()->removeItem(svgRightDark);

    ui->graphicsView_LeftHand->scene()->addItem(svgLeft);
    ui->graphicsView_RightHand->scene()->addItem(svgRight);

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
void MainWindow::darkMain()
{
    theme = "dark";
    ui->textEdit_Article->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
    centralWidget()->setAutoFillBackground(true);
    QPalette dark = centralWidget()->palette();
    dark.setColor(QPalette::Background, QColor(6, 6, 14));
    ui->centralwidget->setPalette(dark);
    ui->statusbar->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
    ui->pushButton_StartCourse->setStyleSheet("QPushButton:enabled{color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}"
                                              "QPushButton:disabled{color: rgb(100, 100, 100); background-color: rgb(36, 36, 44);}");
    ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
    ui->menubar->setStyleSheet("QMenuBar {background-color: rgb(36, 36, 44); color: rgb(211, 213, 201);}"
                               "QMenuBar::selected {background-color: rgb(96, 96, 104); color: white;}");
    ui->graphicsView_LeftHand->setStyleSheet("background-color: rgb(36, 36, 44);");
    ui->graphicsView_RightHand->setStyleSheet("background-color: rgb(36, 36, 44);");
    QString menuStyles = "QMenu {background-color: rgb(36, 36, 44); border: 1px solid black;}"
                         "QMenu::item {color: white; background-color: rgb(36, 36, 44); padding: 2px 10px 2px 10px;}"
                         "QMenu::item:selected {color: white; background-color: rgb(66, 66, 74);}";
    ui->menuCourses->setStyleSheet(menuStyles);
    ui->menuMapping->setStyleSheet(menuStyles);
    ui->menuSlider->setStyleSheet(menuStyles);
    ui->menuThemes->setStyleSheet(menuStyles);
    setCStyleSheet = "QInputDialog {background-color: rgb(6, 6, 14);}"
                     "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                     "QPlainTextEdit {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}"
                     "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 12px;}";
    finishedStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                         "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                         "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";

    uncheck();

    ui->graphicsView_LeftHand->scene()->removeItem(svgLeft);
    ui->graphicsView_RightHand->scene()->removeItem(svgRight);

    ui->graphicsView_LeftHand->scene()->addItem(svgLeftDark);
    ui->graphicsView_RightHand->scene()->addItem(svgRightDark);

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
void MainWindow::updateColors()
{
    QString orange = keyCol.getOrange();
    QString red = keyCol.getRed();
    QString green = keyCol.getGreen();
    QString blue = keyCol.getBlue();
    QString cyan = keyCol.getCyan();
    QString whiteish = keyCol.getWhiteish();

    ui->pushButton_Tilde->setStyleSheet(orange);
    ui->pushButton_1->setStyleSheet(orange);
    ui->pushButton_2->setStyleSheet(orange);
    ui->pushButton_3->setStyleSheet(red);
    ui->pushButton_4->setStyleSheet(green);
    ui->pushButton_5->setStyleSheet(blue);
    ui->pushButton_6->setStyleSheet(blue);
    ui->pushButton_7->setStyleSheet(cyan);
    ui->pushButton_8->setStyleSheet(cyan);
    ui->pushButton_9->setStyleSheet(green);
    ui->pushButton_0->setStyleSheet(red);
    ui->pushButton_Minus->setStyleSheet(orange);
    ui->pushButton_Equals->setStyleSheet(orange);
    ui->pushButton_Backspace->setStyleSheet(orange);
    ui->pushButton_TAB->setStyleSheet(orange);
    ui->pushButton_Q->setStyleSheet(orange);
    ui->pushButton_W->setStyleSheet(red);
    ui->pushButton_E->setStyleSheet(green);
    ui->pushButton_R->setStyleSheet(blue);
    ui->pushButton_T->setStyleSheet(blue);
    ui->pushButton_Y->setStyleSheet(cyan);
    ui->pushButton_U->setStyleSheet(cyan);
    ui->pushButton_I->setStyleSheet(green);
    ui->pushButton_O->setStyleSheet(red);
    ui->pushButton_P->setStyleSheet(orange);
    ui->pushButton_LeftSquareBracket->setStyleSheet(orange);
    ui->pushButton_RightSquareBracket->setStyleSheet(orange);
    ui->pushButton_Backslash->setStyleSheet(orange);
    ui->pushButton_CAPS->setStyleSheet(orange);
    ui->pushButton_A->setStyleSheet(orange);
    ui->pushButton_S->setStyleSheet(red);
    ui->pushButton_D->setStyleSheet(green);
    ui->pushButton_F->setStyleSheet(blue);
    ui->pushButton_G->setStyleSheet(blue);
    ui->pushButton_H->setStyleSheet(cyan);
    ui->pushButton_J->setStyleSheet(cyan);
    ui->pushButton_K->setStyleSheet(green);
    ui->pushButton_L->setStyleSheet(red);
    ui->pushButton_Semicolon->setStyleSheet(orange);
    ui->pushButton_Apostrophe->setStyleSheet(orange);
    ui->pushButton_Enter->setStyleSheet(orange);
    ui->pushButton_LShift->setStyleSheet(orange);
    ui->pushButton_Z->setStyleSheet(orange);
    ui->pushButton_X->setStyleSheet(red);
    ui->pushButton_C->setStyleSheet(green);
    ui->pushButton_V->setStyleSheet(blue);
    ui->pushButton_B->setStyleSheet(blue);
    ui->pushButton_N->setStyleSheet(cyan);
    ui->pushButton_M->setStyleSheet(cyan);
    ui->pushButton_Comma->setStyleSheet(green);
    ui->pushButton_Period->setStyleSheet(red);
    ui->pushButton_Slash->setStyleSheet(orange);
    ui->pushButton_RShift->setStyleSheet(orange);
    ui->pushButton_LCtrl->setStyleSheet(orange);
    ui->pushButton_Super->setStyleSheet(whiteish);
    ui->pushButton_LAlt->setStyleSheet(orange);
    ui->pushButton_Space->setStyleSheet(whiteish);
    ui->pushButton_RAlt->setStyleSheet(orange);
    ui->pushButton_Menu->setStyleSheet(whiteish);
    ui->pushButton_RCtrl->setStyleSheet(orange);

    rHOne->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHOne->setBrush(QColor(keyCol.getSixthCol()));
    QPen penR1(QColor(keyCol.getSixthCol()), 2); rHOne->setPen(penR1);

    rHTwo->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHTwo->setBrush(QColor(keyCol.getFifthCol()));
    QPen penR2(QColor(keyCol.getFifthCol()), 2); rHTwo->setPen(penR2);

    rHThree->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHThree->setBrush(QColor(keyCol.getThirdCol()));
    QPen penR3(QColor(keyCol.getThirdCol()), 2); rHThree->setPen(penR3);

    rHFour->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHFour->setBrush(QColor(keyCol.getSecondCol()));
    QPen penR4(QColor(keyCol.getSecondCol()), 2); rHFour->setPen(penR4);

    rHFive->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    rHFive->setBrush(QColor(keyCol.getFirstCol()));
    QPen penR5(QColor(keyCol.getFirstCol()), 2); rHFive->setPen(penR5);

    lHOne->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHOne->setBrush(QColor(keyCol.getFirstCol()));
    QPen penL1(QColor(keyCol.getFirstCol()), 2); lHOne->setPen(penL1);

    lHTwo->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHTwo->setBrush(QColor(keyCol.getSecondCol()));
    QPen penL2(QColor(keyCol.getSecondCol()), 2); lHTwo->setPen(penL2);

    lHThree->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHThree->setBrush(QColor(keyCol.getThirdCol()));
    QPen penL3(QColor(keyCol.getThirdCol()), 2); lHThree->setPen(penL3);

    lHFour->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHFour->setBrush(QColor(keyCol.getFourthCol()));
    QPen penL4(QColor(keyCol.getFourthCol()), 2); lHFour->setPen(penL4);

    lHFive->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    lHFive->setBrush(QColor(keyCol.getSixthCol()));
    QPen penL5(QColor(keyCol.getSixthCol()), 2); lHFive->setPen(penL5);
}
void MainWindow::updateKeys()
{
    keyMap.updateKeys();

    //Layer 1
    ui->pushButton_Tilde->setText(keyMap.getTilde());
    ui->pushButton_1->setText(keyMap.getN1());
    ui->pushButton_2->setText(keyMap.getN2());
    ui->pushButton_3->setText(keyMap.getN3());
    ui->pushButton_4->setText(keyMap.getN4());
    ui->pushButton_5->setText(keyMap.getN5());
    ui->pushButton_6->setText(keyMap.getN6());
    ui->pushButton_7->setText(keyMap.getN7());
    ui->pushButton_8->setText(keyMap.getN8());
    ui->pushButton_9->setText(keyMap.getN9());
    ui->pushButton_0->setText(keyMap.getN0());
    ui->pushButton_Minus->setText(keyMap.getMinus());
    ui->pushButton_Equals->setText(keyMap.getEquals());
    ui->pushButton_Backspace->setText(keyMap.getBackspace());
    //Layer 2
    ui->pushButton_TAB->setText(keyMap.getTAB());
    ui->pushButton_Q->setText(keyMap.getQ());
    ui->pushButton_W->setText(keyMap.getW());
    ui->pushButton_E->setText(keyMap.getE());
    ui->pushButton_R->setText(keyMap.getR());
    ui->pushButton_T->setText(keyMap.getT());
    ui->pushButton_Y->setText(keyMap.getY());
    ui->pushButton_U->setText(keyMap.getU());
    ui->pushButton_I->setText(keyMap.getI());
    ui->pushButton_O->setText(keyMap.getO());
    ui->pushButton_P->setText(keyMap.getP());
    ui->pushButton_LeftSquareBracket->setText(keyMap.getLeftSquareBracket());
    ui->pushButton_RightSquareBracket->setText(keyMap.getRightSquareBracket());
    ui->pushButton_Backslash->setText(keyMap.getBackslash());
    //Layer 3
    ui->pushButton_CAPS->setText(keyMap.getCAPS());
    ui->pushButton_A->setText(keyMap.getA());
    ui->pushButton_S->setText(keyMap.getS());
    ui->pushButton_D->setText(keyMap.getD());
    ui->pushButton_F->setText(keyMap.getF());
    ui->pushButton_G->setText(keyMap.getG());
    ui->pushButton_H->setText(keyMap.getH());
    ui->pushButton_J->setText(keyMap.getJ());
    ui->pushButton_K->setText(keyMap.getK());
    ui->pushButton_L->setText(keyMap.getL());
    ui->pushButton_Semicolon->setText(keyMap.getSemicolon());
    ui->pushButton_Apostrophe->setText(keyMap.getApostrophe());
    ui->pushButton_Enter->setText(keyMap.getEnter());
    //Layer 4
    ui->pushButton_LShift->setText(keyMap.getLShift());
    ui->pushButton_Z->setText(keyMap.getZ());
    ui->pushButton_X->setText(keyMap.getX());
    ui->pushButton_C->setText(keyMap.getC());
    ui->pushButton_V->setText(keyMap.getV());
    ui->pushButton_B->setText(keyMap.getB());
    ui->pushButton_N->setText(keyMap.getN());
    ui->pushButton_M->setText(keyMap.getM());
    ui->pushButton_Comma->setText(keyMap.getComma());
    ui->pushButton_Period->setText(keyMap.getPeriod());
    ui->pushButton_Slash->setText(keyMap.getSlash());
    ui->pushButton_RShift->setText(keyMap.getRShift());
    //Layer 5
    ui->pushButton_LCtrl->setText(keyMap.getLCtrl());
    ui->pushButton_Super->setText(keyMap.getSuper());
    ui->pushButton_LAlt->setText(keyMap.getLAlt());
    ui->pushButton_Space->setText(keyMap.getSpace());
    ui->pushButton_RAlt->setText(keyMap.getRAlt());
    ui->pushButton_Menu->setText(keyMap.getMenu());
    ui->pushButton_RCtrl->setText(keyMap.getRCtrl());
}

void MainWindow::changeFontSize(int size)
{
    QFont font("Noto Sans");
    font.setPixelSize(size);
    ui->pushButton_0->setFont(font);
    ui->pushButton_Tilde->setFont(font);
    ui->pushButton_0->setFont(font);
    ui->pushButton_1->setFont(font);
    ui->pushButton_2->setFont(font);
    ui->pushButton_3->setFont(font);
    ui->pushButton_4->setFont(font);
    ui->pushButton_5->setFont(font);
    ui->pushButton_6->setFont(font);
    ui->pushButton_7->setFont(font);
    ui->pushButton_8->setFont(font);
    ui->pushButton_9->setFont(font);
    ui->pushButton_Minus->setFont(font);
    ui->pushButton_Equals->setFont(font);
    ui->pushButton_Q->setFont(font);
    ui->pushButton_W->setFont(font);
    ui->pushButton_E->setFont(font);
    ui->pushButton_E->setFont(font);
    ui->pushButton_R->setFont(font);
    ui->pushButton_T->setFont(font);
    ui->pushButton_Y->setFont(font);
    ui->pushButton_U->setFont(font);
    ui->pushButton_I->setFont(font);
    ui->pushButton_O->setFont(font);
    ui->pushButton_P->setFont(font);
    ui->pushButton_LeftSquareBracket->setFont(font);
    ui->pushButton_RightSquareBracket->setFont(font);
    ui->pushButton_Backslash->setFont(font);
    ui->pushButton_A->setFont(font);
    ui->pushButton_S->setFont(font);
    ui->pushButton_D->setFont(font);
    ui->pushButton_F->setFont(font);
    ui->pushButton_G->setFont(font);
    ui->pushButton_H->setFont(font);
    ui->pushButton_J->setFont(font);
    ui->pushButton_K->setFont(font);
    ui->pushButton_L->setFont(font);
    ui->pushButton_Semicolon->setFont(font);
    ui->pushButton_Apostrophe->setFont(font);
    ui->pushButton_Z->setFont(font);
    ui->pushButton_X->setFont(font);
    ui->pushButton_C->setFont(font);
    ui->pushButton_V->setFont(font);
    ui->pushButton_B->setFont(font);
    ui->pushButton_N->setFont(font);
    ui->pushButton_M->setFont(font);
    ui->pushButton_Comma->setFont(font);
    ui->pushButton_Period->setFont(font);
    ui->pushButton_Slash->setFont(font);
    ui->pushButton_Backspace->setFont(font);
    ui->pushButton_TAB->setFont(font);
    ui->pushButton_CAPS->setFont(font);
    ui->pushButton_Enter->setFont(font);
    ui->pushButton_LCtrl->setFont(font);
    ui->pushButton_RCtrl->setFont(font);
    ui->pushButton_LAlt->setFont(font);
    ui->pushButton_RAlt->setFont(font);
    ui->pushButton_Super->setFont(font);
    ui->pushButton_Menu->setFont(font);
    ui->pushButton_Space->setFont(font);
    QFont otherFont("Inconsolata Extra Expanded");
    otherFont.setPointSize(size * 1.3409523809523809523809523809524);
    ui->pushButton_LShift->setFont(otherFont);
    ui->pushButton_RShift->setFont(otherFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_TextInput_textChanged(const QString &arg1)
{
    QString word = arg1;
    QString lastCharacter;
    lastCharacter = arg1.back();
    QString articleIn = article;
    articleIn = article.front();
    QString front;
    QString actualFront;
    stopTwice = 0;

    if (missStop == 0) {
        uncheck();
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
            backspaceSpaceStop = 0;
            if (lastCharacter == " ")
            {
                article = article.simplified();
                backspaceSpaceStop = 1;
            } else {
                article.remove(0, 1);
                backspaceSpaceStop = 1;
            }
            ui->textEdit_Article->setText(article);

            if (actualFront == articleIn) {checker = 1;} else {checker = 0;}
            if (checker == 0) {
                front = articleDeleted.front();
                if (front == " ")
                {
                    articleDeleted = articleDeleted.simplified();
                    spaceMiss = spaceMiss + 1;
                } else {
                    articleDeleted.remove(0, 1);
                }
                actualFront = articleDeleted.front();
                ActualFront = actualFront;
            }
            if (theme == "light") {
                ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white; font-size: 20px;");
            } else {
                ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
            }

            findChar();
        } else {
            misses = misses + 1;
            if (lastCharacter == " ") {spaceMiss = spaceMiss + 2;}
            missStop = 1;
            ui->lineEdit_TextInput->setStyleSheet("background-color: red; font-size: 20px;");
            if (backspaceSpaceStop == 0) {
                ui->pushButton_Backspace->setChecked(true);
                ui->graphicsView_RightHand->scene()->addItem(rHFive);
            }
            text = arg1;
            textM = arg1;
            textM.chop(1);
        }
        if (article == "")
        {
            getInfo.stopRunning();
            ui->lineEdit_TextInput->setReadOnly(true);
            ui->menuCourses->setEnabled(true);
            ui->action_MakeCustomCourse->setEnabled(true);

            ui->lineEdit_TextInput->setText("");
            word = "";
            lastCharacter = "";
            articleIn = "";

            QMessageBox finished;

            finished.setStyleSheet(finishedStyleSheet);
            finished.setWindowTitle("Course finished!");

            QString text = "You've finished the course!\n" + getInfo.getTime() + "\nMisses: " + QString::number(misses - spaceMiss);

            finished.setText(text);

            if (stopTwice == 0) {finished.exec(); stopTwice = 1;}

            ui->statusbar->showMessage("");
            article = "Please select a course!";
            ui->textEdit_Article->setText(article);
            ui->textEdit_Article->setAlignment(Qt::AlignCenter);
            misses = 0;
            spaceMiss = 0;
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
    } else if (missStop == 1) {
        int currC = arg1.count();
        if (once == 0) {
            characters = text.count(); once = 1;
        }
        if (currC > characters)
        {
            ui->lineEdit_TextInput->setText(text);
        }
        if (currC < characters)
        {
            ui->pushButton_Backspace->setChecked(false);
            ui->graphicsView_RightHand->scene()->removeItem(rHFive);
            ui->lineEdit_TextInput->setText(textM);
            missStop = 2;

            findChar();
            if (lastCharacter == articleIn) {
                missStop = 0;
                article.remove(0, 1);
                articleDeleted.remove(0, 1);
                ui->textEdit_Article->setText(article);
                if (theme == "light") {
                    ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white; font-size: 20px;");
                } else {
                    ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
                }
            } else {ui->lineEdit_TextInput->setText(textM);}
        }
    } else {
        findChar();
        if (lastCharacter == articleIn) {
            missStop = 0;
            article.remove(0, 1);
            articleDeleted.remove(0, 1);
            ui->textEdit_Article->setText(article);
            if (theme == "light") {
                ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white; font-size: 20px;");
            } else {
                ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
            }
        } else {ui->lineEdit_TextInput->setText(textM);}
    }
}

void MainWindow::on_action_MakeCustomCourse_triggered()
{
    QString text;
    QInputDialog getCustomText;
    getCustomText.setOption(QInputDialog::UsePlainTextEditForTextInput);
    getCustomText.setWindowTitle("Set a custom course");
    getCustomText.setLabelText("Type in or paste an article.");
    getCustomText.setStyleSheet(setCStyleSheet);
    if (getCustomText.exec() == QInputDialog::Accepted) {
        text = getCustomText.textValue();
        text = text.simplified();

        if (text == "") {
            QMessageBox empty;
            empty.setStyleSheet(finishedStyleSheet);
            empty.setWindowTitle("Empty");
            empty.setText("Warning! You didn't enter anything!");
            empty.exec();
        } else {

            uncheck();

            article = text;
            articleDeleted = text;
            ui->textEdit_Article->setText(articleDeleted);
            ui->pushButton_StartCourse->setEnabled(true);

            findChar();
        }
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
    keyMap.updateKeys();
    keyMap.setModal(true);

    keyMap.setOrange("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getFirstCol() + "; border: 3px solid " + keyCol.getFirstBor() + "; border-radius:10px;");
    keyMap.setRed("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getSecondCol() + "; border: 3px solid " + keyCol.getSecondBor() + "; border-radius:10px;");
    keyMap.setGreen("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getThirdCol() + "; border: 3px solid " + keyCol.getThirdBor() + "; border-radius:10px;");
    keyMap.setBlue("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getFourthCol() + "; border: 3px solid " + keyCol.getFourthBor() + "; border-radius:10px;");
    keyMap.setCyan("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getFifthCol() + "; border: 3px solid " + keyCol.getFifthBor() + "; border-radius:10px;");
    keyMap.setWhiteish("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getSixthCol() + "; border: 3px solid " + keyCol.getSixthBor() + "; border-radius:10px;");

    keyMap.setOrangeS("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getFirstTog() + "; border: 3px solid " + keyCol.getFirstBor() + "; border-radius:10px;");
    keyMap.setRedS("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getSecondTog() + "; border: 3px solid " + keyCol.getSecondBor() + "; border-radius:10px;");
    keyMap.setGreenS("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getThirdTog() + "; border: 3px solid " + keyCol.getThirdBor() + "; border-radius:10px;");
    keyMap.setBlueS("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getFourthTog() + "; border: 3px solid " + keyCol.getFourthBor() + "; border-radius:10px;");
    keyMap.setCyanS("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getFifthTog() + "; border: 3px solid " + keyCol.getFifthBor() + "; border-radius:10px;");
    keyMap.setWhiteishS("color: " + keyCol.getTextCol() +  "; background-color: " + keyCol.getSixthTog() + "; border: 3px solid " + keyCol.getSixthBor() + "; border-radius:10px;");

    QColor color1; QColor color2;
    color1 = keyCol.getFirstTog(); color1 = color1.darker(65); color2 = keyCol.getFirstBor(); color2 = color2.darker(65);
    keyMap.setOrangeSK("color: " + keyCol.getTextCol() +  "; background-color: " + color1.name() + "; border: 3px solid " + color2.name() + "; border-radius:10px;");
    color1 = keyCol.getSecondTog(); color1 = color1.darker(65); color2 = keyCol.getSecondBor(); color2 = color2.darker(65);
    keyMap.setRedSK("color: " + keyCol.getTextCol() +  "; background-color: " + color1.name() + "; border: 3px solid " + color2.name() + "; border-radius:10px;");
    color1 = keyCol.getThirdTog(); color1 = color1.darker(65); color2 = keyCol.getThirdBor(); color2 = color2.darker(65);
    keyMap.setGreenSK("color: " + keyCol.getTextCol() +  "; background-color: " + color1.name() + "; border: 3px solid " + color2.name() + "; border-radius:10px;");
    color1 = keyCol.getFourthTog(); color1 = color1.darker(65); color2 = keyCol.getFourthBor(); color2 = color2.darker(65);
    keyMap.setBlueSK("color: " + keyCol.getTextCol() +  "; background-color: " + color1.name() + "; border: 3px solid " + color2.name() + "; border-radius:10px;");
    color1 = keyCol.getFifthTog(); color1 = color1.darker(65); color2 = keyCol.getFifthBor(); color2 = color2.darker(65);
    keyMap.setCyanSK("color: " + keyCol.getTextCol() +  "; background-color: " + color1.name() + "; border: 3px solid " + color2.name() + "; border-radius:10px;");
    color1 = keyCol.getSixthTog(); color1 = color1.darker(65); color2 = keyCol.getSixthBor(); color2 = color2.darker(65);
    keyMap.setWhiteishSK("color: " + keyCol.getTextCol() +  "; background-color: " + color1.name() + "; border: 3px solid " + color2.name() + "; border-radius:10px;");

    keyMap.on_pushButton_OnShift_toggled(false);
    keyMap.updateColors();
    if (keyMap.exec() == QDialog::Accepted)
    {
        updateKeys();
    }
}

void MainWindow::on_action_CourseSelector_triggered()
{
    courses.setModal(true);
    courses.updateVars();
    if (courses.exec() == QDialog::Accepted)
    {
        uncheck();

        ui->pushButton_StartCourse->setEnabled(true);

        QString cArticle = courses.getArticle();
        articleDeleted = cArticle;
        article = cArticle;
        ui->textEdit_Article->setText(article);

        findChar();
    }
}

void MainWindow::on_action_ChangeKeyColors_triggered()
{
    keyCol.setModal(true);

    //Update mapping
    //Layer 1
    keyCol.setTilde(keyMap.getTilde());
    keyCol.setN1(keyMap.getN1());
    keyCol.setN2(keyMap.getN2());
    keyCol.setN3(keyMap.getN3());
    keyCol.setN4(keyMap.getN4());
    keyCol.setN5(keyMap.getN5());
    keyCol.setN6(keyMap.getN6());
    keyCol.setN7(keyMap.getN7());
    keyCol.setN8(keyMap.getN8());
    keyCol.setN9(keyMap.getN9());
    keyCol.setN0(keyMap.getN0());
    keyCol.setMinus(keyMap.getMinus());
    keyCol.setEquals(keyMap.getEquals());
    keyCol.setBackspace(keyMap.getBackspace());
    //Layer 2
    keyCol.setTAB(keyMap.getTAB());
    keyCol.setQ(keyMap.getQ());
    keyCol.setW(keyMap.getW());
    keyCol.setE(keyMap.getE());
    keyCol.setR(keyMap.getR());
    keyCol.setT(keyMap.getT());
    keyCol.setY(keyMap.getY());
    keyCol.setU(keyMap.getU());
    keyCol.setI(keyMap.getI());
    keyCol.setO(keyMap.getO());
    keyCol.setP(keyMap.getP());
    keyCol.setLeftSquareBracket(keyMap.getLeftSquareBracket());
    keyCol.setRightSquareBracket(keyMap.getRightSquareBracket());
    keyCol.setBackslash(keyMap.getBackslash());
    //Layer 3
    keyCol.setCAPS(keyMap.getCAPS());
    keyCol.setA(keyMap.getA());
    keyCol.setS(keyMap.getS());
    keyCol.setD(keyMap.getD());
    keyCol.setF(keyMap.getF());
    keyCol.setG(keyMap.getG());
    keyCol.setH(keyMap.getH());
    keyCol.setJ(keyMap.getJ());
    keyCol.setK(keyMap.getK());
    keyCol.setL(keyMap.getL());
    keyCol.setSemicolon(keyMap.getSemicolon());
    keyCol.setApostrophe(keyMap.getApostrophe());
    keyCol.setEnter(keyMap.getEnter());
    //Layer 4
    keyCol.setLShift(keyMap.getLShift());
    keyCol.setZ(keyMap.getZ());
    keyCol.setX(keyMap.getX());
    keyCol.setC(keyMap.getC());
    keyCol.setV(keyMap.getV());
    keyCol.setB(keyMap.getB());
    keyCol.setN(keyMap.getN());
    keyCol.setM(keyMap.getM());
    keyCol.setComma(keyMap.getComma());
    keyCol.setPeriod(keyMap.getPeriod());
    keyCol.setSlash(keyMap.getSlash());
    keyCol.setRShift(keyMap.getRShift());
    //Layer 5
    keyCol.setLCtrl(keyMap.getLCtrl());
    keyCol.setSuper(keyMap.getSuper());
    keyCol.setLAlt(keyMap.getLAlt());
    keyCol.setSpace(keyMap.getSpace());
    keyCol.setRAlt(keyMap.getRAlt());
    keyCol.setMenu(keyMap.getMenu());
    keyCol.setRCtrl(keyMap.getRCtrl());

    //Layer 1 shift
    keyCol.setTildeS(keyMap.getTildeS());
    keyCol.setN1S(keyMap.getN1S());
    keyCol.setN2S(keyMap.getN2S());
    keyCol.setN3S(keyMap.getN3S());
    keyCol.setN4S(keyMap.getN4S());
    keyCol.setN5S(keyMap.getN5S());
    keyCol.setN6S(keyMap.getN6S());
    QString bad = keyMap.getN7S(); if (bad == "&") {bad = "&&";}
    keyCol.setN7S(bad);
    keyCol.setN8S(keyMap.getN8S());
    keyCol.setN9S(keyMap.getN9S());
    keyCol.setN0S(keyMap.getN0S());
    keyCol.setMinusS(keyMap.getMinusS());
    keyCol.setEqualsS(keyMap.getEqualsS());
    keyCol.setBackspaceS(keyMap.getBackspaceS());
    //Layer 2 shift
    keyCol.setTABS(keyMap.getTABS());
    keyCol.setQS(keyMap.getQS());
    keyCol.setWS(keyMap.getWS());
    keyCol.setES(keyMap.getES());
    keyCol.setRS(keyMap.getRS());
    keyCol.setTS(keyMap.getTS());
    keyCol.setYS(keyMap.getYS());
    keyCol.setUS(keyMap.getUS());
    keyCol.setIS(keyMap.getIS());
    keyCol.setOS(keyMap.getOS());
    keyCol.setPS(keyMap.getPS());
    keyCol.setLeftSquareBracketS(keyMap.getLeftSquareBracketS());
    keyCol.setRightSquareBracketS(keyMap.getRightSquareBracketS());
    keyCol.setBackslashS(keyMap.getBackslashS());
    //Layer 3 shift
    keyCol.setCAPSS(keyMap.getCAPSS());
    keyCol.setAS(keyMap.getAS());
    keyCol.setSS(keyMap.getSS());
    keyCol.setDS(keyMap.getDS());
    keyCol.setFS(keyMap.getFS());
    keyCol.setGS(keyMap.getGS());
    keyCol.setHS(keyMap.getHS());
    keyCol.setJS(keyMap.getJS());
    keyCol.setKS(keyMap.getKS());
    keyCol.setLS(keyMap.getLS());
    keyCol.setSemicolonS(keyMap.getSemicolonS());
    keyCol.setApostropheS(keyMap.getApostropheS());
    keyCol.setEnterS(keyMap.getEnterS());
    //Layer 4 shift
    keyCol.setLShiftS(keyMap.getLShiftS());
    keyCol.setZS(keyMap.getZS());
    keyCol.setXS(keyMap.getXS());
    keyCol.setCS(keyMap.getCS());
    keyCol.setVS(keyMap.getVS());
    keyCol.setBS(keyMap.getBS());
    keyCol.setNS(keyMap.getNS());
    keyCol.setMS(keyMap.getMS());
    keyCol.setCommaS(keyMap.getCommaS());
    keyCol.setPeriodS(keyMap.getPeriodS());
    keyCol.setSlashS(keyMap.getSlashS());
    keyCol.setRShiftS(keyMap.getRShiftS());
    //Layer 5 shift
    keyCol.setLCtrlS(keyMap.getLCtrlS());
    keyCol.setSuperS(keyMap.getSuperS());
    keyCol.setLAltS(keyMap.getLAltS());
    keyCol.setSpaceS(keyMap.getSpaceS());
    keyCol.setRAltS(keyMap.getRAltS());
    keyCol.setMenuS(keyMap.getMenuS());
    keyCol.setRCtrlS(keyMap.getRCtrlS());

    //cancel handling
    QFile *cancel = new QFile(keyCol.getPath());
    QTextStream reading(cancel);
    cancel->open(QIODevice::ReadOnly);
    QString Cancel = reading.readAll();
    cancel->close();

    keyCol.unToggle();

    if (keyCol.exec() == QDialog::Accepted) {updateColors();} else {
        cancel->open(QIODevice::ReadWrite);
        cancel->resize(0);
        cancel->write(Cancel.toUtf8());
        cancel->close();

        keyCol.updateCols();
    }
}

void MainWindow::on_action_Light_triggered()
{
    lightMain();
    courses.lightCourses();
    keyMap.lightMap();
    keyCol.lightCol();
}
void MainWindow::on_action_Dark_triggered()
{
    darkMain();
    courses.darkCourses();
    keyMap.darkMap();
    keyCol.darkCol();
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    //988 //35
    //450 //32
    double width = this->size().width() / 28.228571;
    double height = this->size().height() / 14.0625;
    ui->pushButton_Tilde->setMaximumSize(width, height);
    ui->pushButton_0->setMaximumSize(width, height);
    ui->pushButton_0->setMinimumSize(width, height);
    ui->pushButton_1->setMaximumSize(width, height);
    ui->pushButton_1->setMinimumSize(width, height);
    ui->pushButton_2->setMaximumSize(width, height);
    ui->pushButton_2->setMinimumSize(width, height);
    ui->pushButton_3->setMaximumSize(width, height);
    ui->pushButton_3->setMinimumSize(width, height);
    ui->pushButton_4->setMaximumSize(width, height);
    ui->pushButton_4->setMinimumSize(width, height);
    ui->pushButton_5->setMaximumSize(width, height);
    ui->pushButton_5->setMinimumSize(width, height);
    ui->pushButton_6->setMaximumSize(width, height);
    ui->pushButton_6->setMinimumSize(width, height);
    ui->pushButton_7->setMaximumSize(width, height);
    ui->pushButton_7->setMinimumSize(width, height);
    ui->pushButton_8->setMaximumSize(width, height);
    ui->pushButton_8->setMinimumSize(width, height);
    ui->pushButton_9->setMaximumSize(width, height);
    ui->pushButton_9->setMinimumSize(width, height);
    ui->pushButton_Minus->setMaximumSize(width, height);
    ui->pushButton_Minus->setMinimumSize(width, height);
    ui->pushButton_Equals->setMaximumSize(width, height);
    ui->pushButton_Equals->setMinimumSize(width, height);
    ui->pushButton_Q->setMaximumSize(width, height);
    ui->pushButton_Q->setMinimumSize(width, height);
    ui->pushButton_W->setMaximumSize(width, height);
    ui->pushButton_W->setMinimumSize(width, height);
    ui->pushButton_E->setMaximumSize(width, height);
    ui->pushButton_E->setMinimumSize(width, height);
    ui->pushButton_R->setMaximumSize(width, height);
    ui->pushButton_R->setMinimumSize(width, height);
    ui->pushButton_T->setMaximumSize(width, height);
    ui->pushButton_T->setMinimumSize(width, height);
    ui->pushButton_Y->setMaximumSize(width, height);
    ui->pushButton_Y->setMinimumSize(width, height);
    ui->pushButton_U->setMaximumSize(width, height);
    ui->pushButton_U->setMinimumSize(width, height);
    ui->pushButton_I->setMaximumSize(width, height);
    ui->pushButton_I->setMinimumSize(width, height);
    ui->pushButton_O->setMaximumSize(width, height);
    ui->pushButton_O->setMinimumSize(width, height);
    ui->pushButton_P->setMaximumSize(width, height);
    ui->pushButton_P->setMinimumSize(width, height);
    ui->pushButton_LeftSquareBracket->setMaximumSize(width, height);
    ui->pushButton_LeftSquareBracket->setMinimumSize(width, height);
    ui->pushButton_RightSquareBracket->setMaximumSize(width, height);
    ui->pushButton_RightSquareBracket->setMinimumSize(width, height);
    ui->pushButton_Backslash->setMaximumSize(width, height);
    ui->pushButton_Backslash->setMinimumSize(width, height);
    ui->pushButton_A->setMaximumSize(width, height);
    ui->pushButton_A->setMinimumSize(width, height);
    ui->pushButton_S->setMaximumSize(width, height);
    ui->pushButton_S->setMinimumSize(width, height);
    ui->pushButton_D->setMaximumSize(width, height);
    ui->pushButton_D->setMinimumSize(width, height);
    ui->pushButton_F->setMaximumSize(width, height);
    ui->pushButton_F->setMinimumSize(width, height);
    ui->pushButton_G->setMaximumSize(width, height);
    ui->pushButton_G->setMinimumSize(width, height);
    ui->pushButton_H->setMaximumSize(width, height);
    ui->pushButton_H->setMinimumSize(width, height);
    ui->pushButton_J->setMaximumSize(width, height);
    ui->pushButton_J->setMinimumSize(width, height);
    ui->pushButton_K->setMaximumSize(width, height);
    ui->pushButton_K->setMinimumSize(width, height);
    ui->pushButton_L->setMaximumSize(width, height);
    ui->pushButton_L->setMinimumSize(width, height);
    ui->pushButton_Semicolon->setMaximumSize(width, height);
    ui->pushButton_Semicolon->setMinimumSize(width, height);
    ui->pushButton_Apostrophe->setMaximumSize(width, height);
    ui->pushButton_Apostrophe->setMinimumSize(width, height);
    ui->pushButton_Z->setMaximumSize(width, height);
    ui->pushButton_Z->setMinimumSize(width, height);
    ui->pushButton_X->setMaximumSize(width, height);
    ui->pushButton_X->setMinimumSize(width, height);
    ui->pushButton_C->setMaximumSize(width, height);
    ui->pushButton_C->setMinimumSize(width, height);
    ui->pushButton_V->setMaximumSize(width, height);
    ui->pushButton_V->setMinimumSize(width, height);
    ui->pushButton_B->setMaximumSize(width, height);
    ui->pushButton_B->setMinimumSize(width, height);
    ui->pushButton_N->setMaximumSize(width, height);
    ui->pushButton_N->setMinimumSize(width, height);
    ui->pushButton_M->setMaximumSize(width, height);
    ui->pushButton_M->setMinimumSize(width, height);
    ui->pushButton_Comma->setMaximumSize(width, height);
    ui->pushButton_Comma->setMinimumSize(width, height);
    ui->pushButton_Period->setMaximumSize(width, height);
    ui->pushButton_Period->setMinimumSize(width, height);
    ui->pushButton_Slash->setMaximumSize(width, height);
    ui->pushButton_Slash->setMinimumSize(width, height);

    width = this->size().width() / 12.35;
    ui->pushButton_Backspace->setMaximumSize(width, height);
    ui->pushButton_Backspace->setMinimumSize(width, height);
    ui->pushButton_TAB->setMaximumSize(width, height);
    ui->pushButton_TAB->setMinimumSize(width, height);

    width = this->size().width() / 12.0487804;
    ui->pushButton_CAPS->setMaximumSize(width, height);
    ui->pushButton_CAPS->setMinimumSize(width, height);

    width = this->size().width() / 14.529411764705882352941176470588;
    ui->pushButton_Enter->setMaximumSize(width, height);
    ui->pushButton_Enter->setMinimumSize(width, height);

    width = this->size().width() / 10.291666666666666666666666666667;
    ui->pushButton_LShift->setMaximumSize(width, height);
    ui->pushButton_LShift->setMinimumSize(width, height);
    ui->pushButton_RShift->setMaximumSize(width, height);
    ui->pushButton_RShift->setMinimumSize(width, height);

    width = this->size().width() / 16.7457621;
    ui->pushButton_LCtrl->setMaximumSize(width, height);
    ui->pushButton_LCtrl->setMinimumSize(width, height);
    ui->pushButton_RCtrl->setMaximumSize(width, height);
    ui->pushButton_RCtrl->setMinimumSize(width, height);

    width = this->size().width() / 23.5238;
    ui->pushButton_LAlt->setMaximumSize(width, height);
    ui->pushButton_LAlt->setMinimumSize(width, height);
    ui->pushButton_RAlt->setMaximumSize(width, height);
    ui->pushButton_RAlt->setMinimumSize(width, height);

    width = this->size().width() / 24.7;
    ui->pushButton_Super->setMaximumSize(width, height);
    ui->pushButton_Super->setMinimumSize(width, height);
    ui->pushButton_Menu->setMaximumSize(width, height);
    ui->pushButton_Menu->setMinimumSize(width, height);

    width = this->size().width() / 3.6323529411764705882352941176471;
    ui->pushButton_Space->setMaximumSize(width, height);
    ui->pushButton_Space->setMinimumSize(width, height);

    //180   //194
    width = this->size().width() / 5.4888888888888888888888888888889;
    height = this->size().height() / 2.5;
    ui->graphicsView_LeftHand->setMaximumSize(width, height);
    ui->graphicsView_LeftHand->setMinimumSize(width, height);
    ui->graphicsView_RightHand->setMaximumSize(width, height);
    ui->graphicsView_RightHand->setMinimumSize(width, height);

    if (ui->graphicsView_LeftHand->height() > ui->graphicsView_LeftHand->width()) {
        ui->graphicsView_LeftHand->resetTransform();
        ui->graphicsView_LeftHand->scale(width / 173, width / 173);
        ui->graphicsView_RightHand->resetTransform();
        ui->graphicsView_RightHand->scale(width / 173, width / 173);
    }

    changeFontSize(this->size().width() / 47.047619047619047619047619047619);
}

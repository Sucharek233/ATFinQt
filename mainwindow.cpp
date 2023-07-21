#include "mainwindow.h"
#include "ui_mainwindow.h"

bool isArticleCapitalised;
QString article;
int checker;
QString ActualFront;

QString saveLast;
int misses;
int stopTwice;
int missStop;

QString text;
QString textM;

QString theme;
QString setCStyleSheet;
QString finishedStyleSheet;

int align = 1;

int selectCheck;

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

bool isItemRemoved(QGraphicsScene* scene, QGraphicsItem* item) {
    QList<QGraphicsItem*> items = scene->items();
    return !items.contains(item);
}
void MainWindow::uncheck()
{
    if (!isItemRemoved(ui->graphicsView_RightHand->scene(), rHOne)) {ui->graphicsView_RightHand->scene()->removeItem(rHOne);}
    if (!isItemRemoved(ui->graphicsView_RightHand->scene(), rHTwo)) {ui->graphicsView_RightHand->scene()->removeItem(rHTwo);}
    if (!isItemRemoved(ui->graphicsView_RightHand->scene(), rHThree)) {ui->graphicsView_RightHand->scene()->removeItem(rHThree);}
    if (!isItemRemoved(ui->graphicsView_RightHand->scene(), rHFour)) {ui->graphicsView_RightHand->scene()->removeItem(rHFour);}
    if (!isItemRemoved(ui->graphicsView_RightHand->scene(), rHFive)) {ui->graphicsView_RightHand->scene()->removeItem(rHFive);}
    if (!isItemRemoved(ui->graphicsView_LeftHand->scene(), lHOne)) {ui->graphicsView_LeftHand->scene()->removeItem(lHOne);}
    if (!isItemRemoved(ui->graphicsView_LeftHand->scene(), lHTwo)) {ui->graphicsView_LeftHand->scene()->removeItem(lHTwo);}
    if (!isItemRemoved(ui->graphicsView_LeftHand->scene(), lHThree)) {ui->graphicsView_LeftHand->scene()->removeItem(lHThree);}
    if (!isItemRemoved(ui->graphicsView_LeftHand->scene(), lHFour)) {ui->graphicsView_LeftHand->scene()->removeItem(lHFour);}
    if (!isItemRemoved(ui->graphicsView_LeftHand->scene(), lHFive)) {ui->graphicsView_LeftHand->scene()->removeItem(lHFive);}

    foreach (QObject *widget, ui->centralwidget->children()) {
        QPushButton *button = qobject_cast<QPushButton *>(widget);
        if (button != nullptr) {
            button->setChecked(false);
        }
    }
}
void MainWindow::findChar()
{
    if (selectCheck == 1) {selectCheck = 0; return;}

    QString articleHands;
    ActualFront = article.front();
    isArticleCapitalised = article.isUpper();

    if (ActualFront.isUpper()) {isArticleCapitalised = true;}
    if (ActualFront.isLower()) {isArticleCapitalised = false;}
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

    if (isArticleCapitalised) {
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

    struct ButtonData {
        QPushButton* button;
        QGraphicsScene* scene;
        QGraphicsItem* item;
    };

    QVector<ButtonData> buttonDataList = {
        {ui->pushButton_Tilde, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_1, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_2, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_3, ui->graphicsView_LeftHand->scene(), lHTwo},
        {ui->pushButton_4, ui->graphicsView_LeftHand->scene(), lHThree},
        {ui->pushButton_5, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_6, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_7, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_8, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_9, ui->graphicsView_RightHand->scene(), rHThree},
        {ui->pushButton_0, ui->graphicsView_RightHand->scene(), rHFour},
        {ui->pushButton_Minus, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_Equals, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_Backspace, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_TAB, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_Q, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_W, ui->graphicsView_LeftHand->scene(), lHTwo},
        {ui->pushButton_E, ui->graphicsView_LeftHand->scene(), lHThree},
        {ui->pushButton_R, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_T, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_Y, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_U, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_I, ui->graphicsView_RightHand->scene(), rHThree},
        {ui->pushButton_O, ui->graphicsView_RightHand->scene(), rHFour},
        {ui->pushButton_P, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_LeftSquareBracket, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_RightSquareBracket, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_Backslash, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_CAPS, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_A, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_S, ui->graphicsView_LeftHand->scene(), lHTwo},
        {ui->pushButton_D, ui->graphicsView_LeftHand->scene(), lHThree},
        {ui->pushButton_F, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_G, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_H, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_J, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_K, ui->graphicsView_RightHand->scene(), rHThree},
        {ui->pushButton_L, ui->graphicsView_RightHand->scene(), rHFour},
        {ui->pushButton_Semicolon, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_Apostrophe, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_Enter, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_LShift, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_Z, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_X, ui->graphicsView_LeftHand->scene(), lHTwo},
        {ui->pushButton_C, ui->graphicsView_LeftHand->scene(), lHThree},
        {ui->pushButton_V, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_B, ui->graphicsView_LeftHand->scene(), lHFour},
        {ui->pushButton_N, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_M, ui->graphicsView_RightHand->scene(), rHTwo},
        {ui->pushButton_Comma, ui->graphicsView_RightHand->scene(), rHThree},
        {ui->pushButton_Period, ui->graphicsView_RightHand->scene(), rHFour},
        {ui->pushButton_Slash, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_RShift, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_LCtrl, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_Super, ui->graphicsView_LeftHand->scene(), lHFive},
        {ui->pushButton_LAlt, ui->graphicsView_LeftHand->scene(), lHOne},
        {ui->pushButton_RAlt, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_Menu, ui->graphicsView_RightHand->scene(), rHOne},
        {ui->pushButton_RCtrl, ui->graphicsView_RightHand->scene(), rHFive},
        {ui->pushButton_Space, ui->graphicsView_LeftHand->scene(), lHFive},
    };

    for (const ButtonData& buttonData : buttonDataList) {
        QString characterSearch = buttonData.button->text();
        if (characterSearch == articleHands) {
            buttonData.button->setChecked(true);
            if (isItemRemoved(buttonData.scene, buttonData.item)) {buttonData.scene->addItem(buttonData.item);}

            if (isArticleCapitalised) {
//                buttonData.scene->addItem(lHTwo);
            }
        }
    }

    if (isArticleCapitalised) {
        ui->pushButton_LShift->setChecked(true); ui->graphicsView_LeftHand->scene()->addItem(lHOne);
        ui->pushButton_RShift->setChecked(true); ui->graphicsView_RightHand->scene()->addItem(rHFive);
    }
}
void MainWindow::lightMain()
{
    if (theme == "light") {return;}
    theme = "light";
    ui->textEdit_Article->setStyleSheet("color: black; background: white; font-size: 20px;");
    centralWidget()->setAutoFillBackground(true);
    QPalette light = centralWidget()->palette();
    light.setColor(QPalette::Background, QColor(240, 240, 240));
    ui->centralwidget->setPalette(light);
    ui->statusbar->setStyleSheet("color: black; background-color: rgb(240, 240, 240); font-size: 20px;");
    ui->pushButton_StartCourse->setStyleSheet("QPushButton:enabled{color: black; background-color: rgb(244, 244, 244);}"
                                              "QPushButton:disabled{color: gray; background-color: rgb(244, 244, 244);}");
    ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white;");
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
                     "QPlainTextEdit {color: black; background-color: white; font-size: 15px;}"
                     "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";
    finishedStyleSheet = "QMessageBox {background-color: rgb(244, 244, 244);}"
                         "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 16px;}"
                         "QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}";

    uncheck();
    if (!isItemRemoved(ui->graphicsView_LeftHand->scene(), svgLeftDark)) {ui->graphicsView_LeftHand->scene()->removeItem(svgLeftDark);}
    if (!isItemRemoved(ui->graphicsView_RightHand->scene(), svgRightDark)) {ui->graphicsView_RightHand->scene()->removeItem(svgRightDark);}

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
    if (theme == "dark") {return;}
    theme = "dark";
    ui->textEdit_Article->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
    centralWidget()->setAutoFillBackground(true);
    QPalette dark = centralWidget()->palette();
    dark.setColor(QPalette::Background, QColor(6, 6, 14));
    ui->centralwidget->setPalette(dark);
    ui->statusbar->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 20px;");
    ui->pushButton_StartCourse->setStyleSheet("QPushButton:enabled{color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}"
                                              "QPushButton:disabled{color: rgb(100, 100, 100); background-color: rgb(36, 36, 44);}");
    ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
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
                     "QPlainTextEdit {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 15px;}"
                     "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";
    finishedStyleSheet = "QMessageBox {background-color: rgb(6, 6, 14);}"
                         "QLabel {background-color: rgb(6, 6, 14); color: rgb(211, 213, 201); font-size: 16px;}"
                         "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}";

    uncheck();

    if (!isItemRemoved(ui->graphicsView_LeftHand->scene(), svgLeft)) {ui->graphicsView_LeftHand->scene()->removeItem(svgLeft);}
    if (!isItemRemoved(ui->graphicsView_RightHand->scene(), svgRight)) {ui->graphicsView_RightHand->scene()->removeItem(svgRight);}

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

    QPushButton* buttons[] = {
        ui->pushButton_Tilde, ui->pushButton_1, ui->pushButton_2, ui->pushButton_3, ui->pushButton_4,
        ui->pushButton_5, ui->pushButton_6, ui->pushButton_7, ui->pushButton_8, ui->pushButton_9,
        ui->pushButton_0, ui->pushButton_Minus, ui->pushButton_Equals, ui->pushButton_Backspace,
        ui->pushButton_TAB, ui->pushButton_Q, ui->pushButton_W, ui->pushButton_E, ui->pushButton_R,
        ui->pushButton_T, ui->pushButton_Y, ui->pushButton_U, ui->pushButton_I, ui->pushButton_O,
        ui->pushButton_P, ui->pushButton_LeftSquareBracket, ui->pushButton_RightSquareBracket,
        ui->pushButton_Backslash, ui->pushButton_CAPS, ui->pushButton_A, ui->pushButton_S,
        ui->pushButton_D, ui->pushButton_F, ui->pushButton_G, ui->pushButton_H, ui->pushButton_J,
        ui->pushButton_K, ui->pushButton_L, ui->pushButton_Semicolon, ui->pushButton_Apostrophe,
        ui->pushButton_Enter, ui->pushButton_LShift, ui->pushButton_Z, ui->pushButton_X,
        ui->pushButton_C, ui->pushButton_V, ui->pushButton_B, ui->pushButton_N, ui->pushButton_M,
        ui->pushButton_Comma, ui->pushButton_Period, ui->pushButton_Slash, ui->pushButton_RShift,
        ui->pushButton_LCtrl, ui->pushButton_Super, ui->pushButton_LAlt, ui->pushButton_Space,
        ui->pushButton_RAlt, ui->pushButton_Menu, ui->pushButton_RCtrl
    };

    QString keyValues[] = {
        keyMap.getTilde(), keyMap.getN1(), keyMap.getN2(), keyMap.getN3(), keyMap.getN4(),
        keyMap.getN5(), keyMap.getN6(), keyMap.getN7(), keyMap.getN8(), keyMap.getN9(),
        keyMap.getN0(), keyMap.getMinus(), keyMap.getEquals(), keyMap.getBackspace(),
        keyMap.getTAB(), keyMap.getQ(), keyMap.getW(), keyMap.getE(), keyMap.getR(),
        keyMap.getT(), keyMap.getY(), keyMap.getU(), keyMap.getI(), keyMap.getO(),
        keyMap.getP(), keyMap.getLeftSquareBracket(), keyMap.getRightSquareBracket(),
        keyMap.getBackslash(), keyMap.getCAPS(), keyMap.getA(), keyMap.getS(),
        keyMap.getD(), keyMap.getF(), keyMap.getG(), keyMap.getH(), keyMap.getJ(),
        keyMap.getK(), keyMap.getL(), keyMap.getSemicolon(), keyMap.getApostrophe(),
        keyMap.getEnter(), keyMap.getLShift(), keyMap.getZ(), keyMap.getX(),
        keyMap.getC(), keyMap.getV(), keyMap.getB(), keyMap.getN(), keyMap.getM(),
        keyMap.getComma(), keyMap.getPeriod(), keyMap.getSlash(), keyMap.getRShift(),
        keyMap.getLCtrl(), keyMap.getSuper(), keyMap.getLAlt(), keyMap.getSpace(),
        keyMap.getRAlt(), keyMap.getMenu(), keyMap.getRCtrl()
    };

    for (unsigned long long i = 0; i < sizeof(buttons) / sizeof(buttons[0]); ++i) {
        buttons[i]->setText(keyValues[i]);
    }
}

void MainWindow::changeFontSize(int size)
{
    QFont font("Noto Sans");
    font.setPixelSize(size);
    QFont otherFont("Inconsolata Extra Expanded");
    otherFont.setPointSize(size * 1.3409523809523809523809523809524);

    QPushButton* buttons[] = {
        ui->pushButton_0, ui->pushButton_Tilde, ui->pushButton_1, ui->pushButton_2, ui->pushButton_3,
        ui->pushButton_4, ui->pushButton_5, ui->pushButton_6, ui->pushButton_7, ui->pushButton_8,
        ui->pushButton_9, ui->pushButton_Minus, ui->pushButton_Equals, ui->pushButton_Q, ui->pushButton_W,
        ui->pushButton_E, ui->pushButton_R, ui->pushButton_T, ui->pushButton_Y, ui->pushButton_U,
        ui->pushButton_I, ui->pushButton_O, ui->pushButton_P, ui->pushButton_LeftSquareBracket, ui->pushButton_RightSquareBracket,
        ui->pushButton_Backslash, ui->pushButton_A, ui->pushButton_S, ui->pushButton_D, ui->pushButton_F,
        ui->pushButton_G, ui->pushButton_H, ui->pushButton_J, ui->pushButton_K, ui->pushButton_L,
        ui->pushButton_Semicolon, ui->pushButton_Apostrophe, ui->pushButton_Z, ui->pushButton_X, ui->pushButton_C,
        ui->pushButton_V, ui->pushButton_B, ui->pushButton_N, ui->pushButton_M, ui->pushButton_Comma,
        ui->pushButton_Period, ui->pushButton_Slash, ui->pushButton_Backspace, ui->pushButton_TAB, ui->pushButton_CAPS,
        ui->pushButton_Enter, ui->pushButton_LCtrl, ui->pushButton_RCtrl, ui->pushButton_LAlt, ui->pushButton_RAlt,
        ui->pushButton_Super, ui->pushButton_Menu, ui->pushButton_Space, ui->pushButton_LShift, ui->pushButton_RShift
    };

    for (QPushButton* button : buttons) {
        if (button == ui->pushButton_LShift || button == ui->pushButton_RShift) {
            button->setFont(otherFont);
        } else {
            button->setFont(font);
        }
    }

}
void MainWindow::resize()
{
    //988 //35
    //450 //32

    double width = this->size().width() / (988 / 35);
    double height = this->size().height() / (450 / 32);

    foreach (QObject *widget, ui->centralwidget->children()) {
        int skip = 0;
        QPushButton *button = qobject_cast<QPushButton *>(widget);
        if (button != nullptr) {
            if (button->text() == "Start course") {skip = 1;}
            if (skip == 0) {
                button->setMinimumSize(width, height);
                button->setMaximumSize(width, height);
            }
        }
    }

    changeFontSize((width + height) / 3.1904761904761904761904761904762);

    width = this->size().width() / (double(988) / 80);
    ui->pushButton_Backspace->setMaximumSize(width, height);
    ui->pushButton_Backspace->setMinimumSize(width, height);
    ui->pushButton_TAB->setMaximumSize(width, height);
    ui->pushButton_TAB->setMinimumSize(width, height);

    width = this->size().width() / (double(988) / 83);
    ui->pushButton_CAPS->setMaximumSize(width, height);
    ui->pushButton_CAPS->setMinimumSize(width, height);
    width = this->size().width() / (double(988) / 68);
    ui->pushButton_Enter->setMaximumSize(width, height);
    ui->pushButton_Enter->setMinimumSize(width, height);

    width = this->size().width() / (double(988) / 96);
    ui->pushButton_LShift->setMaximumSize(width, height);
    ui->pushButton_LShift->setMinimumSize(width, height);
    ui->pushButton_RShift->setMaximumSize(width, height);
    ui->pushButton_RShift->setMinimumSize(width, height);

    width = this->size().width() / (double(988) / 59);
    ui->pushButton_LCtrl->setMaximumSize(width, height);
    ui->pushButton_LCtrl->setMinimumSize(width, height);
    ui->pushButton_RCtrl->setMaximumSize(width, height);
    ui->pushButton_RCtrl->setMinimumSize(width, height);

    width = this->size().width() / (double(988) / 42);
    ui->pushButton_LAlt->setMaximumSize(width, height);
    ui->pushButton_LAlt->setMinimumSize(width, height);
    ui->pushButton_RAlt->setMaximumSize(width, height);
    ui->pushButton_RAlt->setMinimumSize(width, height);

    width = this->size().width() / (double(988) / 40);
    ui->pushButton_Super->setMaximumSize(width, height);
    ui->pushButton_Super->setMinimumSize(width, height);
    ui->pushButton_Menu->setMaximumSize(width, height);
    ui->pushButton_Menu->setMinimumSize(width, height);

    width = this->size().width() / (double(988) / 272);
    ui->pushButton_Space->setMaximumSize(width, height);
    ui->pushButton_Space->setMinimumSize(width, height);

    //180   //194
    width = this->size().width() / 5.4888888888888888888888888888889;
    height = this->size().height() / 2.5;
    ui->graphicsView_LeftHand->setMaximumSize(width, height);
    ui->graphicsView_LeftHand->setMinimumSize(width, height);
    ui->graphicsView_RightHand->setMaximumSize(width, height);
    ui->graphicsView_RightHand->setMinimumSize(width, height);

    QTimer timer;
    if (theme == "light") {
        timer.singleShot(0, this, [this]() {ui->graphicsView_LeftHand->fitInView(svgLeft, Qt::KeepAspectRatio);});
        timer.singleShot(0, this, [this]() {ui->graphicsView_RightHand->fitInView(svgLeft, Qt::KeepAspectRatio);});
    } else {
        timer.singleShot(0, this, [this]() {ui->graphicsView_LeftHand->fitInView(svgLeft, Qt::KeepAspectRatio);});
        timer.singleShot(0, this, [this]() {ui->graphicsView_RightHand->fitInView(svgLeft, Qt::KeepAspectRatio);});
    }

    width = this->size().width();
    height = this->size().height();
    if (width > 987 && height > 700) {
        int size = this->size().height() / 46.666666666666666666666666666667;
        height = this->size().height() / 20.588235294117647058823529411765;
        ui->lineEdit_TextInput->setMinimumHeight(height);
        ui->lineEdit_TextInput->setFont(QFont("Noto Sans", size, QFont::Normal));
        ui->lineEdit_TextInput->setText(ui->lineEdit_TextInput->text());

        ui->textEdit_Article->setFontPointSize(size);
        ui->textEdit_Article->setText(ui->textEdit_Article->toPlainText());
        if (align == 1) {ui->textEdit_Article->setAlignment(Qt::AlignCenter);}

        height = this->size().height() / 23.333333333333333333333333333333;
        ui->pushButton_StartCourse->setMinimumHeight(height);
        size = this->size().height() / 58.333333333333333333333333333333;
        ui->pushButton_StartCourse->setFont(QFont("Noto Sans", size, QFont::Normal));
    } else {
        ui->lineEdit_TextInput->setMinimumHeight(34);
        ui->lineEdit_TextInput->setFont(QFont("Noto Sans", 15, QFont::Normal));
        ui->lineEdit_TextInput->setText(ui->lineEdit_TextInput->text());

        ui->textEdit_Article->setFontPointSize(15);
        ui->textEdit_Article->setText(ui->textEdit_Article->toPlainText());
        if (align == 1) {ui->textEdit_Article->setAlignment(Qt::AlignCenter);}

        ui->pushButton_StartCourse->setMinimumHeight(30);
        ui->pushButton_StartCourse->setFont(QFont("Noto Sans", 12, QFont::Normal));
    }

//    qDebug() << "";
//    qDebug() << "first" << ui->firstLayer->sizeHint();
//    qDebug() << "second" << ui->secondLayer->sizeHint();
//    qDebug() << "third" << ui->thirdLayer->sizeHint();
//    qDebug() << "fourth" << ui->fourthLayer->sizeHint();
//    qDebug() << "fifth" << ui->fifthLayer->sizeHint();

//    qDebug() << "";
//    qDebug() << "normal" << ui->pushButton_3->size();
//    qDebug() << "tab" << ui->pushButton_CAPS->size();

//    {
//    qDebug() << "";
//    QList<QPushButton *> pushButtons;
//    for (int i = 0; i < ui->firstLayer->count(); ++i) {
//        QWidget *widget = ui->firstLayer->itemAt(i)->widget();
//        QPushButton *pushButton = qobject_cast<QPushButton *>(widget);
//        pushButtons.append(pushButton);
//    }
//    double size = 0;
//    for (QPushButton *pushButton : pushButtons) {
//        size += pushButton->width();
//    }
//    qDebug() << "first" << size - (14 * 4);

//    pushButtons.clear();
//    for (int i = 0; i < ui->secondLayer->count(); ++i) {
//        QWidget *widget = ui->secondLayer->itemAt(i)->widget();
//        QPushButton *pushButton = qobject_cast<QPushButton *>(widget);
//        pushButtons.append(pushButton);
//    }
//    size = 0;
//    for (QPushButton *pushButton : pushButtons) {
//        size += pushButton->width();
//    }
//    qDebug() << "second" << size - (14 * 4);

//    pushButtons.clear();
//    for (int i = 0; i < ui->thirdLayer->count(); ++i) {
//        QWidget *widget = ui->thirdLayer->itemAt(i)->widget();
//        QPushButton *pushButton = qobject_cast<QPushButton *>(widget);
//        pushButtons.append(pushButton);
//    }
//    size = 0;
//    for (QPushButton *pushButton : pushButtons) {
//        size += pushButton->width();
//    }
//    qDebug() << "third" << size - (13 * 4);

//    pushButtons.clear();
//    for (int i = 0; i < ui->fourthLayer->count(); ++i) {
//        QWidget *widget = ui->fourthLayer->itemAt(i)->widget();
//        QPushButton *pushButton = qobject_cast<QPushButton *>(widget);
//        pushButtons.append(pushButton);
//    }
//    size = 0;
//    for (QPushButton *pushButton : pushButtons) {
//        size += pushButton->width();
//    }
//    qDebug() << "fourth" << size - (12 * 4);

//    pushButtons.clear();
//    for (int i = 0; i < ui->fifthLayer->count(); ++i) {
//        QWidget *widget = ui->fifthLayer->itemAt(i)->widget();
//        QPushButton *pushButton = qobject_cast<QPushButton *>(widget);
//        pushButtons.append(pushButton);
//    }
//    size = 0;
//    for (QPushButton *pushButton : pushButtons) {
//        size += pushButton->width();
//    }
//    qDebug() << "fifth" << size - (7 * 4);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleNewlines()
{
    while (article.front() == "\n") {
        article = article.remove(0, 1);
        ui->lineEdit_TextInput->setText("");
        if (article == "\n" || article.isEmpty()) {break;}
        if (article.front() != "\n") {
            article = " " + article;
        }
    }
}
void MainWindow::on_lineEdit_TextInput_textChanged(const QString &arg1)
{

    QString word = arg1;
    QString lastCharacter = arg1.back();
    QString articleIn = article;
    articleIn = articleIn.front();
    stopTwice = 0;

    if (missStop == 0) {
        uncheck();
        if (lastCharacter == " ") {
            ui->lineEdit_TextInput->setText("");
            word = "";
        }

        if (lastCharacter == articleIn) {
            missStop = 0;
            align = 0;
            saveLast = "";

            if (lastCharacter == " ") {
                article = article.remove(0, 1);
            } else {
                article.remove(0, 1);
            }

            handleNewlines();

            ui->textEdit_Article->setText(article);

            if (theme == "light") {
                ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white;");
            } else {
                ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
            }

            findChar();
        } else {
            if (arg1.isEmpty()) {return;}
            if (arg1.count() < saveLast.count()) {
                QString removed = QString(saveLast.back());
                article = removed + article;
                ui->textEdit_Article->setText(article);
                saveLast.chop(1); ui->lineEdit_TextInput->setText(saveLast);

                misses += 1;
                missStop = 2;
                ui->lineEdit_TextInput->setStyleSheet("background-color: red;");

                text = arg1;
                textM = arg1;
                textM.chop(1);

                uncheck();
                findChar();
                return;
            }
            if (arg1.count() == saveLast.count()) {findChar(); return;}

            misses += 1;
            missStop = 1;
            ui->lineEdit_TextInput->setStyleSheet("background-color: red;");

            ui->pushButton_Backspace->setChecked(true);
            ui->graphicsView_RightHand->scene()->addItem(rHFive);

            text = arg1;
            textM = arg1;
            textM.chop(1);
        }

        if (article.isEmpty()) {
            getInfo.stopRunning();
            ui->lineEdit_TextInput->setReadOnly(true);
            ui->menuCourses->setEnabled(true);
            ui->action_MakeCustomCourse->setEnabled(true);

            ui->lineEdit_TextInput->setText("");
            word = "";
            lastCharacter = "";
            articleIn = "";

            ui->statusbar->showMessage("");
            article = "Please select a course!";
            ui->textEdit_Article->setText(article);
            ui->textEdit_Article->setAlignment(Qt::AlignCenter);
            align = 1;

            selectCheck = 1;

            QMessageBox finished;
            finished.setStyleSheet(finishedStyleSheet);
            finished.setWindowTitle("Course finished!");

            QString text = "You've finished the course!\n" + getInfo.getTime() + "\nMisses: " + QString::number(misses);
            finished.setText(text);
            if (stopTwice == 0) {
                if (isItemRemoved(ui->graphicsView_RightHand->scene(), rHOne)) {ui->graphicsView_RightHand->scene()->addItem(rHOne);}
                if (isItemRemoved(ui->graphicsView_RightHand->scene(), rHTwo)) {ui->graphicsView_RightHand->scene()->addItem(rHTwo);}
                if (isItemRemoved(ui->graphicsView_RightHand->scene(), rHThree)) {ui->graphicsView_RightHand->scene()->addItem(rHThree);}
                if (isItemRemoved(ui->graphicsView_RightHand->scene(), rHFour)) {ui->graphicsView_RightHand->scene()->addItem(rHFour);}
                if (isItemRemoved(ui->graphicsView_RightHand->scene(), rHFive)) {ui->graphicsView_RightHand->scene()->addItem(rHFive);}
                if (isItemRemoved(ui->graphicsView_LeftHand->scene(), lHOne)) {ui->graphicsView_LeftHand->scene()->addItem(lHOne);}
                if (isItemRemoved(ui->graphicsView_LeftHand->scene(), lHTwo)) {ui->graphicsView_LeftHand->scene()->addItem(lHTwo);}
                if (isItemRemoved(ui->graphicsView_LeftHand->scene(), lHThree)) {ui->graphicsView_LeftHand->scene()->addItem(lHThree);}
                if (isItemRemoved(ui->graphicsView_LeftHand->scene(), lHFour)) {ui->graphicsView_LeftHand->scene()->addItem(lHFour);}
                if (isItemRemoved(ui->graphicsView_LeftHand->scene(), lHFive)) {ui->graphicsView_LeftHand->scene()->addItem(lHFive);}

                finished.exec();

                misses = 0;
                stopTwice = 1;
            }
        }
    } else if (missStop == 1) {
        int currC = arg1.count();

        if (currC > text.count()) {ui->lineEdit_TextInput->setText(arg1.chopped(1)); return;}
        if (currC < text.count()) {
            ui->lineEdit_TextInput->setText(textM);

            uncheck();
            findChar();

            return;
        }
        if (currC == text.count()) {
            if (lastCharacter != articleIn) {return;}
            missStop = 0;
            article.remove(0, 1);
            handleNewlines();
            ui->textEdit_Article->setText(article);

            uncheck();
            findChar();

            if (theme == "light") {
                ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white;");
            } else {
                ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
            }
        }
    } else if (missStop == 2) {
        int currC = arg1.count();
        if (currC < text.count()) {ui->lineEdit_TextInput->setText(text); return;}
        if (currC > text.count()) {
            if (lastCharacter != articleIn) {ui->lineEdit_TextInput->setText(text); return;}
            missStop = 0;
            article.remove(0, 1);
            handleNewlines();
            ui->textEdit_Article->setText(article);

            uncheck();
            findChar();

            if (theme == "light") {
                ui->lineEdit_TextInput->setStyleSheet("color: black; background-color: white;");
            } else {
                ui->lineEdit_TextInput->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
            }
            return;
        }
    }

    if (stopTwice == 1) {ui->textEdit_Article->setAlignment(Qt::AlignCenter);}

    saveLast = arg1;
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
        text = getCustomText.textValue().simplified();

        if (text == "") {
            QMessageBox empty;
            empty.setStyleSheet(finishedStyleSheet);
            empty.setWindowTitle("Empty");
            empty.setText("Warning! You didn't enter anything!");
            empty.exec();
        } else {
            uncheck();

            article = text;
            ui->textEdit_Article->setText(article);
            ui->pushButton_StartCourse->setEnabled(true);

            align = 0;

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

    uncheck();
    findChar();

    align = 0;
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
        article = cArticle;
        ui->textEdit_Article->setText(article);

        align = 0;

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
    resize();
}

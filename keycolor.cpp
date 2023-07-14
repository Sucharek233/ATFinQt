#include "keycolor.h"
#include "ui_keycolor.h"

bool Toggled;

QString QColSS;

keyColor::keyColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyColor)
{
    ui->setupUi(this);

    updateCols();
    lightCol();
}

void keyColor::updateCols()
{
    QFile *load = new QFile(colorSlots.getPath());
    load->open(QIODevice::ReadOnly);
    QTextStream reading(load);
    reading.readLine();
    firstCol = reading.readLine();
    firstBor = reading.readLine();
    firstTog = reading.readLine();

    secondCol = reading.readLine();
    secondBor = reading.readLine();
    secondTog = reading.readLine();

    thirdCol = reading.readLine();
    thirdBor = reading.readLine();
    thirdTog = reading.readLine();

    fourthCol = reading.readLine();
    fourthBor = reading.readLine();
    fourthTog = reading.readLine();

    fifthCol = reading.readLine();
    fifthBor = reading.readLine();
    fifthTog = reading.readLine();

    sixthCol = reading.readLine();
    sixthBor = reading.readLine();
    sixthTog = reading.readLine();

    textColor = reading.readLine();

    load->close();

    ui->toolButton_Col1->setStyleSheet("background-color: " + firstCol + "; border-radius: 10px;");
    ui->toolButton_Col2->setStyleSheet("background-color: " + secondCol + "; border-radius: 10px;");
    ui->toolButton_Col3->setStyleSheet("background-color: " + thirdCol + "; border-radius: 10px;");
    ui->toolButton_Col4->setStyleSheet("background-color: " + fourthCol + "; border-radius: 10px;");
    ui->toolButton_Col5->setStyleSheet("background-color: " + fifthCol + "; border-radius: 10px;");
    ui->toolButton_Col6->setStyleSheet("background-color: " + sixthCol + "; border-radius: 10px;");

    ui->toolButton_Bor1->setStyleSheet("background-color: " + firstBor + "; border-radius: 10px;");
    ui->toolButton_Bor2->setStyleSheet("background-color: " + secondBor + "; border-radius: 10px;");
    ui->toolButton_Bor3->setStyleSheet("background-color: " + thirdBor + "; border-radius: 10px;");
    ui->toolButton_Bor4->setStyleSheet("background-color: " + fourthBor + "; border-radius: 10px;");
    ui->toolButton_Bor5->setStyleSheet("background-color: " + fifthBor + "; border-radius: 10px;");
    ui->toolButton_Bor6->setStyleSheet("background-color: " + sixthBor + "; border-radius: 10px;");

    ui->toolButton_Tog1->setStyleSheet("background-color: " + firstTog + "; border-radius: 10px;");
    ui->toolButton_Tog2->setStyleSheet("background-color: " + secondTog + "; border-radius: 10px;");
    ui->toolButton_Tog3->setStyleSheet("background-color: " + thirdTog + "; border-radius: 10px;");
    ui->toolButton_Tog4->setStyleSheet("background-color: " + fourthTog + "; border-radius: 10px;");
    ui->toolButton_Tog5->setStyleSheet("background-color: " + fifthTog + "; border-radius: 10px;");
    ui->toolButton_Tog6->setStyleSheet("background-color: " + sixthTog + "; border-radius: 10px;");

    ui->prev1->setStyleSheet("color: " + textColor + "; background-color: " + firstCol + "; border: 3px solid " + firstBor + "; border-radius: 10px;");
    ui->prev2->setStyleSheet("color: " + textColor + "; background-color: " + secondCol + "; border: 3px solid " + secondBor + "; border-radius: 10px;");
    ui->prev3->setStyleSheet("color: " + textColor + "; background-color: " + thirdCol + "; border: 3px solid " + thirdBor + "; border-radius: 10px;");
    ui->prev4->setStyleSheet("color: " + textColor + "; background-color: " + fourthCol + "; border: 3px solid " + fourthBor + "; border-radius: 10px;");
    ui->prev5->setStyleSheet("color: " + textColor + "; background-color: " + fifthCol + "; border: 3px solid " + fifthBor + "; border-radius: 10px;");
    ui->prev6->setStyleSheet("color: " + textColor + "; background-color: " + sixthCol + "; border: 3px solid " + sixthBor + "; border-radius: 10px;");

    if (Toggled == true) {
        ui->prev1->setStyleSheet("color: " + textColor + "; background-color: " + firstTog + "; border: 3px solid " + firstBor + "; border-radius: 10px;");
        ui->prev2->setStyleSheet("color: " + textColor + "; background-color: " + secondTog + "; border: 3px solid " + secondBor + "; border-radius: 10px;");
        ui->prev3->setStyleSheet("color: " + textColor + "; background-color: " + thirdTog + "; border: 3px solid " + thirdBor + "; border-radius: 10px;");
        ui->prev4->setStyleSheet("color: " + textColor + "; background-color: " + fourthTog + "; border: 3px solid " + fourthBor + "; border-radius: 10px;");
        ui->prev5->setStyleSheet("color: " + textColor + "; background-color: " + fifthTog + "; border: 3px solid " + fifthBor + "; border-radius: 10px;");
        ui->prev6->setStyleSheet("color: " + textColor + "; background-color: " + sixthTog + "; border: 3px solid " + sixthBor + "; border-radius: 10px;");
    }

    orange = "QPushButton {color: " + textColor + "; background-color: " + firstCol + "; border: 3px solid " + firstBor + "; border-radius:10px;}"
             "QPushButton:checked {color: " + textColor + "; background-color: " + firstTog + "; border-radius:10px;}";
    red = "QPushButton {color: " + textColor + "; background-color: " + secondCol + "; border: 3px solid " + secondBor + "; border-radius:10px;}"
          "QPushButton:checked {color: " + textColor + "; background-color: " + secondTog + "; border-radius:10px;}";
    green = "QPushButton {color: " + textColor + "; background-color: " + thirdCol + "; border: 3px solid " + thirdBor + "; border-radius:10px;}"
            "QPushButton:checked {color: " + textColor + "; background-color: " + thirdTog + "; border-radius:10px;}";
    blue = "QPushButton {color: " + textColor + "; background-color: " + fourthCol + "; border: 3px solid " + fourthBor + "; border-radius:10px;}"
           "QPushButton:checked {color: " + textColor + "; background-color: " + fourthTog + "; border-radius:10px;}";
    cyan = "QPushButton {color: " + textColor + "; background-color: " + fifthCol + "; border: 3px solid " + fifthBor + "; border-radius:10px;}"
            "QPushButton:checked {color: " + textColor + "; background-color: " + fifthTog + "; border-radius:10px;}";
    whiteish = "QPushButton {color: " + textColor + "; background-color: " + sixthCol + "; border: 3px solid " + sixthBor + "; border-radius:10px;}"
               "QPushButton:checked {color: " + textColor + "; background-color: " + sixthTog + "; border-radius:10px;}";

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
}

void keyColor::updateMapping(int shift)
{
    if (shift == 1) {
        //Layer 1
        ui->pushButton_Tilde->setText(tilde);
        ui->pushButton_1->setText(n1);
        ui->pushButton_2->setText(n2);
        ui->pushButton_3->setText(n3);
        ui->pushButton_4->setText(n4);
        ui->pushButton_5->setText(n5);
        ui->pushButton_6->setText(n6);
        ui->pushButton_7->setText(n7);
        ui->pushButton_8->setText(n8);
        ui->pushButton_9->setText(n9);
        ui->pushButton_0->setText(n0);
        ui->pushButton_Minus->setText(minus);
        ui->pushButton_Equals->setText(equals);
        ui->pushButton_Backspace->setText(backspace);
        //Layer 2
        ui->pushButton_TAB->setText(TAB);
        ui->pushButton_Q->setText(q);
        ui->pushButton_W->setText(w);
        ui->pushButton_E->setText(e);
        ui->pushButton_R->setText(r);
        ui->pushButton_T->setText(t);
        ui->pushButton_Y->setText(y);
        ui->pushButton_U->setText(u);
        ui->pushButton_I->setText(i);
        ui->pushButton_O->setText(o);
        ui->pushButton_P->setText(p);
        ui->pushButton_LeftSquareBracket->setText(leftSquareBracket);
        ui->pushButton_RightSquareBracket->setText(rightSquareBracket);
        ui->pushButton_Backslash->setText(backslash);
        //Layer 3
        ui->pushButton_CAPS->setText(CAPS);
        ui->pushButton_A->setText(a);
        ui->pushButton_S->setText(s);
        ui->pushButton_D->setText(d);
        ui->pushButton_F->setText(f);
        ui->pushButton_G->setText(g);
        ui->pushButton_H->setText(h);
        ui->pushButton_J->setText(j);
        ui->pushButton_K->setText(k);
        ui->pushButton_L->setText(l);
        ui->pushButton_Semicolon->setText(semicolon);
        ui->pushButton_Apostrophe->setText(apostrophe);
        ui->pushButton_Enter->setText(enter);
        //Layer 4
        ui->pushButton_LShift->setText(LShift);
        ui->pushButton_Z->setText(z);
        ui->pushButton_X->setText(x);
        ui->pushButton_C->setText(c);
        ui->pushButton_V->setText(v);
        ui->pushButton_B->setText(b);
        ui->pushButton_N->setText(n);
        ui->pushButton_M->setText(m);
        ui->pushButton_Comma->setText(comma);
        ui->pushButton_Period->setText(period);
        ui->pushButton_Slash->setText(slash);
        ui->pushButton_RShift->setText(RShift);
        //Layer 5
        ui->pushButton_LCtrl->setText(LCtrl);
        ui->pushButton_Super->setText(super);
        ui->pushButton_LAlt->setText(LAlt);
        ui->pushButton_Space->setText(space);
        ui->pushButton_RAlt->setText(RAlt);
        ui->pushButton_Menu->setText(menu);
        ui->pushButton_RCtrl->setText(RCtrl);
     } else {
        //Layer 1
        ui->pushButton_Tilde->setText(tildeS);
        ui->pushButton_1->setText(n1S);
        ui->pushButton_2->setText(n2S);
        ui->pushButton_3->setText(n3S);
        ui->pushButton_4->setText(n4S);
        ui->pushButton_5->setText(n5S);
        ui->pushButton_6->setText(n6S);
        ui->pushButton_7->setText(n7S);
        ui->pushButton_8->setText(n8S);
        ui->pushButton_9->setText(n9S);
        ui->pushButton_0->setText(n0S);
        ui->pushButton_Minus->setText(minusS);
        ui->pushButton_Equals->setText(equalsS);
        ui->pushButton_Backspace->setText(backspaceS);
        //Layer 2
        ui->pushButton_TAB->setText(TABS);
        ui->pushButton_Q->setText(qS);
        ui->pushButton_W->setText(wS);
        ui->pushButton_E->setText(eS);
        ui->pushButton_R->setText(rS);
        ui->pushButton_T->setText(tS);
        ui->pushButton_Y->setText(yS);
        ui->pushButton_U->setText(uS);
        ui->pushButton_I->setText(iS);
        ui->pushButton_O->setText(oS);
        ui->pushButton_P->setText(pS);
        ui->pushButton_LeftSquareBracket->setText(leftSquareBracketS);
        ui->pushButton_RightSquareBracket->setText(rightSquareBracketS);
        ui->pushButton_Backslash->setText(backslashS);
        //Layer 3
        ui->pushButton_CAPS->setText(CAPSS);
        ui->pushButton_A->setText(aS);
        ui->pushButton_S->setText(sS);
        ui->pushButton_D->setText(dS);
        ui->pushButton_F->setText(fS);
        ui->pushButton_G->setText(gS);
        ui->pushButton_H->setText(hS);
        ui->pushButton_J->setText(jS);
        ui->pushButton_K->setText(kS);
        ui->pushButton_L->setText(lS);
        ui->pushButton_Semicolon->setText(semicolonS);
        ui->pushButton_Apostrophe->setText(apostropheS);
        ui->pushButton_Enter->setText(enterS);
        //Layer 4
        ui->pushButton_LShift->setText(LShiftS);
        ui->pushButton_Z->setText(zS);
        ui->pushButton_X->setText(xS);
        ui->pushButton_C->setText(cS);
        ui->pushButton_V->setText(vS);
        ui->pushButton_B->setText(bS);
        ui->pushButton_N->setText(nS);
        ui->pushButton_M->setText(mS);
        ui->pushButton_Comma->setText(commaS);
        ui->pushButton_Period->setText(periodS);
        ui->pushButton_Slash->setText(slashS);
        ui->pushButton_RShift->setText(RShiftS);
        //Layer 5
        ui->pushButton_LCtrl->setText(LCtrlS);
        ui->pushButton_Super->setText(superS);
        ui->pushButton_LAlt->setText(LAltS);
        ui->pushButton_Space->setText(spaceS);
        ui->pushButton_RAlt->setText(RAltS);
        ui->pushButton_Menu->setText(menuS);
        ui->pushButton_RCtrl->setText(RCtrlS);
    }
}

void keyColor::lightCol()
{
    keyColor::setStyleSheet("background-color: rgb(244, 244, 244);");
    ui->pushButton_Toggled->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    ui->pushButton_TextCol->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    ui->pushButton_Reset->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    ui->pushButton_Slots->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}");
    QColSS = "QColorDialog {background-color: rgb(244, 244, 244);}"
             "QPushButton {background-color: rgb(244, 244, 244); color: black; font-size: 11px;}"
             "QLabel {background-color: rgb(244, 244, 244); color: black; font-size: 12px;}"
             "QLineEdit {background-color: white; color: black; font-size: 11px;}"
             "QSpinBox {background-color: white; color: black; font-size: 11px;}";
    colorSlots.lightColSlots();
}
void keyColor::darkCol()
{
    keyColor::setStyleSheet("background-color: rgb(6, 6, 14);");
    ui->pushButton_Toggled->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    ui->pushButton_TextCol->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    ui->pushButton_Reset->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    ui->pushButton_Slots->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}");
    QColSS = "QColorDialog {background-color: rgb(6, 6, 14);}"
             "QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 11px;}"
             "QLabel {color: rgb(211, 213, 201); background-color: rgb(6, 6, 14); font-size: 12px;}"
             "QLineEdit {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 11px;}"
             "QSpinBox {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 11px;}";
    colorSlots.darkColSlots();
}

void keyColor::unToggle()
{
    ui->pushButton_Toggled->setChecked(false);
    updateMapping(1);
}

void keyColor::changeFontSize(int size)
{
    QFont font("Arial");
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

keyColor::~keyColor()
{
    delete ui;
}

void keyColor::write(QString input, int line)
{
    int check = 0;
    QFile *write = new QFile(colorSlots.getPath());
    write->open(QIODevice::ReadOnly);
    QTextStream reading(write);
    for (int i = 0; i < 25; i++) {
        QString fileCheck = reading.readLine();
        if (fileCheck == input) {
            check = 1;
            break;
        } else {check = 0;}
    }
    write->close();
    if (check == 1) {
        QMessageBox dupe;
        dupe.setWindowTitle("Duplicate");
        dupe.setText("Warning! Duplicate color found!\nPlease select a different color!");
        dupe.exec();
    } else {
        QString replace;
        write->open(QIODevice::ReadWrite);
        for (int i = 0; i < line; i++) {
            replace = reading.readLine();
        }

        QFile *con = new QFile(colorSlots.getPath());
        con->open(QIODevice::ReadOnly);
        QTextStream read(con);
        QString contents = read.readAll();
        con->close();

        contents = contents.replace(replace, input);
        write->resize(0);
        write->write(contents.toUtf8());
        write->close();
    }
}

void keyColor::on_toolButton_Col1_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(firstCol);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color = pick.selectedColor().name();
        write(color.name(), 2);
        updateCols();
    }
}
void keyColor::on_toolButton_Bor1_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(firstBor);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 3);
        updateCols();
    }
}
void keyColor::on_toolButton_Tog1_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(firstTog);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 4);
        updateCols();
    }
}
void keyColor::on_toolButton_Col2_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(secondCol);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 5);
        updateCols();
    }
}
void keyColor::on_toolButton_Bor2_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(secondBor);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 6);
        updateCols();
    }
}
void keyColor::on_toolButton_Tog2_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(secondTog);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 7);
        updateCols();
    }
}
void keyColor::on_toolButton_Col3_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(thirdCol);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 8);
        updateCols();
    }
}
void keyColor::on_toolButton_Bor3_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(thirdBor);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 9);
        updateCols();
    }
}
void keyColor::on_toolButton_Tog3_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(thirdTog);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 10);
        updateCols();
    }
}
void keyColor::on_toolButton_Col4_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(fourthCol);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 11);
        updateCols();
    }
}
void keyColor::on_toolButton_Bor4_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(fourthBor);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 12);
        updateCols();
    }
}
void keyColor::on_toolButton_Tog4_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(fourthTog);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 13);
        updateCols();
    }
}
void keyColor::on_toolButton_Col5_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(fifthCol);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 14);
        updateCols();
    }
}
void keyColor::on_toolButton_Bor5_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(fifthBor);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 15);
        updateCols();
    }
}
void keyColor::on_toolButton_Tog5_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(fifthTog);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 16);
        updateCols();
    }
}
void keyColor::on_toolButton_Col6_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(sixthCol);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 17);
        updateCols();
    }
}
void keyColor::on_toolButton_Bor6_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(sixthBor);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 18);
        updateCols();
    }
}
void keyColor::on_toolButton_Tog6_clicked()
{
    QColorDialog pick;
    pick.setStyleSheet(QColSS); pick.setCurrentColor(sixthTog);
    if (pick.exec() == QColorDialog::Accepted) {
        QColor const color  = pick.selectedColor().name();
        write(color.name(), 19);
        updateCols();
    }
}
void keyColor::on_pushButton_Toggled_toggled(bool checked)
{
    Toggled = checked;

    if (Toggled == true) {
        ui->pushButton_Tilde->setChecked(true);
        ui->pushButton_1->setChecked(true);
        ui->pushButton_2->setChecked(true);
        ui->pushButton_3->setChecked(true);
        ui->pushButton_4->setChecked(true);
        ui->pushButton_5->setChecked(true);
        ui->pushButton_6->setChecked(true);
        ui->pushButton_7->setChecked(true);
        ui->pushButton_8->setChecked(true);
        ui->pushButton_9->setChecked(true);
        ui->pushButton_0->setChecked(true);
        ui->pushButton_Minus->setChecked(true);
        ui->pushButton_Equals->setChecked(true);
        ui->pushButton_Backspace->setChecked(true);
        ui->pushButton_TAB->setChecked(true);
        ui->pushButton_Q->setChecked(true);
        ui->pushButton_W->setChecked(true);
        ui->pushButton_E->setChecked(true);
        ui->pushButton_R->setChecked(true);
        ui->pushButton_T->setChecked(true);
        ui->pushButton_Y->setChecked(true);
        ui->pushButton_U->setChecked(true);
        ui->pushButton_I->setChecked(true);
        ui->pushButton_O->setChecked(true);
        ui->pushButton_P->setChecked(true);
        ui->pushButton_LeftSquareBracket->setChecked(true);
        ui->pushButton_RightSquareBracket->setChecked(true);
        ui->pushButton_Backslash->setChecked(true);
        ui->pushButton_CAPS->setChecked(true);
        ui->pushButton_A->setChecked(true);
        ui->pushButton_S->setChecked(true);
        ui->pushButton_D->setChecked(true);
        ui->pushButton_F->setChecked(true);
        ui->pushButton_G->setChecked(true);
        ui->pushButton_H->setChecked(true);
        ui->pushButton_J->setChecked(true);
        ui->pushButton_K->setChecked(true);
        ui->pushButton_L->setChecked(true);
        ui->pushButton_Semicolon->setChecked(true);
        ui->pushButton_Apostrophe->setChecked(true);
        ui->pushButton_Enter->setChecked(true);
        ui->pushButton_LShift->setChecked(true);
        ui->pushButton_Z->setChecked(true);
        ui->pushButton_X->setChecked(true);
        ui->pushButton_C->setChecked(true);
        ui->pushButton_V->setChecked(true);
        ui->pushButton_B->setChecked(true);
        ui->pushButton_N->setChecked(true);
        ui->pushButton_M->setChecked(true);
        ui->pushButton_Comma->setChecked(true);
        ui->pushButton_Period->setChecked(true);
        ui->pushButton_Slash->setChecked(true);
        ui->pushButton_RShift->setChecked(true);
        ui->pushButton_LCtrl->setChecked(true);
        ui->pushButton_Super->setChecked(true);
        ui->pushButton_LAlt->setChecked(true);
        ui->pushButton_Space->setChecked(true);
        ui->pushButton_RAlt->setChecked(true);
        ui->pushButton_Menu->setChecked(true);
        ui->pushButton_RCtrl->setChecked(true);

        updateCols();
        updateMapping(2);
    } else {
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

        updateCols();
        updateMapping(1);
    }
}

void keyColor::on_pushButton_Reset_clicked()
{
    QFile *reset = new QFile(colorSlots.getPath());
    reset->open(QIODevice::ReadWrite);
    QString keepName = reset->readLine();
    reset->resize(0);
    QString toWrite = keepName +
                      "#ffaa00\n"
                      "#af5a00\n"
                      "#cd7800\n"
                      "#ff0f0f\n"
                      "#960000\n"
                      "#780000\n"
                      "#14ff14\n"
                      "#00cd00\n"
                      "#009600\n"
                      "#3232ff\n"
                      "#0000cd\n"
                      "#0000af\n"
                      "#00ffff\n"
                      "#00cdcd\n"
                      "#00afaf\n"
                      "#bee6ff\n"
                      "#a0c8e1\n"
                      "#8cb4cd\n"
                      "#000000\n";
    reset->write(toWrite.toUtf8());
    reset->close();

    updateCols();
}

void keyColor::on_pushButton_TextCol_clicked()
{
    QColor color = QColorDialog::getColor(textColor);
    if (!color.isValid()) return;
    write(color.name(), 20);
    updateCols();
}

void keyColor::resizeEvent(QResizeEvent*)
{
    //612   //351
    double width = this->size().width() / 17.485714285714285714285714285714;
    double height = this->size().height() / 10.96875;
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
    ui->pushButton_Super->setMaximumSize(width, height);
    ui->pushButton_Super->setMinimumSize(width, height);
    ui->pushButton_Menu->setMaximumSize(width, height);
    ui->pushButton_Menu->setMinimumSize(width, height);

    width = this->size().width() / 8.7428571428571428571428571428571;
    ui->pushButton_Backspace->setMaximumSize(width, height);
    ui->pushButton_Backspace->setMinimumSize(width, height);
    ui->pushButton_TAB->setMaximumSize(width, height);
    ui->pushButton_TAB->setMinimumSize(width, height);

    width = this->size().width() / 7.4634146341463414634146341463415;
    ui->pushButton_CAPS->setMaximumSize(width, height);
    ui->pushButton_CAPS->setMinimumSize(width, height);

    width = this->size().width() / 9.8709677419354838709677419354839;
    ui->pushButton_Enter->setMaximumSize(width, height);
    ui->pushButton_Enter->setMinimumSize(width, height);

    width = this->size().width() / 6.6521739130434782608695652173913;
    ui->pushButton_LShift->setMaximumSize(width, height);
    ui->pushButton_LShift->setMinimumSize(width, height);
    ui->pushButton_RShift->setMaximumSize(width, height);
    ui->pushButton_RShift->setMinimumSize(width, height);

    width = this->size().width() / 10.372881355932203389830508474576;
    ui->pushButton_LCtrl->setMaximumSize(width, height);
    ui->pushButton_LCtrl->setMinimumSize(width, height);
    ui->pushButton_RCtrl->setMaximumSize(width, height);
    ui->pushButton_RCtrl->setMinimumSize(width, height);

    width = this->size().width() / 14.571428571428571428571428571429;
    ui->pushButton_LAlt->setMaximumSize(width, height);
    ui->pushButton_LAlt->setMinimumSize(width, height);
    ui->pushButton_RAlt->setMaximumSize(width, height);
    ui->pushButton_RAlt->setMinimumSize(width, height);

    width = this->size().width() / 2.1779359430604982206405693950178;
    ui->pushButton_Space->setMaximumSize(width, height);
    ui->pushButton_Space->setMinimumSize(width, height);

    changeFontSize(this->size().width() / 29.142857142857142857142857142857);
}

void keyColor::on_buttonBox_accepted()
{
    accept();
    close();
}

void keyColor::on_buttonBox_rejected()
{
    reject();
    close();
}

void keyColor::on_pushButton_Slots_clicked()
{
    colorSlots.setModal(true);
    colorSlots.initialize();
    if (colorSlots.exec() == QDialog::Accepted) {
        updateCols();
    }
}

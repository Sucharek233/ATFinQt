#include "keymapping.h"
#include "ui_keymapping.h"

bool toggled;

keyMapping::keyMapping(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyMapping)
{
    ui->setupUi(this);

    lightMap();
    updateKeys();
}

void keyMapping::lightMap()
{
    ui->pushButton_OnShift->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    ui->pushButton_Slots->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    ui->pushButton_Reset->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    keyMapping::setStyleSheet("background-color: rgb(244, 244, 244);");
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244); font-size: 14px;}");
    mapSlots.lightMapSlots();
}
void keyMapping::darkMap()
{
    ui->pushButton_OnShift->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    ui->pushButton_Slots->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    ui->pushButton_Reset->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    keyMapping::setStyleSheet("background-color: rgb(6, 6, 14);");
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44); font-size: 14px;}");
    mapSlots.darkMapSlots();
}

void keyMapping::updateColors()
{
    ui->lineEdit_Tilde->setStyleSheet(orange);
    ui->lineEdit_1->setStyleSheet(orange);
    ui->lineEdit_2->setStyleSheet(orange);
    ui->lineEdit_3->setStyleSheet(red);
    ui->lineEdit_4->setStyleSheet(green);
    ui->lineEdit_5->setStyleSheet(blue);
    ui->lineEdit_6->setStyleSheet(blue);
    ui->lineEdit_7->setStyleSheet(cyan);
    ui->lineEdit_8->setStyleSheet(cyan);
    ui->lineEdit_9->setStyleSheet(green);
    ui->lineEdit_0->setStyleSheet(red);
    ui->lineEdit_Minus->setStyleSheet(orange);
    ui->lineEdit_Equals->setStyleSheet(orange);
    ui->lineEdit_Backspace->setStyleSheet(orange);
    ui->lineEdit_TAB->setStyleSheet(orange);
    ui->lineEdit_Q->setStyleSheet(orange);
    ui->lineEdit_W->setStyleSheet(red);
    ui->lineEdit_E->setStyleSheet(green);
    ui->lineEdit_R->setStyleSheet(blue);
    ui->lineEdit_T->setStyleSheet(blue);
    ui->lineEdit_Y->setStyleSheet(cyan);
    ui->lineEdit_U->setStyleSheet(cyan);
    ui->lineEdit_I->setStyleSheet(green);
    ui->lineEdit_O->setStyleSheet(red);
    ui->lineEdit_P->setStyleSheet(orange);
    ui->lineEdit_leftSqureBracket->setStyleSheet(orange);
    ui->lineEdit_rightSquareBracket->setStyleSheet(orange);
    ui->lineEdit_Backslash->setStyleSheet(orange);
    ui->lineEdit_CAPS->setStyleSheet(orange);
    ui->lineEdit_A->setStyleSheet(orange);
    ui->lineEdit_S->setStyleSheet(red);
    ui->lineEdit_D->setStyleSheet(green);
    ui->lineEdit_F->setStyleSheet(blue);
    ui->lineEdit_G->setStyleSheet(blue);
    ui->lineEdit_H->setStyleSheet(cyan);
    ui->lineEdit_J->setStyleSheet(cyan);
    ui->lineEdit_K->setStyleSheet(green);
    ui->lineEdit_L->setStyleSheet(red);
    ui->lineEdit_Semicolon->setStyleSheet(orange);
    ui->lineEdit_Apostrophe->setStyleSheet(orange);
    ui->lineEdit_Enter->setStyleSheet(orange);
    ui->lineEdit_LShift->setStyleSheet(orange);
    ui->lineEdit_Z->setStyleSheet(orange);
    ui->lineEdit_X->setStyleSheet(red);
    ui->lineEdit_C->setStyleSheet(green);
    ui->lineEdit_V->setStyleSheet(blue);
    ui->lineEdit_B->setStyleSheet(blue);
    ui->lineEdit_N->setStyleSheet(cyan);
    ui->lineEdit_M->setStyleSheet(cyan);
    ui->lineEdit_Comma->setStyleSheet(green);
    ui->lineEdit_Period->setStyleSheet(red);
    ui->lineEdit_Slash->setStyleSheet(orange);
    ui->lineEdit_RShift->setStyleSheet(orange);
    ui->lineEdit_LCtrl->setStyleSheet(orange);
    ui->lineEdit_Super->setStyleSheet(whiteish);
    ui->lineEdit_LAlt->setStyleSheet(orange);
    ui->lineEdit_Space->setStyleSheet(whiteish);
    ui->lineEdit_RAlt->setStyleSheet(orange);
    ui->lineEdit_Menu->setStyleSheet(whiteish);
    ui->lineEdit_RCtrl->setStyleSheet(orange);
}
void keyMapping::updateKeys()
{
    QFile *load = new QFile(mapSlots.GetPath());
    load->open(QIODevice::ReadOnly);
    QTextStream reading(load);
    reading.setCodec("UTF-8");
    reading.readLine();

    tilde = reading.readLine(); ui->lineEdit_Tilde->setText(tilde);
    n1 = reading.readLine();    ui->lineEdit_1->setText(n1);
    n2 = reading.readLine();    ui->lineEdit_2->setText(n2);
    n3 = reading.readLine();    ui->lineEdit_3->setText(n3);
    n4 = reading.readLine();    ui->lineEdit_4->setText(n4);
    n5 = reading.readLine();    ui->lineEdit_5->setText(n5);
    n6 = reading.readLine();    ui->lineEdit_6->setText(n6);
    n7 = reading.readLine();    ui->lineEdit_7->setText(n7);
    n8 = reading.readLine();    ui->lineEdit_8->setText(n8);
    n9 = reading.readLine();    ui->lineEdit_9->setText(n9);
    n0 = reading.readLine();    ui->lineEdit_0->setText(n0);
    minus = reading.readLine(); ui->lineEdit_Minus->setText(minus);
    equals = reading.readLine();    ui->lineEdit_Equals->setText(equals);
    backspace = reading.readLine(); ui->lineEdit_Backspace->setText(backspace);
    TAB = reading.readLine();   ui->lineEdit_TAB->setText(TAB);
    q = reading.readLine(); ui->lineEdit_Q->setText(q);
    w = reading.readLine(); ui->lineEdit_W->setText(w);
    e = reading.readLine(); ui->lineEdit_E->setText(e);
    r = reading.readLine(); ui->lineEdit_R->setText(r);
    t = reading.readLine(); ui->lineEdit_T->setText(t);
    y = reading.readLine(); ui->lineEdit_Y->setText(y);
    u = reading.readLine(); ui->lineEdit_U->setText(u);
    i = reading.readLine(); ui->lineEdit_I->setText(i);
    o = reading.readLine(); ui->lineEdit_O->setText(o);
    p = reading.readLine(); ui->lineEdit_P->setText(p);
    leftSquareBracket = reading.readLine();     ui->lineEdit_leftSqureBracket->setText(leftSquareBracket);
    rightSquareBracket = reading.readLine();    ui->lineEdit_rightSquareBracket->setText(rightSquareBracket);
    backslash = reading.readLine(); ui->lineEdit_Backslash->setText(backslash);
    CAPS = reading.readLine();  ui->lineEdit_CAPS->setText(CAPS);
    a = reading.readLine(); ui->lineEdit_A->setText(a);
    s = reading.readLine(); ui->lineEdit_S->setText(s);
    d = reading.readLine(); ui->lineEdit_D->setText(d);
    f = reading.readLine(); ui->lineEdit_F->setText(f);
    g = reading.readLine(); ui->lineEdit_G->setText(g);
    h = reading.readLine(); ui->lineEdit_H->setText(h);
    j = reading.readLine(); ui->lineEdit_J->setText(j);
    k = reading.readLine(); ui->lineEdit_K->setText(k);
    l = reading.readLine(); ui->lineEdit_L->setText(l);
    semicolon = reading.readLine(); ui->lineEdit_Semicolon->setText(semicolon);
    apostrophe = reading.readLine();    ui->lineEdit_Apostrophe->setText(apostrophe);
    enter = reading.readLine(); ui->lineEdit_Enter->setText(enter);
    LShift = reading.readLine();    ui->lineEdit_LShift->setText(LShift);
    z = reading.readLine(); ui->lineEdit_Z->setText(z);
    x = reading.readLine(); ui->lineEdit_X->setText(x);
    c = reading.readLine(); ui->lineEdit_C->setText(c);
    v = reading.readLine(); ui->lineEdit_V->setText(v);
    b = reading.readLine(); ui->lineEdit_B->setText(b);
    n = reading.readLine(); ui->lineEdit_N->setText(n);
    m = reading.readLine(); ui->lineEdit_M->setText(m);
    comma = reading.readLine(); ui->lineEdit_Comma->setText(comma);
    period = reading.readLine();    ui->lineEdit_Period->setText(period);
    slash = reading.readLine(); ui->lineEdit_Slash->setText(slash);
    RShift = reading.readLine();    ui->lineEdit_RShift->setText(RShift);
    LCtrl = reading.readLine(); ui->lineEdit_LCtrl->setText(LCtrl);
    super = reading.readLine(); ui->lineEdit_Super->setText(super);
    LAlt = reading.readLine();  ui->lineEdit_LAlt->setText(LAlt);
    space = reading.readLine(); ui->lineEdit_Space->setText(space);
    RAlt = reading.readLine();  ui->lineEdit_RAlt->setText(RAlt);
    menu = reading.readLine();  ui->lineEdit_Menu->setText(menu);
    RCtrl = reading.readLine(); ui->lineEdit_RCtrl->setText(RCtrl);

    tildeS = reading.readLine();
    n1S = reading.readLine();
    n2S = reading.readLine();
    n3S = reading.readLine();
    n4S = reading.readLine();
    n5S = reading.readLine();
    n6S = reading.readLine();
    n7S = reading.readLine();
    n8S = reading.readLine();
    n9S = reading.readLine();
    n0S = reading.readLine();
    minusS = reading.readLine();
    equalsS = reading.readLine();
    backspaceS = reading.readLine();
    TABS = reading.readLine();
    qS = reading.readLine();
    wS = reading.readLine();
    eS = reading.readLine();
    rS = reading.readLine();
    tS = reading.readLine();
    yS = reading.readLine();
    uS = reading.readLine();
    iS = reading.readLine();
    oS = reading.readLine();
    pS = reading.readLine();
    leftSquareBracketS = reading.readLine();
    rightSquareBracketS = reading.readLine();
    backslashS = reading.readLine();
    CAPSS = reading.readLine();
    aS = reading.readLine();
    sS = reading.readLine();
    dS = reading.readLine();
    fS = reading.readLine();
    gS = reading.readLine();
    hS = reading.readLine();
    jS = reading.readLine();
    kS = reading.readLine();
    lS = reading.readLine();
    semicolonS = reading.readLine();
    apostropheS = reading.readLine();
    enterS = reading.readLine();
    LShiftS = reading.readLine();
    zS = reading.readLine();
    xS = reading.readLine();
    cS = reading.readLine();
    vS = reading.readLine();
    bS = reading.readLine();
    nS = reading.readLine();
    mS = reading.readLine();
    commaS = reading.readLine();
    periodS = reading.readLine();
    slashS = reading.readLine();
    RShiftS = reading.readLine();
    LCtrlS = reading.readLine();
    superS = reading.readLine();
    LAltS = reading.readLine();
    spaceS = reading.readLine();
    RAltS = reading.readLine();
    menuS = reading.readLine();
    RCtrlS = reading.readLine();

    load->close();
}

void keyMapping::Write()
{
    QFile *write = new QFile(mapSlots.GetPath());
    write->open(QIODevice::ReadOnly);
    QTextStream read(write);
    read.setCodec("UTF-8");
    QString name = read.readLine();
    write->close();
    QString toWrite = name+"\n"+tilde+"\n"+n1+"\n"+n2+"\n"+n3+"\n"+n4+"\n"+n5+"\n"+n6+"\n"+n7+"\n"+n8+"\n"+n9+"\n"+n0+"\n"+minus+"\n"+equals+"\n"+backspace+"\n"+
                      TAB+"\n"+q+"\n"+w+"\n"+e+"\n"+r+"\n"+t+"\n"+y+"\n"+u+"\n"+i+"\n"+o+"\n"+p+"\n"+leftSquareBracket+"\n"+rightSquareBracket+"\n"+backslash+"\n"+
                      CAPS+"\n"+a+"\n"+s+"\n"+d+"\n"+f+"\n"+g+"\n"+h+"\n"+j+"\n"+k+"\n"+l+"\n"+semicolon+"\n"+apostrophe+"\n"+enter+"\n"+
                      LShift+"\n"+z+"\n"+x+"\n"+c+"\n"+v+"\n"+b+"\n"+n+"\n"+m+"\n"+comma+"\n"+period+"\n"+slash+"\n"+RShift+"\n"+
                      LCtrl+"\n"+super+"\n"+LAlt+"\n"+space+"\n"+RAlt+"\n"+menu+"\n"+RCtrl+"\n"+

                      tildeS+"\n"+n1S+"\n"+n2S+"\n"+n3S+"\n"+n4S+"\n"+n5S+"\n"+n6S+"\n"+n7S+"\n"+n8S+"\n"+n9S+"\n"+n0S+"\n"+minusS+"\n"+equalsS+"\n"+backspaceS+"\n"+
                      TABS+"\n"+qS+"\n"+wS+"\n"+eS+"\n"+rS+"\n"+tS+"\n"+yS+"\n"+uS+"\n"+iS+"\n"+oS+"\n"+pS+"\n"+leftSquareBracketS+"\n"+rightSquareBracketS+"\n"+backslashS+"\n"+
                      CAPSS+"\n"+aS+"\n"+sS+"\n"+dS+"\n"+fS+"\n"+gS+"\n"+hS+"\n"+jS+"\n"+kS+"\n"+lS+"\n"+semicolonS+"\n"+apostropheS+"\n"+enterS+"\n"+
                      LShiftS+"\n"+zS+"\n"+xS+"\n"+cS+"\n"+vS+"\n"+bS+"\n"+nS+"\n"+mS+"\n"+commaS+"\n"+periodS+"\n"+slashS+"\n"+RShiftS+"\n"+
                      LCtrlS+"\n"+superS+"\n"+LAltS+"\n"+spaceS+"\n"+RAltS+"\n"+menuS+"\n"+RCtrlS;
    write->open(QIODevice::ReadWrite);
    write->resize(0);
    write->write(toWrite.toUtf8());
    write->close();
}

keyMapping::~keyMapping()
{
    delete ui;
}

void keyMapping::changeFontSize(int size)
{
    QFont font("Arial");
    font.setPixelSize(size);
    ui->lineEdit_0->setFont(font);
    ui->lineEdit_Tilde->setFont(font);
    ui->lineEdit_0->setFont(font);
    ui->lineEdit_1->setFont(font);
    ui->lineEdit_2->setFont(font);
    ui->lineEdit_3->setFont(font);
    ui->lineEdit_4->setFont(font);
    ui->lineEdit_5->setFont(font);
    ui->lineEdit_6->setFont(font);
    ui->lineEdit_7->setFont(font);
    ui->lineEdit_8->setFont(font);
    ui->lineEdit_9->setFont(font);
    ui->lineEdit_Minus->setFont(font);
    ui->lineEdit_Equals->setFont(font);
    ui->lineEdit_Q->setFont(font);
    ui->lineEdit_W->setFont(font);
    ui->lineEdit_E->setFont(font);
    ui->lineEdit_E->setFont(font);
    ui->lineEdit_R->setFont(font);
    ui->lineEdit_T->setFont(font);
    ui->lineEdit_Y->setFont(font);
    ui->lineEdit_U->setFont(font);
    ui->lineEdit_I->setFont(font);
    ui->lineEdit_O->setFont(font);
    ui->lineEdit_P->setFont(font);
    ui->lineEdit_leftSqureBracket->setFont(font);
    ui->lineEdit_rightSquareBracket->setFont(font);
    ui->lineEdit_Backslash->setFont(font);
    ui->lineEdit_A->setFont(font);
    ui->lineEdit_S->setFont(font);
    ui->lineEdit_D->setFont(font);
    ui->lineEdit_F->setFont(font);
    ui->lineEdit_G->setFont(font);
    ui->lineEdit_H->setFont(font);
    ui->lineEdit_J->setFont(font);
    ui->lineEdit_K->setFont(font);
    ui->lineEdit_L->setFont(font);
    ui->lineEdit_Semicolon->setFont(font);
    ui->lineEdit_Apostrophe->setFont(font);
    ui->lineEdit_Z->setFont(font);
    ui->lineEdit_X->setFont(font);
    ui->lineEdit_C->setFont(font);
    ui->lineEdit_V->setFont(font);
    ui->lineEdit_B->setFont(font);
    ui->lineEdit_N->setFont(font);
    ui->lineEdit_M->setFont(font);
    ui->lineEdit_Comma->setFont(font);
    ui->lineEdit_Period->setFont(font);
    ui->lineEdit_Slash->setFont(font);
    ui->lineEdit_Backspace->setFont(font);
    ui->lineEdit_TAB->setFont(font);
    ui->lineEdit_CAPS->setFont(font);
    ui->lineEdit_Enter->setFont(font);
    ui->lineEdit_LCtrl->setFont(font);
    ui->lineEdit_RCtrl->setFont(font);
    ui->lineEdit_LAlt->setFont(font);
    ui->lineEdit_RAlt->setFont(font);
    ui->lineEdit_Super->setFont(font);
    ui->lineEdit_Menu->setFont(font);
    ui->lineEdit_Space->setFont(font);
    QFont otherFont("Inconsolata Extra Expanded");
    otherFont.setPointSize(size * 1.3409523809523809523809523809524);
    ui->lineEdit_LShift->setFont(otherFont);
    ui->lineEdit_RShift->setFont(otherFont);
}

void keyMapping::on_lineEdit_Tilde_textChanged(const QString &arg1)
{
    if (toggled == true) {
        tildeS = arg1;
    } else {
        tilde = arg1;
    }
}

void keyMapping::on_lineEdit_1_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n1S = arg1;
    } else {
        n1 = arg1;
    }
}

void keyMapping::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n2S = arg1;
    } else {
        n2 = arg1;
    }
}

void keyMapping::on_lineEdit_3_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n3S = arg1;
    } else {
        n3 = arg1;
    }
}

void keyMapping::on_lineEdit_4_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n4S = arg1;
    } else {
        n4 = arg1;
    }
}

void keyMapping::on_lineEdit_5_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n5S = arg1;
    } else {
        n5 = arg1;
    }
}

void keyMapping::on_lineEdit_6_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n6S = arg1;
    } else {
        n6 = arg1;
    }
}

void keyMapping::on_lineEdit_7_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n7S = arg1;
    } else {
        n7 = arg1;
    }
}

void keyMapping::on_lineEdit_8_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n8S = arg1;
    } else {
        n8 = arg1;
    }
}

void keyMapping::on_lineEdit_9_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n9S = arg1;
    } else {
        n9 = arg1;
    }
}

void keyMapping::on_lineEdit_0_textChanged(const QString &arg1)
{
    if (toggled == true) {
        n0S = arg1;
    } else {
        n0 = arg1;
    }
}

void keyMapping::on_lineEdit_Minus_textChanged(const QString &arg1)
{
    if (toggled == true) {
        minusS = arg1;
    } else {
        minus = arg1;
    }
}

void keyMapping::on_lineEdit_Equals_textChanged(const QString &arg1)
{
    if (toggled == true) {
        equalsS = arg1;
    } else {
        equals = arg1;
    }
}

void keyMapping::on_lineEdit_Backspace_textChanged(const QString &arg1)
{
    backspace = arg1;
    if (toggled == true) {
    } else {
    }
}

void keyMapping::on_lineEdit_TAB_textChanged(const QString &arg1)
{
    if (toggled == true) {
        TABS = arg1;
    } else {
        TAB = arg1;
    }
}

void keyMapping::on_lineEdit_Q_textChanged(const QString &arg1)
{
    if (toggled == true) {
        qS = arg1;
    } else {
        q = arg1;
    }
}

void keyMapping::on_lineEdit_W_textChanged(const QString &arg1)
{
    if (toggled == true) {
        wS = arg1;
    } else {
        w = arg1;
    }
}

void keyMapping::on_lineEdit_E_textChanged(const QString &arg1)
{
    if (toggled == true) {
        eS = arg1;
    } else {
        e = arg1;
    }
}

void keyMapping::on_lineEdit_R_textChanged(const QString &arg1)
{
    if (toggled == true) {
        rS = arg1;
    } else {
        r = arg1;
    }
}

void keyMapping::on_lineEdit_T_textChanged(const QString &arg1)
{
    if (toggled == true) {
        tS = arg1;
    } else {
        t = arg1;
    }
}

void keyMapping::on_lineEdit_Y_textChanged(const QString &arg1)
{
    if (toggled == true) {
        yS = arg1;
    } else {
        y = arg1;
    }
}

void keyMapping::on_lineEdit_U_textChanged(const QString &arg1)
{
    if (toggled == true) {
        uS = arg1;
    } else {
        u = arg1;
    }
}

void keyMapping::on_lineEdit_I_textChanged(const QString &arg1)
{
    if (toggled == true) {
        iS = arg1;
    } else {
        i = arg1;
    }
}

void keyMapping::on_lineEdit_O_textChanged(const QString &arg1)
{
    if (toggled == true) {
        oS = arg1;
    } else {
        o = arg1;
    }
}

void keyMapping::on_lineEdit_P_textChanged(const QString &arg1)
{
    if (toggled == true) {
        pS = arg1;
    } else {
        p = arg1;
    }
}

void keyMapping::on_lineEdit_leftSqureBracket_textChanged(const QString &arg1)
{
    if (toggled == true) {
        leftSquareBracketS = arg1;
    } else {
        leftSquareBracket = arg1;
    }
}

void keyMapping::on_lineEdit_rightSquareBracket_textChanged(const QString &arg1)
{
    if (toggled == true) {
        rightSquareBracketS = arg1;
    } else {
        rightSquareBracket = arg1;
    }
}

void keyMapping::on_lineEdit_Backslash_textChanged(const QString &arg1)
{
    if (toggled == true) {
        backslashS = arg1;
    } else {
        backslash = arg1;
    }
}

void keyMapping::on_lineEdit_CAPS_textChanged(const QString &arg1)
{
    if (toggled == true) {
        CAPSS = arg1;
    } else {
        CAPS = arg1;
    }
}

void keyMapping::on_lineEdit_A_textChanged(const QString &arg1)
{
    if (toggled == true) {
        aS = arg1;
    } else {
        a = arg1;
    }
}

void keyMapping::on_lineEdit_S_textChanged(const QString &arg1)
{
    if (toggled == true) {
        sS = arg1;
    } else {
        s = arg1;
    }
}

void keyMapping::on_lineEdit_D_textChanged(const QString &arg1)
{
    if (toggled == true) {
        dS = arg1;
    } else {
        d = arg1;
    }
}

void keyMapping::on_lineEdit_F_textChanged(const QString &arg1)
{
    if (toggled == true) {
        fS = arg1;
    } else {
        f = arg1;
    }
}

void keyMapping::on_lineEdit_G_textChanged(const QString &arg1)
{
    if (toggled == true) {
        gS = arg1;
    } else {
        g = arg1;
    }
}

void keyMapping::on_lineEdit_H_textChanged(const QString &arg1)
{
    if (toggled == true) {
        hS = arg1;
    } else {
        h = arg1;
    }
}

void keyMapping::on_lineEdit_J_textChanged(const QString &arg1)
{
    if (toggled == true) {
        jS = arg1;
    } else {
        j = arg1;
    }
}

void keyMapping::on_lineEdit_K_textChanged(const QString &arg1)
{
    if (toggled == true) {
        kS = arg1;
    } else {
        k = arg1;
    }
}

void keyMapping::on_lineEdit_L_textChanged(const QString &arg1)
{
    if (toggled == true) {
        lS = arg1;
    } else {
        l = arg1;
    }
}

void keyMapping::on_lineEdit_Semicolon_textChanged(const QString &arg1)
{
    if (toggled == true) {
        semicolonS = arg1;
    } else {
        semicolon = arg1;
    }
}

void keyMapping::on_lineEdit_Apostrophe_textChanged(const QString &arg1)
{
    if (toggled == true) {
        apostropheS = arg1;
    } else {
        apostrophe = arg1;
    }
}

void keyMapping::on_lineEdit_Enter_textChanged(const QString &arg1)
{
    if (toggled == true) {
        enterS = arg1;
    } else {
        enter = arg1;
    }
}

void keyMapping::on_lineEdit_LShift_textChanged(const QString &arg1)
{
    if (toggled == true) {
        LShiftS = arg1;
    } else {
        LShift = arg1;
    }
}

void keyMapping::on_lineEdit_Z_textChanged(const QString &arg1)
{
    if (toggled == true) {
        zS = arg1;
    } else {
        z = arg1;
    }
}

void keyMapping::on_lineEdit_X_textChanged(const QString &arg1)
{
    if (toggled == true) {
        xS = arg1;
    } else {
        x = arg1;
    }
}


void keyMapping::on_lineEdit_C_textChanged(const QString &arg1)
{
    if (toggled == true) {
        cS = arg1;
    } else {
        c = arg1;
    }
}

void keyMapping::on_lineEdit_V_textChanged(const QString &arg1)
{
    if (toggled == true) {
        vS = arg1;
    } else {
        v = arg1;
    }
}

void keyMapping::on_lineEdit_B_textChanged(const QString &arg1)
{
    if (toggled == true) {
        bS = arg1;
    } else {
        b = arg1;
    }
}

void keyMapping::on_lineEdit_N_textChanged(const QString &arg1)
{
    if (toggled == true) {
        nS = arg1;
    } else {
        n = arg1;
    }
}

void keyMapping::on_lineEdit_M_textChanged(const QString &arg1)
{
    if (toggled == true) {
        mS = arg1;
    } else {
        m = arg1;
    }
}

void keyMapping::on_lineEdit_Comma_textChanged(const QString &arg1)
{
    if (toggled == true) {
        commaS = arg1;
    } else {
        comma = arg1;
    }
}

void keyMapping::on_lineEdit_Period_textChanged(const QString &arg1)
{
    if (toggled == true) {
        periodS = arg1;
    } else {
        period = arg1;
    }
}

void keyMapping::on_lineEdit_Slash_textChanged(const QString &arg1)
{
    if (toggled == true) {
        slashS = arg1;
    } else {
        slash = arg1;
    }
}

void keyMapping::on_lineEdit_RShift_textChanged(const QString &arg1)
{
    if (toggled == true) {
        RShiftS = arg1;
    } else {
        RShift = arg1;
    }
}

void keyMapping::on_lineEdit_LCtrl_textChanged(const QString &arg1)
{
    if (toggled == true) {
        LCtrlS = arg1;
    } else {
        LCtrl = arg1;
    }
}

void keyMapping::on_lineEdit_Super_textChanged(const QString &arg1)
{
    if (toggled == true) {
        superS = arg1;
    } else {
        super = arg1;
    }
}

void keyMapping::on_lineEdit_LAlt_textChanged(const QString &arg1)
{
    if (toggled == true) {
        LAltS = arg1;
    } else {
        LAlt = arg1;
    }
}

void keyMapping::on_lineEdit_Space_textChanged(const QString &arg1)
{
    if (toggled == true) {
        spaceS = arg1;
    } else {
        space = arg1;
    }
}

void keyMapping::on_lineEdit_RAlt_textChanged(const QString &arg1)
{
    if (toggled == true) {
        RAltS = arg1;
    } else {
        RAlt = arg1;
    }
}

void keyMapping::on_lineEdit_Menu_textChanged(const QString &arg1)
{
    if (toggled == true) {
        menuS = arg1;
    } else {
        menu = arg1;
    }
}

void keyMapping::on_lineEdit_RCtrl_textChanged(const QString &arg1)
{
    if (toggled == true) {
        RCtrlS = arg1;
    } else {
        RCtrl = arg1;
    }
}

void keyMapping::on_pushButton_OnShift_toggled(bool checked)
{
   toggled = checked;
   if (toggled == true) {
        ui->lineEdit_Tilde->setText(tildeS);
        ui->lineEdit_1->setText(n1S);
        ui->lineEdit_2->setText(n2S);
        ui->lineEdit_3->setText(n3S);
        ui->lineEdit_4->setText(n4S);
        ui->lineEdit_5->setText(n5S);
        ui->lineEdit_6->setText(n6S);
        ui->lineEdit_7->setText(n7S);
        if (n7S == "&&") {ui->lineEdit_7->setText("&");}
        ui->lineEdit_8->setText(n8S);
        ui->lineEdit_9->setText(n9S);
        ui->lineEdit_0->setText(n0S);
        ui->lineEdit_Minus->setText(minusS);
        ui->lineEdit_Equals->setText(equalsS);
        ui->lineEdit_Backspace->setText(backspaceS);
        ui->lineEdit_TAB->setText(TABS);
        ui->lineEdit_Q->setText(qS);
        ui->lineEdit_W->setText(wS);
        ui->lineEdit_E->setText(eS);
        ui->lineEdit_R->setText(rS);
        ui->lineEdit_T->setText(tS);
        ui->lineEdit_Y->setText(yS);
        ui->lineEdit_U->setText(uS);
        ui->lineEdit_I->setText(iS);
        ui->lineEdit_O->setText(oS);
        ui->lineEdit_P->setText(pS);
        ui->lineEdit_leftSqureBracket->setText(leftSquareBracketS);
        ui->lineEdit_rightSquareBracket->setText(rightSquareBracketS);
        ui->lineEdit_Backslash->setText(backslashS);
        ui->lineEdit_CAPS->setText(CAPSS);
        ui->lineEdit_A->setText(aS);
        ui->lineEdit_S->setText(sS);
        ui->lineEdit_D->setText(dS);
        ui->lineEdit_F->setText(fS);
        ui->lineEdit_G->setText(gS);
        ui->lineEdit_H->setText(hS);
        ui->lineEdit_J->setText(jS);
        ui->lineEdit_K->setText(kS);
        ui->lineEdit_L->setText(lS);
        ui->lineEdit_Semicolon->setText(semicolonS);
        ui->lineEdit_Apostrophe->setText(apostropheS);
        ui->lineEdit_Enter->setText(enterS);
        ui->lineEdit_LShift->setText(LShiftS);
        ui->lineEdit_Z->setText(zS);
        ui->lineEdit_X->setText(xS);
        ui->lineEdit_C->setText(cS);
        ui->lineEdit_V->setText(vS);
        ui->lineEdit_B->setText(bS);
        ui->lineEdit_N->setText(nS);
        ui->lineEdit_M->setText(mS);
        ui->lineEdit_Comma->setText(commaS);
        ui->lineEdit_Period->setText(periodS);
        ui->lineEdit_Slash->setText(slashS);
        ui->lineEdit_RShift->setText(RShiftS);
        ui->lineEdit_LCtrl->setText(LCtrlS);
        ui->lineEdit_Super->setText(superS);
        ui->lineEdit_LAlt->setText(LAltS);
        ui->lineEdit_Space->setText(spaceS);
        ui->lineEdit_RAlt->setText(RAltS);
        ui->lineEdit_Menu->setText(menuS);
        ui->lineEdit_RCtrl->setText(RCtrlS);

        ui->lineEdit_Tilde->setStyleSheet(orangeSK);
        ui->lineEdit_1->setStyleSheet(orangeSK);
        ui->lineEdit_2->setStyleSheet(orangeSK);
        ui->lineEdit_3->setStyleSheet(redSK);
        ui->lineEdit_4->setStyleSheet(greenSK);
        ui->lineEdit_5->setStyleSheet(blueSK);
        ui->lineEdit_6->setStyleSheet(blueSK);
        ui->lineEdit_7->setStyleSheet(cyanSK);
        ui->lineEdit_8->setStyleSheet(cyanSK);
        ui->lineEdit_9->setStyleSheet(greenSK);
        ui->lineEdit_0->setStyleSheet(redSK);
        ui->lineEdit_Minus->setStyleSheet(orangeSK);
        ui->lineEdit_Equals->setStyleSheet(orangeSK);
        ui->lineEdit_Backspace->setStyleSheet(orangeS);
        ui->lineEdit_TAB->setStyleSheet(orangeS);
        ui->lineEdit_Q->setStyleSheet(orangeS);
        ui->lineEdit_W->setStyleSheet(redS);
        ui->lineEdit_E->setStyleSheet(greenS);
        ui->lineEdit_R->setStyleSheet(blueS);
        ui->lineEdit_T->setStyleSheet(blueS);
        ui->lineEdit_Y->setStyleSheet(cyanS);
        ui->lineEdit_U->setStyleSheet(cyanS);
        ui->lineEdit_I->setStyleSheet(greenS);
        ui->lineEdit_O->setStyleSheet(redS);
        ui->lineEdit_P->setStyleSheet(orangeS);
        ui->lineEdit_leftSqureBracket->setStyleSheet(orangeSK);
        ui->lineEdit_rightSquareBracket->setStyleSheet(orangeSK);
        ui->lineEdit_Backslash->setStyleSheet(orangeSK);
        ui->lineEdit_CAPS->setStyleSheet(orangeS);
        ui->lineEdit_A->setStyleSheet(orangeS);
        ui->lineEdit_S->setStyleSheet(redS);
        ui->lineEdit_D->setStyleSheet(greenS);
        ui->lineEdit_F->setStyleSheet(blueS);
        ui->lineEdit_G->setStyleSheet(blueS);
        ui->lineEdit_H->setStyleSheet(cyanS);
        ui->lineEdit_J->setStyleSheet(cyanS);
        ui->lineEdit_K->setStyleSheet(greenS);
        ui->lineEdit_L->setStyleSheet(redS);
        ui->lineEdit_Semicolon->setStyleSheet(orangeSK);
        ui->lineEdit_Apostrophe->setStyleSheet(orangeSK);
        ui->lineEdit_Enter->setStyleSheet(orangeS);
        ui->lineEdit_LShift->setStyleSheet(orangeS);
        ui->lineEdit_Z->setStyleSheet(orangeS);
        ui->lineEdit_X->setStyleSheet(redS);
        ui->lineEdit_C->setStyleSheet(greenS);
        ui->lineEdit_V->setStyleSheet(blueS);
        ui->lineEdit_B->setStyleSheet(blueS);
        ui->lineEdit_N->setStyleSheet(cyanS);
        ui->lineEdit_M->setStyleSheet(cyanS);
        ui->lineEdit_Comma->setStyleSheet(greenSK);
        ui->lineEdit_Period->setStyleSheet(redSK);
        ui->lineEdit_Slash->setStyleSheet(orangeSK);
        ui->lineEdit_RShift->setStyleSheet(orangeS);
        ui->lineEdit_LCtrl->setStyleSheet(orangeS);
        ui->lineEdit_Super->setStyleSheet(whiteishS);
        ui->lineEdit_LAlt->setStyleSheet(orangeS);
        ui->lineEdit_Space->setStyleSheet(whiteishS);
        ui->lineEdit_RAlt->setStyleSheet(orangeS);
        ui->lineEdit_Menu->setStyleSheet(whiteishS);
        ui->lineEdit_RCtrl->setStyleSheet(orangeS);
   } else {
       ui->pushButton_OnShift->setChecked(false);
       ui->lineEdit_Tilde->setText(tilde);
       ui->lineEdit_1->setText(n1);
       ui->lineEdit_2->setText(n2);
       ui->lineEdit_3->setText(n3);
       ui->lineEdit_4->setText(n4);
       ui->lineEdit_5->setText(n5);
       ui->lineEdit_6->setText(n6);
       ui->lineEdit_7->setText(n7);
       ui->lineEdit_8->setText(n8);
       ui->lineEdit_9->setText(n9);
       ui->lineEdit_0->setText(n0);
       ui->lineEdit_Minus->setText(minus);
       ui->lineEdit_Equals->setText(equals);
       ui->lineEdit_Backspace->setText(backspace);
       ui->lineEdit_TAB->setText(TAB);
       ui->lineEdit_Q->setText(q);
       ui->lineEdit_W->setText(w);
       ui->lineEdit_E->setText(e);
       ui->lineEdit_R->setText(r);
       ui->lineEdit_T->setText(t);
       ui->lineEdit_Y->setText(y);
       ui->lineEdit_U->setText(u);
       ui->lineEdit_I->setText(i);
       ui->lineEdit_O->setText(o);
       ui->lineEdit_P->setText(p);
       ui->lineEdit_leftSqureBracket->setText(leftSquareBracket);
       ui->lineEdit_rightSquareBracket->setText(rightSquareBracket);
       ui->lineEdit_Backslash->setText(backslash);
       ui->lineEdit_CAPS->setText(CAPS);
       ui->lineEdit_A->setText(a);
       ui->lineEdit_S->setText(s);
       ui->lineEdit_D->setText(d);
       ui->lineEdit_F->setText(f);
       ui->lineEdit_G->setText(g);
       ui->lineEdit_H->setText(h);
       ui->lineEdit_J->setText(j);
       ui->lineEdit_K->setText(k);
       ui->lineEdit_L->setText(l);
       ui->lineEdit_Semicolon->setText(semicolon);
       ui->lineEdit_Apostrophe->setText(apostrophe);
       ui->lineEdit_Enter->setText(enter);
       ui->lineEdit_LShift->setText(LShift);
       ui->lineEdit_Z->setText(z);
       ui->lineEdit_X->setText(x);
       ui->lineEdit_C->setText(c);
       ui->lineEdit_V->setText(v);
       ui->lineEdit_B->setText(b);
       ui->lineEdit_N->setText(n);
       ui->lineEdit_M->setText(m);
       ui->lineEdit_Comma->setText(comma);
       ui->lineEdit_Period->setText(period);
       ui->lineEdit_Slash->setText(slash);
       ui->lineEdit_RShift->setText(RShift);
       ui->lineEdit_LCtrl->setText(LCtrl);
       ui->lineEdit_Super->setText(super);
       ui->lineEdit_LAlt->setText(LAlt);
       ui->lineEdit_Space->setText(space);
       ui->lineEdit_RAlt->setText(RAlt);
       ui->lineEdit_Menu->setText(menu);
       ui->lineEdit_RCtrl->setText(RCtrl);

       ui->lineEdit_Tilde->setStyleSheet(orange);
       ui->lineEdit_1->setStyleSheet(orange);
       ui->lineEdit_2->setStyleSheet(orange);
       ui->lineEdit_3->setStyleSheet(red);
       ui->lineEdit_4->setStyleSheet(green);
       ui->lineEdit_5->setStyleSheet(blue);
       ui->lineEdit_6->setStyleSheet(blue);
       ui->lineEdit_7->setStyleSheet(cyan);
       ui->lineEdit_8->setStyleSheet(cyan);
       ui->lineEdit_9->setStyleSheet(green);
       ui->lineEdit_0->setStyleSheet(red);
       ui->lineEdit_Minus->setStyleSheet(orange);
       ui->lineEdit_Equals->setStyleSheet(orange);
       ui->lineEdit_Backspace->setStyleSheet(orange);
       ui->lineEdit_TAB->setStyleSheet(orange);
       ui->lineEdit_Q->setStyleSheet(orange);
       ui->lineEdit_W->setStyleSheet(red);
       ui->lineEdit_E->setStyleSheet(green);
       ui->lineEdit_R->setStyleSheet(blue);
       ui->lineEdit_T->setStyleSheet(blue);
       ui->lineEdit_Y->setStyleSheet(cyan);
       ui->lineEdit_U->setStyleSheet(cyan);
       ui->lineEdit_I->setStyleSheet(green);
       ui->lineEdit_O->setStyleSheet(red);
       ui->lineEdit_P->setStyleSheet(orange);
       ui->lineEdit_leftSqureBracket->setStyleSheet(orange);
       ui->lineEdit_rightSquareBracket->setStyleSheet(orange);
       ui->lineEdit_Backslash->setStyleSheet(orange);
       ui->lineEdit_CAPS->setStyleSheet(orange);
       ui->lineEdit_A->setStyleSheet(orange);
       ui->lineEdit_S->setStyleSheet(red);
       ui->lineEdit_D->setStyleSheet(green);
       ui->lineEdit_F->setStyleSheet(blue);
       ui->lineEdit_G->setStyleSheet(blue);
       ui->lineEdit_H->setStyleSheet(cyan);
       ui->lineEdit_J->setStyleSheet(cyan);
       ui->lineEdit_K->setStyleSheet(green);
       ui->lineEdit_L->setStyleSheet(red);
       ui->lineEdit_Semicolon->setStyleSheet(orange);
       ui->lineEdit_Apostrophe->setStyleSheet(orange);
       ui->lineEdit_Enter->setStyleSheet(orange);
       ui->lineEdit_LShift->setStyleSheet(orange);
       ui->lineEdit_Z->setStyleSheet(orange);
       ui->lineEdit_X->setStyleSheet(red);
       ui->lineEdit_C->setStyleSheet(green);
       ui->lineEdit_V->setStyleSheet(blue);
       ui->lineEdit_B->setStyleSheet(blue);
       ui->lineEdit_N->setStyleSheet(cyan);
       ui->lineEdit_M->setStyleSheet(cyan);
       ui->lineEdit_Comma->setStyleSheet(green);
       ui->lineEdit_Period->setStyleSheet(red);
       ui->lineEdit_Slash->setStyleSheet(orange);
       ui->lineEdit_RShift->setStyleSheet(orange);
       ui->lineEdit_LCtrl->setStyleSheet(orange);
       ui->lineEdit_Super->setStyleSheet(whiteish);
       ui->lineEdit_LAlt->setStyleSheet(orange);
       ui->lineEdit_Space->setStyleSheet(whiteish);
       ui->lineEdit_RAlt->setStyleSheet(orange);
       ui->lineEdit_Menu->setStyleSheet(whiteish);
       ui->lineEdit_RCtrl->setStyleSheet(orange);
   }
}

void keyMapping::resizeEvent(QResizeEvent*)
{
    //624
    //272
    double width = this->size().width() / 17.828571428571428571428571428571;
    double height = this->size().height() / 8.5;
    ui->lineEdit_Tilde->setMaximumSize(width, height);
    ui->lineEdit_0->setMaximumSize(width, height);
    ui->lineEdit_0->setMinimumSize(width, height);
    ui->lineEdit_1->setMaximumSize(width, height);
    ui->lineEdit_1->setMinimumSize(width, height);
    ui->lineEdit_2->setMaximumSize(width, height);
    ui->lineEdit_2->setMinimumSize(width, height);
    ui->lineEdit_3->setMaximumSize(width, height);
    ui->lineEdit_3->setMinimumSize(width, height);
    ui->lineEdit_4->setMaximumSize(width, height);
    ui->lineEdit_4->setMinimumSize(width, height);
    ui->lineEdit_5->setMaximumSize(width, height);
    ui->lineEdit_5->setMinimumSize(width, height);
    ui->lineEdit_6->setMaximumSize(width, height);
    ui->lineEdit_6->setMinimumSize(width, height);
    ui->lineEdit_7->setMaximumSize(width, height);
    ui->lineEdit_7->setMinimumSize(width, height);
    ui->lineEdit_8->setMaximumSize(width, height);
    ui->lineEdit_8->setMinimumSize(width, height);
    ui->lineEdit_9->setMaximumSize(width, height);
    ui->lineEdit_9->setMinimumSize(width, height);
    ui->lineEdit_Minus->setMaximumSize(width, height);
    ui->lineEdit_Minus->setMinimumSize(width, height);
    ui->lineEdit_Equals->setMaximumSize(width, height);
    ui->lineEdit_Equals->setMinimumSize(width, height);
    ui->lineEdit_Q->setMaximumSize(width, height);
    ui->lineEdit_Q->setMinimumSize(width, height);
    ui->lineEdit_W->setMaximumSize(width, height);
    ui->lineEdit_W->setMinimumSize(width, height);
    ui->lineEdit_E->setMaximumSize(width, height);
    ui->lineEdit_E->setMinimumSize(width, height);
    ui->lineEdit_R->setMaximumSize(width, height);
    ui->lineEdit_R->setMinimumSize(width, height);
    ui->lineEdit_T->setMaximumSize(width, height);
    ui->lineEdit_T->setMinimumSize(width, height);
    ui->lineEdit_Y->setMaximumSize(width, height);
    ui->lineEdit_Y->setMinimumSize(width, height);
    ui->lineEdit_U->setMaximumSize(width, height);
    ui->lineEdit_U->setMinimumSize(width, height);
    ui->lineEdit_I->setMaximumSize(width, height);
    ui->lineEdit_I->setMinimumSize(width, height);
    ui->lineEdit_O->setMaximumSize(width, height);
    ui->lineEdit_O->setMinimumSize(width, height);
    ui->lineEdit_P->setMaximumSize(width, height);
    ui->lineEdit_P->setMinimumSize(width, height);
    ui->lineEdit_leftSqureBracket->setMaximumSize(width, height);
    ui->lineEdit_leftSqureBracket->setMinimumSize(width, height);
    ui->lineEdit_rightSquareBracket->setMaximumSize(width, height);
    ui->lineEdit_rightSquareBracket->setMinimumSize(width, height);
    ui->lineEdit_Backslash->setMaximumSize(width, height);
    ui->lineEdit_Backslash->setMinimumSize(width, height);
    ui->lineEdit_A->setMaximumSize(width, height);
    ui->lineEdit_A->setMinimumSize(width, height);
    ui->lineEdit_S->setMaximumSize(width, height);
    ui->lineEdit_S->setMinimumSize(width, height);
    ui->lineEdit_D->setMaximumSize(width, height);
    ui->lineEdit_D->setMinimumSize(width, height);
    ui->lineEdit_F->setMaximumSize(width, height);
    ui->lineEdit_F->setMinimumSize(width, height);
    ui->lineEdit_G->setMaximumSize(width, height);
    ui->lineEdit_G->setMinimumSize(width, height);
    ui->lineEdit_H->setMaximumSize(width, height);
    ui->lineEdit_H->setMinimumSize(width, height);
    ui->lineEdit_J->setMaximumSize(width, height);
    ui->lineEdit_J->setMinimumSize(width, height);
    ui->lineEdit_K->setMaximumSize(width, height);
    ui->lineEdit_K->setMinimumSize(width, height);
    ui->lineEdit_L->setMaximumSize(width, height);
    ui->lineEdit_L->setMinimumSize(width, height);
    ui->lineEdit_Semicolon->setMaximumSize(width, height);
    ui->lineEdit_Semicolon->setMinimumSize(width, height);
    ui->lineEdit_Apostrophe->setMaximumSize(width, height);
    ui->lineEdit_Apostrophe->setMinimumSize(width, height);
    ui->lineEdit_Z->setMaximumSize(width, height);
    ui->lineEdit_Z->setMinimumSize(width, height);
    ui->lineEdit_X->setMaximumSize(width, height);
    ui->lineEdit_X->setMinimumSize(width, height);
    ui->lineEdit_C->setMaximumSize(width, height);
    ui->lineEdit_C->setMinimumSize(width, height);
    ui->lineEdit_V->setMaximumSize(width, height);
    ui->lineEdit_V->setMinimumSize(width, height);
    ui->lineEdit_B->setMaximumSize(width, height);
    ui->lineEdit_B->setMinimumSize(width, height);
    ui->lineEdit_N->setMaximumSize(width, height);
    ui->lineEdit_N->setMinimumSize(width, height);
    ui->lineEdit_M->setMaximumSize(width, height);
    ui->lineEdit_M->setMinimumSize(width, height);
    ui->lineEdit_Comma->setMaximumSize(width, height);
    ui->lineEdit_Comma->setMinimumSize(width, height);
    ui->lineEdit_Period->setMaximumSize(width, height);
    ui->lineEdit_Period->setMinimumSize(width, height);
    ui->lineEdit_Slash->setMaximumSize(width, height);
    ui->lineEdit_Slash->setMinimumSize(width, height);

    width = this->size().width() / 8.7887323943661971830985915492958;
    ui->lineEdit_TAB->setMaximumSize(width, height);
    ui->lineEdit_TAB->setMinimumSize(width, height);

    width = this->size().width() / 6.4329896907216494845360824742268;
    ui->lineEdit_Backspace->setMaximumSize(width, height);
    ui->lineEdit_Backspace->setMinimumSize(width, height);

    width = this->size().width() / 7.6097560975609756097560975609756;
    ui->lineEdit_CAPS->setMaximumSize(width, height);
    ui->lineEdit_CAPS->setMinimumSize(width, height);

    width = this->size().width() / 9.6;
    ui->lineEdit_Enter->setMaximumSize(width, height);
    ui->lineEdit_Enter->setMinimumSize(width, height);

    width = this->size().width() / 6.6382978723404255319148936170213;
    ui->lineEdit_LShift->setMaximumSize(width, height);
    ui->lineEdit_LShift->setMinimumSize(width, height);
    ui->lineEdit_RShift->setMaximumSize(width, height);
    ui->lineEdit_RShift->setMinimumSize(width, height);

    width = this->size().width() / 13.276595744680851063829787234043;
    ui->lineEdit_LCtrl->setMaximumSize(width, height);
    ui->lineEdit_LCtrl->setMinimumSize(width, height);
    ui->lineEdit_RCtrl->setMaximumSize(width, height);
    ui->lineEdit_RCtrl->setMinimumSize(width, height);

    width = this->size().width() / 14.857142857142857142857142857143;
    ui->lineEdit_LAlt->setMaximumSize(width, height);
    ui->lineEdit_LAlt->setMinimumSize(width, height);
    ui->lineEdit_RAlt->setMaximumSize(width, height);
    ui->lineEdit_RAlt->setMinimumSize(width, height);

    width = this->size().width() / 13.866666666666666666666666666667;
    ui->lineEdit_Super->setMaximumSize(width, height);
    ui->lineEdit_Super->setMinimumSize(width, height);
    ui->lineEdit_Menu->setMaximumSize(width, height);
    ui->lineEdit_Menu->setMinimumSize(width, height);

    width = this->size().width() / 2.08;
    ui->lineEdit_Space->setMaximumSize(width, height);
    ui->lineEdit_Space->setMinimumSize(width, height);

    changeFontSize(this->size().width() / 29.14285714285714285714285714286);
}

void keyMapping::on_buttonBox_accepted()
{
    Write();
    accept();
    close();
}

void keyMapping::on_buttonBox_rejected()
{
    close();
}

void keyMapping::on_pushButton_Slots_clicked()
{
    mapSlots.setModal(true);
    mapSlots.Initialize();
    if (mapSlots.exec() == QDialog::Accepted) {
        keyMapping::on_pushButton_OnShift_toggled(false);
        updateColors();
        updateKeys();
    }
}

void keyMapping::on_pushButton_Reset_clicked()
{
    QFile *write = new QFile(mapSlots.GetPath());
    write->open(QIODevice::ReadOnly);
    QTextStream read(write);
    read.setCodec("UTF-8");
    QString name = read.readLine();
    write->close();
    QString toWrite = name + "\n~​\n1\n2\n3\n4\n5\n6\n7\n8\n9\n0\n-\n=\n⌫\n"
                      "tab\nq\nw\ne\nr\nt\ny\nu\ni\no\np\n[\n]\n\\\n"
                      "caps\na\ns\nd\nf\ng\nh\nj\nk\nl\n;\n'\n⏎\n"
                      "⇧\nz\nx\nc\nv\nb\nn\nm\n,\n.\n/\n⇧\n"
                      "ctrl\nsu\nalt\n \nalt\nme\nctrl\n"
                      "~\n!\n@\n#\n$\n%\n^\n&\n*\n(\n)\n_\n+\n⌫\n"
                      "tab\nQ\nW\nE\nR\nT\nY\nU\nI\nO\nP\n{\n}\n|\n"
                      "caps\nA\nS\nD\nF\nG\nH\nJ\nK\nL\n:\n\"\n⏎\n"
                      "⇧\nZ\nX\nC\nV\nB\nN\nM\n<\n>\n?\n⇧\n"
                      "ctrl\nsu\nalt\n \nalt\nme\nctrl\n";
    write->open(QIODevice::ReadWrite);
    write->resize(0);
    write->write(toWrite.toUtf8());
    write->close();

    keyMapping::on_pushButton_OnShift_toggled(false);
    updateKeys();
    updateColors();

}

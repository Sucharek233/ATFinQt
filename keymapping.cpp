#include "keymapping.h"
#include "ui_keymapping.h"

bool toggled;

keyMapping::keyMapping(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyMapping)
{
    ui->setupUi(this);
}

void keyMapping::lightMap()
{
    ui->pushButton_OnShift->setStyleSheet("color: black; background-color: rgb(244, 244, 244);");
    keyMapping::setStyleSheet("background-color: rgb(244, 244, 244);");
    ui->buttonBox->setStyleSheet("QPushButton {color: black; background-color: rgb(244, 244, 244);}");
}
void keyMapping::darkMap()
{
    ui->pushButton_OnShift->setStyleSheet("color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);");
    keyMapping::setStyleSheet("background-color: rgb(6, 6, 14);");
    ui->buttonBox->setStyleSheet("QPushButton {color: rgb(211, 213, 201); background-color: rgb(36, 36, 44);}");
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

keyMapping::~keyMapping()
{
    delete ui;
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

void keyMapping::on_buttonBox_accepted()
{
    accept();
    close();
}

void keyMapping::on_buttonBox_rejected()
{
    close();
}

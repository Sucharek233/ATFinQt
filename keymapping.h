#ifndef KEYMAPPINGH_H
#define KEYMAPPINGH_H

#include "keymappingslots.h"
#include <QDialog>
#include <QDebug>

namespace Ui {
class keyMapping;
}

class keyMapping : public QDialog
{
    Q_OBJECT

public:
    explicit keyMapping(QWidget *parent = nullptr);
    ~keyMapping();

    void resizeEvent(QResizeEvent*);

    void changeFontSize(int size);

    void updateKeys();

    void Write();

    QString getTilde() { return tilde; }
    QString getN1() { return n1; }
    QString getN2() { return n2; }
    QString getN3() { return n3; }
    QString getN4() { return n4; }
    QString getN5() { return n5; }
    QString getN6() { return n6; }
    QString getN7() { return n7; }
    QString getN8() { return n8; }
    QString getN9() { return n9; }
    QString getN0() { return n0; }
    QString getMinus() { return minus; }
    QString getEquals() { return equals; }
    QString getBackspace() { return backspace; }
    QString getTAB() { return TAB; }
    QString getQ() { return q; }
    QString getW() { return w; }
    QString getE() { return e; }
    QString getR() { return r; }
    QString getT() { return t; }
    QString getY() { return y; }
    QString getU() { return u; }
    QString getI() { return i; }
    QString getO() { return o; }
    QString getP() { return p; }
    QString getLeftSquareBracket() { return leftSquareBracket; }
    QString getRightSquareBracket() { return rightSquareBracket; }
    QString getBackslash() { return backslash; }
    QString getCAPS() { return CAPS; }
    QString getA() { return a; }
    QString getS() { return s; }
    QString getD() { return d; }
    QString getF() { return f; }
    QString getG() { return g; }
    QString getH() { return h; }
    QString getJ() { return j; }
    QString getK() { return k; }
    QString getL() { return l; }
    QString getSemicolon() { return semicolon; }
    QString getApostrophe() { return apostrophe; }
    QString getEnter() { return enter; }
    QString getLShift() { return LShift; }
    QString getZ() { return z; }
    QString getX() { return x; }
    QString getC() { return c; }
    QString getV() { return v; }
    QString getB() { return b; }
    QString getN() { return n; }
    QString getM() { return m; }
    QString getComma() { return comma; }
    QString getPeriod() { return period; }
    QString getSlash() { return slash; }
    QString getRShift() { return RShift; }
    QString getLCtrl() { return LCtrl; }
    QString getSuper() { return super; }
    QString getLAlt() { return LAlt; }
    QString getSpace() { return space; }
    QString getRAlt() { return RAlt; }
    QString getMenu() { return menu; }
    QString getRCtrl() { return RCtrl; }

    QString getTildeS() { return tildeS; }
    QString getN1S() { return n1S; }
    QString getN2S() { return n2S; }
    QString getN3S() { return n3S; }
    QString getN4S() { return n4S; }
    QString getN5S() { return n5S; }
    QString getN6S() { return n6S; }
    QString getN7S() { if (n7S == "&&") {n7S = "&";} return n7S; }
    QString getN8S() { return n8S; }
    QString getN9S() { return n9S; }
    QString getN0S() { return n0S; }
    QString getMinusS() { return minusS; }
    QString getEqualsS() { return equalsS; }
    QString getBackspaceS() { return backspaceS; }
    QString getTABS() { return TABS; }
    QString getQS() { return qS; }
    QString getWS() { return wS; }
    QString getES() { return eS; }
    QString getRS() { return rS; }
    QString getTS() { return tS; }
    QString getYS() { return yS; }
    QString getUS() { return uS; }
    QString getIS() { return iS; }
    QString getOS() { return oS; }
    QString getPS() { return pS; }
    QString getLeftSquareBracketS() { return leftSquareBracketS; }
    QString getRightSquareBracketS() { return rightSquareBracketS; }
    QString getBackslashS() { return backslashS; }
    QString getCAPSS() { return CAPSS; }
    QString getAS() { return aS; }
    QString getSS() { return sS; }
    QString getDS() { return dS; }
    QString getFS() { return fS; }
    QString getGS() { return gS; }
    QString getHS() { return hS; }
    QString getJS() { return jS; }
    QString getKS() { return kS; }
    QString getLS() { return lS; }
    QString getSemicolonS() { return semicolonS; }
    QString getApostropheS() { return apostropheS; }
    QString getEnterS() { return enterS; }
    QString getLShiftS() { return LShiftS; }
    QString getZS() { return zS; }
    QString getXS() { return xS; }
    QString getCS() { return cS; }
    QString getVS() { return vS; }
    QString getBS() { return bS; }
    QString getNS() { return nS; }
    QString getMS() { return mS; }
    QString getCommaS() { return commaS; }
    QString getPeriodS() { return periodS; }
    QString getSlashS() { return slashS; }
    QString getRShiftS() { return RShiftS; }
    QString getLCtrlS() { return LCtrlS; }
    QString getSuperS() { return superS; }
    QString getLAltS() { return LAltS; }
    QString getSpaceS() { return spaceS; }
    QString getRAltS() { return RAltS; }
    QString getMenuS() { return menuS; }
    QString getRCtrlS() { return RCtrlS; }

    void lightMap();
    void darkMap();

    void setOrange(QString stuff) {orange = stuff;}
    void setRed(QString stuff) {red = stuff;}
    void setGreen(QString stuff) {green = stuff;}
    void setBlue(QString stuff) {blue = stuff;}
    void setCyan(QString stuff) {cyan = stuff;}
    void setWhiteish(QString stuff) {whiteish = stuff;}

    void setOrangeS(QString stuff) {orangeS = stuff;}
    void setRedS(QString stuff) {redS = stuff;}
    void setGreenS(QString stuff) {greenS = stuff;}
    void setBlueS(QString stuff) {blueS = stuff;}
    void setCyanS(QString stuff) {cyanS = stuff;}
    void setWhiteishS(QString stuff) {whiteishS = stuff;}


    void setOrangeSK(QString stuff) {orangeSK = stuff;}
    void setRedSK(QString stuff) {redSK = stuff;}
    void setGreenSK(QString stuff) {greenSK = stuff;}
    void setBlueSK(QString stuff) {blueSK = stuff;}
    void setCyanSK(QString stuff) {cyanSK = stuff;}
    void setWhiteishSK(QString stuff) {whiteishSK = stuff;}

    void updateColors();

public slots:
    void on_lineEdit_Tilde_textChanged(const QString &arg1);

    void on_lineEdit_1_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_9_textChanged(const QString &arg1);

    void on_lineEdit_0_textChanged(const QString &arg1);

    void on_lineEdit_Minus_textChanged(const QString &arg1);

    void on_lineEdit_Equals_textChanged(const QString &arg1);

    void on_lineEdit_Backspace_textChanged(const QString &arg1);

    void on_lineEdit_TAB_textChanged(const QString &arg1);

    void on_lineEdit_Q_textChanged(const QString &arg1);

    void on_lineEdit_W_textChanged(const QString &arg1);

    void on_lineEdit_E_textChanged(const QString &arg1);

    void on_lineEdit_R_textChanged(const QString &arg1);

    void on_lineEdit_T_textChanged(const QString &arg1);

    void on_lineEdit_Y_textChanged(const QString &arg1);

    void on_lineEdit_U_textChanged(const QString &arg1);

    void on_lineEdit_I_textChanged(const QString &arg1);

    void on_lineEdit_O_textChanged(const QString &arg1);

    void on_lineEdit_P_textChanged(const QString &arg1);

    void on_lineEdit_leftSqureBracket_textChanged(const QString &arg1);

    void on_lineEdit_rightSquareBracket_textChanged(const QString &arg1);

    void on_lineEdit_Backslash_textChanged(const QString &arg1);

    void on_lineEdit_CAPS_textChanged(const QString &arg1);

    void on_lineEdit_A_textChanged(const QString &arg1);

    void on_lineEdit_S_textChanged(const QString &arg1);

    void on_lineEdit_D_textChanged(const QString &arg1);

    void on_lineEdit_F_textChanged(const QString &arg1);

    void on_lineEdit_G_textChanged(const QString &arg1);

    void on_lineEdit_H_textChanged(const QString &arg1);

    void on_lineEdit_J_textChanged(const QString &arg1);

    void on_lineEdit_K_textChanged(const QString &arg1);

    void on_lineEdit_L_textChanged(const QString &arg1);

    void on_lineEdit_Semicolon_textChanged(const QString &arg1);

    void on_lineEdit_Apostrophe_textChanged(const QString &arg1);

    void on_lineEdit_Enter_textChanged(const QString &arg1);

    void on_lineEdit_LShift_textChanged(const QString &arg1);

    void on_lineEdit_Z_textChanged(const QString &arg1);

    void on_lineEdit_X_textChanged(const QString &arg1);

    void on_lineEdit_C_textChanged(const QString &arg1);

    void on_lineEdit_V_textChanged(const QString &arg1);

    void on_lineEdit_B_textChanged(const QString &arg1);

    void on_lineEdit_N_textChanged(const QString &arg1);

    void on_lineEdit_M_textChanged(const QString &arg1);

    void on_lineEdit_Comma_textChanged(const QString &arg1);

    void on_lineEdit_Period_textChanged(const QString &arg1);

    void on_lineEdit_Slash_textChanged(const QString &arg1);

    void on_lineEdit_RShift_textChanged(const QString &arg1);

    void on_lineEdit_LCtrl_textChanged(const QString &arg1);

    void on_lineEdit_Super_textChanged(const QString &arg1);

    void on_lineEdit_LAlt_textChanged(const QString &arg1);

    void on_lineEdit_Space_textChanged(const QString &arg1);

    void on_lineEdit_RAlt_textChanged(const QString &arg1);

    void on_lineEdit_Menu_textChanged(const QString &arg1);

    void on_lineEdit_RCtrl_textChanged(const QString &arg1);

    void on_pushButton_OnShift_toggled(bool checked);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private slots:
    void on_pushButton_Slots_clicked();

    void on_pushButton_Reset_clicked();

private:
    Ui::keyMapping *ui;
    keyMappingSlots mapSlots;

    QString tilde;
    QString n1;
    QString n2;
    QString n3;
    QString n4;
    QString n5;
    QString n6;
    QString n7;
    QString n8;
    QString n9;
    QString n0;
    QString minus;
    QString equals;
    QString backspace;
    QString TAB;
    QString q;
    QString w;
    QString e;
    QString r;
    QString t;
    QString y;
    QString u;
    QString i;
    QString o;
    QString p;
    QString leftSquareBracket;
    QString rightSquareBracket;
    QString backslash;
    QString CAPS;
    QString a;
    QString s;
    QString d;
    QString f;
    QString g;
    QString h;
    QString j;
    QString k;
    QString l;
    QString semicolon;
    QString apostrophe;
    QString enter;
    QString LShift;
    QString z;
    QString x;
    QString c;
    QString v;
    QString b;
    QString n;
    QString m;
    QString comma;
    QString period;
    QString slash;
    QString RShift;
    QString LCtrl;
    QString super;
    QString LAlt;
    QString space;
    QString RAlt;
    QString menu;
    QString RCtrl;

    QString tildeS;
    QString n1S;
    QString n2S;
    QString n3S;
    QString n4S;
    QString n5S;
    QString n6S;
    QString n7S;
    QString n8S;
    QString n9S;
    QString n0S;
    QString minusS;
    QString equalsS;
    QString backspaceS;
    QString TABS;
    QString qS;
    QString wS;
    QString eS;
    QString rS;
    QString tS;
    QString yS;
    QString uS;
    QString iS;
    QString oS;
    QString pS;
    QString leftSquareBracketS;
    QString rightSquareBracketS;
    QString backslashS;
    QString CAPSS;
    QString aS;
    QString sS;
    QString dS;
    QString fS;
    QString gS;
    QString hS;
    QString jS;
    QString kS;
    QString lS;
    QString semicolonS;
    QString apostropheS;
    QString enterS;
    QString LShiftS;
    QString zS;
    QString xS;
    QString cS;
    QString vS;
    QString bS;
    QString nS;
    QString mS;
    QString commaS;
    QString periodS;
    QString slashS;
    QString RShiftS;
    QString LCtrlS;
    QString superS;
    QString LAltS;
    QString spaceS;
    QString RAltS;
    QString menuS;
    QString RCtrlS;

    QString orange;
    QString red;
    QString green;
    QString blue;
    QString cyan;
    QString whiteish;

    QString orangeS;
    QString redS;
    QString greenS;
    QString blueS;
    QString cyanS;
    QString whiteishS;

    QString orangeSK;
    QString redSK;
    QString greenSK;
    QString blueSK;
    QString cyanSK;
    QString whiteishSK;
};

#endif // KEYMAPPINGH_H

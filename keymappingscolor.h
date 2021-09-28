#ifndef KEYMAPPINGSCOLOR_H
#define KEYMAPPINGSCOLOR_H

#include <QDialog>

namespace Ui {
class keyMappingsColor;
}

class keyMappingsColor : public QDialog
{
    Q_OBJECT

public:
    explicit keyMappingsColor(QWidget *parent = nullptr);
    ~keyMappingsColor();

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

private slots:
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

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::keyMappingsColor *ui;

    QString tilde = "~";
    QString n1 = "1";
    QString n2 = "2";
    QString n3 = "3";
    QString n4 = "4";
    QString n5 = "5";
    QString n6 = "6";
    QString n7 = "7";
    QString n8 = "8";
    QString n9 = "9";
    QString n0 = "0";
    QString minus = "-";
    QString equals = "=";
    QString backspace = "←";
    QString TAB = "tab";
    QString q = "q";
    QString w = "w";
    QString e = "e";
    QString r = "r";
    QString t = "t";
    QString y = "y";
    QString u = "u";
    QString i = "i";
    QString o = "o";
    QString p = "p";
    QString leftSquareBracket = "[";
    QString rightSquareBracket = "]";
    QString backslash = "\\";
    QString CAPS = "caps";
    QString a = "a";
    QString s = "s";
    QString d = "d";
    QString f = "f";
    QString g = "g";
    QString h = "h";
    QString j = "j";
    QString k = "k";
    QString l = "l";
    QString semicolon = ";";
    QString apostrophe = "'";
    QString enter = "⏎";
    QString LShift = "⇧";
    QString z = "z";
    QString x = "x";
    QString c = "c";
    QString v = "v";
    QString b = "b";
    QString n = "n";
    QString m = "m";
    QString comma = ",";
    QString period = ".";
    QString slash = "/";
    QString RShift = "⇧";
    QString LCtrl = "ctrl";
    QString super = "se";
    QString LAlt = "alt";
    QString space = " ";
    QString RAlt = "alt";
    QString menu = "me";
    QString RCtrl = "ctrl";
};

#endif // KEYMAPPINGSCOLOR_H

#ifndef KEYCOLOR_H
#define KEYCOLOR_H

#include <QDialog>
#include <QColorDialog>
#include <QDebug>

namespace Ui {
class keyColor;
}

class keyColor : public QDialog
{
    Q_OBJECT

public:
    explicit keyColor(QWidget *parent = nullptr);
    ~keyColor();

    void updateMapping(int shift);
    void updateCols();

    void lightCol();
    void darkCol();

    QString getFirstCol() {return firstCol;}
    QString getFirstBor() {return firstBor;}
    QString getFirstTog() {return firstTog;}
    void setFirstCol(QString stuff) {firstCol = stuff;}
    void setFirstBor(QString stuff) {firstBor = stuff;}
    void setFirstTog(QString stuff) {firstTog = stuff;}

    QString getSecondCol() {return secondCol;}
    QString getSecondBor() {return secondBor;}
    QString getSecondTog() {return secondTog;}
    void setSecondCol(QString stuff) {secondCol = stuff;}
    void setSecondBor(QString stuff) {secondBor = stuff;}
    void setSecondTog(QString stuff) {secondTog = stuff;}

    QString getThirdCol() {return thirdCol;}
    QString getThirdBor() {return thirdBor;}
    QString getThirdTog() {return thirdTog;}
    void setThirdCol(QString stuff) {thirdCol = stuff;}
    void setThirdBor(QString stuff) {thirdBor = stuff;}
    void setThirdTog(QString stuff) {thirdTog = stuff;}

    QString getFourthCol() {return fourthCol;}
    QString getFourthBor() {return fourthBor;}
    QString getFourthTog() {return fourthTog;}
    void setFourthCol(QString stuff) {fourthCol = stuff;}
    void setFourthBor(QString stuff) {fourthBor = stuff;}
    void setFourthTog(QString stuff) {fourthTog = stuff;}

    QString getFifthCol() {return fifthCol;}
    QString getFifthBor() {return fifthBor;}
    QString getFifthTog() {return fifthTog;}
    void setFifthCol(QString stuff) {fifthCol = stuff;}
    void setFifthBor(QString stuff) {fifthBor = stuff;}
    void setFifthTog(QString stuff) {fifthTog = stuff;}

    QString getSixthCol() {return sixthCol;}
    QString getSixthBor() {return sixthBor;}
    QString getSixthTog() {return sixthTog;}
    void setSixthCol(QString stuff) {sixthCol = stuff;}
    void setSixthBor(QString stuff) {sixthBor = stuff;}
    void setSixthTog(QString stuff) {sixthTog = stuff;}

    QString getTextCol() {return textColor;}
    void setTextCol(QString stuff) {textColor = stuff;}

    void setTilde(QString stuff) { tilde = stuff; }
    void setN1(QString stuff) { n1 = stuff; }
    void setN2(QString stuff) { n2 = stuff; }
    void setN3(QString stuff) { n3 = stuff; }
    void setN4(QString stuff) { n4 = stuff; }
    void setN5(QString stuff) { n5 = stuff; }
    void setN6(QString stuff) { n6 = stuff; }
    void setN7(QString stuff) { n7 = stuff; }
    void setN8(QString stuff) { n8 = stuff; }
    void setN9(QString stuff) { n9 = stuff; }
    void setN0(QString stuff) { n0 = stuff; }
    void setMinus(QString stuff) { minus = stuff; }
    void setEquals(QString stuff) { equals = stuff; }
    void setBackspace(QString stuff) { backspace = stuff; }
    void setTAB(QString stuff) { TAB = stuff; }
    void setQ(QString stuff) { q = stuff; }
    void setW(QString stuff) { w = stuff; }
    void setE(QString stuff) { e = stuff; }
    void setR(QString stuff) { r = stuff; }
    void setT(QString stuff) { t = stuff; }
    void setY(QString stuff) { y = stuff; }
    void setU(QString stuff) { u = stuff; }
    void setI(QString stuff) { i = stuff; }
    void setO(QString stuff) { o = stuff; }
    void setP(QString stuff) { p = stuff; }
    void setLeftSquareBracket(QString stuff) { leftSquareBracket = stuff; }
    void setRightSquareBracket(QString stuff) { rightSquareBracket = stuff; }
    void setBackslash(QString stuff) { backslash = stuff; }
    void setCAPS(QString stuff) { CAPS = stuff; }
    void setA(QString stuff) { a = stuff; }
    void setS(QString stuff) { s = stuff; }
    void setD(QString stuff) { d = stuff; }
    void setF(QString stuff) { f = stuff; }
    void setG(QString stuff) { g = stuff; }
    void setH(QString stuff) { h = stuff; }
    void setJ(QString stuff) { j = stuff; }
    void setK(QString stuff) { k = stuff; }
    void setL(QString stuff) { l = stuff; }
    void setSemicolon(QString stuff) { semicolon = stuff; }
    void setApostrophe(QString stuff) { apostrophe = stuff; }
    void setEnter(QString stuff) { enter = stuff; }
    void setLShift(QString stuff) { LShift = stuff; }
    void setZ(QString stuff) { z = stuff; }
    void setX(QString stuff) { x = stuff; }
    void setC(QString stuff) { c = stuff; }
    void setV(QString stuff) { v = stuff; }
    void setB(QString stuff) { b = stuff; }
    void setN(QString stuff) { n = stuff; }
    void setM(QString stuff) { m = stuff; }
    void setComma(QString stuff) { comma = stuff; }
    void setPeriod(QString stuff) { period = stuff; }
    void setSlash(QString stuff) { slash = stuff; }
    void setRShift(QString stuff) { RShift = stuff; }
    void setLCtrl(QString stuff) { LCtrl = stuff; }
    void setSuper(QString stuff) { super = stuff; }
    void setLAlt(QString stuff) { LAlt = stuff; }
    void setSpace(QString stuff) { space = stuff; }
    void setRAlt(QString stuff) { RAlt = stuff; }
    void setMenu(QString stuff) { menu = stuff; }
    void setRCtrl(QString stuff) { RCtrl = stuff; }

    void setTildeS(QString stuff) { tildeS = stuff; }
    void setN1S(QString stuff) { n1S = stuff; }
    void setN2S(QString stuff) { n2S = stuff; }
    void setN3S(QString stuff) { n3S = stuff; }
    void setN4S(QString stuff) { n4S = stuff; }
    void setN5S(QString stuff) { n5S = stuff; }
    void setN6S(QString stuff) { n6S = stuff; }
    void setN7S(QString stuff) { n7S = stuff; }
    void setN8S(QString stuff) { n8S = stuff; }
    void setN9S(QString stuff) { n9S = stuff; }
    void setN0S(QString stuff) { n0S = stuff; }
    void setMinusS(QString stuff) { minusS = stuff; }
    void setEqualsS(QString stuff) { equalsS = stuff; }
    void setBackspaceS(QString stuff) { backspaceS = stuff; }
    void setTABS(QString stuff) { TABS = stuff; }
    void setQS(QString stuff) { qS = stuff; }
    void setWS(QString stuff) { wS = stuff; }
    void setES(QString stuff) { eS = stuff; }
    void setRS(QString stuff) { rS = stuff; }
    void setTS(QString stuff) { tS = stuff; }
    void setYS(QString stuff) { yS = stuff; }
    void setUS(QString stuff) { uS = stuff; }
    void setIS(QString stuff) { iS = stuff; }
    void setOS(QString stuff) { oS = stuff; }
    void setPS(QString stuff) { pS = stuff; }
    void setLeftSquareBracketS(QString stuff) { leftSquareBracketS = stuff; }
    void setRightSquareBracketS(QString stuff) { rightSquareBracketS = stuff; }
    void setBackslashS(QString stuff) { backslashS = stuff; }
    void setCAPSS(QString stuff) { CAPSS = stuff; }
    void setAS(QString stuff) { aS = stuff; }
    void setSS(QString stuff) { sS = stuff; }
    void setDS(QString stuff) { dS = stuff; }
    void setFS(QString stuff) { fS = stuff; }
    void setGS(QString stuff) { gS = stuff; }
    void setHS(QString stuff) { hS = stuff; }
    void setJS(QString stuff) { jS = stuff; }
    void setKS(QString stuff) { kS = stuff; }
    void setLS(QString stuff) { lS = stuff; }
    void setSemicolonS(QString stuff) { semicolonS = stuff; }
    void setApostropheS(QString stuff) { apostropheS = stuff; }
    void setEnterS(QString stuff) { enterS = stuff; }
    void setLShiftS(QString stuff) { LShiftS = stuff; }
    void setZS(QString stuff) { zS = stuff; }
    void setXS(QString stuff) { xS = stuff; }
    void setCS(QString stuff) { cS = stuff; }
    void setVS(QString stuff) { vS = stuff; }
    void setBS(QString stuff) { bS = stuff; }
    void setNS(QString stuff) { nS = stuff; }
    void setMS(QString stuff) { mS = stuff; }
    void setCommaS(QString stuff) { commaS = stuff; }
    void setPeriodS(QString stuff) { periodS = stuff; }
    void setSlashS(QString stuff) { slashS = stuff; }
    void setRShiftS(QString stuff) { RShiftS = stuff; }
    void setLCtrlS(QString stuff) { LCtrlS = stuff; }
    void setSuperS(QString stuff) { superS = stuff; }
    void setLAltS(QString stuff) { LAltS = stuff; }
    void setSpaceS(QString stuff) { spaceS = stuff; }
    void setRAltS(QString stuff) { RAltS = stuff; }
    void setMenuS(QString stuff) { menuS = stuff; }
    void setRCtrlS(QString stuff) { RCtrlS = stuff; }

    QString getOrange() {return orange;}
    QString getRed() {return red;}
    QString getGreen() {return green;}
    QString getBlue() {return blue;}
    QString getCyan() {return cyan;}
    QString getWhiteish() {return whiteish;}

    void unToggle();

private slots:
    void on_toolButton_Col1_clicked();

    void on_toolButton_Bor1_clicked();

    void on_toolButton_Tog1_clicked();

    void on_toolButton_Col2_clicked();

    void on_toolButton_Bor2_clicked();

    void on_toolButton_Tog2_clicked();

    void on_toolButton_Col3_clicked();

    void on_toolButton_Bor3_clicked();

    void on_toolButton_Tog3_clicked();

    void on_toolButton_Col4_clicked();

    void on_toolButton_Bor4_clicked();

    void on_toolButton_Tog4_clicked();

    void on_toolButton_Col5_clicked();

    void on_toolButton_Bor5_clicked();

    void on_toolButton_Tog5_clicked();

    void on_toolButton_Col6_clicked();

    void on_toolButton_Bor6_clicked();

    void on_toolButton_Tog6_clicked();

    void on_pushButton_Toggled_toggled(bool checked);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_Reset_clicked();

    void on_pushButton_TextCol_clicked();

private:
    Ui::keyColor *ui;

    QString orange;
    QString red;
    QString green;
    QString blue;
    QString cyan;
    QString whiteish;

    QString firstCol = "#ffaa00";
    QString firstBor = "#af5a00";
    QString firstTog = "#cd7800";

    QString secondCol = "#ff0f0f";
    QString secondBor = "#960000";
    QString secondTog = "#780000";

    QString thirdCol = "#14ff14";
    QString thirdBor = "#00cd00";
    QString thirdTog = "#009600";

    QString fourthCol = "#3232ff";
    QString fourthBor = "#0000cd";
    QString fourthTog = "#0000af";

    QString fifthCol = "#00ffff";
    QString fifthBor = "#00cdcd";
    QString fifthTog = "#00afaf";

    QString sixthCol = "#bee6ff";
    QString sixthBor = "#a0c8e1";
    QString sixthTog = "#8cb4cd";

    QString textColor = "#000000";

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

    QString tildeS = "~";
    QString n1S = "!";
    QString n2S = "@";
    QString n3S = "#";
    QString n4S = "$";
    QString n5S = "%";
    QString n6S = "^";
    QString n7S = "&&";
    QString n8S = "*";
    QString n9S = "(";
    QString n0S = ")";
    QString minusS = "_";
    QString equalsS = "+";
    QString backspaceS = "←";
    QString TABS = "tab";
    QString qS = "Q";
    QString wS = "W";
    QString eS = "E";
    QString rS = "R";
    QString tS = "T";
    QString yS = "Y";
    QString uS = "U";
    QString iS = "I";
    QString oS = "O";
    QString pS = "P";
    QString leftSquareBracketS = "{";
    QString rightSquareBracketS = "}";
    QString backslashS = "|";
    QString CAPSS = "caps";
    QString aS = "A";
    QString sS = "S";
    QString dS = "D";
    QString fS = "F";
    QString gS = "G";
    QString hS = "H";
    QString jS = "J";
    QString kS = "K";
    QString lS = "L";
    QString semicolonS = ":";
    QString apostropheS = "\"";
    QString enterS = "⏎";
    QString LShiftS = "⇧";
    QString zS = "Z";
    QString xS = "X";
    QString cS = "C";
    QString vS = "V";
    QString bS = "B";
    QString nS = "N";
    QString mS = "M";
    QString commaS = "<";
    QString periodS = ">";
    QString slashS = "?";
    QString RShiftS = "⇧";
    QString LCtrlS = "ctrl";
    QString superS = "s";
    QString LAltS = "alt";
    QString spaceS = " ";
    QString RAltS = "alt";
    QString menuS = "m";
    QString RCtrlS = "ctrl";
};

#endif // KEYCOLOR_H

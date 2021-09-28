#include "keymappingscolor.h"
#include "ui_keymappingscolor.h"

keyMappingsColor::keyMappingsColor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyMappingsColor)
{
    ui->setupUi(this);
}

keyMappingsColor::~keyMappingsColor()
{
    delete ui;
}

void keyMappingsColor::on_lineEdit_Tilde_textChanged(const QString &arg1)
{
    tilde = arg1;
}

void keyMappingsColor::on_lineEdit_1_textChanged(const QString &arg1)
{
    n1 = arg1;
}

void keyMappingsColor::on_lineEdit_2_textChanged(const QString &arg1)
{
    n2 = arg1;
}

void keyMappingsColor::on_lineEdit_3_textChanged(const QString &arg1)
{
    n3 = arg1;
}

void keyMappingsColor::on_lineEdit_4_textChanged(const QString &arg1)
{
    n4 = arg1;
}

void keyMappingsColor::on_lineEdit_5_textChanged(const QString &arg1)
{
    n5 = arg1;
}

void keyMappingsColor::on_lineEdit_6_textChanged(const QString &arg1)
{
    n6 = arg1;
}

void keyMappingsColor::on_lineEdit_7_textChanged(const QString &arg1)
{
    n7 = arg1;
}

void keyMappingsColor::on_lineEdit_8_textChanged(const QString &arg1)
{
    n8 = arg1;
}

void keyMappingsColor::on_lineEdit_9_textChanged(const QString &arg1)
{
    n9 = arg1;
}

void keyMappingsColor::on_lineEdit_0_textChanged(const QString &arg1)
{
    n0 = arg1;
}

void keyMappingsColor::on_lineEdit_Minus_textChanged(const QString &arg1)
{
    minus = arg1;
}

void keyMappingsColor::on_lineEdit_Equals_textChanged(const QString &arg1)
{
    equals = arg1;
}

void keyMappingsColor::on_lineEdit_Backspace_textChanged(const QString &arg1)
{
    backspace = arg1;
}

void keyMappingsColor::on_lineEdit_TAB_textChanged(const QString &arg1)
{
    TAB = arg1;
}

void keyMappingsColor::on_lineEdit_Q_textChanged(const QString &arg1)
{
    q = arg1;
}

void keyMappingsColor::on_lineEdit_W_textChanged(const QString &arg1)
{
    w = arg1;
}

void keyMappingsColor::on_lineEdit_E_textChanged(const QString &arg1)
{
    e = arg1;
}

void keyMappingsColor::on_lineEdit_R_textChanged(const QString &arg1)
{
    r = arg1;
}

void keyMappingsColor::on_lineEdit_T_textChanged(const QString &arg1)
{
    t = arg1;
}

void keyMappingsColor::on_lineEdit_Y_textChanged(const QString &arg1)
{
    y = arg1;
}

void keyMappingsColor::on_lineEdit_U_textChanged(const QString &arg1)
{
    u = arg1;
}

void keyMappingsColor::on_lineEdit_I_textChanged(const QString &arg1)
{
    i = arg1;
}

void keyMappingsColor::on_lineEdit_O_textChanged(const QString &arg1)
{
    o = arg1;
}

void keyMappingsColor::on_lineEdit_P_textChanged(const QString &arg1)
{
    p = arg1;
}

void keyMappingsColor::on_lineEdit_leftSqureBracket_textChanged(const QString &arg1)
{
    leftSquareBracket = arg1;
}

void keyMappingsColor::on_lineEdit_rightSquareBracket_textChanged(const QString &arg1)
{
    rightSquareBracket = arg1;
}

void keyMappingsColor::on_lineEdit_Backslash_textChanged(const QString &arg1)
{
    backslash = arg1;
}

void keyMappingsColor::on_lineEdit_CAPS_textChanged(const QString &arg1)
{
    CAPS = arg1;
}

void keyMappingsColor::on_lineEdit_A_textChanged(const QString &arg1)
{
    a = arg1;
}

void keyMappingsColor::on_lineEdit_S_textChanged(const QString &arg1)
{
    s = arg1;
}

void keyMappingsColor::on_lineEdit_D_textChanged(const QString &arg1)
{
    d = arg1;
}

void keyMappingsColor::on_lineEdit_F_textChanged(const QString &arg1)
{
    f = arg1;
}

void keyMappingsColor::on_lineEdit_G_textChanged(const QString &arg1)
{
    g = arg1;
}

void keyMappingsColor::on_lineEdit_H_textChanged(const QString &arg1)
{
    h = arg1;
}

void keyMappingsColor::on_lineEdit_J_textChanged(const QString &arg1)
{
    j = arg1;
}

void keyMappingsColor::on_lineEdit_K_textChanged(const QString &arg1)
{
    k = arg1;
}

void keyMappingsColor::on_lineEdit_L_textChanged(const QString &arg1)
{
    l = arg1;
}

void keyMappingsColor::on_lineEdit_Semicolon_textChanged(const QString &arg1)
{
    semicolon = arg1;
}

void keyMappingsColor::on_lineEdit_Apostrophe_textChanged(const QString &arg1)
{
    apostrophe = arg1;
}

void keyMappingsColor::on_lineEdit_Enter_textChanged(const QString &arg1)
{
    enter = arg1;
}

void keyMappingsColor::on_lineEdit_LShift_textChanged(const QString &arg1)
{
    LShift = arg1;
}

void keyMappingsColor::on_lineEdit_Z_textChanged(const QString &arg1)
{
    z = arg1;
}

void keyMappingsColor::on_lineEdit_X_textChanged(const QString &arg1)
{
    x = arg1;
}


void keyMappingsColor::on_lineEdit_C_textChanged(const QString &arg1)
{
    c = arg1;
}

void keyMappingsColor::on_lineEdit_V_textChanged(const QString &arg1)
{
    v = arg1;
}

void keyMappingsColor::on_lineEdit_B_textChanged(const QString &arg1)
{
    b = arg1;
}

void keyMappingsColor::on_lineEdit_N_textChanged(const QString &arg1)
{
    n = arg1;
}

void keyMappingsColor::on_lineEdit_M_textChanged(const QString &arg1)
{
    m = arg1;
}

void keyMappingsColor::on_lineEdit_Comma_textChanged(const QString &arg1)
{
    comma = arg1;
}

void keyMappingsColor::on_lineEdit_Period_textChanged(const QString &arg1)
{
    period = arg1;
}

void keyMappingsColor::on_lineEdit_Slash_textChanged(const QString &arg1)
{
    slash = arg1;
}

void keyMappingsColor::on_lineEdit_RShift_textChanged(const QString &arg1)
{
    RShift = arg1;
}

void keyMappingsColor::on_lineEdit_LCtrl_textChanged(const QString &arg1)
{
    LCtrl = arg1;
}

void keyMappingsColor::on_lineEdit_Super_textChanged(const QString &arg1)
{
    super = arg1;
}

void keyMappingsColor::on_lineEdit_LAlt_textChanged(const QString &arg1)
{
    LAlt = arg1;
}

void keyMappingsColor::on_lineEdit_Space_textChanged(const QString &arg1)
{
    space = arg1;
}

void keyMappingsColor::on_lineEdit_RAlt_textChanged(const QString &arg1)
{
    RAlt = arg1;
}

void keyMappingsColor::on_lineEdit_Menu_textChanged(const QString &arg1)
{
    menu = arg1;
}

void keyMappingsColor::on_lineEdit_RCtrl_textChanged(const QString &arg1)
{
    RCtrl = arg1;
}

void keyMappingsColor::on_buttonBox_accepted()
{
    accept();
    close();
}

void keyMappingsColor::on_buttonBox_rejected()
{
    close();
}

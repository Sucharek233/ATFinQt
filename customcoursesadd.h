#ifndef CUSTOMCOURSESADD_H
#define CUSTOMCOURSESADD_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class customCoursesAdd;
}

class customCoursesAdd : public QDialog
{
    Q_OBJECT

public:
    explicit customCoursesAdd(QWidget *parent = nullptr);
    ~customCoursesAdd();

    void initialize();

    QString getName() { return name; }
    QString getText() { return text; }
    void setName(QString SName) {name = SName;}
    void setText(QString SText) {text = SText;}

    void lightCourseAdd();
    void darkCourseAdd();

private slots:
    void on_lineEdit_Name_textChanged(const QString &arg1);

    void on_textEdit_Text_textChanged();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::customCoursesAdd *ui;

    QString name;
    QString text;
    int currSlot = 0;
};

#endif // CUSTOMCOURSESADD_H

#ifndef CALC_H
#define CALC_H

#include <QGridLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QString>
#include <QWidget>

#define SIMPLE_MODE 1
#define ENGINEERING_MODE 2

#define STAGE1 1
#define STAGE2 2

class Calc : public QMainWindow
{
    Q_OBJECT
private:
    QWidget *mainWidget;
    //QGridLayout *mainLayout;
    QWidget *common;
    QLineEdit *display;

    QString slot1;
    QString slot2;
    QString operation;
    int stage;
    int mode;

    void showSimple();
    void createCommonWidget();
public:
    Calc(QWidget *parent = nullptr);
    ~Calc();
};
#endif // CALC_H

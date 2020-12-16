#ifndef CALC_H
#define CALC_H

#include <QGridLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
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
    QGridLayout *mainLayout;
    QWidget *common;
    QWidget *simple;
    QWidget *engineering;
    QLineEdit *display;
    QRadioButton *simpleRadioButton;
    QRadioButton *engineeringRadioButton;

    QString slot1;
    QString slot2;
    QString operation;
    int stage;
    int mode;

    void createCommonWidget();
    void createSimpleWidget();
    void createEngineeringWidget();

    void showSimple();
    void showEngineering();
public:
    Calc(QWidget *parent = nullptr);
    ~Calc();
};
#endif // CALC_H

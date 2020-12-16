#ifndef CALC_H
#define CALC_H

#include <QGridLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QString>
#include <QWidget>


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

    void createCommonWidget();
    void createSimpleWidget();
    void createEngineeringWidget();

    void showSimple();
    void showEngineering();
public:
    Calc(QWidget *parent = nullptr);
    ~Calc();
public slots:
    void SwitchMode();
};
#endif // CALC_H

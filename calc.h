#ifndef CALC_H
#define CALC_H

#include <QGridLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QString>
#include <QVector>
#include <QWidget>


#define STAGE1 1
#define STAGE2 2

#define OPERATION_PLUZ 1
#define OPERATION_MINUS 2
#define OPERATION_INCREASE 3
#define OPERATION_OBELUS 4
#define OPERATION_STEP_Y 5
#define OPERATION_Y_ROOT 6
#define OPERATION_LOG_Y 7

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
    double x;
    int operation;
    int stage;
    bool hasNumber;
    bool hasComma;

    void createCommonWidget();
    void createSimpleWidget();
    void createEngineeringWidget();

    void showSimple();
    void showEngineering();
public:
    Calc(QWidget *parent = nullptr);
    ~Calc();
public slots:
    void error();
    void switchMode();
    void updateDisplay();
    void clear();
    void zeroClicked();
    void numberClicked();
    void commaClicked();
    void equalClicked();
    void binaryClicked();
    void unaryClicked();
    void pluzClicked();
    void minusClicked();
    void increaseClicked();
    void obelusClicked();
    void stepYClicked();
    void yrtClicked();
    void logYClicked();
    void changeClicked();
    void procentClicked();
    void step2Clicked();
    void step3Clicked();
    void stepEClicked();
    void step10Clicked();
    void invertClicked();
    void sqrtClicked();
    void cbrtClicked();
    void factorialClicked();
    void lnClicked();
    void logClicked();
    void exponClicked();
    void piClicked();
    void sinClicked();
    void cosClicked();
    void tgClicked();
    void ctgClicked();
    void secClicked();
    void shClicked();
    void cthClicked();
    void cscClicked();
    void chClicked();
    void thClicked();
};
#endif // CALC_H

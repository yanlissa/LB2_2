#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

class Calc : public QMainWindow
{
    Q_OBJECT

public:
    Calc(QWidget *parent = nullptr);
    ~Calc();
};
#endif // CALC_H

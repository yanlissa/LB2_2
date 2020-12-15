#include "calc.h"

Calc::Calc(QWidget *parent)
    : QMainWindow(parent), mainWidget(nullptr)
{
    createCommonWidget();
    showSimple();
}

Calc::~Calc()
{
    delete common;
}

void Calc::createCommonWidget()
{
    common = new QWidget;
    QGridLayout *commonLayout = new QGridLayout(common);
    display = new QLineEdit(common);
    display->setReadOnly(true);
    commonLayout->addWidget(display, 0, 0, 1, 4);
    common->setLayout(commonLayout);
}

void Calc::showSimple ()
{
    delete mainWidget;

    mainWidget = new QWidget;
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(common, 0, 0, 1, 1);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    setWindowTitle("Калькулятор (обычный)");
    setMinimumSize(380, 450);
    setMaximumSize(380, 450);
    mode = SIMPLE_MODE;
}

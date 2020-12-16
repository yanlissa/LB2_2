#include "calc.h"

#include <cmath>

void Calc::error()
{
    slot1 = "Ошибка";
    x = 0.0;
    hasNumber = false;
    hasComma = false;
    operation = 0;
    stage = STAGE1;
    updateDisplay();
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double obelus(double a, double b)
{
    return a / b;
}

double stepY(double a, double b)
{
    return pow(a, b);
}

double y_root(double a, double b)
{
    return pow(a, 1/b);
}

double log_y(double a, double b)
{
    return log(a)/log(b);
}

double (*operations[])(double, double) = {
        nullptr,
        add,
        subtract,
        multiply,
        obelus,
        stepY,
        y_root,
        log_y
};


Calc::Calc(QWidget *parent)
    : QMainWindow(parent), mainWidget(nullptr), mainLayout(nullptr)
{
    mainWidget = new QWidget;
    setCentralWidget(mainWidget);

    createCommonWidget();
    createSimpleWidget();
    createEngineeringWidget();
    clear();
    showSimple();
}

Calc::~Calc()
{
    delete common;
    delete simple;
    delete engineering;
}

void Calc::createCommonWidget()
{
    common = new QWidget;
    QGridLayout *commonLayout = new QGridLayout(common);


    // Настройка дисплея
    display = new QLineEdit(common);
    display->setReadOnly(true);
    display->setStyleSheet("QLineEdit{ qproperty-alignment: 'AlignVCenter | AlignRight'; border: 1px solid black; background-color: black; color: rgb(255, 255, 255); font: 45pt 'Ubuntu';}");
    display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    display->setPlaceholderText("0");

    // Настройка кнопок выбора
    simpleRadioButton = new QRadioButton("Обычный");
    engineeringRadioButton = new QRadioButton("Инженерный");
    simpleRadioButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    engineeringRadioButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QString st = "QRadioButton{ color: white; font: 15pt 'Ubuntu'; border-radius: 30px;} QRadioButton:hover{ background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #0F0F0F, stop: 1 #171717);}";
    simpleRadioButton->setStyleSheet(st);
    engineeringRadioButton->setStyleSheet(st);

    simpleRadioButton->setChecked(true);
    connect(simpleRadioButton, SIGNAL(toggled(bool)), SLOT(switchMode()));

    commonLayout->setSpacing(0);
    commonLayout->addWidget(display, 0, 0, 1, 4);
    commonLayout->addWidget(simpleRadioButton, 1, 0, 1, 1);
    commonLayout->addWidget(engineeringRadioButton, 1, 1, 1, 1);
    common->layout()->setContentsMargins(0, 0, 0, 10);

}

void Calc::createSimpleWidget()
{
    simple = new QWidget;
    QGridLayout *simpleLayout = new QGridLayout(simple);

    QPushButton* Button0 = new QPushButton("0");
    QPushButton* Button1 = new QPushButton("1");
    QPushButton* Button2 = new QPushButton("2");
    QPushButton* Button3 = new QPushButton("3");
    QPushButton* Button4 = new QPushButton("4");
    QPushButton* Button5 = new QPushButton("5");
    QPushButton* Button6 = new QPushButton("6");
    QPushButton* Button7 = new QPushButton("7");
    QPushButton* Button8 = new QPushButton("8");
    QPushButton* Button9 = new QPushButton("9");
    QPushButton* ButtonComma = new QPushButton(",");
    QPushButton* ButtonClear = new QPushButton("AC");
    QPushButton* ButtonChange = new QPushButton("+/-");
    QPushButton* ButtonProcent = new QPushButton("%");
    QPushButton* ButtonObelus = new QPushButton("÷");
    QPushButton* ButtonIncrease = new QPushButton("×");
    QPushButton* ButtonMinus = new QPushButton("-");
    QPushButton* ButtonPluz = new QPushButton("+");
    QPushButton* ButtonEqual = new QPushButton("=");

    // Предпочтительные размеры (чтоб красивое окошко было)
    Button0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    Button9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonComma->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonClear->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonChange->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonProcent->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonObelus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonIncrease->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonMinus->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonPluz->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonEqual->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    // Создаем три стиля кнопок: для чисел, верхних и боковых кнопок
    QString St1 = "QPushButton {background-color: #404040; color: white; border: 1px solid black; font: 15pt 'Ubuntu'; border-radius: 30px;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #8c8c8c, stop: 1 #a6a6a6);}";
    QString St2 = "QPushButton {background-color: #b3b3b3; border: 1px solid black; font: 15pt 'Ubuntu'; border-radius: 30px;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #d9d9d9, stop: 1 #e6e6e6);}";
    QString St3 = "QPushButton {background-color: #ffa600; color: white; border: 1px solid black; font: 15pt 'Ubuntu'; border-radius: 30px;} QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffc966, stop: 1 #ffd280);}";

    // Присваиваем каждой кнопке свой стиль
    Button0->setStyleSheet(St1);
    Button1->setStyleSheet(St1);
    Button2->setStyleSheet(St1);
    Button3->setStyleSheet(St1);
    Button4->setStyleSheet(St1);
    Button5->setStyleSheet(St1);
    Button6->setStyleSheet(St1);
    Button7->setStyleSheet(St1);
    Button8->setStyleSheet(St1);
    Button9->setStyleSheet(St1);
    ButtonComma->setStyleSheet(St1);
    ButtonClear->setStyleSheet(St2);
    ButtonChange->setStyleSheet(St2);
    ButtonProcent->setStyleSheet(St2);
    ButtonObelus->setStyleSheet(St3);
    ButtonIncrease->setStyleSheet(St3);
    ButtonMinus->setStyleSheet(St3);
    ButtonPluz->setStyleSheet(St3);
    ButtonEqual->setStyleSheet(St3);

    // Расстояние между кнопками 5px
    simpleLayout->setSpacing(5);

    // Устанавливаем компановщик во весь виджет с отступом по 10px справа, слева и снизу
    simpleLayout->setContentsMargins(10, 0, 10, 10);

    // Добавляем кнопки в компановщик
    simpleLayout->addWidget(ButtonClear, 0, 0, 1, 1);
    simpleLayout->addWidget(ButtonChange, 0, 1, 1, 1);
    simpleLayout->addWidget(ButtonProcent, 0, 2, 1, 1);
    simpleLayout->addWidget(ButtonObelus, 0, 3, 1, 1);
    simpleLayout->addWidget(Button7, 1, 0, 1, 1);
    simpleLayout->addWidget(Button8, 1, 1, 1, 1);
    simpleLayout->addWidget(Button9, 1, 2, 1, 1);
    simpleLayout->addWidget(ButtonIncrease, 1, 3, 1, 1);
    simpleLayout->addWidget(Button4, 2, 0, 1, 1);
    simpleLayout->addWidget(Button5, 2, 1, 1, 1);
    simpleLayout->addWidget(Button6, 2, 2, 1, 1);
    simpleLayout->addWidget(ButtonMinus, 2, 3, 1, 1);
    simpleLayout->addWidget(Button1, 3, 0, 1, 1);
    simpleLayout->addWidget(Button2, 3, 1, 1, 1);
    simpleLayout->addWidget(Button3, 3, 2, 1, 1);
    simpleLayout->addWidget(ButtonPluz, 3, 3, 1, 1);
    simpleLayout->addWidget(Button0, 4, 0, 1, 2);
    simpleLayout->addWidget(ButtonComma, 4, 2, 1, 1);
    simpleLayout->addWidget(ButtonEqual, 4, 3, 1, 1);

    // Добавляет компановщик в виджет простого калькулятора
    simple->setLayout(simpleLayout);

    // Connect
    connect(ButtonClear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(Button0, SIGNAL(clicked()), this, SLOT(zeroClicked()));
    connect(Button1, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button2, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button3, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button4, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button5, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button6, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button7, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button8, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(Button9, SIGNAL(clicked()), this, SLOT(numberClicked()));
    connect(ButtonComma, SIGNAL(clicked()), this, SLOT(commaClicked()));
    connect(ButtonEqual, SIGNAL(clicked()), this, SLOT(equalClicked()));
    connect(ButtonPluz, SIGNAL(clicked()), this, SLOT(pluzClicked()));
    connect(ButtonMinus, SIGNAL(clicked()), this, SLOT(minusClicked()));
    connect(ButtonIncrease, SIGNAL(clicked()), this, SLOT(increaseClicked()));
    connect(ButtonObelus, SIGNAL(clicked()), this, SLOT(obelusClicked()));
    connect(ButtonChange, SIGNAL(clicked()), this, SLOT(changeClicked()));
    connect(ButtonProcent, SIGNAL(clicked()), this, SLOT(procentClicked()));
}

void Calc::createEngineeringWidget()
{
    engineering = new QWidget;
    QGridLayout *engineeringLayout = new QGridLayout(engineering);

    QPushButton* ButtonStep2 = new QPushButton("x²");
    QPushButton* ButtonStep3 = new QPushButton("x³");
    QPushButton* ButtonStepY = new QPushButton("xʸ");
    QPushButton* ButtonStepE = new QPushButton("eˣ");
    QPushButton* ButtonStep10 = new QPushButton("10ˣ");
    QPushButton* ButtonInvert = new QPushButton("¹⁄ₓ");
    QPushButton* ButtonSqrt = new QPushButton("√x");
    QPushButton* ButtonCbrt = new QPushButton("³√x");
    QPushButton* ButtonYrt = new QPushButton("ʸ√x");
    QPushButton* ButtonFactorial = new QPushButton("x!");
    QPushButton* ButtonLn = new QPushButton("ln");
    QPushButton* ButtonLog = new QPushButton("log");
    QPushButton* ButtonLogY = new QPushButton("logᵧx");
    QPushButton* ButtonExpon = new QPushButton("e");
    QPushButton* ButtonPi = new QPushButton("π");
    QPushButton* ButtonSin = new QPushButton("sin");
    QPushButton* ButtonCos = new QPushButton("cos");
    QPushButton* ButtonTg = new QPushButton("tg");
    QPushButton* ButtonCtg = new QPushButton("ctg");
    QPushButton* ButtonSec = new QPushButton("sec");
    QPushButton* ButtonSh = new QPushButton("sh");
    QPushButton* ButtonCh = new QPushButton("ch");
    QPushButton* ButtonTh = new QPushButton("th");
    QPushButton* ButtonCth = new QPushButton("cth");
    QPushButton* ButtonCsc = new QPushButton("csc");

    // Предпочтительные размеры
    ButtonStep2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonStep3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonStepY->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonStepE->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonStep10->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonInvert->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonSqrt->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonCbrt->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonYrt->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonFactorial->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonLn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonLog->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonLogY->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonExpon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonPi->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonSin->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonCos->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonTg->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonCtg->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonSec->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonSh->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonCh->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonTh->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonCth->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ButtonCsc->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    // Стиль кнопок
    QString St = "QPushButton{ background: #262626; color: white; font: 15pt 'Ubuntu'; border-radius: 30px; border: 1px solid black;} QPushButton:pressed{ background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #5E5E5E, stop: 1 #696969);}";

    // Присваиваем стиль
    ButtonStep2->setStyleSheet(St);
    ButtonStep3->setStyleSheet(St);
    ButtonStepY->setStyleSheet(St);
    ButtonStepE->setStyleSheet(St);
    ButtonStep10->setStyleSheet(St);
    ButtonInvert->setStyleSheet(St);
    ButtonSqrt->setStyleSheet(St);
    ButtonCbrt->setStyleSheet(St);
    ButtonYrt->setStyleSheet(St);
    ButtonFactorial->setStyleSheet(St);
    ButtonLn->setStyleSheet(St);
    ButtonLog->setStyleSheet(St);
    ButtonLogY->setStyleSheet(St);
    ButtonExpon->setStyleSheet(St);
    ButtonPi->setStyleSheet(St);
    ButtonSin->setStyleSheet(St);
    ButtonCos->setStyleSheet(St);
    ButtonTg->setStyleSheet(St);
    ButtonCtg->setStyleSheet(St);
    ButtonSec->setStyleSheet(St);
    ButtonSh->setStyleSheet(St);
    ButtonCh->setStyleSheet(St);
    ButtonTh->setStyleSheet(St);
    ButtonCth->setStyleSheet(St);
    ButtonCsc->setStyleSheet(St);

    // Расстояние между кнопками 5px
    engineeringLayout->setSpacing(5);

    // Отступ снизу, слева и справа по 10px
    engineeringLayout->setContentsMargins(10, 0, 10, 10);

    // Добавляем кнопки в компановщик
    engineeringLayout->addWidget(ButtonStep2, 0, 0, 1, 1);
    engineeringLayout->addWidget(ButtonStep3, 0, 1, 1, 1);
    engineeringLayout->addWidget(ButtonStepY, 0, 2, 1, 1);
    engineeringLayout->addWidget(ButtonStepE, 0, 3, 1, 1);
    engineeringLayout->addWidget(ButtonStep10, 0, 4, 1, 1);
    engineeringLayout->addWidget(ButtonInvert, 1, 0, 1, 1);
    engineeringLayout->addWidget(ButtonSqrt, 1, 1, 1, 1);
    engineeringLayout->addWidget(ButtonCbrt, 1, 2, 1, 1);
    engineeringLayout->addWidget(ButtonYrt, 1, 3, 1, 1);
    engineeringLayout->addWidget(ButtonFactorial, 1, 4, 1, 1);
    engineeringLayout->addWidget(ButtonLn, 2, 0, 1, 1);
    engineeringLayout->addWidget(ButtonLog, 2, 1, 1, 1);
    engineeringLayout->addWidget(ButtonLogY, 2, 2, 1, 1);
    engineeringLayout->addWidget(ButtonExpon, 2, 3, 1, 1);
    engineeringLayout->addWidget(ButtonPi, 2, 4, 1, 1);
    engineeringLayout->addWidget(ButtonSin, 3, 0, 1, 1);
    engineeringLayout->addWidget(ButtonCos, 3, 1, 1, 1);
    engineeringLayout->addWidget(ButtonTg, 3, 2, 1, 1);
    engineeringLayout->addWidget(ButtonCtg, 3, 3, 1, 1);
    engineeringLayout->addWidget(ButtonSec, 3, 4, 1, 1);
    engineeringLayout->addWidget(ButtonSh, 4, 0, 1, 1);
    engineeringLayout->addWidget(ButtonCh, 4, 1, 1, 1);
    engineeringLayout->addWidget(ButtonTh, 4, 2, 1, 1);
    engineeringLayout->addWidget(ButtonCth, 4, 3, 1, 1);
    engineeringLayout->addWidget(ButtonCsc, 4, 4, 1, 1);

    // Добавляем конпановщик в виджет
    engineering->setLayout(engineeringLayout);

    // Connect
    connect(ButtonStepY, SIGNAL(clicked()), this, SLOT(stepYClicked()));
    connect(ButtonYrt, SIGNAL(clicked()), this, SLOT(yrtClicked()));
    connect(ButtonLogY, SIGNAL(clicked()), this, SLOT(logYClicked()));
    connect(ButtonStep2, SIGNAL(clicked()), this, SLOT(step2Clicked()));
    connect(ButtonStep3, SIGNAL(clicked()), this, SLOT(step3Clicked()));
    connect(ButtonStepE, SIGNAL(clicked()), this, SLOT(stepEClicked()));
    connect(ButtonStep10, SIGNAL(clicked()), this, SLOT(step10Clicked()));
}

void Calc::showSimple ()
{
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);

    setWindowTitle("Калькулятор (обычный)");
    setMinimumSize(380, 525);
    setMaximumSize(380, 525);

    mainLayout->addWidget(common, 0, 0, 3, 1);
    mainLayout->addWidget(simple, 4, 0, 7, 1);
    mainWidget->setLayout(mainLayout);
    mainWidget->setStyleSheet("background-color: black;");

    mainWidget->layout()->setContentsMargins(0, 0, 0, 0);
}

void Calc::showEngineering ()
{
    mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);

    setWindowTitle("Калькулятор (инженерный)");
    setMinimumSize(855, 525);
    setMaximumSize(855, 525);

    mainLayout->addWidget(common, 0, 0, 3, 9);
    mainLayout->addWidget(engineering, 4, 0, 7, 5);
    mainLayout->addWidget(simple, 4, 5, 7, 4);
    mainWidget->setLayout(mainLayout);
    mainWidget->setStyleSheet("background-color: black;");

    mainWidget->layout()->setContentsMargins(0, 0, 0, 0);
}

void Calc::switchMode()
{
    common->setParent(this);
    simple->setParent(this);
    engineering->setParent(this);
    delete mainLayout;
    if (!simpleRadioButton->isChecked()) {
        showEngineering();
    }
    else {
        showSimple();
    }
}

void Calc::clear()
{
    slot1 = "0";
    x = 0.0;
    hasNumber = false;
    hasComma = false;
    operation = 0;
    stage = STAGE1;
    updateDisplay();
}

void Calc::updateDisplay()
{
    display->setText(slot1);
}

void Calc::zeroClicked()
{
    if (!hasNumber) {
        slot1 = "0";
        return updateDisplay();
    }
    if (slot1.size() > 10) {
        return;
    }

    slot1 += "0";
    updateDisplay();
}

void Calc::numberClicked()
{
    if (!hasNumber) {
        slot1 = "";
        hasNumber = true;
    }
    if (slot1.size() > 10) {
        return;
    }
    slot1 += ((QPushButton*)sender())->text();
    updateDisplay();
}

void Calc::commaClicked()
{
    if (hasComma) {
        return;
    }
    if (slot1.size() > 10) {
        return;
    }
    if (!hasNumber) {
        hasNumber = true;
    }
    slot1 += ".";
    hasComma = true;
    updateDisplay();
}

void Calc::equalClicked()
{
    if (stage != STAGE2) {
        return;
    }
    double y = slot1.toDouble();
    try {
        double res = operations[operation](x, y);
        if (res != res || res >= std::numeric_limits<double>::max() || res <= -std::numeric_limits<double>::max()) {
            return error();
        }
        slot1 = QString("%1").arg(res, 0, 'g', 6);
        hasComma = false;
        hasNumber = false;
        updateDisplay();
    } catch (...) {
        error();
    }
}

void Calc::binaryClicked()
{
    if (stage == STAGE2) {
        equalClicked();
    } else {
        hasComma = false;
        hasNumber = false;
        stage = STAGE2;
    }
    x = slot1.toDouble();
    updateDisplay();
}

void Calc::pluzClicked()
{
    binaryClicked();
    operation = OPERATION_PLUZ;
}

void Calc::minusClicked()
{
    binaryClicked();
    operation = OPERATION_MINUS;
}

void Calc::increaseClicked()
{
    binaryClicked();
    operation = OPERATION_INCREASE;
}

void Calc::obelusClicked()
{
    binaryClicked();
    operation = OPERATION_OBELUS;
}

void Calc::stepYClicked()
{
    binaryClicked();
    operation = OPERATION_STEP_Y;
}

void Calc::yrtClicked()
{
    binaryClicked();
    operation = OPERATION_Y_ROOT;
}

void Calc::logYClicked()
{
    binaryClicked();
    operation = OPERATION_LOG_Y;
}

void Calc::changeClicked()
{
    if (slot1[0] == '-') {
        slot1.remove(0,1);
    } else {
        slot1 = "-" + slot1;
    }
    updateDisplay();
}

void Calc::procentClicked()
{
    double y = slot1.toDouble();
    y /= 100;
    slot1 = QString::number(y);
    updateDisplay();
}

void Calc::step2Clicked()
{
    double y = slot1.toDouble();
    y *= y;
    slot1 = QString::number(y);
    updateDisplay();
}

void Calc::step3Clicked()
{
    double y = slot1.toDouble();
    y *= y*y;
    slot1 = QString::number(y);
    updateDisplay();
}

void Calc::stepEClicked()
{
    double y = slot1.toDouble();
    y = exp(y);
    slot1 = QString::number(y);
    updateDisplay();
}

void Calc::step10Clicked()
{
    double y = slot1.toDouble();
    y = pow(10, y);
    slot1 = QString::number(y);
    updateDisplay();
}

#include "calc.h"

Calc::Calc(QWidget *parent)
    : QMainWindow(parent), mainWidget(nullptr)
{
    createCommonWidget();
    createSimpleWidget();
    //createEngineeringWidget();
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


    // Настройка дисплея
    display = new QLineEdit(common);
    display->setReadOnly(true);
    display->setStyleSheet("QLineEdit{ qproperty-alignment: 'AlignVCenter | AlignRight'; border: 1px solid black; background-color: black; color: white; font: 45pt 'Ubuntu';}");
    display->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    display->setPlaceholderText("0");

    // Временно
    commonLayout->setSpacing(0);

    commonLayout->addWidget(display, 0, 0, 1, 4);
    common->layout()->setContentsMargins(0, 0, 0, 0);

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

    // Расстояние между кнопками нет
    simpleLayout->setSpacing(5);

    // Устанавливаем компановщик во весь виджет
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
}

void Calc::createEngineeringWidget()
{
    engineering = new QWidget;
    QGridLayout *engineeringLayout = new QGridLayout(engineering);

    QPushButton* Button;

    engineeringLayout->setSpacing(0);

    engineering->setLayout(engineeringLayout);
}

void Calc::showSimple ()
{
    delete mainWidget;

    mainWidget = new QWidget;
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->addWidget(common, 0, 0, 2, 1);


    setWindowTitle("Калькулятор (обычный)");
    setMinimumSize(380, 450);
    setMaximumSize(380, 450);
    mode = SIMPLE_MODE;

    mainLayout->addWidget(simple, 3, 0, 7, 1);
    mainWidget->setLayout(mainLayout);
    mainWidget->setStyleSheet("background-color: black;");

    setCentralWidget(mainWidget);
    mainWidget->layout()->setContentsMargins(0, 0, 0, 0);
}

void Calc::showEngineering ()
{

}

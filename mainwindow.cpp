#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtMath>
#include <cmath>
#include <qstring.h>
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Basic Calculator
void MainWindow::calculate(QString basicOperator)
{
    // variable
    double num1, num2, ans;

    // input and convert to double
    num1 = ui->number1Input->text().toDouble();
    num2 = ui->number2Input->text().toDouble();

    // calculate
    ans = 0;

    // basic calculator
    if (basicOperator == "+")
    {
        ans = num1 + num2;
    }
    else if (basicOperator == "-")
    {
        ans = num1 - num2;
    }
    else if (basicOperator == "*")
    {
        ans = num1 * num2;
    }
    else if (basicOperator == "/")
    {
        ans = num1 / num2;
    }
    else if (basicOperator == "√")
    {
        ans = sqrt(num1);
    }
    else if (basicOperator == "%")
    {
        ans = fmod(num1, num2);
    }
    // convert to string
    QString str;
    if (ans == static_cast<int>(ans))
    {
        str = QString::number(ans, 'f', 0);
    }
    else
    {
        str = QString::number(ans, 'g', 15);
    }

    // display
    ui->displayAnswer->setText(str);
}

void MainWindow::on_plusButton_clicked()
{
    calculate("+");
}

void MainWindow::on_minusButton_clicked()
{
    calculate("-");
}

void MainWindow::on_mulButton_clicked()
{
    calculate("*");
}

void MainWindow::on_divButton_clicked()
{
    calculate("/");
}

void MainWindow::on_sqrtButton_clicked()
{
    calculate("√");
}

void MainWindow::on_modButton_clicked()
{
    calculate("%");
}

// Trigonometric Calculator
void MainWindow::calculateTrigonometricFunction(QString function)
{
    double num, deg, ans;
    num = ui->tri_input->text().toDouble();
    deg = (num * M_PI) / 180;

    if (function == "sin")
    {
        ans = sin(deg);
    }
    else if (function == "cos")
    {
        if(abs(num - 90) < 1e-10 || abs(num + 90) < 1e-10) {
            ui->displayAnswer->setText("0");
            return;
        }
        ans = cos(deg);
    }
    else if (function == "tan")
    {
        if(abs(num - 90) < 1e-10 || abs(num + 90) < 1e-10) {
            ui->displayAnswer->setText("Math Error");
            return;
        }
        ans = tan(deg);
    }
    else if (function == "sec")
    {
        if(abs(num - 90) < 1e-10 || abs(num + 90) < 1e-10) {
            ui->displayAnswer->setText("Math Error");
            return;
        }
        ans = 1 / cos(deg);
    }
    else if (function == "cosec")
    {
        ans = 1 / sin(deg);
    }
    else if (function == "cot")
    {
        ans = 1 / tan(deg);
    }
    else if (function == "sin-1")
    {
        ans = asin(num) * (180 / M_PI);
    }
    else if (function == "cos-1")
    {
        ans = acos(num) * (180 / M_PI);
    }
    else if (function == "tan-1")
    {
        ans = atan(num) * (180 / M_PI);
    }
    else
    {
        return;
    }

    if(abs(ans) < 1e-10) {
        ans = 0;
    }

    QString str;
    str.setNum(ans, 'g', 10);
    ui->displayAnswer->setText(str);
}

void MainWindow::on_sinButton_clicked()
{
    calculateTrigonometricFunction("sin");
}

void MainWindow::on_cosButton_clicked()
{
    calculateTrigonometricFunction("cos");
}

void MainWindow::on_tanButton_clicked()
{
    calculateTrigonometricFunction("tan");
}

void MainWindow::on_secButton_clicked()
{
    calculateTrigonometricFunction("sec");
}

void MainWindow::on_cosecButton_clicked()
{
    calculateTrigonometricFunction("cosec");
}

void MainWindow::on_cotButton_clicked()
{
    calculateTrigonometricFunction("cot");
}

void MainWindow::on_asinButton_clicked()
{
    calculateTrigonometricFunction("sin-1");
}

void MainWindow::on_acosButton_clicked()
{
    calculateTrigonometricFunction("cos-1");
}

void MainWindow::on_atanButton_clicked()
{
    calculateTrigonometricFunction("tan-1");
}

// Menu Buttons
void MainWindow::on_actionExit_triggered()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::on_actionHelp_Content_triggered()
{
    QMessageBox help;
    help.setWindowTitle("Help");
    help.setText("-----------Basic Calculator----------\n"
                 "1. Enter 2 numbers in 2 number text boxes\n"
                 "2. Press on any operator.\n"
                 "3. See result in the answer box.\n\n"
                 "-------Trigonometric Calculator-------\n"
                 "1. Enter numbers in input box.\n"
                 "2. Press on any trigonometric operator.\n"
                 "3. See result in the answer box.\n");
    help.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox about;
    about.setWindowTitle("About Simple Calculator");
    about.setText("Calculator\n"
                  "Version: 2.2.5\n"
                  "Developer: Abdullah Al Shaimon\n"
                  "Github: https://github.com/al-shaimon/\n"
                  "Email: alshaimon152@gmail.com");
    about.exec();
}

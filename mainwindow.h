#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_mulButton_clicked();

    void on_divButton_clicked();

    void on_actionExit_triggered();

    void on_actionHelp_Content_triggered();

    void on_actionAbout_triggered();


    void on_sinButton_clicked();

    void on_cosButton_clicked();

    void on_tanButton_clicked();

    void on_cotButton_clicked();

    void on_secButton_clicked();

    void on_cosecButton_clicked();

    void on_asinButton_clicked();

    void on_acosButton_clicked();

    void on_atanButton_clicked();

    void on_sqrtButton_clicked();

    void on_modButton_clicked();

private:
    Ui::MainWindow *ui;
    void calculate(QString basicOperator);
private:
    void calculateTrigonometricFunction(QString function);    
};

#endif // MAINWINDOW_H

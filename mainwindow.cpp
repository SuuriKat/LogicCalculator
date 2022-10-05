#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

bool result;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    bool boolFirstOperand = ui->firstOperand->currentIndex();
//    bool boolSecondOperand = ui->secondOperand->currentIndex();
//    QString operation = ui->operation->currentText();

//    QPalette palette(this->palette());

//    if (operation == "КОНЪЮНКЦИЯ")
//    {
//        result = boolFirstOperand && boolSecondOperand;
//    }
//    else if (operation == "ДИЗЪЮНКЦИЯ")
//    {
//        result = boolFirstOperand || boolSecondOperand;
//    }
//    else if (operation == "ЭКВИВАЛЕНЦИЯ")
//    {
//        result = boolFirstOperand == boolSecondOperand;
//    }
//    else if (operation == "ИСКЛЮЧАЮЩЕЕ ИЛИ")
//    {
//        result = boolFirstOperand != boolSecondOperand;
//    }
//    else if (operation == "ИМПЛИКАЦИЯ")
//    {
//        result = !boolFirstOperand + boolSecondOperand;
//    }
//    else if (operation == "ИНВЕРСИЯ")
//    {
//        result = !boolSecondOperand;
//    }
//    else if (operation == "ШТРИХ ШЕФФЕРА")
//    {
//        result = boolFirstOperand and !boolSecondOperand;
//    }
//    else if (operation == "СТРЕЛКА ПИРСА")
//    {
//        result = boolFirstOperand or !boolSecondOperand;
//    }
//    else
//    {
//        result = false;
//        QMessageBox::warning(this, "", "Случился баг, такого быть не должно, выберите операцию");
//    }

//    if (result)
//    {
//        palette.setColor(QPalette::Background, Qt::green);
//        this->setPalette(palette);
//    }
//    else
//    {
//        palette.setColor(QPalette::Background, Qt::red);
//        this->setPalette(palette);
//    }
}

void MainWindow::on_operation_currentIndexChanged(int index)
{
    bool boolFirstOperand = ui->firstOperand->currentIndex();
    bool boolSecondOperand = ui->secondOperand->currentIndex();
    QString operation = ui->operation->currentText();

    QPalette palette(this->palette());

    if (index == 0)
    {
        result = boolFirstOperand && boolSecondOperand;
    }
    else if (index == 1)
    {
        result = boolFirstOperand || boolSecondOperand;
    }
    else if (index == 2)
    {
        result = boolFirstOperand == boolSecondOperand;
    }
    else if (index == 3)
    {
        result = boolFirstOperand != boolSecondOperand;
    }
    else if (index == 4)
    {
        result = !boolFirstOperand + boolSecondOperand;
    }
    else if (index == 5)
    {
        result = !boolSecondOperand;
    }
    else if (index == 6)
    {
        result = !(boolFirstOperand and boolSecondOperand);
    }
    else if (index == 7)
    {
        result = !(boolFirstOperand or boolSecondOperand);
    }
    else
    {
        result = false;
        QMessageBox::warning(this, "", "Случился баг, такого быть не должно, выберите операцию");
    }

        if (result)
        {
            palette.setColor(QPalette::Background, Qt::green);
            this->setPalette(palette);
        }
        else
        {
            palette.setColor(QPalette::Background, Qt::red);
            this->setPalette(palette);
        }

    if (index == 5)
    {
        ui->firstOperand->setVisible(false);
    }
    else
    {
        ui->firstOperand->setVisible(true);
    }
}

void MainWindow::on_firstOperand_currentIndexChanged(int index)
{
    int operationIndex = ui->operation->currentIndex();
    MainWindow::on_operation_currentIndexChanged(operationIndex);
}

void MainWindow::on_secondOperand_currentIndexChanged(int index)
{
    int operationIndex = ui->operation->currentIndex();
    MainWindow::on_operation_currentIndexChanged(operationIndex);
}

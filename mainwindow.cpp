#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vector->append(5);
    vector->append(5);
    red = new RedNeuronal(vector,2);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete vector;
    delete red;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    float esperado1 = ui->textEdit_3->toPlainText().toFloat();
    float esperado2 = ui->textEdit_4->toPlainText().toFloat();
    float esperado3 = ui->textEdit_5->toPlainText().toFloat();
    float resultado1 =  ui->textEdit_10->toPlainText().toFloat();
    float resultado2 =  ui->textEdit_10->toPlainText().toFloat();
    float resultado3 =  ui->textEdit_10->toPlainText().toFloat();
    float error1 = red->CalcularError(resultado1,esperado1);
    float error2 = red->CalcularError(resultado2,esperado2);
    float error3 = red->CalcularError(resultado3,esperado3);
    red->CorregirCapas(error1);
    red->CorregirCapas(error2);
    red->CorregirCapas(error3);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_2->setText(red->MostrarRed());
}

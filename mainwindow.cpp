#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    vector->append(10);
    vector->append(3);
    vector->append(4);
    vector->append(4);
    vector->append(3);
    red = new RedNeuronal(vector,5);
    ui->setupUi(this);
    ui->textEdit_9->setReadOnly(true);
    ui->textEdit_10->setReadOnly(true);
    ui->textEdit_12->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete vector;
    delete red;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double esperado1 = ui->textEdit_3->toPlainText().toDouble();
    double esperado2 = ui->textEdit_4->toPlainText().toDouble();
    double esperado3 = ui->textEdit_5->toPlainText().toDouble();
    double resultado1 =  ui->textEdit_10->toPlainText().toDouble();
    double resultado2 =  ui->textEdit_10->toPlainText().toDouble();
    double resultado3 =  ui->textEdit_10->toPlainText().toDouble();
    double error1 = red->CalcularError(resultado1,esperado1);
    double error2 = red->CalcularError(resultado2,esperado2);
    double error3 = red->CalcularError(resultado3,esperado3);
    red->CorregirCapas(error1);
    red->CorregirCapas(error2);
    red->CorregirCapas(error3);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_2->setText(red->MostrarRed());
}

void MainWindow::on_pushButton_2_clicked()
{
    Texto *t = new Texto(ui->textEdit->toPlainText());
    QString rep="";
    QVector<int>* vec = t->EncontrarRepetidas();
    std::sort(vec->begin(),vec->end(),std::greater<int>());
    red->Entrenar(vec);
    QVector<double>* out = red->Output();
    for(int i = 0; i < out->size(); i++){
        if(i == 0){
            ui->textEdit_9->setText(QString::number(out->at(i)));
        }else if(i == 1){
            ui->textEdit_10->setText(QString::number(out->at(i)));
        }else if(i == 2){
            ui->textEdit_12->setText(QString::number(out->at(i)));
        }

    }
    /*for(int i = 0; i < vec->size() && i < 10; i++){

        red->Entrenar()
        //rep.append(QString::number(vec->at(i)));
        //rep.append(" / ");
    }
    ui->textEdit_2->setText(rep);*/
}

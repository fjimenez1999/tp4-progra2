#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "redneuronal.h"
#include <QVector>
#include "texto.h"
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
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVector<int>* vector = new QVector<int>;
    RedNeuronal* red;
};

#endif // MAINWINDOW_H

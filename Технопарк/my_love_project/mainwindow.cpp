#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "catform.h"
#include "regform.h"
#include "planwindow.h"
#include <iostream>

MainWindow::MainWindow(int x, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// основной вход
void MainWindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    hide();

    planWindow plan;
    plan.setModal(true);
    plan.exec();
}

// форма регистрации
void MainWindow::on_pushButton_2_clicked()
{
    regform reg;
    reg.setModal(true);
    reg.exec();
}

// форма с котиками
void MainWindow::on_pushButton_3_clicked()
{
    catform cats;
    cats.setModal(true);
    cats.exec();
}

#include "regform.h"
#include "ui_regform.h"
#include <QString>
#include <QFile>
#include <QMessageBox>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

regform::regform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regform)
{
    ui->setupUi(this);
}

regform::~regform()
{
    delete ui;
}

// функция, которая обрабатывает введенные значения
// правда, записывать что-либо в обычный файлик она захотела, но не туда, куда нужно
void regform::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString mail = ui->mail->text();
    QString password = ui->password->text();
    QString password_again = ui->password_again->text();

    if(QString::compare(password, password_again, Qt::CaseInsensitive) == 0)
    {
        // записать на плюсах
//        QFile file("./db.txt");
//        if (file.open(QIODevice::Append)) {
//           std::cout <<"i ti";
//           file.write(name.toUtf8());
//        }
//        else
//        {
//            std::cout <<"error with open file";
//        }
//        file.close();


        // записать на сях
        FILE *f = fopen("../db.txt", "a");
        if(!f)
        {
            std::cout << "error with open file\n";
            return ;
        }
        fprintf(f, "%s %s %s\n", name.toLatin1().data(), mail.toLatin1().data(), password.toLatin1().data());
        fclose(f);
    }

    QWidget::close();
}

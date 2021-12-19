#include "create_new_task.h"
#include "ui_create_new_task.h"
#include <iostream>

create_new_task::create_new_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::create_new_task)
{
    ui->setupUi(this);
}

create_new_task::~create_new_task()
{
    delete ui;
}

void create_new_task::on_create_clicked()
{
    QString text_of_task = ui->text_of_new_task->toPlainText();

    std::cout << "Text " << text_of_task.toLatin1().data();

    QWidget::close();
}

#include "catform.h"
#include "ui_catform.h"
#include <QPixmap>

#include <string.h>

catform::catform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::catform)
{
    ui->setupUi(this);
    QPixmap pix(":/img/cats/2.jpg");
    int w = ui->image->width();
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

catform::~catform()
{
    delete ui;
}

void catform::on_pushButton_clicked()
{
    QWidget::close();
}

#include "edittask.h"
#include "ui_edittask.h"

edittask::edittask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edittask)
{
    ui->setupUi(this);
}

edittask::~edittask()
{
    delete ui;
}

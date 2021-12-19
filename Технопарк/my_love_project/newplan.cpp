#include "newplan.h"
#include "ui_newplan.h"

newplan::newplan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newplan)
{
    ui->setupUi(this);
}

newplan::~newplan()
{
    delete ui;
}

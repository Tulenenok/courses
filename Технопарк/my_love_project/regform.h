#ifndef REGFORM_H
#define REGFORM_H

#include <QDialog>

namespace Ui {
class regform;
}

class regform : public QDialog
{
    Q_OBJECT

public:
    explicit regform(QWidget *parent = nullptr);
    ~regform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::regform *ui;
};

#endif // REGFORM_H

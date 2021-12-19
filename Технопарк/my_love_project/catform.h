#ifndef CATFORM_H
#define CATFORM_H

#include <QDialog>

namespace Ui {
class catform;
}

class catform : public QDialog
{
    Q_OBJECT

public:
    explicit catform(QWidget *parent = nullptr);
    ~catform();

    int changeCat();

private slots:
    void on_pushButton_clicked();

private:
    Ui::catform *ui;
};

#endif // CATFORM_H

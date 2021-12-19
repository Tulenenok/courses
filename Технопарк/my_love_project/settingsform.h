#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QDialog>

namespace Ui {
class settingsForm;
}

class settingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit settingsForm(QWidget *parent = nullptr);
    ~settingsForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::settingsForm *ui;

    QString user_name;
    QString user_password;
};

#endif // SETTINGSFORM_H

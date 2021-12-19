#ifndef CREATE_NEW_TASK_H
#define CREATE_NEW_TASK_H

#include <QDialog>

namespace Ui {
class create_new_task;
}

class create_new_task : public QDialog
{
    Q_OBJECT

public:
    explicit create_new_task(QWidget *parent = nullptr);
    ~create_new_task();

private slots:
    void on_create_clicked();

private:
    Ui::create_new_task *ui;
};

#endif // CREATE_NEW_TASK_H

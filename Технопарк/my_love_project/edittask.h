#ifndef EDITTASK_H
#define EDITTASK_H

#include <QDialog>

namespace Ui {
class edittask;
}

class edittask : public QDialog
{
    Q_OBJECT

public:
    explicit edittask(QWidget *parent = nullptr);
    ~edittask();

private:
    Ui::edittask *ui;
};

#endif // EDITTASK_H

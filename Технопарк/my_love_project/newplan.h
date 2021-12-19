#ifndef NEWPLAN_H
#define NEWPLAN_H

#include <QWidget>

namespace Ui {
class newplan;
}

class newplan : public QWidget
{
    Q_OBJECT

public:
    explicit newplan(QWidget *parent = nullptr);
    ~newplan();

private:
    Ui::newplan *ui;
};

#endif // NEWPLAN_H

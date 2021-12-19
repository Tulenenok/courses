#ifndef PLANWINDOW_H
#define PLANWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class planWindow;
}

class planWindow : public QDialog
{
    Q_OBJECT

public:
    explicit planWindow(QWidget *parent = nullptr);
 //   explicit planWindow(QString name, QWidget *parent = nullptr);
    ~planWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_settingsButton_clicked();

    void on_create_clicked();

    void on_see_cats_clicked();

    void on_done_1_clicked();

    void on_done_2_clicked();

    void on_done_3_clicked();

    void on_edit_1_clicked();
    void on_edit_2_clicked();
    void on_edit_3_clicked();

private:
    Ui::planWindow *ui;

    QString user_name;
    QString *tasks;

    int count_tasks = 3;

    void setPhotos();
    void uploadDataTasks();
    void fillTasks();
};

#endif // PLANWINDOW_H

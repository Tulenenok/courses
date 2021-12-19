#include "planwindow.h"
#include "ui_planwindow.h"
#include "settingsform.h"
#include "create_new_task.h"
#include "catform.h"
#include "edittask.h"

#include <QPixmap>
#include <QIcon>
#include <iostream>

void planWindow::setPhotos()
{
    QPixmap heart_pix(":/img/heart.png");
    int w = ui->heart->width();
    int h = ui->heart->height();

    ui->heart->setPixmap(heart_pix.scaled(w, h, Qt::KeepAspectRatio));

    QPixmap profile_pix(":/img/cats/7.png");
    ui->profileImg->setPixmap(profile_pix.scaled(ui->profileImg->width(), ui->profileImg->height(), Qt::KeepAspectRatio));

   // QPixmap settings_pix(":/img/cats/7.png");
    ui->settingsButton->setIcon(QIcon(":/img/settings.png"));
    ui->settingsButton->setIconSize(QSize(45, 45));

//    QPixmap cat_pix(":/img/cats/10.jpg");
//    ui->cat->setPixmap(cat_pix.scaled(ui->cat->width(), ui->cat->height(), Qt::KeepAspectRatio));
}

// функция для загрузки данных о задачах
void planWindow::uploadDataTasks()
{
    planWindow::tasks = new QString[planWindow::count_tasks];

    tasks[0] = "Сделать технопарк";
    tasks[1] = "Почесать кота";
    tasks[2] = "Поспать";
}

void planWindow::fillTasks()
{
    ui->numberLabel_1->setText("1");
    ui->taskLabel_1->setText(planWindow::tasks[0]);

    ui->numberLabel_2->setText("2");
    ui->taskLabel_2->setText(planWindow::tasks[1]);

    ui->numberLabel_3->setText("3");
    ui->taskLabel_3->setText(planWindow::tasks[2]);
}

planWindow::planWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planWindow)
{
    ui->setupUi(this);

    planWindow::setPhotos();
    planWindow::uploadDataTasks();
    planWindow::fillTasks();

    planWindow::user_name = "Cat";                       // какое-то считываение данных о пользователе
    ui->userNameLable->setText(planWindow::user_name);
}

//planWindow::planWindow(QString name, QWidget *parent = nullptr) :
//    QDialog(parent),
//    ui(new Ui::planWindow)
//{
//    ui->setupUi(this);

//    planWindow::setPhotos();
//    planWindow::uploadDataTasks();
//    planWindow::fillTasks();

//    planWindow::user_name = name;                       // какое-то считываение данных о пользователе
//    ui->userNameLable->setText(planWindow::user_name);
//}

planWindow::~planWindow()
{
    delete ui;
}

// хорошо бы здесь сделать высплывающее окошко с вопросом
void planWindow::on_pushButton_2_clicked()
{
    QWidget::close();
}

void planWindow::on_settingsButton_clicked()
{
    settingsForm sets;
    sets.setModal(true);
    sets.exec();
}

void planWindow::on_see_cats_clicked()
{
    catform cats;
    cats.setModal(true);
    cats.exec();
}

void planWindow::on_create_clicked()
{
    QString text_of_task = ui->text_of_new_task->toPlainText();

    std::cout << "Text " << text_of_task.toLatin1().data();
}

void planWindow::on_done_1_clicked()
{
//    auto pos_of_elem = tasks.cbegin() + number_of_top_task;
//   numbers2.erase(tasks.cbegin() + pos_of_elem, pos_of_elem);

//    delete_task(user_id, task_id);

//    fillTasks();

    std::cout << "Ну-ну, удачи";
}

void planWindow::on_done_2_clicked()
{
//    auto pos_of_elem = tasks.cbegin() + number_of_top_task + 1;
//    numbers2.erase(tasks.cbegin() + pos_of_elem, pos_of_elem);

//    delete_task(user_id, task_id);

//    fillTasks();

    std::cout << "Понаехали...";
}

void planWindow::on_done_3_clicked()
{
//    auto pos_of_elem = tasks.cbegin() + number_of_top_task + 1;
//    numbers2.erase(tasks.cbegin() + pos_of_elem, pos_of_elem);

//    delete_task(user_id, task_id);

//    fillTasks();

    std::cout << "Хватит жмякать уже!";
}

void planWindow::on_edit_1_clicked()
{
    edittask edit;
    edit.setModal(true);
    edit.exec();
}

void planWindow::on_edit_2_clicked()
{
    edittask edit;
    edit.setModal(true);
    edit.exec();
}

void planWindow::on_edit_3_clicked()
{
    edittask edit;
    edit.setModal(true);
    edit.exec();
}

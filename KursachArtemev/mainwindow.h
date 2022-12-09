#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "popup.h"
#include "database.h"
#include "QTimer"

#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QDateTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    DataBase        *db;
    QTimer m_timer;
    QString timeNow;
    QString timeForm;
    QString textintoappend;
    QDate DateForAppend;
    QTime TimeForAppend;
    bool saveSetting = false;
    bool newOrOld=false;
    int NumberRow;
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    //void dateConfirm();
    //void get_textEdit_text();
   // //void on_dateTimeEdit_dateChanged(const QDate &date);
    void sravnenie();
    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    //void on_checkBox_stateChanged(int arg1);

    void on_checkBox_toggled(bool checked);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


signals:
    void sigToUpdate(bool x);
public slots:
        void get_textEdit_text();
        void set_textEdit_text();
private:
    Ui::MainWindow *ui;
    PopUp *popUp;       // Объявляем объект всплывающего сообщения
    QTimer *timerforcheck;
    QTimer *checkBoxTimer;

    bool repeat =false;
};

#endif // MAINWINDOW_H

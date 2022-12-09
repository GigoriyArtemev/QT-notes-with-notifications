#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    popUp = new PopUp();
    timerforcheck = new QTimer(this);
    timerforcheck->setInterval(1000);
    connect(timerforcheck, SIGNAL(timeout()), this, SLOT(sravnenie()));
    timerforcheck->start(); // И запустим таймер
ui->dateTimeEdit->setCalendarPopup(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    if(ui->textEdit->toPlainText() =="")
    {
        popUp->setPopupText("Пример текста в уведомлении!");
             popUp->show();
    }
    else
    {
        popUp->setPopupText(ui->textEdit->toPlainText());

        popUp->show();
    }
}

void MainWindow::sravnenie()
{   db = new DataBase();
    QDate dateNOW = QDate::currentDate();
    QTime timeNOW = QTime::currentTime();

    textintoappend = ui->textEdit->toPlainText();
    timeNow = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    if(timeForm ==timeNow)
    {


        if(repeat==true){
            QTimer::singleShot( 30000, this, SLOT(on_pushButton_clicked()) );

        }
    }

    db->selectSortToDate(dateNOW , timeNOW);
    //qWarning()<<"trueSave = "<<db->trueSave;
   if(db->trueSave == true){
        popUp->setPopupText(db->loadMessForPopUp);
        popUp->show();
        db->trueSave =false;

    }


}
void MainWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{

    timeForm = dateTime.date().toString("dd.MM.yyyy") + dateTime.time().toString(" HH:mm:ss");
    DateForAppend = dateTime.date();
    TimeForAppend = dateTime.time();
}

void MainWindow::get_textEdit_text(){
   textintoappend = ui->textEdit->toPlainText();
}
void MainWindow::set_textEdit_text()
{
    qWarning()<<" newOrOld: "<<newOrOld;


        db->selectFromTable(NumberRow);
        ui->textEdit->setText(db->loadMess);
        ui->dateTimeEdit->setDate(db->loadDate);
        ui->dateTimeEdit->setTime(db->loadTime);
        if(db->loadMess==""){
            ui->dateTimeEdit->setDate(QDate::currentDate());
           // ui->dateTimeEdit->setTime(QTime::currentTime());
            //newOrOld=false;
        }

    newOrOld =99999;
}
void MainWindow::on_checkBox_toggled(bool checked)
{
    repeat=checked;
}


void MainWindow::on_pushButton_2_clicked()
{

    qWarning()<<"я попал в отправку данных";
    if(DateForAppend.toString("dd.MM.yyyy")=="" or textintoappend=="" )
    {
        qWarning()<<DateForAppend.toString("dd.MM.yyyy");
        QMessageBox::warning(this, "Минуточку внимания!","Заполните заметку чтобы сохранить её.");
    }
    else
    {
        QVariantList data;
        data.append(DateForAppend);
        data.append(TimeForAppend) ;
        data.append(NumberRow);
        data.append(textintoappend);
        db->selectFromTable(NumberRow);

          if(db->loadMess == ""){
            db->inserIntoTable(data);
          }
          else
          {
             db->updateRowIntoTable(NumberRow, data);
          }
          emit sigToUpdate(true);

    }


}

void MainWindow::on_pushButton_3_clicked()
{
 MainWindow::close();
}



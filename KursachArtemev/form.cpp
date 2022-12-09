#include "form.h"
#include "ui_form.h"
//#include "mainwindow.h"
#include <QTextStream>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    this->setWindowTitle("Заметки с уведомлениями");
   out = new QTextStream ;
   m= new MainWindow();
   db = new DataBase();

   QMessageBox msgBox;

   db->connectToDataBase();

   model = new QSqlTableModel(db);
   model->setTable(_TABLE);
   model->select();

   ui->tableView->setModel(model);
     connect(m, SIGNAL(sigToUpdate(bool)),this,SLOT(updateTableViev(bool))); // кнопка загрузить

     m->newOrOld=model->rowCount();
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
   ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(3);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    model->setHeaderData(1, Qt::Horizontal, "Дата");
     model->setHeaderData(2, Qt::Horizontal, "Время");
     model->setHeaderData(4, Qt::Horizontal, "Текст заметки");
}
Form::~Form()
{
    delete ui;
}
void Form::updateTableViev(bool x)
{
    if(x==true)
    {
        model->select();
    }

}
void Form::pause() // пауза таймера.
{

}

void Form::resume() // таймер продолжает работу.
{

}


void Form::on_pushButton_clicked() // добавить строку
{
    model->insertRow(model->rowCount()); 
   qWarning()<<m->NumberRow;

  m->NumberRow= model->rowCount()-1;
  qWarning()<<m->NumberRow;
  m->set_textEdit_text();
  m->show();
  model->select();

   ljop = true;

}



void Form::on_pushButton_2_clicked() // удаление
{
    QMessageBox msgBox;
    msgBox.setText("Внимание!");
    msgBox.setInformativeText("Удалить строку?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int res = msgBox.exec();

    if (res == QMessageBox::Ok){        
      model->removeRow(row);
      db->updateIdtab(row);
      model->select();
    }
    else
    {

    }


}


void Form::on_tableView_clicked(const QModelIndex &index) // один клик по строке
{

    row = index.row();

}

void Form::on_tableView_doubleClicked(const QModelIndex &index) // два клика по строке
{

     m->NumberRow= index.row();
    qWarning()<<m->NumberRow;
    m->set_textEdit_text();
    m->show();
    model->select();
}
void Form::on_checkBox_toggled(bool checked) //темный дизайн
{

    if(checked ==true){
        // Создаём палитру для тёмной темы оформления
        QPalette darkPalette;

        // Настраиваем палитру для цветовых ролей элементов интерфейса
        ui->tableView->horizontalHeader()->setStyleSheet("background-color:black;");
        ui->tableView->verticalHeader()->setStyleSheet("background-color:black;");
        ui->tableView->horizontalHeader()->setStyleSheet("selection-color: yellow;");
        ui->tableView->verticalHeader()->setStyleSheet("selection-color: yellow;");

        darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::WindowText, Qt::white);
        darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, Qt::white);
        darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);

        // Устанавливаем данную палитру
        qApp->setPalette(darkPalette);
    }
    else
    {
        qApp->setPalette(style()->standardPalette());
        ui->tableView->horizontalHeader()->setStyleSheet("background-color:white;");
        ui->tableView->verticalHeader()->setStyleSheet("background-color:white;");
        ui->tableView->horizontalHeader()->setStyleSheet("selection-color: yellow;");
        ui->tableView->verticalHeader()->setStyleSheet("selection-color: yellow;");
    }
}

void Form::on_pushButton_3_clicked()
{
    qApp->closeAllWindows();
}

void Form::on_pushButton_4_clicked()
{
    m->NumberRow= row;
    qWarning()<<m->NumberRow;
    m->set_textEdit_text();
    m->show();
    model->select();
}

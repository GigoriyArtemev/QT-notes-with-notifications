#ifndef FORM_H
#define FORM_H
#include <QtWidgets>
#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <database.h>
#include <mainwindow.h>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QTextEdit>
#include <QMenu>
#include <Qt>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

public:
     bool ljop = false;
public slots:
   // void updateTableViev();
private slots:
    //void on_tabWidget_tabCloseRequested(int index);

   void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);
   // void loadData();
   void on_pushButton_2_clicked();
   void pause();
   void resume();
   void on_tableView_clicked(const QModelIndex &index);
   void updateTableViev(bool x);
   void on_tableView_doubleClicked(const QModelIndex &index);
   void on_pushButton_3_clicked();

   void on_pushButton_4_clicked();

public slots:
   void slotAbout()
   {
       QMessageBox::about(this,"У нас умерли","Электропечь, фрезировщик, компановщик, мать ....");
   }
private:
    Ui::Form *ui;
    QSqlQueryModel *modelForm;
    bool theme = false;
   DataBase        *db;

   // QTimer m_timer;
    QSqlTableModel    *model;
    MainWindow *m;
    QTextStream* out;
    QSqlQuery *query;
    int row;

private:
    /* Также присутствуют два метода, которые формируют модель
     * и внешний вид TableView
     * */
   // void setupMainModel(const QStringList &headers);
   // void setupModel(const QString &tableName, const QStringList &headers);
   // void createUI();
};

#endif // FORM_H

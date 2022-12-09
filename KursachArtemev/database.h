#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define _HOSTNAME   "ExampleDataBase"
#define _NAME       "DataBase.db"

#define _TABLE             "TableExample"
#define _DATE              "Date"
#define _TIME              "Time"
#define _MESSAGE           "Message"
#define _IDTAB            "Idtab"
class DataBase : public QObject
{
    Q_OBJECT
public:
        explicit DataBase(QObject *parent = 0);
           ~DataBase();
           /* Методы для непосредственной работы с классом
            * Подключение к базе данных и вставка записей в таблицу
            * */
           void updateRowIntoTable(int row, const QVariantList &data);
           int updateIdtab(int row);
           void connectToDataBase();
           bool inserIntoTable(const QVariantList &data);
           void selectFromTable(int Idtab);
           void deleteFromTable(int idNumber);
           void selectSortToDate(QDate date, QTime time);
           bool trueSave = false;
           QString loadMess;
           QString loadMessForPopUp;
           QDate loadDate;
           QTime loadTime;

           //int doubleClickedRow=0;
private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;
    QSqlRecord *rec;

private:
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
};

#endif // DATABASE_H

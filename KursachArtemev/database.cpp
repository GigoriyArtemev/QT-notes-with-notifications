
#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}
DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile("./"_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(_HOSTNAME);
    db.setDatabaseName("./" _NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы в базе данных
 * */
bool DataBase::createTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " _TABLE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            _DATE      " DATE            NOT NULL,"
                            _TIME      " TIME            NOT NULL,"
                            _IDTAB     " INTEGER         NOT NULL,"
                            _MESSAGE   " VARCHAR(255)    NOT NULL"   //STRING
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << _TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

void DataBase::deleteFromTable(int Idtab)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TableExample WHERE Id = ?");
    query.addBindValue(Idtab);
    if(!query.exec()){
        qDebug() << "error delete  " << _TABLE;
        qDebug() << query.lastError().text();
    }
}
int DataBase::updateIdtab(int row){

    QSqlQuery query;
    query.prepare(QString("UPDATE TableExample SET Idtab = Idtab - 1 WHERE Idtab >=%1 ").arg(row));
    //query.addBindValue(row);
    if(!query.exec()){
        qDebug() << "error updateIdTab:  " << _TABLE;
        qDebug() << query.lastError().text();
    }


    return 0;
}



void DataBase::updateRowIntoTable(int row, const QVariantList &data){
    QSqlQuery query;
    //selectFromTable(row);
    qWarning()<<row<<" - строчка";
    query.prepare(QString("UPDATE TableExample SET Date = ? WHERE Idtab = %1 ").arg(row));
    query.addBindValue(data[0].toDate());
    if(!query.exec()){
        qDebug() << "error update Date:  " << _TABLE;
        qDebug() << query.lastError().text();
    }
    query.prepare(QString("UPDATE TableExample SET Time = ? WHERE Idtab = %1 ").arg(row));
    query.addBindValue(data[1].toTime());
    if(!query.exec()){
        qDebug() << "error update Time:  " << _TABLE;
        qDebug() << query.lastError().text();
    }
    query.prepare(QString("UPDATE TableExample SET Message = ? WHERE Idtab = %1 ").arg(row));
    query.addBindValue(data[3].toString());
    if(!query.exec()){
        qDebug() << "error update Message:  " << _TABLE;
        qDebug() << query.lastError().text();
    }

}
void DataBase::selectSortToDate(QDate date, QTime time){
    QSqlQuery query;
    //qWarning()<<"дата: "<<date<<", время: "<<time;
    query.prepare("SELECT " _MESSAGE", " _TIME  " FROM " _TABLE " WHERE Date = ?");

    query.addBindValue(date);
    if(!query.exec()){
        qDebug() << "error select from table  " << _TABLE;
        qDebug() << query.lastError().text();
    }   //всё норм там
    while (query.next()) {
       // qWarning()<<"время которое выдаёт бд: "<<query.value(1).toTime();
        if((query.value(1).toTime()<time) and (query.value(1).toTime().addSecs(1)>time)){

            loadMessForPopUp=query.value(0).toString();
            qDebug() << loadMessForPopUp;
            trueSave = true;
        }

        //int idtaB = query.value(1).toInt();

        }
}
void DataBase::selectFromTable(int Idtab)
{
    QSqlQuery query;

    query.prepare("SELECT " _MESSAGE", " _DATE", " _TIME  " FROM " _TABLE " WHERE Idtab = ?");
    query.addBindValue(Idtab);
    if(!query.exec()){
        qDebug() << "error select from table  " << _TABLE;
        qDebug() << query.lastError().text();
    }   //всё норм там
    while (query.next()) {
        loadMess = query.value(0).toString();
        loadDate = query.value(1).toDate();
        loadTime = query.value(2).toTime();
        //int idtaB = query.value(1).toInt();
        qDebug() << loadMess << " "<<loadDate <<" "<<loadTime; //<< " " << idtaB;
        }
}
/* Метод для вставки записи в базу данных
 * */

bool DataBase::inserIntoTable(const QVariantList &data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT INTO " _TABLE " ( " _DATE ", "
                                             _TIME ", "
                                             _IDTAB ", "
                                             _MESSAGE " ) "
                  "VALUES (:Date, :Time, :Idtab, :Message )");
    query.bindValue(":Date",        data[0].toDate());
    query.bindValue(":Time",        data[1].toTime());
    query.bindValue(":Idtab",       data[2].toInt());
    query.bindValue(":Message",     data[3].toString());
    // После чего выполняется запросом методом exec()
    qWarning()<<"запросик прошёл";
    if(!query.exec()){
        qDebug() << "error insert into " << _TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}


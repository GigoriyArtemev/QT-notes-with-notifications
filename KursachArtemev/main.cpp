#include "form.h"
#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>
#include <QSplashScreen>
void loadModules(QSplashScreen* psplash){
    QTime time;
    time.start();

    for (int i=0; i<100;){
        if (time.elapsed()>40){
            time.start();
            i+=2;
        }
        psplash->showMessage("Загрузка заметок!: " + QString::number(i)+"%", Qt::AlignCenter|Qt::AlignCenter, Qt::black);
        qApp->processEvents();
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./your_icon.ico"));
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QSplashScreen splash(QPixmap("s.png"));
    splash.show();
    Form w;
    loadModules(&splash);
    QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    w.setMinimumSize(325, 400);
    w.setMaximumWidth(325);
    w.setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    splash.finish(&w);
    w.show();

    return a.exec();
}

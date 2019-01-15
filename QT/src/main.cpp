#include "maincontrol.h"
#include <QApplication>
#include <QTextCodec>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainControl w;

    return a.exec();
}

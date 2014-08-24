#include "mainwindow.h"
#include <QApplication>
#include "core/node.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Node a1("lel");
    Node a2("lol");

    return a.exec();
}

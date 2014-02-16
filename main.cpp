#include "galaxyportal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GalaxyPortal w;
    w.show();


    return a.exec();
}

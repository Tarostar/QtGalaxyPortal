#include "galaxyportal.h"
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GalaxyPortal w;
    w.show();

    Login* login = new Login(&w);
    QString name = "Claus";
    login->setUsername(name);
    QObject::connect(login, SIGNAL(acceptLogin(QString&,QString&)), &w, SLOT(doLogin(QString&,QString&)));
    int result = login->exec();
    if (result < 1)
    {
        // login rejected, abort!
        return result;
    }

    return a.exec();
}

#include "galaxyportal.h"
#include "ui_galaxyportal.h"
#include "login.h"

GalaxyPortal::GalaxyPortal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GalaxyPortal)
{
    ui->setupUi(this);

    Login* login = new Login(this);
    QString name = "Claus";
    login->setUsername(name);
    connect(login, SIGNAL(acceptLogin(QString&,QString&,int&)),
                     this, SLOT(slotAcceptUserLogin(QString&,QString&)));
    login->exec();
}

GalaxyPortal::~GalaxyPortal()
{
    delete ui;
}

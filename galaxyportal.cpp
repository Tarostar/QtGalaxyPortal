#include "galaxyportal.h"
#include "ui_galaxyportal.h"
#include <qmessagebox.h>
#include <qlabel.h>

GalaxyPortal::GalaxyPortal(QWidget *parent) : QMainWindow(parent), ui(new Ui::GalaxyPortal)
{

}

GalaxyPortal::~GalaxyPortal()
{
    delete ui;
}

void GalaxyPortal::doLogin(QString& username, QString& password)
{
    // qDebug() << "username: " << username << "password" << password;

    QMessageBox msgBox;

    if (username != "Claus" || password != "p")
    {
        msgBox.setText("Wrong username or password");
        msgBox.exec();
        close();
        return;
    }

    msgBox.setText("Welcome Claus.");
    msgBox.exec();
    ui->setupUi(this);

    QLabel *userLabel = new QLabel(username, ui->centralWidget);
    userLabel->show();
}

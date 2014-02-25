#include "galaxyportal.h"
#include "ui_galaxyportal.h"
#include <qmessagebox.h>
#include <qlabel.h>
#include <QCryptographicHash>
#include <QtGui>

GalaxyPortal::GalaxyPortal(QWidget *parent) : QMainWindow(parent), ui(new Ui::GalaxyPortal)
{

}

GalaxyPortal::~GalaxyPortal()
{
    delete ui;
}

void GalaxyPortal::doLogin(QString& username, QString& password)
{
    QCryptographicHash hash_incoming(QCryptographicHash::Md4);
    hash_incoming.addData(password.toUtf8());

    QString correctPassword = "passord";
    QCryptographicHash hash_correct(QCryptographicHash::Md4);
    hash_correct.addData(correctPassword.toUtf8());




    qDebug() << "passord: " << password << "Md4" << hash_incoming.result().toHex();
    qDebug() << "correct: " << correctPassword << "Md4" << hash_correct.result().toHex();

    QMessageBox msgBox;

    if (username != "Claus" || hash_incoming.result() != hash_correct.result())
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

#include "galaxyportal.h"
//#include "ui_galaxyportal.h"
#include <QApplication>
#include <QMessageBox>
#include <QLabel.h>
#include <QCryptographicHash>
#include <QtGui>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QHBoxLayout>

GalaxyPortal::GalaxyPortal(QWidget *parent) : QMainWindow(parent)/*, ui(new Ui::GalaxyPortal)*/
{
    // set Qt to take care of deleting the window from memory as soon as it is closed
    setAttribute( Qt::WA_DeleteOnClose );

    createActions();
    createMenus();
    createToolbars();
}

GalaxyPortal::~GalaxyPortal()
{
    //delete ui;
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
    //ui->setupUi(this);

    QLabel *userLabel = new QLabel(username);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget( userLabel );

    QWidget* widget = new QWidget();
    widget->setLayout(hLayout);
    setCentralWidget(widget);
}

void GalaxyPortal::createActions()
{
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Quit Galaxy Portal"));
    QObject::connect(exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    aboutGPAction = new QAction(tr("About &Galaxy Portal"), this);
    aboutGPAction->setStatusTip(tr("About the Galaxy Portal app"));
    QObject::connect(aboutGPAction, SIGNAL(triggered()), this, SLOT(helpAbout()));

    connectAction = new QAction(QIcon(":/resources/connect32.png"), tr("&Connect"), this);
    connectAction->setShortcut(tr("Ctrl+C"));
    connectAction->setStatusTip(tr("Connect to the Galaxy system"));
    QObject::connect(connectAction, SIGNAL(triggered()), this, SLOT(connect()));
}

void GalaxyPortal::createMenus()
{
    QMenu *menu;
    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(connectAction);
    menu->addSeparator();
    menu->addAction(exitAction);

    menu = menuBar()->addMenu(tr("&Help"));
    menu->addAction(aboutGPAction);
}

void GalaxyPortal::createToolbars()
{
    QToolBar *toolbar;
    toolbar = addToolBar(tr("File"));
    toolbar->addAction(connectAction);
    toolbar->addAction(aboutGPAction);
    toolbar->addSeparator();
    toolbar->addAction(exitAction);
}

void GalaxyPortal::helpAbout()
{
    QMessageBox::about(this, tr("About Galaxy Portal"), tr("An interface app to Galaxy."));
}

void GalaxyPortal::connect()
{
    // TODO: implement
    QMessageBox::information(this, tr("Galaxy Portal"), tr("The code to connect to Galaxy has not been written yet.") );
}

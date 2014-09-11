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
#include <QProgressBar>
#include <QHBoxLayout>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkProxy>
#include <QtXml/QDomDocument>
#include <QtScript/QScriptEngine>

// static const char *REQUEST_URL = "https://api.github.com/users/mralexgray/repos";
//static const char *USER = "user";
//static const char *PASSWORD = "asas";

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

    QString correctPassword = "p";
    QCryptographicHash hash_correct(QCryptographicHash::Md4);
    hash_correct.addData(correctPassword.toUtf8());




    qDebug() << "p: " << password << "Md4" << hash_incoming.result().toHex();
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

    /* Attempted rest call */
  /*

    QVBoxLayout *layout = new QVBoxLayout(this);

    m_label = new QLabel();
    m_progress = new QProgressBar();
    m_progress->setRange(0, 100);

    layout->addWidget(m_label);
    layout->addWidget(m_progress);
    setLayout(layout);

    m_network = new QNetworkAccessManager(this);
    QNetworkRequest request;
    //request.setRawHeader("Authorization", "Basic " +
    //                     QByteArray(QString("%1:%2").arg(USER).arg(PASSWORD).toAscii()).toBase64());
    request.setUrl(QUrl(REQUEST_URL));
    QNetworkReply *reply = m_network->get(request);

    QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
                            SLOT(slotSetProgress(qint64,qint64)));
    QObject::connect(m_network, SIGNAL(finished(QNetworkReply *)),
                                SLOT(slotRequestFinished(QNetworkReply *)));
   */


    QUrl url("https://usegalaxy.org/api/histories?key=218afad6146272c7c771688e10fb9884");
    //QUrl url("https://api.github.com/users/mralexgray/repos");
    //QUrl url("http://ip.jsontest.com/");
    QNetworkRequest request;
    request.setUrl(url);

   // m_currentReply = networkManager.get(request);  // GET
    m_network = new QNetworkAccessManager(this);
    /*QNetworkReply *reply =*/ m_network->get(request);


    //QObject::connect(m_network, SIGNAL(finished(QNetworkReply *)),SLOT(onResult(QNetworkReply *)));
      QObject::connect(m_network, SIGNAL(finished(QNetworkReply*)), SLOT(onResult(QNetworkReply*)));


}

void GalaxyPortal::onResult(QNetworkReply* reply)
{
    QString msg;
    if (reply->error() > 0) {
        msg = "Error number = ";
        msg += reply->errorString();
    }
    else {
        QByteArray data = reply->readAll();

        QJsonDocument json(QJsonDocument::fromJson(data));

        //QString ch= "[0,{\"1\":{\"2\":{\"3\":{\"4\":[5,{\"6\":7}]}}}}]";
        //QJsonDocument json(QJsonDocument::fromJson(ch.toLocal8Bit()));

        if (json.isObject())
        {
            msg = "object: ";
            QJsonObject object = json.object();

            /*QJsonObject::iterator i = object.begin();
             while (i != object.end())
             {
                 msg += i.value().toString();
             }*/

            //QJsonObject json = (QJsonObject)reply->readAll();
            msg += object["name"].toString();
        }
        else if (json.isArray())
        {
            msg = "array: ";


            msg += QString::number(json.array().size());

            /*foreach (const QJsonValue & value, jsonArray)
            {
                QJsonObject obj = value.toObject();

                propertyNames.append(obj["PropertyName"].toString());
                propertyKeys.append(obj["key"].toString());
            }*/

            //QJsonValueRef ref = array[0];
            /*msg += ref.toObjectsid"].toString();*/
        }
        else
        {
            msg = "not object";
        }



        //QByteArray data = reply->readAll();

        /*QString data = (QString) reply->readAll();

        QScriptEngine engine;
        QScriptValue result = engine.evaluate(data);
        msg = result.property("ip").toString();*/


        /*QDomDocument doc;
        doc.setContent(data);
        QDomNodeList nodes = doc.elementsByTagName("ip");

        if (nodes.size() > 0) {
            //m_label->setText(nodes.at(0).toElement().text());
            msg = "node: " + nodes.at(0).toElement().text();
        }*/
    }



    /*if (reply->error() != QNetworkReply::NoError)
        return;  // ...only in a blog post

    QString data = (QString) reply->readAll();*/

    QMessageBox msgBox;
     msgBox.setText(msg);
     msgBox.exec();

 //   QScriptEngine engine;
 //   QScriptValue result = engine.evaluate(data);

    /*
      Google YouTube JSON looks like this :

      {
        "version": "1.0",
        "encoding": "UTF-8",
        "feed": {
          ..
          ..
          "entry": [{
            "title": {
                "$t": "Nickelback- When We Stand Together"
            },
            "content": {
                "type": "application/x-shockwave-flash",
                "src": "http://www.youtube.com/v/76vdvdll0Y?version=3&f=standard&app=youtube_gdata"
            },
            "yt$statistics": {
                "favoriteCount": "29182",
                "viewCount": "41513706"
            },
            ...
            ...
          },
          ...
          ...
          ]
        }
      }
    */

    // Now parse this JSON according to your needs !
 /*   QScriptValue entries = result.property("feed").property("entry");
    QScriptValueIterator it(entries);
    while (it.hasNext()) {
        it.next();
        QScriptValue entry = it.value();

        QString link = entry.property("content").property("src").toString();
        int viewCount = entry.property("yt$statistics").property("viewCount").toInteger();

        // Do something with those...
        QLabel *userLabel = new QLabel(username);

        QHBoxLayout *hLayout = new QHBoxLayout();
        hLayout->addWidget( userLabel );

        QWidget* widget = new QWidget();
        widget->setLayout(hLayout);
        setCentralWidget(widget);

    }*/
}

void GalaxyPortal::slotRequestFinished(QNetworkReply *reply)
{
    m_progress->setValue(0);

    if (reply->error() > 0) {
        m_label->setText("Error number = " + reply->errorString());
    }
    else {
        QByteArray data = reply->readAll();
        QDomDocument doc;
        doc.setContent(data);
        QDomNodeList nodes = doc.elementsByTagName("message");

        if (nodes.size() > 0) {
            m_label->setText(nodes.at(0).toElement().text());
        }
    }
}

void GalaxyPortal::slotSetProgress(qint64 received, qint64 total)
{
    if (total > 0 && received > 0) {
        m_progress->setValue((int) total / received);
    }
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

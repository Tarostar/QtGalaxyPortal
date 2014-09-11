#ifndef GALAXYPORTAL_H
#define GALAXYPORTAL_H

#include <QMainWindow>
class QProgressBar;
class QNetworkAccessManager;
class QNetworkReply;
class QLabel;

/*namespace Ui {
class GalaxyPortal;
}*/

class GalaxyPortal : public QMainWindow
{
    Q_OBJECT

public:
    explicit GalaxyPortal(QWidget *parent = 0);
    ~GalaxyPortal();

public slots:
    // accepts login
    void doLogin(QString& username, QString& password);
    void connect();
    void helpAbout();
    void slotRequestFinished(QNetworkReply *reply);
    void slotSetProgress(qint64, qint64);

    void onResult(QNetworkReply* reply);

private:
    void createActions();
    void createMenus();
    void createToolbars();

    //Ui::GalaxyPortal *ui;
    QAction *connectAction;
    QAction *exitAction;
    QAction *aboutGPAction;

    QLabel *m_label;
    QProgressBar *m_progress;

    QNetworkAccessManager *m_network;

    QNetworkReply* m_currentReply;

};

#endif // GALAXYPORTAL_H

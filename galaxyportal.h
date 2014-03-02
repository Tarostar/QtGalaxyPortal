#ifndef GALAXYPORTAL_H
#define GALAXYPORTAL_H

#include <QMainWindow>

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


private:
    void createActions();
    void createMenus();
    void createToolbars();

    //Ui::GalaxyPortal *ui;
    QAction *connectAction;
    QAction *exitAction;
    QAction *aboutGPAction;

};

#endif // GALAXYPORTAL_H

#ifndef GALAXYPORTAL_H
#define GALAXYPORTAL_H

#include <QMainWindow>

namespace Ui {
class GalaxyPortal;
}

class GalaxyPortal : public QMainWindow
{
    Q_OBJECT

public:
    explicit GalaxyPortal(QWidget *parent = 0);
    ~GalaxyPortal();

private:
    Ui::GalaxyPortal *ui;

public slots:
    // accepts login
    void doLogin(QString& username, QString& password);
};

#endif // GALAXYPORTAL_H

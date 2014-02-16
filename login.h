#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

class Login : public QDialog
{
    Q_OBJECT

private:
    QLabel* labelUsername;
    QLabel* labelPassword;

    // username edit and selection list
    QComboBox* comboUsername;
    // password field (password will be masked)
    QLineEdit* editPassword;

    // buttons in a layout that conforms to the interface guidelines for the platform
    QDialogButtonBox* buttons;

    // init method
    void setupGUI();

public:
    // explicit keyword to the constructor prevents the compiler from using the constructor for implicit conversions
    explicit Login(QWidget *parent = 0);

    // set a proposed username
    void setUsername(QString& username);
    // set a proposed password (for remembered password)
    void setPassword(QString& password);
    // provide a list of usernames to choose from without having to type
    void setUsernamesList(const QStringList& usernames);

signals:
    // signal on login with username and password
    void acceptLogin(QString& username, QString& password);

public slots:
    // emits acceptLogin when user hits ok (not on cancel) and closes dialog
    void slotAcceptLogin();

};

#endif // LOGINDIALOG_H

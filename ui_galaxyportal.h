/********************************************************************************
** Form generated from reading UI file 'galaxyportal.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALAXYPORTAL_H
#define UI_GALAXYPORTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GalaxyPortal
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GalaxyPortal)
    {
        if (GalaxyPortal->objectName().isEmpty())
            GalaxyPortal->setObjectName(QStringLiteral("GalaxyPortal"));
        GalaxyPortal->resize(400, 300);
        menuBar = new QMenuBar(GalaxyPortal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GalaxyPortal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GalaxyPortal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GalaxyPortal->addToolBar(mainToolBar);
        centralWidget = new QWidget(GalaxyPortal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GalaxyPortal->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GalaxyPortal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GalaxyPortal->setStatusBar(statusBar);

        retranslateUi(GalaxyPortal);

        QMetaObject::connectSlotsByName(GalaxyPortal);
    } // setupUi

    void retranslateUi(QMainWindow *GalaxyPortal)
    {
        GalaxyPortal->setWindowTitle(QApplication::translate("GalaxyPortal", "GalaxyPortal", 0));
    } // retranslateUi

};

namespace Ui {
    class GalaxyPortal: public Ui_GalaxyPortal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALAXYPORTAL_H

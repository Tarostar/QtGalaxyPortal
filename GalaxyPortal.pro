#-------------------------------------------------
#
# Project created by QtCreator 2014-02-16T18:21:38
#
#-------------------------------------------------

include(GalaxyPortalSrc.pri)

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GalaxyPortal
TEMPLATE = app


FORMS    += galaxyportal.ui

OTHER_FILES += \
    GalaxyPortalSrc.pri

RESOURCES += \
    galaxyResources.qrc

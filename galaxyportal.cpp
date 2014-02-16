#include "galaxyportal.h"
#include "ui_galaxyportal.h"

GalaxyPortal::GalaxyPortal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GalaxyPortal)
{
    ui->setupUi(this);
}

GalaxyPortal::~GalaxyPortal()
{
    delete ui;
}

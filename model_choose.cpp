#include "model_choose.h"
#include "ui_model_choose.h"

Model_Choose::Model_Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Model_Choose)
{
    ui->setupUi(this);
}

Model_Choose::~Model_Choose()
{
    delete ui;
}

#include "exercise.h"
#include "ui_exercise.h"

Exercise::Exercise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exercise)
{
    ui->setupUi(this);
}

Exercise::~Exercise()
{
    delete ui;
}

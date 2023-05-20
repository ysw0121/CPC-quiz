#ifndef EXERCISE_H
#define EXERCISE_H

#include <QDialog>

namespace Ui {
class Exercise;
}

class Exercise : public QDialog
{
    Q_OBJECT

public:
    explicit Exercise(QWidget *parent = nullptr);
    ~Exercise();

private:
    Ui::Exercise *ui;
};

#endif // EXERCISE_H

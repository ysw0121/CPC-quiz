#ifndef MODEL_CHOOSE_H
#define MODEL_CHOOSE_H

#include <QDialog>

namespace Ui {
class Model_Choose;
}

class Model_Choose : public QDialog
{
    Q_OBJECT

public:
    explicit Model_Choose(QWidget *parent = nullptr);
    ~Model_Choose();

private:
    Ui::Model_Choose *ui;
};

#endif // MODEL_CHOOSE_H

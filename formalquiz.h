#ifndef FORMALQUIZ_H
#define FORMALQUIZ_H

#include <QDialog>

namespace Ui {
class FormalQuiz;
}

class FormalQuiz : public QDialog
{
    Q_OBJECT

public:
    explicit FormalQuiz(QWidget *parent = nullptr);
    ~FormalQuiz();

private slots:
    void on_return_2_clicked();

private:
    Ui::FormalQuiz *ui;
};

#endif // FORMALQUIZ_H
#ifndef FORMALQUIZ_H
#define FORMALQUIZ_H

#include <QDialog>
#include<QTime>
#include<QTimer>

namespace Ui {
class FormalQuiz;
}

class FormalQuiz : public QDialog
{
    Q_OBJECT

public:
    explicit FormalQuiz(QWidget *parent = nullptr);
    ~FormalQuiz();

   // QTimer *tim;
    QTime time;


private slots:

    void countdown();

    void on_next_clicked();

private:
    Ui::FormalQuiz *ui;
};

#endif // FORMALQUIZ_H

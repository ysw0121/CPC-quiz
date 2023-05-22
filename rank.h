#ifndef RANK_H
#define RANK_H

#include <QDialog>

namespace Ui {
class Rank;
}

class Rank : public QDialog
{
    Q_OBJECT

public:
    explicit Rank(QWidget *parent = nullptr);
    ~Rank();

private slots:
    void on_return_2_clicked();

private:
    Ui::Rank *ui;
};

#endif // RANK_H

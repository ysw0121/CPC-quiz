#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_return_2_clicked();

    void on_certain_clicked();

    void on_name_textEdited(const QString &arg1);

    void on_password_textEdited(const QString &arg1);

    void on_showpsw_clicked(bool checked);

private:
    Ui::Register *ui;
};

#endif // REGISTER_H

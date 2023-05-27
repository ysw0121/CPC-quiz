/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *return_2;
    QPushButton *certain;
    QLabel *label_2;
    QLineEdit *name;
    QLineEdit *password;
    QLabel *label;
    QLabel *nwarning;
    QLabel *pwarning;
    QCheckBox *showpsw;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(492, 385);
        return_2 = new QPushButton(Register);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(300, 290, 80, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        return_2->setFont(font);
        certain = new QPushButton(Register);
        certain->setObjectName(QString::fromUtf8("certain"));
        certain->setGeometry(QRect(110, 290, 80, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        certain->setFont(font1);
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 170, 61, 31));
        label_2->setFont(font1);
        name = new QLineEdit(Register);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(130, 60, 201, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        name->setFont(font2);
        password = new QLineEdit(Register);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(130, 170, 201, 31));
        password->setFont(font2);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 61, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        nwarning = new QLabel(Register);
        nwarning->setObjectName(QString::fromUtf8("nwarning"));
        nwarning->setGeometry(QRect(340, 60, 131, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setBold(true);
        font4.setWeight(75);
        nwarning->setFont(font4);
        pwarning = new QLabel(Register);
        pwarning->setObjectName(QString::fromUtf8("pwarning"));
        pwarning->setGeometry(QRect(340, 170, 131, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(9);
        font5.setBold(true);
        font5.setWeight(75);
        pwarning->setFont(font5);
        showpsw = new QCheckBox(Register);
        showpsw->setObjectName(QString::fromUtf8("showpsw"));
        showpsw->setGeometry(QRect(270, 230, 81, 18));
        showpsw->setFont(font2);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", nullptr));
        return_2->setText(QApplication::translate("Register", "\350\277\224\345\233\236", nullptr));
        certain->setText(QApplication::translate("Register", "\347\241\256\345\256\232", nullptr));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        name->setPlaceholderText(QApplication::translate("Register", "\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\357\274\214\344\270\215\350\246\201\350\266\205\350\277\20715\345\255\227", nullptr));
        password->setInputMask(QString());
        password->setText(QString());
        password->setPlaceholderText(QApplication::translate("Register", "\350\276\223\345\205\245\345\257\206\347\240\201\357\274\214\351\225\277\345\272\246\344\270\215\350\246\201\350\266\205\350\277\20715", nullptr));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", nullptr));
        nwarning->setText(QString());
        pwarning->setText(QString());
        showpsw->setText(QApplication::translate("Register", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H

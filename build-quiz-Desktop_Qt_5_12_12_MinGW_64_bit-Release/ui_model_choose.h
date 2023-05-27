/********************************************************************************
** Form generated from reading UI file 'model_choose.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_CHOOSE_H
#define UI_MODEL_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Model_Choose
{
public:
    QPushButton *return_2;
    QPushButton *formal;
    QPushButton *simulate;
    QPushButton *exercise;
    QPushButton *rankView;
    QLabel *label;
    QLabel *remain;

    void setupUi(QDialog *Model_Choose)
    {
        if (Model_Choose->objectName().isEmpty())
            Model_Choose->setObjectName(QString::fromUtf8("Model_Choose"));
        Model_Choose->resize(392, 329);
        return_2 = new QPushButton(Model_Choose);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(320, 0, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        return_2->setFont(font);
        return_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        formal = new QPushButton(Model_Choose);
        formal->setObjectName(QString::fromUtf8("formal"));
        formal->setGeometry(QRect(270, 90, 71, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        formal->setFont(font1);
        formal->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 255);"));
        simulate = new QPushButton(Model_Choose);
        simulate->setObjectName(QString::fromUtf8("simulate"));
        simulate->setGeometry(QRect(160, 150, 71, 41));
        simulate->setFont(font1);
        simulate->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        exercise = new QPushButton(Model_Choose);
        exercise->setObjectName(QString::fromUtf8("exercise"));
        exercise->setGeometry(QRect(50, 220, 71, 41));
        exercise->setFont(font1);
        exercise->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));
        rankView = new QPushButton(Model_Choose);
        rankView->setObjectName(QString::fromUtf8("rankView"));
        rankView->setGeometry(QRect(0, 40, 101, 41));
        rankView->setFont(font1);
        rankView->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 241, 7);"));
        label = new QLabel(Model_Choose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-50, -60, 481, 431));
        label->setPixmap(QPixmap(QString::fromUtf8(":/780.jpg")));
        remain = new QLabel(Model_Choose);
        remain->setObjectName(QString::fromUtf8("remain"));
        remain->setGeometry(QRect(0, 0, 201, 21));
        remain->setFont(font1);
        remain->setStyleSheet(QString::fromUtf8("color: rgb(255, 161, 53);\n"
"background-color: rgb(231, 231, 231);"));
        label->raise();
        return_2->raise();
        formal->raise();
        simulate->raise();
        exercise->raise();
        rankView->raise();
        remain->raise();

        retranslateUi(Model_Choose);

        QMetaObject::connectSlotsByName(Model_Choose);
    } // setupUi

    void retranslateUi(QDialog *Model_Choose)
    {
        Model_Choose->setWindowTitle(QApplication::translate("Model_Choose", "Dialog", nullptr));
        return_2->setText(QApplication::translate("Model_Choose", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        formal->setText(QApplication::translate("Model_Choose", "\346\255\243\345\274\217\346\265\213\350\257\225", nullptr));
        simulate->setText(QApplication::translate("Model_Choose", "\346\250\241\346\213\237\346\265\213\350\257\225", nullptr));
        exercise->setText(QApplication::translate("Model_Choose", "\347\273\203\344\271\240\346\250\241\345\274\217", nullptr));
        rankView->setText(QApplication::translate("Model_Choose", "\346\237\245\347\234\213\346\216\222\350\241\214\346\246\234", nullptr));
        label->setText(QString());
        remain->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Model_Choose: public Ui_Model_Choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_CHOOSE_H

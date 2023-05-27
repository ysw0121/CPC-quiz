/********************************************************************************
** Form generated from reading UI file 'exercise.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXERCISE_H
#define UI_EXERCISE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Exercise
{
public:
    QPushButton *return_2;
    QTextBrowser *textBrowser;
    QRadioButton *A;
    QLabel *label;
    QRadioButton *B;
    QRadioButton *C;
    QPushButton *certain;

    void setupUi(QDialog *Exercise)
    {
        if (Exercise->objectName().isEmpty())
            Exercise->setObjectName(QString::fromUtf8("Exercise"));
        Exercise->resize(471, 399);
        return_2 = new QPushButton(Exercise);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(390, 0, 80, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        return_2->setFont(font);
        return_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        textBrowser = new QTextBrowser(Exercise);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 40, 381, 291));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        textBrowser->setFont(font1);
        A = new QRadioButton(Exercise);
        A->setObjectName(QString::fromUtf8("A"));
        A->setGeometry(QRect(30, 340, 41, 18));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial Black"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        A->setFont(font2);
        A->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(Exercise);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-20, 0, 491, 711));
        label->setPixmap(QPixmap(QString::fromUtf8(":/p_18695608.png")));
        B = new QRadioButton(Exercise);
        B->setObjectName(QString::fromUtf8("B"));
        B->setGeometry(QRect(70, 340, 41, 18));
        B->setFont(font2);
        B->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        C = new QRadioButton(Exercise);
        C->setObjectName(QString::fromUtf8("C"));
        C->setGeometry(QRect(110, 340, 41, 18));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Black"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        C->setFont(font3);
        C->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        certain = new QPushButton(Exercise);
        certain->setObjectName(QString::fromUtf8("certain"));
        certain->setGeometry(QRect(349, 330, 61, 31));
        certain->setFont(font);
        certain->setStyleSheet(QString::fromUtf8("background-color: rgb(125, 131, 247);"));
        label->raise();
        return_2->raise();
        textBrowser->raise();
        A->raise();
        B->raise();
        C->raise();
        certain->raise();

        retranslateUi(Exercise);

        QMetaObject::connectSlotsByName(Exercise);
    } // setupUi

    void retranslateUi(QDialog *Exercise)
    {
        Exercise->setWindowTitle(QApplication::translate("Exercise", "Dialog", nullptr));
        return_2->setText(QApplication::translate("Exercise", "\347\273\223\346\235\237\347\273\203\344\271\240", nullptr));
        A->setText(QApplication::translate("Exercise", "A", nullptr));
        label->setText(QString());
        B->setText(QApplication::translate("Exercise", "B", nullptr));
        C->setText(QApplication::translate("Exercise", "C", nullptr));
        certain->setText(QApplication::translate("Exercise", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exercise: public Ui_Exercise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCISE_H

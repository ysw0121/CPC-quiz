/********************************************************************************
** Form generated from reading UI file 'formalquiz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMALQUIZ_H
#define UI_FORMALQUIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_FormalQuiz
{
public:
    QTextBrowser *paper;
    QLCDNumber *CountDown;
    QPushButton *next;
    QRadioButton *A;
    QRadioButton *B;
    QRadioButton *C;
    QLabel *label;

    void setupUi(QDialog *FormalQuiz)
    {
        if (FormalQuiz->objectName().isEmpty())
            FormalQuiz->setObjectName(QString::fromUtf8("FormalQuiz"));
        FormalQuiz->resize(507, 405);
        paper = new QTextBrowser(FormalQuiz);
        paper->setObjectName(QString::fromUtf8("paper"));
        paper->setGeometry(QRect(60, 50, 381, 291));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        paper->setFont(font);
        CountDown = new QLCDNumber(FormalQuiz);
        CountDown->setObjectName(QString::fromUtf8("CountDown"));
        CountDown->setGeometry(QRect(300, 20, 141, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        CountDown->setFont(font1);
        CountDown->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(63, 206, 80);"));
        next = new QPushButton(FormalQuiz);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(380, 340, 61, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        next->setFont(font2);
        next->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        A = new QRadioButton(FormalQuiz);
        A->setObjectName(QString::fromUtf8("A"));
        A->setGeometry(QRect(60, 340, 41, 18));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Black"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        A->setFont(font3);
        A->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        B = new QRadioButton(FormalQuiz);
        B->setObjectName(QString::fromUtf8("B"));
        B->setGeometry(QRect(100, 340, 41, 18));
        B->setFont(font3);
        B->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        C = new QRadioButton(FormalQuiz);
        C->setObjectName(QString::fromUtf8("C"));
        C->setGeometry(QRect(140, 340, 41, 18));
        C->setFont(font3);
        C->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(FormalQuiz);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-60, -10, 631, 481));
        label->setPixmap(QPixmap(QString::fromUtf8(":/p_18695608.png")));
        label->raise();
        paper->raise();
        CountDown->raise();
        next->raise();
        A->raise();
        B->raise();
        C->raise();

        retranslateUi(FormalQuiz);

        QMetaObject::connectSlotsByName(FormalQuiz);
    } // setupUi

    void retranslateUi(QDialog *FormalQuiz)
    {
        FormalQuiz->setWindowTitle(QApplication::translate("FormalQuiz", "Dialog", nullptr));
        next->setText(QApplication::translate("FormalQuiz", "\344\270\213\344\270\200\351\242\230", nullptr));
        A->setText(QApplication::translate("FormalQuiz", "A", nullptr));
        B->setText(QApplication::translate("FormalQuiz", "B", nullptr));
        C->setText(QApplication::translate("FormalQuiz", "C", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormalQuiz: public Ui_FormalQuiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMALQUIZ_H

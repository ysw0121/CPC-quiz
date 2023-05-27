/********************************************************************************
** Form generated from reading UI file 'rank.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Rank
{
public:
    QPushButton *return_2;
    QListWidget *rankList;

    void setupUi(QDialog *Rank)
    {
        if (Rank->objectName().isEmpty())
            Rank->setObjectName(QString::fromUtf8("Rank"));
        Rank->resize(400, 300);
        return_2 = new QPushButton(Rank);
        return_2->setObjectName(QString::fromUtf8("return_2"));
        return_2->setGeometry(QRect(320, 0, 80, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        return_2->setFont(font);
        rankList = new QListWidget(Rank);
        rankList->setObjectName(QString::fromUtf8("rankList"));
        rankList->setGeometry(QRect(40, 20, 271, 261));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        rankList->setFont(font1);
        rankList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        retranslateUi(Rank);

        QMetaObject::connectSlotsByName(Rank);
    } // setupUi

    void retranslateUi(QDialog *Rank)
    {
        Rank->setWindowTitle(QApplication::translate("Rank", "Dialog", nullptr));
        return_2->setText(QApplication::translate("Rank", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rank: public Ui_Rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H

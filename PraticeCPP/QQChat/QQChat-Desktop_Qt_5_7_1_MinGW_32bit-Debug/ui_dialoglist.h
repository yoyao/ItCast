/********************************************************************************
** Form generated from reading UI file 'dialoglist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLIST_H
#define UI_DIALOGLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogList
{
public:
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *Group;
    QVBoxLayout *GroupLayout;

    void setupUi(QWidget *DialogList)
    {
        if (DialogList->objectName().isEmpty())
            DialogList->setObjectName(QStringLiteral("DialogList"));
        DialogList->resize(291, 664);
        DialogList->setBaseSize(QSize(700, 250));
        verticalLayout = new QVBoxLayout(DialogList);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(DialogList);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        Group = new QWidget();
        Group->setObjectName(QStringLiteral("Group"));
        Group->setGeometry(QRect(0, 0, 291, 634));
        GroupLayout = new QVBoxLayout(Group);
        GroupLayout->setObjectName(QStringLiteral("GroupLayout"));
        GroupLayout->setContentsMargins(0, 0, 0, 0);
        toolBox->addItem(Group, QString::fromUtf8("\347\276\244\346\210\220\345\221\230"));

        verticalLayout->addWidget(toolBox);


        retranslateUi(DialogList);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogList);
    } // setupUi

    void retranslateUi(QWidget *DialogList)
    {
        DialogList->setWindowTitle(QApplication::translate("DialogList", "QQChat", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(Group), QApplication::translate("DialogList", "\347\276\244\346\210\220\345\221\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogList: public Ui_DialogList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLIST_H

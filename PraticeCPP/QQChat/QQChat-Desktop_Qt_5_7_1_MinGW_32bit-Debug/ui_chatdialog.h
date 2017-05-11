/********************************************************************************
** Form generated from reading UI file 'chatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATDIALOG_H
#define UI_CHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QTextBrowser *txt_read;
    QTableWidget *table_online;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *comb_font;
    QComboBox *comb_fontsize;
    QToolButton *btn_blod;
    QToolButton *btn_italic;
    QToolButton *btn_underline;
    QToolButton *btn_color;
    QToolButton *btn_save;
    QToolButton *btn_clear;
    QTextEdit *txt_write;
    QLabel *label_info;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_onlinepeople;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_send;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_exit;

    void setupUi(QWidget *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(798, 629);
        txt_read = new QTextBrowser(ChatDialog);
        txt_read->setObjectName(QStringLiteral("txt_read"));
        txt_read->setGeometry(QRect(10, 20, 611, 331));
        table_online = new QTableWidget(ChatDialog);
        if (table_online->columnCount() < 1)
            table_online->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_online->setHorizontalHeaderItem(0, __qtablewidgetitem);
        table_online->setObjectName(QStringLiteral("table_online"));
        table_online->setGeometry(QRect(630, 20, 161, 561));
        table_online->setLineWidth(1);
        table_online->setSelectionMode(QAbstractItemView::SingleSelection);
        table_online->setSelectionBehavior(QAbstractItemView::SelectRows);
        widget = new QWidget(ChatDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 350, 621, 54));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comb_font = new QFontComboBox(widget);
        comb_font->setObjectName(QStringLiteral("comb_font"));

        horizontalLayout->addWidget(comb_font);

        comb_fontsize = new QComboBox(widget);
        comb_fontsize->setObjectName(QStringLiteral("comb_fontsize"));
        comb_fontsize->setMinimumSize(QSize(5, 5));
        comb_fontsize->setMaxVisibleItems(30);

        horizontalLayout->addWidget(comb_fontsize);

        btn_blod = new QToolButton(widget);
        btn_blod->setObjectName(QStringLiteral("btn_blod"));
        QIcon icon;
        QString iconThemeName = QStringLiteral(":/images/bold.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        btn_blod->setIcon(icon);
        btn_blod->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(btn_blod);

        btn_italic = new QToolButton(widget);
        btn_italic->setObjectName(QStringLiteral("btn_italic"));
        QIcon icon1;
        iconThemeName = QStringLiteral(":/images/italic.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        btn_italic->setIcon(icon1);
        btn_italic->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(btn_italic);

        btn_underline = new QToolButton(widget);
        btn_underline->setObjectName(QStringLiteral("btn_underline"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/under.png"), QSize(), QIcon::Normal, QIcon::On);
        btn_underline->setIcon(icon2);
        btn_underline->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(btn_underline);

        btn_color = new QToolButton(widget);
        btn_color->setObjectName(QStringLiteral("btn_color"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::On);
        btn_color->setIcon(icon3);
        btn_color->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(btn_color);

        btn_save = new QToolButton(widget);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::On);
        btn_save->setIcon(icon4);
        btn_save->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(btn_save);

        btn_clear = new QToolButton(widget);
        btn_clear->setObjectName(QStringLiteral("btn_clear"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/clear.png"), QSize(), QIcon::Normal, QIcon::On);
        btn_clear->setIcon(icon5);
        btn_clear->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(btn_clear);

        txt_write = new QTextEdit(ChatDialog);
        txt_write->setObjectName(QStringLiteral("txt_write"));
        txt_write->setGeometry(QRect(10, 400, 611, 181));
        txt_write->setToolTipDuration(1);
        label_info = new QLabel(ChatDialog);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setGeometry(QRect(1169, 1269, 138, 28));
        widget_2 = new QWidget(ChatDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 580, 781, 51));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(159, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_onlinepeople = new QLabel(widget_2);
        label_onlinepeople->setObjectName(QStringLiteral("label_onlinepeople"));

        horizontalLayout_2->addWidget(label_onlinepeople);

        horizontalSpacer = new QSpacerItem(160, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_send = new QPushButton(widget_2);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        horizontalLayout_2->addWidget(btn_send);

        horizontalSpacer_2 = new QSpacerItem(159, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_exit = new QPushButton(widget_2);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));

        horizontalLayout_2->addWidget(btn_exit);


        retranslateUi(ChatDialog);

        comb_fontsize->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QWidget *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table_online->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ChatDialog", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        comb_font->setToolTip(QApplication::translate("ChatDialog", "\351\200\211\346\213\251\345\255\227\344\275\223", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        comb_fontsize->clear();
        comb_fontsize->insertItems(0, QStringList()
         << QApplication::translate("ChatDialog", "8", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "9", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "10", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "11", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "12", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "13", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "14", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "15", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "16", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "17", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "18", Q_NULLPTR)
         << QApplication::translate("ChatDialog", "19", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        comb_fontsize->setToolTip(QApplication::translate("ChatDialog", "\346\226\207\345\255\227\345\244\247\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        btn_blod->setToolTip(QApplication::translate("ChatDialog", "\345\212\240\347\262\227", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_blod->setText(QApplication::translate("ChatDialog", "\345\212\240\347\262\227", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_italic->setToolTip(QApplication::translate("ChatDialog", "\345\200\276\346\226\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_italic->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_underline->setToolTip(QApplication::translate("ChatDialog", "\344\270\213\345\210\222\347\272\277", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_underline->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_color->setToolTip(QApplication::translate("ChatDialog", "\351\242\234\350\211\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_color->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_save->setToolTip(QApplication::translate("ChatDialog", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_save->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_clear->setToolTip(QApplication::translate("ChatDialog", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_clear->setText(QApplication::translate("ChatDialog", "...", Q_NULLPTR));
        label_info->setText(QApplication::translate("ChatDialog", "\345\234\250\347\272\277\344\272\272\346\225\260:\344\272\272", Q_NULLPTR));
        label_onlinepeople->setText(QApplication::translate("ChatDialog", "\345\234\250\347\272\277\344\272\272\346\225\260: \344\272\272", Q_NULLPTR));
        btn_send->setText(QApplication::translate("ChatDialog", "\345\217\221\351\200\201", Q_NULLPTR));
        btn_send->setShortcut(QApplication::translate("ChatDialog", "Ctrl+S", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("ChatDialog", "\351\200\200\345\207\272", Q_NULLPTR));
        btn_exit->setShortcut(QApplication::translate("ChatDialog", "Alt+C", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATDIALOG_H

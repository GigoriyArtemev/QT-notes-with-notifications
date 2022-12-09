/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(667, 428);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(Form);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setAutoFillBackground(false);

        verticalLayout->addWidget(tableView);

        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        checkBox = new QCheckBox(Form);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(false);
        checkBox->setAutoRepeatInterval(100);

        verticalLayout->addWidget(checkBox);

        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        pushButton_4->setText(QApplication::translate("Form", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\267\320\260\320\274\320\265\321\202\320\272\321\203", nullptr));
        pushButton->setText(QApplication::translate("Form", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\320\274\320\265\321\202\320\272\320\260", nullptr));
        pushButton_2->setText(QApplication::translate("Form", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\274\320\265\321\202\320\272\321\203", nullptr));
        checkBox->setText(QApplication::translate("Form", "\321\202\320\265\320\274\320\275\320\260\321\217 \321\202\320\265\320\274\320\260", nullptr));
        pushButton_3->setText(QApplication::translate("Form", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H

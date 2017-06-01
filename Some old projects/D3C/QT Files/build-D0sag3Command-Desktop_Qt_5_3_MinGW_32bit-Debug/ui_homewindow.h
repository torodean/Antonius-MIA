/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QAction *actionHome;
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *Home_Encryption_Button;
    QPushButton *Home_Combinatorics_Button;
    QPushButton *Home_Conversions_Button;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName(QStringLiteral("HomeWindow"));
        HomeWindow->resize(1000, 700);
        actionHome = new QAction(HomeWindow);
        actionHome->setObjectName(QStringLiteral("actionHome"));
        actionExit = new QAction(HomeWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(HomeWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Home_Encryption_Button = new QPushButton(centralWidget);
        Home_Encryption_Button->setObjectName(QStringLiteral("Home_Encryption_Button"));
        Home_Encryption_Button->setGeometry(QRect(50, 50, 101, 51));
        Home_Combinatorics_Button = new QPushButton(centralWidget);
        Home_Combinatorics_Button->setObjectName(QStringLiteral("Home_Combinatorics_Button"));
        Home_Combinatorics_Button->setGeometry(QRect(50, 110, 101, 51));
        Home_Conversions_Button = new QPushButton(centralWidget);
        Home_Conversions_Button->setObjectName(QStringLiteral("Home_Conversions_Button"));
        Home_Conversions_Button->setGeometry(QRect(50, 170, 101, 51));
        HomeWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HomeWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        HomeWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionHome);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindow)
    {
        HomeWindow->setWindowTitle(QApplication::translate("HomeWindow", "HomeWindow", 0));
        actionHome->setText(QApplication::translate("HomeWindow", "Home", 0));
        actionExit->setText(QApplication::translate("HomeWindow", "Exit", 0));
        Home_Encryption_Button->setText(QApplication::translate("HomeWindow", "Encryption", 0));
        Home_Combinatorics_Button->setText(QApplication::translate("HomeWindow", "Combinatorics", 0));
        Home_Conversions_Button->setText(QApplication::translate("HomeWindow", "Conversions", 0));
        menuFile->setTitle(QApplication::translate("HomeWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("HomeWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("HomeWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H

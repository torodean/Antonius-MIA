/********************************************************************************
** Form generated from reading UI file 'encryptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCRYPTIONWINDOW_H
#define UI_ENCRYPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_encryptionwindow
{
public:
    QAction *actionHome;
    QAction *actionExit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *encryptionwindow)
    {
        if (encryptionwindow->objectName().isEmpty())
            encryptionwindow->setObjectName(QStringLiteral("encryptionwindow"));
        encryptionwindow->resize(1000, 700);
        actionHome = new QAction(encryptionwindow);
        actionHome->setObjectName(QStringLiteral("actionHome"));
        actionExit = new QAction(encryptionwindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralwidget = new QWidget(encryptionwindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        encryptionwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(encryptionwindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        encryptionwindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionHome);
        menuFile->addAction(actionExit);

        retranslateUi(encryptionwindow);

        QMetaObject::connectSlotsByName(encryptionwindow);
    } // setupUi

    void retranslateUi(QMainWindow *encryptionwindow)
    {
        encryptionwindow->setWindowTitle(QApplication::translate("encryptionwindow", "MainWindow", 0));
        actionHome->setText(QApplication::translate("encryptionwindow", "Home", 0));
        actionExit->setText(QApplication::translate("encryptionwindow", "Exit", 0));
        menuFile->setTitle(QApplication::translate("encryptionwindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("encryptionwindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("encryptionwindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class encryptionwindow: public Ui_encryptionwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCRYPTIONWINDOW_H

#include "homewindow.h"
#include <QApplication>
#include "programconstants.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    HomeWindow window;
    ProgramConstants constants;

    QString windowTitle = "D0sag3 Command Version " + constants.getProgramVersion();
    QIcon D3CIcon("C:/Users/User/Desktop/D3C/Images/form_logo_icon.ico");
    window.setWindowIcon(D3CIcon);
    window.setWindowTitle(windowTitle);
    window.setStyleSheet("background-image:url(C:/Users/User/Desktop/D3C/Images/3d_abstract_white-HD_half.jpg)");
    window.setMaximumHeight(700);
    window.setMaximumWidth(1000);

    window.show();

    return a.exec();
}

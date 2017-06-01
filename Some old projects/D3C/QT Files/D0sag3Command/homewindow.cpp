#include "homewindow.h"
#include "programconstants.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::HomeWindow){
    ui->setupUi(this);
}

HomeWindow::~HomeWindow(){
    delete ui;
}

void HomeWindow::on_Home_Encryption_Button_clicked(){

}

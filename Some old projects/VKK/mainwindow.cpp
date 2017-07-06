#define WINVER 0x0500
#include <windows.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "keys.h"
#include <math.h>
#include <iostream>
#include<fstream>


using namespace std;

Keys type;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

//Cleared input values for a WoW tournament fee calculation
void MainWindow::clearBoxes(){
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
}

//Button Spam - took two parameters (button, amount)
void MainWindow::on_pushButton_3_clicked(){
    Sleep(5000);
    QString character = ui->lineEdit_2->text();
    int amount = ui->lineEdit_3->text().toInt();


        for (int i=0;i<amount;i++){
            type.press(character);
            Sleep(500);
        }
}

//This Function was used for a World of Warcraft tournament fee calculations
void MainWindow::on_pushButton_5_clicked(){
    long achievement = ui->lineEdit_6->text().toLong();
    long pets = ui->lineEdit_7->text().toLong();
    double long feefactor = .000066;
    double long petfactor = pow(pets/(pets-10.0),5.0);
    double long fee = achievement*pets*feefactor*petfactor;
    int gold = fee;
    double long fee100= fee*100;
    int silver = fee100;
    silver = silver %100;
    double long fee10000= fee100*100;
    int copper = fee10000;
    copper = copper%100;
    ui->lineEdit_8->setText(QString::number(gold));
    ui->lineEdit_9->setText(QString::number(silver));
    ui->lineEdit_10->setText(QString::number(copper));

}

//an old world of warcraft function for duplicating a letter
void MainWindow::on_pushButton_2_clicked(){
    Sleep(5000);
    int copies = ui->lineEdit->text().toInt();
    QString to = ui->lineEdit_5->text();
    for(int i=0;i<copies;i++){
        type.type(to);
        Sleep(200);
        type.tab();
        Sleep(200);
        type.type("subject");
        Sleep(200);
        type.tab();
        Sleep(200);
        type.paste();
        Sleep(200);
        type.leftclick();
        Sleep(1500);
    }
}

//an old WoW function for mass mailing a letter to a list of people.
void MainWindow::on_pushButton_clicked(){
    Sleep(5000);
    std::cout << "Mass Mailing started" << endl;
    string file = ui->lineEdit_4->text().toStdString();
    cout << "File: " << file << endl;
    ifstream myFile;
    string output;

    if (file == "Mailing_List_Wyrmrest.txt"){
        myFile.open("../../../../../Users/User/Desktop/Desktop/WoW/Petco/Wyrmrest Accord/Mailing_List_Wyrmrest.txt");
    }else{
        ui->lineEdit_4->setText("File Not found...");
        myFile.close();
    }

    if(myFile.is_open()){
        while (std::getline(myFile, output)) {
            std::cout << output << endl;
            type.type(QString::fromStdString(output));
            Sleep(200);
            type.type("-wyrmrestaccord");
            Sleep(200);
            type.tab();
            Sleep(200);
            type.type("petco event");
            Sleep(200);
            type.tab();
            Sleep(200);
            type.paste();
            Sleep(200);
            type.leftclick();
            Sleep(1500);
        }
    }
    myFile.close();
}

//exited app
void MainWindow::on_actionExit_triggered(){
    qApp->quit();
}

void MainWindow::on_actionClear_triggered(){
    clearBoxes();
}

//myfile.open("../build-D0sag3Command-Desktop_Qt_5_3_MinGW_32bit-Release/D3CCL.txt");

//Corresponding to a "minecraft dig" button. This was for perpetual minecraft digging motions.
void MainWindow::on_pushButton_4_clicked()
{
    Sleep(4000);
    INPUT ip;
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = 0x57; // virtual-key code for the "w" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    INPUT    Input={0};
    // left down
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1,&Input,sizeof(INPUT));
    Sleep(2000000);
    // left up
    ::ZeroMemory(&Input,sizeof(INPUT));
    Input.type      = INPUT_MOUSE;
    Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
    ::SendInput(1,&Input,sizeof(INPUT));
    Sleep(100);
    // Release the "w" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

//Performed some math. I literally have zero idea what I made this for but it must have done something important.
void MainWindow::on_pushButton_6_clicked()
{
    std::cout << "start" << std::endl;
    int limit=100;
    int n1,n2;
    for(int m=1;m<limit;m++){
        for(int x=1;x<limit;x++){
            for(int y=1;y<limit;y++){
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                m=-m;
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                x=-x;
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                y=-y;
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                x=-x;
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                m=-m; x=-x; y=-y;
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                y=-y;
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                x=-x;
                n1=(35*m+26)/x;
                n2=(7*m+3)/y;
                if(7*m*x-35*m*y+3*x-26*y==0 && 35*m+26-x*n1 == 0 && 7*m+3-y*n2==0 ){
					std::cout << "m: " << m << ", ";
					std::cout << "x: " << x << ", ";
					std::cout << "y: " << y << std::endl; std::cout << "n1: " << n1 << ", " << "n2: " << n2 << std::endl;
                }
                y=-y;
            }
        }
    }
    std::cout << "finished." << std::endl;
}

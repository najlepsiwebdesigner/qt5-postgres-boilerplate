#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

int testFcn() {
   std::cout << "testFcn!" << std::endl;
    return 0;
}


MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow)
{
    // this has to go before connect!
    ui->setupUi(this);

    connect(ui->connectPG, SIGNAL(clicked()), this, SLOT(testClick()));

//    connect(ui->connectPG,&QPushButton::clicked, testFcn);
}

MainWindow::~MainWindow()
{
}

void MainWindow::testClick() {
    std::cout << "testClick!" << std::endl;
}

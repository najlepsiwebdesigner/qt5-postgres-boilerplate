#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <pqxx/pqxx>
#include <iostream>

using namespace pqxx;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try{
          connection C("dbname=scidb user=postgres password=postgres \
          hostaddr=127.0.0.1 port=5432");
          if (C.is_open()) {
             cout << "Opened database successfully: " << C.dbname() << endl;
          } else {
             cout << "Can't open database" << endl;
//             return 1;
          }
          C.disconnect ();
       }catch (const std::exception &e){
          cerr << e.what() << std::endl;
//          return 1;
       }



}

MainWindow::~MainWindow()
{
}

#include <QApplication>

#include <pqxx/pqxx>
#include <iostream>

#include "mainwindow.h"

using namespace pqxx;
using namespace std;

int main(int argc, char *argv[])
{
    try{
          connection C("dbname=scidb user=postgres password=postgres \
          hostaddr=127.0.0.1 port=5432");
          if (C.is_open()) {
             cout << "Opened database successfully: " << C.dbname() << endl;
          } else {
             cout << "Can't open database" << endl;
//             return 0;
          }
          C.disconnect ();
       }catch (const std::exception &e){
          cerr << e.what() << std::endl;
//          return 0;
       }



    QApplication app(argc, argv);

    // Retina display support for Mac OS, iOS and X11:
    // http://blog.qt.digia.com/blog/2013/04/25/retina-display-support-for-mac-os-ios-and-x11/
    //
    // AA_UseHighDpiPixmaps attribute is off by default in Qt 5.1 but will most
    // likely be on by default in a future release of Qt.
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);

    QIcon appIcon;
    appIcon.addFile(":/Icons/AppIcon32");
    appIcon.addFile(":/Icons/AppIcon128");
    app.setWindowIcon(appIcon);

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}



#include <QApplication>
//#include <QSettings>
//#include <QList>
#include <QMessageBox>
#include <QList>
//#include <QDir>
//#include "mainwindow.h"
//#include "boost/shared_ptr.hpp"
//#include "boost/scoped_ptr.hpp"
//#include "boost/ptr_container/ptr_vector.hpp"

//#include "qjson/parser.h"
#include "settings/SettingsManager.h"
#include "AppRegistry.h"
#include "settings/ConnectionRecord.h"
//#include "Core.h"

using namespace Robomongo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //for (int i = 0; i < 1; i ++)
    AppRegistry::instance().settingsManager().save();

    QMessageBox box;
    box.setText("Hello");
    box.show();

    ConnectionRecord record;
    record.setConnectionName("Hello");

    ConnectionRecord another = record;
    another.setDatabasePort(345);




//    QList<QString> *str = new QList<QString>();


//    MainWindow w;
//    w.show();

    return a.exec();
}

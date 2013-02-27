#pragma once

#include <QtGui>
#include <QWidget>

#include "robomongo/core/Core.h"
#include "robomongo/gui/ViewMode.h"

namespace Robomongo
{
    class LogWidget;
    class ExplorerWidget;
    class MongoManager;
    class SettingsManager;
    class EventBus;
    class ConnectionFailedEvent;
    class WorkAreaWidget;
    class ConnectionMenu;

    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow();
        void keyPressEvent(QKeyEvent *event);
        ViewMode viewMode() const { return _viewMode; }

    public slots:
        void manageConnections();
        void toggleOrientation();
        void enterTextMode();
        void enterTreeMode();
        void enterCustomMode();
        void executeScript();
        void toggleFullScreen2();
        void refreshConnections();
        void toggleLogs(bool show);
        void connectToServer(QAction *action);
        void handle(ConnectionFailedEvent *event);

    private:
        QLabel *_status;
        ViewMode _viewMode;
        LogWidget *_log;
        QDockWidget *_logDock;

        WorkAreaWidget *_workArea;

        /*
        ** The only Explorer in the window
        */
        ExplorerWidget *_explorer;

        App *_app;
        SettingsManager *_settingsManager;
        EventBus *_bus;

        ConnectionMenu *_connectionsMenu;
        QAction *_connectAction;
        void updateConnectionsMenu();

        void createDatabaseExplorer();
        void createTabs();
    };

    class ConnectionMenu : public QMenu
    {
        Q_OBJECT

    public:
        ConnectionMenu(QWidget *parent) : QMenu(parent) {}
        void keyPressEvent(QKeyEvent *event);
    };

}

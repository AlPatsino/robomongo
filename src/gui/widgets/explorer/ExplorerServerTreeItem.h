#ifndef EXPLORERSERVERTREEITEM_H
#define EXPLORERSERVERTREEITEM_H

#include <QTreeWidgetItem>
#include <QObject>
#include "Core.h"
#include "events/MongoEvents.h"

namespace Robomongo
{
    class Dispatcher;

    class ExplorerServerTreeItem : public QObject, public QTreeWidgetItem
    {
        Q_OBJECT

    public:

        /*
        ** Constructs ExplorerServerTreeItem
        */
        ExplorerServerTreeItem(const MongoServerPtr &server);
        ~ExplorerServerTreeItem();

        bool event(QEvent *event);

        /*
        ** Expand server tree item;
        */
        void expand();


    public slots:

        /*
        **
        */
        void databaseRefreshed(const QList<MongoDatabasePtr> &dbs);


    private:
        void handle(DatabaseListLoadedEvent *event);

    private:

        MongoServerPtr _server;
        Dispatcher &_dispatcher;

    };
}


#endif // EXPLORERSERVERTREEITEM_H

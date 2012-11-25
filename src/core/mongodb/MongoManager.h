#ifndef MONGOMANAGER_H
#define MONGOMANAGER_H

#include <QObject>
#include <QHash>
#include <QUuid>
#include "Core.h"

namespace Robomongo
{
    class MongoManager : public QObject
    {
        Q_OBJECT

    public:
        MongoManager(Dispatcher *dispatcher, QObject *parent = 0);

    public slots:
        /**
         * @brief Connect to MongoDB server
         */
        void connectToServer(const ConnectionRecordPtr &connectionRecord);

    signals:

        /**
         * @brief Fires when connected
         */
        void connected(const MongoServerPtr &server);

        void connectionFailed(const MongoServerPtr &server);

        /**
         * @brief Fires when disconnected
         */
        void disconnected(const MongoServerPtr &server);

    private slots:
        void onConnectionEstablished(const MongoServerPtr &server, const QString &address);
        void onConnectionFailed(const MongoServerPtr &server, const QString &address);

    private:
        QList<MongoServerPtr> _servers;
        Dispatcher *_dispatcher;
    };
}

#endif // MONGOMANAGER_H

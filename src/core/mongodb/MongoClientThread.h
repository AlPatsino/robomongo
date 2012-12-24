#ifndef MONGOCLIENTTHREAD_H
#define MONGOCLIENTTHREAD_H

#include <QObject>
#include <QThread>

namespace Robomongo
{
    class MongoClient;

    class MongoClientThread : public QThread
    {
        Q_OBJECT
    public:
        explicit MongoClientThread(MongoClient *client);

        MongoClient *client() const { return _client; }

    protected:
        void run();

    private:
        MongoClient *_client;

    };
}

#endif // MONGOCLIENTTHREAD_H

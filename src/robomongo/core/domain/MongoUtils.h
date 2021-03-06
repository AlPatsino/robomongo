#pragma once

#include <QString>
#include <mongo/client/dbclient.h>

namespace Robomongo
{
    class MongoUtils
    {
    public:
        MongoUtils();

        /**
         * @brief Extracts short name from fullName (i.e. collection namespace)
         */
        static QString getName(const QString &fullName);

        /**
         * @throws mongo::MsgAssertionException
         */
        static mongo::BSONObj fromjson(const QString &text);

        static QString buildNiceSizeString(int sizeBytes);
        static QString buildNiceSizeString(double sizeBytes);
        static QString buildPasswordHash(const QString &username, const QString &password);

//        static
    };
}

#ifndef DEBUG_H
#define DEBUG_H

#include <QDebug>
#include <QDateTime>

#define MSG_TO_LOG() qDebug() << QDateTime::currentDateTime().toString("HH:mm:ss.zzz") << __PRETTY_FUNCTION__ << "LINE:" << __LINE__

#endif // DEBUG_H

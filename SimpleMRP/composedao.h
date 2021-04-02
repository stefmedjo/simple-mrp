#ifndef COMPOSEDAO_H
#define COMPOSEDAO_H

#include <QObject>
#include "compose.h"

class ComposeDAO : public QObject
{
    Q_OBJECT
public:
    explicit ComposeDAO(QObject *parent = 0);
    
    bool create(Compose *c);
    bool remove(Compose *c);
    bool update(Compose *c);
    QList<Compose *> findAll();
    Compose *find(QString i);


signals:
    
public slots:
    
};

#endif // COMPOSEDAO_H

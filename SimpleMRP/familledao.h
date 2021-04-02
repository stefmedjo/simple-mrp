#ifndef FAMILLEDAO_H
#define FAMILLEDAO_H

#include <QObject>
#include "QDateTime"
#include <QSqlTableModel>
#include "famille.h"
#include "article.h"

class FamilleDAO : public QObject
{
    Q_OBJECT
public:
    explicit FamilleDAO(QObject *parent = 0);

    bool create(Famille *famille);
    bool remove(Famille *famille);
    bool update(Famille *famille);
    QList<Famille *> findAll(Famille *famille);
    Famille *find(QString i);

signals:
    
public slots:
    
};

#endif // FAMILLEDAO_H

#ifndef ORDREDEBUTDAO_H
#define ORDREDEBUTDAO_H

#include <QObject>
#include "QSqlTableModel"
#include "ordredebut.h"
class OrdreDebutDAO : public QObject
{
    Q_OBJECT
public:
    explicit OrdreDebutDAO(QObject *parent = 0);

    bool create(OrdreDebut *ordredebut);
    bool remove(OrdreDebut *ordredebut);
    bool update(OrdreDebut *ordredebut);
    QList<OrdreDebut *> findAll();
    OrdreDebut *find(QString i);

signals:
    
public slots:
    
};

#endif // ORDREDEBUTDAO_H

#ifndef COMPOSANTDAO_H
#define COMPOSANTDAO_H

#include <QObject>
#include "QtWidgets"
#include "QSqlTableModel"

#include "composant.h"

#include "famille.h"
#include "fournisseurdao.h"

class Compose;

class ComposantDAO : public QObject
{
    Q_OBJECT
public:
    explicit ComposantDAO(QObject *parent = 0);
    
    bool create(Composant *composant);
    bool remove(Composant *composant);
    bool update(Composant *composant);
    QList<Composant *> findAll();
    Composant *find(QString i);


signals:
    
public slots:
    
};

#endif // COMPOSANTDAO_H

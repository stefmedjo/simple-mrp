#ifndef FOURNISSEURDAO_H
#define FOURNISSEURDAO_H

#include <QObject>
#include "fournisseur.h"
#include "QSqlTableModel"
#include "QDateTime"
#include "composant.h"
#include "composantdao.h"

class FournisseurDAO : public QObject
{
    Q_OBJECT
public:
    explicit FournisseurDAO(QObject *parent = 0);
    
    bool create(Fournisseur *fournisseur);
    bool remove(Fournisseur *fournisseur);
    bool update(Fournisseur *fournisseur);
    QList<Fournisseur *> findAll();
    Fournisseur *find(QString i);

signals:
    
public slots:
    
};

#endif // FOURNISSEURDAO_H

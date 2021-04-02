#include "ordredebutdao.h"

OrdreDebutDAO::OrdreDebutDAO(QObject *parent) :
    QObject(parent)
{
}

bool OrdreDebutDAO::create(OrdreDebut *ordredebut)
{
    QSqlTableModel modele;
    modele.setTable("ordredebut");
    int row = 0;
    modele.insertRows(row,1);
    modele.setData()
}

bool OrdreDebutDAO::remove(OrdreDebut *ordredebut)
{
}

bool OrdreDebutDAO::update(OrdreDebut *ordredebut)
{
}

QList<OrdreDebut *> OrdreDebutDAO::findAll()
{
}

OrdreDebut *OrdreDebutDAO::find(QString i)
{
}

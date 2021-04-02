#include "periode.h"

Periode::Periode(QObject *parent) :
    QObject(parent)
{
}

QString Periode::getId()
{
    return id;
}

QString Periode::getDateDebut()
{
    return dateDebut;
}

QString Periode::getDateFin()
{
    return dateFin;
}

void Periode::setDateDebut(QString date)
{
    dateDebut = date;
}

void Periode::setDateFin(QString date)
{
    dateFin = date;
}

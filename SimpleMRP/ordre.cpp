#include "ordre.h"

Ordre::Ordre(QObject *parent) :
    QObject(parent)
{
}

void Ordre::setType(QString ty)
{
    type = ty;
}

void Ordre::setQuantite(QString value)
{
    quantite = value;
}

QString Ordre::getId()
{
    return id;
}

QString Ordre::getType()
{
    return type;
}

QString Ordre::getQuantite()
{
    return quantite;
}

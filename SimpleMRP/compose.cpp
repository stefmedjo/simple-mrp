#include "compose.h"

Compose::Compose(QObject *parent) :
    Article(parent)
{
}

void Compose::addComposant(Composant *c, double val)
{
    listeComposant.insert(c,val);
}

void Compose::removeComposant(Composant *c)
{
    listeComposant.remove(c);
}

QHash<Composant *, double> Compose::getListeComposant()
{
    return listeComposant;
}

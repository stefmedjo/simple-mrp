#include "composant.h"

Composant::Composant(QObject *parent) :
    Article(parent)
{
}

void Composant::addFournisseur(Fournisseur *f)
{
    listeFournisseur.append(f);
}

void Composant::removeFournisseur(Fournisseur *f)
{
    listeFournisseur.removeOne(f);
}

QList<Fournisseur *> Composant::getListeFournisseur()
{
    return listeFournisseur;
}

void Composant::addCompose(Compose *c, double val)
{
    listeCompose.insert(c, val);
}

void Composant::removeCompose(Compose *c)
{
    listeCompose.remove(c);
}

QHash<Compose *, double> Composant::getListeCompose()
{
    return listeCompose;
}

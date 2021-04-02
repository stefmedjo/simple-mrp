#include "fournisseur.h"

Fournisseur::Fournisseur(QObject *parent) :
    QObject(parent)
{
}

void Fournisseur::setId(QString i)
{
    id = i;
}

void Fournisseur::setNom(QString n)
{
    nom = n;
}

void Fournisseur::setEmail(QString e)
{
    email = e;
}

void Fournisseur::setAdresse(QString a)
{
    adresse = a;
}

void Fournisseur::addComposant(Composant *c)
{
    listeComposant.append(c);
}

void Fournisseur::removeComposant(Composant *c)
{
    listeComposant.removeOne(c);
}

void Fournisseur::setTelephone(QString tel)
{
    telephone = tel;
}

QString Fournisseur::getId()
{
    return id;
}

QString Fournisseur::getNom()
{
    return nom;
}

QString Fournisseur::getEmail()
{
    return email;
}

QString Fournisseur::getAdresse()
{
    return adresse;
}

QList<Composant *> Fournisseur::getListeComposant()
{
    return listeComposant;
}

QString Fournisseur::getTelephone()
{
    return telephone;
}

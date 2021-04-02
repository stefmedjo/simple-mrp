#include "famille.h"

Famille::Famille(QObject *parent) :
    QObject(parent)
{
}


void Famille::setId(QString a)
{
    id = a;
}

QString Famille::getId()
{
    return id;
}

void Famille::setNom(QString a)
{
    nom = a;
}

QString Famille::getNom()
{
    return nom;
}

void Famille::addArticle(Article *article)
{
    listeArticle.append(article);
}

void Famille::removeArticle(Article *article)
{
    listeArticle.removeOne(article);
}

QList<Article *> Famille::getListeArticle()
{
    return listeArticle;
}

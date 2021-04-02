#include "article.h"

Article::Article(QObject *parent) :
    QObject(parent)
{
}

void Article::setId(QString a)
{
    id = a;
}

QString Article::getId()
{
    return id;
}

void Article::setDesignation(QString valeur)
{
    designation = valeur;
}

QString Article::getDesignation()
{
    return designation;
}

void Article::setUnite(QString valeur)
{
    unite = valeur;
}

QString Article::getUnite()
{
    return unite;
}

void Article::setDelai(QString valeur)
{
    delai = valeur;
}

QString Article::getDelai()
{
    return delai;
}

void Article::setLot(QString valeur)
{
    lot = valeur;
}

QString Article::getLot()
{
    return lot;
}

void Article::setPrixVente(QString p)
{
    prixVente = p;
}

QString Article::getPrixVente()
{
    return prixVente;
}

void Article::setPrixAchat(QString prix)
{
    prixAchat = prix;
}

QString Article::getPrixAchat()
{
    return prixAchat;
}

void Article::setNiveauStock(QString valeur)
{
    niveauStock = valeur;
}

QString Article::getNiveauStock()
{
    return niveauStock;
}

void Article::setFamille(Famille *family)
{
    famille = family;
}

Famille *Article::getFamille()
{
    return famille;
}

void Article::setCheminPhoto(QString chemin)
{
    cheminPhoto = chemin;
}

QString Article::getCheminPhoto()
{
    return cheminPhoto;
}

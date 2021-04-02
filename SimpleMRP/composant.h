#ifndef COMPOSANT_H
#define COMPOSANT_H

#include "article.h"
#include "QHash"

class Fournisseur;
class Compose;

class Composant : public Article
{
    Q_OBJECT
public:
    explicit Composant(QObject *parent = 0);
    
    void addFournisseur(Fournisseur *f);
    void removeFournisseur(Fournisseur *f);
    QList<Fournisseur *> getListeFournisseur();

    void addCompose(Compose *c, double val);
    void removeCompose(Compose *c);
    QHash<Compose *, double> getListeCompose();


signals:
    
public slots:

private:
    QList<Fournisseur *> listeFournisseur;
    QHash<Compose *, double> listeCompose;
};

#endif // COMPOSANT_H

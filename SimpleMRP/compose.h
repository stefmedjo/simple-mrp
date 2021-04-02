#ifndef COMPOSE_H
#define COMPOSE_H

#include "article.h"
#include "QHash"
class Composant;

class Compose : public Article
{
    Q_OBJECT
public:
    explicit Compose(QObject *parent = 0);

    void addComposant(Composant *c, double val);
    void removeComposant(Composant *c);
    QHash<Composant *, double> getListeComposant();
    
signals:
    
public slots:

private:
    QHash<Composant *, double> listeComposant;

    
};

#endif // COMPOSE_H

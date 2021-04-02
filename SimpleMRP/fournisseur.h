#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QObject>
class Composant;

class Fournisseur : public QObject
{
    Q_OBJECT
public:
    explicit Fournisseur(QObject *parent = 0);
    
    void setId(QString i);
    void setNom(QString n);
    void setEmail(QString e);
    void setAdresse(QString a);
    void addComposant(Composant *c);
    void removeComposant(Composant *c);
    void setTelephone(QString tel);

    QString getId();
    QString getNom();
    QString getEmail();
    QString getAdresse();
    QList<Composant *> getListeComposant();
    QString getTelephone();

signals:
    
public slots:
    
private:
    QString id;
    QString nom;
    QString email;
    QString adresse;
    QString telephone;
    QList<Composant *> listeComposant;
};

#endif // FOURNISSEUR_H

#ifndef ORDRE_H
#define ORDRE_H

#include <QObject>

class Ordre : public QObject
{
    Q_OBJECT
public:
    explicit Ordre(QObject *parent = 0);

    void setType(QString ty);
    void setQuantite(QString value);

    QString getId();
    QString getType();
    QString getQuantite();
    
signals:
    
public slots:

private:
    QString id;
    QString quantite;
    QString type;

};

#endif // ORDRE_H

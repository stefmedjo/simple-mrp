#ifndef PERIODE_H
#define PERIODE_H

#include <QObject>

class Periode : public QObject
{
    Q_OBJECT
public:
    explicit Periode(QObject *parent = 0);
    
    QString getId();
    QString getDateDebut();
    QString getDateFin();

    void setDateDebut(QString date);
    void setDateFin(QString date);

signals:
    
public slots:


private:
    QString id;
    QString dateDebut;
    QString dateFin;
    
};

#endif // PERIODE_H

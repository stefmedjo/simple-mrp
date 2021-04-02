#ifndef ORDREFIN_H
#define ORDREFIN_H

#include "ordre.h"
#include "ordredebut.h"

class OrdreFin : public Ordre
{
    Q_OBJECT
public:
    explicit OrdreFin(QObject *parent = 0);
    
    void setOrdreDebut(OrdreDebut *ordre);
    OrdreDebut *getOrdreDebut();

signals:
    
public slots:


private:
    OrdreDebut *ordreDebut;
    
};

#endif // ORDREFIN_H

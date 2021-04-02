#include "ordrefin.h"

OrdreFin::OrdreFin(QObject *parent) :
    Ordre(parent)
{
}

void OrdreFin::setOrdreDebut(OrdreDebut *ordre)
{
    ordreDebut = ordre;
}


OrdreDebut *OrdreFin::getOrdreDebut()
{
    return ordreDebut;
}

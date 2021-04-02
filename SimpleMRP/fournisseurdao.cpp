#include "fournisseurdao.h"

FournisseurDAO::FournisseurDAO(QObject *parent) :
    QObject(parent)
{
}

bool FournisseurDAO::create(Fournisseur *fournisseur)
{
    QSqlTableModel modele;
    modele.setTable("fournisseur");
    int row = 0;
    modele.insertRows(row,1);
    modele.setData(modele.index(row,1), fournisseur->getNom());
    modele.setData(modele.index(row,2), fournisseur->getAdresse());
    modele.setData(modele.index(row,3), fournisseur->getEmail());
    modele.setData(modele.index(row,4), fournisseur->getTelephone());
    modele.setData(modele.index(row,5), QDateTime::currentDateTime());

    if(modele.submitAll()){
        modele.clear();
        modele.setTable("livrerPar");
        for(int i = 0; i < fournisseur->getListeComposant().length(); i++){
           int row = 0;
           modele.insertRows(row,1);
           modele.setData(modele.index(row,1), fournisseur->getId());
           modele.setData(modele.index(row,2), fournisseur->getListeComposant().at(i)->getId());
           modele.setData(modele.index(row,3), QDateTime::currentDateTime());
           modele.submitAll();
        }
        return true;
    }else{
        return false;
    }
}

bool FournisseurDAO::remove(Fournisseur *fournisseur)
{
    QSqlTableModel modele;
    modele.setTable("fournisseur");
    modele.setFilter("id="+fournisseur->getId());
    modele.select();
    if(modele.rowCount() > 0){
        modele.removeRows(0,1);
        if(modele.submitAll()){
            modele.clear();
            modele.setTable("livrerPar");
            modele.setFilter("fournisseur_id=" + fournisseur->getId());
            modele.select();
            if(modele.rowCount() > 0){
                for(int j = 0; j < modele.rowCount(); j++){
                    modele.removeRows(j,1);
                    modele.submitAll();
                }
            }
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool FournisseurDAO::update(Fournisseur *fournisseur)
{
    QSqlTableModel modele;
    modele.setTable("fournisseur");
    modele.setFilter("id=" + fournisseur->getId());
    modele.select();
    if(modele.rowCount() > 0){
        int row = 0;
        modele.setData(modele.index(row,1), fournisseur->getNom());
        modele.setData(modele.index(row,2), fournisseur->getAdresse());
        modele.setData(modele.index(row,3), fournisseur->getEmail());
        modele.setData(modele.index(row,4), fournisseur->getTelephone());
        modele.setData(modele.index(row,5), QDateTime::currentDateTime());
        modele.submitAll();

        modele.clear();
        modele.setTable("livrerPar");
        modele.setFilter("fournisseur_id=" + fournisseur->getId());
        modele.select();
        if(modele.rowCount() > 0){
            for(int j = 0; j < modele.rowCount(); j++){
                modele.removeRows(j,1);
                modele.submitAll();
            }
        }

        modele.clear();
        modele.setTable("livrerPar");
        for(int i = 0; i < fournisseur->getListeComposant().length(); i++){
           int row = 0;
           modele.insertRows(row,1);
           modele.setData(modele.index(row,1), fournisseur->getId());
           modele.setData(modele.index(row,2), fournisseur->getListeComposant().at(i)->getId());
           modele.setData(modele.index(row,3), QDateTime::currentDateTime());
           modele.submitAll();
        }

        return true;
    }else{
        return false;
    }
}

QList<Fournisseur *> FournisseurDAO::findAll()
{
    QList<Fournisseur *> listeFournisseur;
    QSqlTableModel modele;
    modele.setTable("fournisseur");
    modele.select();
    for(int i = 0; i < modele.rowCount(); i++){
        Fournisseur *f = new Fournisseur;
        FournisseurDAO fDAO;
        f = fDAO.find(modele.data(modele.index(i,0)).toString());
        listeFournisseur.append(f);
    }
    return listeFournisseur;
}

Fournisseur *FournisseurDAO::find(QString i)
{
    Fournisseur *fournisseur = new Fournisseur;
    QSqlTableModel modele;
    modele.setTable("fournisseur");
    modele.setFilter("id="+i);
    modele.select();
    if(modele.rowCount() > 0){
        fournisseur->setId(i);
        fournisseur->setNom(modele.data(modele.index(0,1)).toString());
        fournisseur->setAdresse(modele.data(modele.index(0,2)).toString());
        fournisseur->setEmail(modele.data(modele.index(0,3)).toString());
        fournisseur->setTelephone(modele.data(modele.index(0,4)).toString());

        modele.clear();
        modele.setTable("composant");
        modele.setFilter("fournisseur_id=" + fournisseur->getId());
        modele.select();
        if(modele.rowCount() > 0){
            for(int j = 0; j < modele.rowCount(); j++){
                Composant *c = new Composant;
                ComposantDAO cDAO;
                c = cDAO.find(modele.data(modele.index(j,1)).toString());
                fournisseur->addComposant(c);
            }
        }

    }
    return fournisseur;
}

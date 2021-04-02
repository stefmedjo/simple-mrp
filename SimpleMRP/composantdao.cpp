#include "composantdao.h"

ComposantDAO::ComposantDAO(QObject *parent) :
    QObject(parent)
{
}

bool ComposantDAO::create(Composant *composant)
{
    QSqlTableModel modele;
    modele.setTable("composant");
    int row = 0;
    modele.insertRows(row,1);
    modele.setData(modele.index(row,1), composant->getDesignation());
    modele.setData(modele.index(row,2), composant->getDelai().toInt());
    modele.setData(modele.index(row,3), composant->getLot().toDouble());
    modele.setData(modele.index(row,4), composant->getNiveauStock().toDouble());
    modele.setData(modele.index(row,5), composant->getPrixAchat().toDouble());
    modele.setData(modele.index(row,6), composant->getPrixVente().toDouble());
    modele.setData(modele.index(row,7), composant->getUnite());
    modele.setData(modele.index(row,8), composant->getFamille()->getId());
    modele.setData(modele.index(row,9), composant->getCheminPhoto());
    modele.setData(modele.index(row,10), QDateTime::currentDateTime());

    if(modele.submitAll()){
        return true;
    }else{
        return false;
    }

}

bool ComposantDAO::remove(Composant *composant)
{
    QSqlTableModel modele;
    modele.setTable("composant");
    modele.setFilter("id=" + composant->getId());
    modele.select();
    if(modele.rowCount() > 0){
        modele.removeRows(0,1);
        if(modele.submitAll()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool ComposantDAO::update(Composant *composant)
{
    QSqlTableModel modele;
    modele.setTable("composant");
    modele.setFilter("id=" + composant->getId());
    modele.select();
    if(modele.rowCount() > 0){
        int row = 0;
        modele.setData(modele.index(row,1), composant->getDesignation());
        modele.setData(modele.index(row,2), composant->getDelai().toInt());
        modele.setData(modele.index(row,3), composant->getLot().toDouble());
        modele.setData(modele.index(row,4), composant->getNiveauStock().toDouble());
        modele.setData(modele.index(row,5), composant->getPrixAchat().toDouble());
        modele.setData(modele.index(row,6), composant->getPrixVente().toDouble());
        modele.setData(modele.index(row,7), composant->getUnite());
        modele.setData(modele.index(row,8), composant->getFamille()->getId());
        modele.setData(modele.index(row,9), composant->getCheminPhoto());
        modele.setData(modele.index(row,10), QDateTime::currentDateTime());
        if(modele.submitAll()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

QList<Composant *> ComposantDAO::findAll()
{
    QList<Composant *> listeComposant;
    QSqlTableModel modele;
    modele.setTable("composant");
    modele.select();
    if(modele.rowCount() > 0){
        for(int i = 0; i < modele.rowCount(); i++){
            ComposantDAO c;
            Composant *com = new Composant;
            com = c.find(modele.data(modele.index(i,0)).toString());
            listeComposant.append(com);
        }
    }
    return listeComposant;
}

Composant *ComposantDAO::find(QString i)
{
    Composant *composant = new Composant;
    QSqlTableModel modele;
    modele.setTable("composant");
    modele.setFilter("id=" + i);
    modele.select();
    if(modele.rowCount() > 0){

        composant->setId(i);
        composant->setDesignation(modele.data(modele.index(0,1)).toString());
        composant->setDelai(modele.data(modele.index(0,2)).toString());
        composant->setLot(modele.data(modele.index(0,3)).toString());
        composant->setNiveauStock(modele.data(modele.index(0,4)).toString());
        composant->setPrixAchat(modele.data(modele.index(0,5)).toString());
        composant->setPrixVente(modele.data(modele.index(0,6)).toString());
        composant->setUnite(modele.data(modele.index(0,7)).toString());
        composant->setCheminPhoto(modele.data(modele.index(0,8)).toString());
    }

    modele.clear();
    modele.setTable("livrerPar");
    modele.setFilter("composant_id=" + i);
    modele.select();
    if(modele.rowCount() > 0){
        for(int j = 0; j < modele.rowCount(); j++){

            //Charger la liste des fournisseurs ici
            FournisseurDAO f;
            Fournisseur *fournisseur = new Fournisseur;
            fournisseur = f.find(modele.data(modele.index(j,1)).toString());
            composant->addFournisseur(fournisseur);

        }
    }

    modele.clear();
    modele.setTable("nomenclature");
    modele.setFilter("composant_id=" + i);
    modele.select();
    if(modele.rowCount() > 0){
        for(int j = 0; j < modele.rowCount(); j++){
            //Creation d'un composé vide
            //Création d'un composé DAO
            //composé vide = composé DAO
            //Ajout du composé dans la liste des composés de ce composant
        }
    }

    return composant;
}

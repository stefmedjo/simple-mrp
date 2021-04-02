#include "familledao.h"

FamilleDAO::FamilleDAO(QObject *parent) :
    QObject(parent)
{
}

bool FamilleDAO::create(Famille *famille)
{
    QSqlTableModel modele;
    modele.setTable("famille");
    int row = 0;
    modele.insertRows(row,1);
    modele.setData(modele.index(row,0), famille->getId());
    modele.setData(modele.index(row,1), famille->getNom());
    modele.setData(modele.index(row,2), QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    if(modele.submitAll()){
        return true;
    }else{
        return false;
    }
}

bool FamilleDAO::remove(Famille *famille)
{
    QSqlTableModel modele;
    modele.setTable("famille");
    modele.setFilter("id=" + famille->getId());
    modele.select();
    if(modele.rowCount() > 0){
        modele.removeRows(0,1);
    }
    if(modele.submitAll()){
        return true;
    }else{
        return false;
    }
}

bool FamilleDAO::update(Famille *famille)
{
    QSqlTableModel modele;
    modele.setTable("famille");
    modele.setFilter("id=" + famille->getId());
    modele.select();
    if(modele.rowCount() > 0){
        modele.setData(modele.index(0,1), famille->getNom());
        modele.setData(modele.index(0,1), QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
        if(modele.submitAll()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

Famille *FamilleDAO::find(QString i)
{
    QSqlTableModel modele;
    modele.setTable("famille");
    modele.setFilter("id=" + i);
    modele.select();

    Famille *famille = new Famille();
    famille->setId(modele.data(modele.index(0,0)).toString());
    famille->setNom(modele.data(modele.index(0,1)).toString());

    modele.clear();

    modele.setTable("article");
    modele.setFilter("famille_id=" + i);
    modele.select();

    if(modele.rowCount()){
        for(int j = 0; j < modele.rowCount(); j++){
            Article *article = new Article;
            article->setId(modele.data(modele.index(j,0)).toString());
            famille->addArticle(article);
        }
    }

    return famille;
}


QList<Famille *> FamilleDAO::findAll(Famille *famille)
{
    QList<Famille *> listeFamille;
    QSqlTableModel modele;
    modele.setTable("famille");
    modele.setFilter("id=" + famille->getId());
    modele.select();
    if(modele.rowCount() > 0){
        for(int i = 0; i < modele.rowCount(); i++){
            QString id = modele.data(modele.index(i,0)).toString();
            Famille *f = new Famille();
            FamilleDAO familleDAO;
            f = familleDAO.find(id);
            listeFamille.append(f);
        }
    }
    return listeFamille;
}

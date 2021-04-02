#include <QObject>
class Famille;

class Article : public QObject
{
    Q_OBJECT
public:
    explicit Article(QObject *parent = 0);

    void setId(QString a);
    QString getId();

    void setDesignation(QString designation);
    QString getDesignation();

    void setUnite(QString unite);
    QString getUnite();

    void setDelai(QString delai);
    QString getDelai();

    void setLot(QString lot);
    QString getLot();

    void setPrixVente(QString p);
    QString getPrixVente();

    void setPrixAchat(QString prix);
    QString getPrixAchat();

    void setNiveauStock(QString valeur);
    QString getNiveauStock();

    void setFamille(Famille *family);
    Famille *getFamille();

    void setCheminPhoto(QString chemin);
    QString getCheminPhoto();

signals:
    
public slots:

private:

    QString id;
    QString designation;
    QString unite;
    QString delai;
    QString lot;
    QString prixVente;
    QString prixAchat;
    QString niveauStock;
    Famille *famille;
    QString cheminPhoto;
};


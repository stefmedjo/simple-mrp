#include <QObject>
class Article;

class Famille : public QObject
{
    Q_OBJECT
public:
    explicit Famille(QObject *parent = 0);

    void setId(QString id);
    QString getId();

    void setNom(QString nom);
    QString getNom();

    void addArticle(Article *article);
    void removeArticle(Article *article);
    QList<Article *> getListeArticle();

signals:
    
public slots:
    
private:
    QString id;
    QString nom;
    QList<Article *> listeArticle;
};


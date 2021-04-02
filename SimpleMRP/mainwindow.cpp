#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:\\tepan2\\QtProject\\SimpleMRP\\database\\smrpdb.sqlite");
    if(!db.open()){
        QMessageBox::warning(this, tr("Connexion à la Base de données"), tr("Impossible de se connecter à la base de données."));
    }else{

    }

    //Mettre le pragma foreign keys à ON

    Famille *famille = new Famille;
    FamilleDAO *fDAO = new FamilleDAO;
    famille = fDAO->find("1");
    fDAO->remove(famille);


}

MainWindow::~MainWindow()
{
    delete ui;
}

#-------------------------------------------------
#
# Project created by QtCreator 2014-04-13T21:41:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += sql

TARGET = SimpleMRP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    article.cpp \
    famille.cpp \
    familledao.cpp \
    composant.cpp \
    compose.cpp \
    fournisseur.cpp \
    periode.cpp \
    ordre.cpp \
    ordrefin.cpp \
    ordredebut.cpp \
    composantdao.cpp \
    fournisseurdao.cpp \
    composedao.cpp \
    ordrefindao.cpp \
    ordredebutdao.cpp \
    periodedao.cpp

HEADERS  += mainwindow.h \
    article.h \
    famille.h \
    familledao.h \
    composant.h \
    compose.h \
    fournisseur.h \
    periode.h \
    ordre.h \
    ordrefin.h \
    ordredebut.h \
    composantdao.h \
    fournisseurdao.h \
    composedao.h \
    ordrefindao.h \
    ordredebutdao.h \
    periodedao.h

FORMS    += mainwindow.ui

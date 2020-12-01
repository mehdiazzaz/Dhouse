QT       += core gui sql gui multimedia multimediawidgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia core
CONFIG += c++11 console
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    crud_client.cpp \
    crud_produit.cpp \
    gestion_client.cpp \
    gestion_produit.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connexion.h \
    crud_client.h \
    crud_produit.h \
    gestion_client.h \
    gestion_produit.h \
    login.h \
    mainwindow.h

FORMS += \
    gestion_client.ui \
    gestion_produit.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

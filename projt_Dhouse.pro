QT       += core gui sql gui multimedia multimediawidgets printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia core
CONFIG += c++11 console
CONFIG += c++11
TARGET =arduino
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../smtp/emailaddress.cpp \
    ../smtp/mimeattachment.cpp \
    ../smtp/mimecontentformatter.cpp \
    ../smtp/mimefile.cpp \
    ../smtp/mimehtml.cpp \
    ../smtp/mimeinlinefile.cpp \
    ../smtp/mimemessage.cpp \
    ../smtp/mimemultipart.cpp \
    ../smtp/mimepart.cpp \
    ../smtp/mimetext.cpp \
    ../smtp/quotedprintable.cpp \
    ../smtp/smtpclient.cpp \
    adminitrateur.cpp \
    agent.cpp \
    arduino.cpp \
    crud_client.cpp \
    crud_commandes.cpp \
    crud_produit.cpp \
    crud_reclamation.cpp \
    dialog.cpp \
    gestion_administrateur.cpp \
    gestion_arduino.cpp \
    gestion_client.cpp \
    gestion_commande.cpp \
    gestion_partenaires.cpp \
    gestion_produit.cpp \
    gestiondereclamation.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    oracleqt.cpp \
    partenaire.cpp \
    publicite.cpp \
    statistique.cpp

HEADERS += \
    ../smtp/SmtpMime \
    ../smtp/emailaddress.h \
    ../smtp/mimeattachment.h \
    ../smtp/mimecontentformatter.h \
    ../smtp/mimefile.h \
    ../smtp/mimehtml.h \
    ../smtp/mimeinlinefile.h \
    ../smtp/mimemessage.h \
    ../smtp/mimemultipart.h \
    ../smtp/mimepart.h \
    ../smtp/mimetext.h \
    ../smtp/quotedprintable.h \
    ../smtp/smtpclient.h \
    ../smtp/smtpexports.h \
    adminitrateur.h \
    agent.h \
    arduino.h \
    crud_client.h \
    crud_commandes.h \
    crud_produit.h \
    crud_reclamation.h \
    dialog.h \
    gestion_administrateur.h \
    gestion_arduino.h \
    gestion_client.h \
    gestion_commande.h \
    gestion_partenaires.h \
    gestion_produit.h \
    gestiondereclamation.h \
    login.h \
    mainwindow.h \
    oracleqt.h \
    partenaire.h \
    publicite.h \
    statistique.h

FORMS += \
    dialog.ui \
    gestion_administrateur.ui \
    gestion_arduino.ui \
    gestion_client.ui \
    gestion_commande.ui \
    gestion_partenaires.ui \
    gestion_produit.ui \
    gestiondereclamation.ui \
    login.ui \
    mainwindow.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

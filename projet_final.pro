QT       += core gui sql printsupport network
QT       += core gui
config += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Desktop/smtp/emailaddress.cpp \
    ../../Desktop/smtp/mimeattachment.cpp \
    ../../Desktop/smtp/mimecontentformatter.cpp \
    ../../Desktop/smtp/mimefile.cpp \
    ../../Desktop/smtp/mimehtml.cpp \
    ../../Desktop/smtp/mimeinlinefile.cpp \
    ../../Desktop/smtp/mimemessage.cpp \
    ../../Desktop/smtp/mimemultipart.cpp \
    ../../Desktop/smtp/mimepart.cpp \
    ../../Desktop/smtp/mimetext.cpp \
    ../../Desktop/smtp/quotedprintable.cpp \
    ../../Desktop/smtp/smtpclient.cpp \
    crud_commandes.cpp \
    crud_reclamation.cpp \
    dialog.cpp \
    gestion_commande.cpp \
    gestiondereclamation.cpp \
    main.cpp \
    mainwindow.cpp \
    oracleqt.cpp

HEADERS += \
    ../../Desktop/smtp/SmtpMime \
    ../../Desktop/smtp/emailaddress.h \
    ../../Desktop/smtp/mimeattachment.h \
    ../../Desktop/smtp/mimecontentformatter.h \
    ../../Desktop/smtp/mimefile.h \
    ../../Desktop/smtp/mimehtml.h \
    ../../Desktop/smtp/mimeinlinefile.h \
    ../../Desktop/smtp/mimemessage.h \
    ../../Desktop/smtp/mimemultipart.h \
    ../../Desktop/smtp/mimepart.h \
    ../../Desktop/smtp/mimetext.h \
    ../../Desktop/smtp/quotedprintable.h \
    ../../Desktop/smtp/smtpclient.h \
    ../../Desktop/smtp/smtpexports.h \
    crud_commandes.h \
    crud_reclamation.h \
    dialog.h \
    gestion_commande.h \
    gestiondereclamation.h \
    mainwindow.h \
    oracleqt.h

FORMS += \
    dialog.ui \
    gestion_commande.ui \
    gestiondereclamation.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

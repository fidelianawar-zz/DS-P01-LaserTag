TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    dsstring.cpp \
    lasertag.cpp \
    main.cpp \
    player.cpp \
    team.cpp

HEADERS += \
    dsstring.h \
    lasertag.h \
    main.h \
    player.h \
    team.h

DISTFILES += \
    TeamA.txt

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        account.cpp \
        cli.cpp \
        course.cpp \
        main.cpp \
        university.cpp \
        utils.cpp

HEADERS += \
    account.hh \
    cli.hh \
    course.hh \
    university.hh \
    utils.hh

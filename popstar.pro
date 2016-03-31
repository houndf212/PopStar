TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrix.cpp \
    pos.cpp \
    matrixgenerator.cpp \
    matrixslice.cpp \
    matrixgame.cpp \
    scorecalc.cpp \
    humansolver.cpp \
    maxsolver.cpp \
    scorecalccontainer.cpp \
    matrixinput.cpp \
    rndsolver.cpp \
    createlengthsolver.cpp \
    maxfinder.cpp

HEADERS += \
    matrix.h \
    pos.h \
    basic_matrix.h \
    basic_pos.h \
    matrixgenerator.h \
    matrixslice.h \
    matrixgame.h \
    scorecalc.h \
    humansolver.h \
    maxsolver.h \
    scorecalccontainer.h \
    matrixinput.h \
    rndsolver.h \
    createlengthsolver.h \
    maxfinder.h


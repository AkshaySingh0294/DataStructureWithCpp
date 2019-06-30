TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS +=

DISTFILES +=

include (Sorting/SortingControl.pri)
include (DefinitionControl/DefinitionControl.pri)
include (LinkedListControl/LinkedListControl.pri)
include (PractiseSpace/PractiseControl.pri)
include (TreeControl/TreeControl.pri)

# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = BorneGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjoutBorneFontaineUI.cpp AjoutBorneStationnementUI.cpp SupprimerBorneUI.cpp borneGUI.cpp main.cpp
HEADERS += AjoutBorneFontaineUI.h AjoutBorneStationnementUI.h SupprimerBorneUI.h borneGUI.h
FORMS += AjoutBorneFontaineUI.ui AjoutBorneStationnementUI.ui SupprimerBorneUI.ui borneGUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../Source 
LIBS += ../Source/dist/Debug/GNU-Linux/libsource.a  

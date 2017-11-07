#ifndef CONFIGREADER_H
#define CONFIGREADER_H
#include <QString>
#include <qxmlstream.h>
#include <QDebug>
#include <QtCore>
#include <QtXml/QtXml>


class ConfigReader
{
    int xspace, yspace, xfactor, yfactor, numOfPlayers, numOfCards, diceMaxNumber, playerCash;

public:
    ConfigReader();
    int getNumOfPlayers();
    int getNumOfCards();
    int getDiceMaxNumber();
    int getPlayerCash();
    int getXspace();
    int getYspace();
    int getXfactor();
    int getYfactor();
    void XMLParser();
};

#endif // CONFIGREADER_H

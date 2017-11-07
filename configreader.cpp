#include "configreader.h"

ConfigReader::ConfigReader()
{
    XMLParser();
}

int ConfigReader::getNumOfPlayers()
{
    return numOfPlayers;
}

int ConfigReader::getNumOfCards()
{
    return numOfCards;
}

int ConfigReader::getDiceMaxNumber()
{
    return diceMaxNumber;
}

int ConfigReader::getPlayerCash()
{
    return playerCash;
}

int ConfigReader::getXspace()
{
    return xspace;
}

int ConfigReader::getYspace()
{
    return yspace;
}

int ConfigReader::getXfactor()
{
    return xfactor;
}

int ConfigReader::getYfactor()
{
    return yfactor;
}


void ConfigReader::XMLParser()
{
//    QString numplayers;
//    QString PlayerCash;
//    QString diceMaxNumber;
    QDomDocument document;
    QFile xmlFile("C:/Users/siamcio/Desktop/monopoly/monopoly2/config.xml");

    if (!xmlFile.open(QIODevice::ReadOnly) )
    {
        qDebug() << "Check your file";
        return;
    }
    //load the file
    document.setContent(&xmlFile);
    QDomElement root = document.firstChildElement();
    QDomElement element_1 = root.firstChildElement();
    QDomElement element_2 = element_1.nextSiblingElement();
    QDomElement element_1_child = element_1.firstChildElement();
    QDomElement element_2_child = element_2.firstChildElement();
    QDomElement element_3 = element_2.nextSiblingElement();
    QDomElement element_3_child = element_3.firstChildElement();
    while(!element_1_child.isNull())
    {
        if(element_1_child.tagName() == "numOfPlayers")
        {
//            numplayers = element_1_child.text();
            numOfPlayers = element_1_child.text().toInt();
        }
        if(element_1_child.tagName() == "playerCash"){
//            PlayerCash = element_1_child.text();
            playerCash = element_1_child.text().toInt();
        }
        if(element_1_child.tagName() == "diceMaxNumber")
        {
            diceMaxNumber = element_1_child.text().toInt();
        }
        element_1_child =element_1_child.nextSiblingElement();
    }
     while(!element_2_child.isNull())
      {
      if(element_2_child.tagName() == "numOfCards")
           numOfCards = element_2_child.text().toInt();


        element_2_child =element_2_child.nextSiblingElement();
    }
     while(!element_3_child.isNull())
      {
      if(element_3_child.tagName() == "xspace")
           xspace = element_3_child.text().toInt();
      if(element_3_child.tagName() == "yspace")
           yspace = element_3_child.text().toInt();
      if(element_3_child.tagName() == "xfactor")
           xfactor = element_3_child.text().toInt();
      if(element_3_child.tagName() == "yfactor")
           yfactor = element_3_child.text().toInt();
        element_3_child =element_3_child.nextSiblingElement();
    }
//    qDebug()<< numplayers<< playerCash <<diceMaxNumber;

}




#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "time.h"
#include <QObject>


class Game : public QObject
{
    Q_OBJECT
    Board board;
    QVector<Player*> playerPointers;
    Player* currentPlayer;
    int numberOfPlayers=4;
    int playerCash=3000;
    int auctionPrice;
    Card *tradeCard;
    Player* tradingPlayer;

    const int DiceMaxNumber = 6;

public:

    Game();
    Game(int _numberOfPlayers);

    void MovePlayer();
    void EndPlayerTurn();
    void BuyProperty();
    void BuyHouse();
    bool CanBuyHouse();
    bool CanBuyProperty();
    bool CanTradeProperty(int nrcard);
    void TradeProperty(int nrcard);
    void Dice();
    void Auction();
    void setAuctionPrice(int auctionprice);
    int getAuctionPrice();
    void EndAuction();
    void EndTradeOK(Player *player, int price, int nrcard);
    void EndTradeNo(Player *player);
    bool HasPlayerCard(int nrCard);
    Player *getTradingPlayer();
    QString whosTurn();
    Player *getCurrentPlayer();
    Player* getPlayerPointer(int index);
    Board* getBoardPtr();
    int getNumberOfPlayers();
    void setNumberOfPlayers(int numberofplayers);
    void isPlayerDone();





    ~Game();

signals:
    void newDiceThrow(int);
    void statement(QString);
    void DataChanged();
    void auctionEnd();
    void tradeEnd();
private:
    int ThrowDice();
    Player* getCardOwner(Card* card);
    void transferMoney(Player* sender, Player* receiver, int amount);
    void payBank(Player* player, int amount);
    void receiveFromBank(Player* player, int amount);
};

#endif // GAME_H

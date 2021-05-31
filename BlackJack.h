
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

#ifndef BlackJack_h
#define BlackJack_h

//classe principale del programma

class BlackJack
{
public:
    BlackJack(int cash);
    ~BlackJack();
    
    void dealerPlay(); //giocata automatica del banco
    void hit();
    void choice(); //fa compiere al giocatore le scelte nel corso del gioco
    void checkWinner(); //controlla il vincitore e distruibuisce la vincita
    void setBet(int pBet); //permette di modificare ad ogni mano la scommessa piazzata dal giocatore
    Player* getPlayer(); //funzione non indispensabile, utile per effetture stampa nel main
    
    void play();
    
private:
    Deck *gameDeck;
    Dealer dealer;
    Player player;
    int theBet;
};



#endif /* BlackJack_h */

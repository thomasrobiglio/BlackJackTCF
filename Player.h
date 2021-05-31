#include "Hand.h"

#ifndef Player_h
#define Player_h

class Player
{
public:
    Player(){};
    ~Player(){};
    
    int placeBet(); // prende un int da tastiera come scommessa che piazza il giocatore
    int getCashTotal() const;
    Hand* getHand(); //NOTA: non può essere dichiarata const perchè ritorna un puntatore
    void setCash(int cash); 
    
private:
    Hand PlayerHand;
    int cashTotal;
};

#endif /* Player_h */

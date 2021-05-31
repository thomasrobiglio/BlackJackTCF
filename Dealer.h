
#ifndef Dealer_h
#define Dealer_h

#include "Hand.h"

class Dealer
{
public:
    Dealer(){};
    ~Dealer(){};

    Hand* getHand();
    bool checkOver17() const; //utile per implementare la regola: "il banco deve proseguire con il gioco fino a quando non fa 17 o più"
    
private:
    Hand DealerHand;
};



#endif /* Dealer_h */

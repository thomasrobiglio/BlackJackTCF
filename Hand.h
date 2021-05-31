
#include "Card.h"

#include <vector>
using std::vector;


#ifndef Hand_h
#define Hand_h

class Hand
{
public:
    Hand(){};
    ~Hand();
    
    void addCard(Card pCard);
    int getTotal() const;
    void printHand() const;
    bool checkBust() const; //controlla che il totale della mano sia >21 (in tal caso return true)
    
    void clearHand(); //utilizzo la funzione clear() di STL per "pulire" il vettore in caso in cui si debba giocare una seconda mano nella stessa partita.
    
private:
    vector<Card*> hand; 
};

#endif /* Hand_h */


#ifndef Deck_h
#define Deck_h

#include <vector> //intendiamo il mazzo come vettore per usare le funzioni di STL
using std::vector;

#include "Card.h"

class Deck{

public:
    Deck();
    ~Deck();
    
    void shuffle(); //non mescola il mazzo, ma rimette le carte già uscite nel mazzo, utile per giocare una nuova mano nella stesso partita
    Card drawCard();
    
private:
    vector<Card*> deck; //vettore di puntatore a oggetti di tipo Card
    vector<Card*> releasedCards; //ci serve per poter giocare più "mani" con lo stesso mazzo
};

#endif /* Deck_h */

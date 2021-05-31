
#include <iostream>
using std::cout;
using std::endl;

#include "Hand.h"

Hand :: ~Hand()
{
    vector<Card*> :: iterator i;
    for(i = hand.begin(); i != hand.end(); i++) {delete *i;}
}

void Hand :: addCard(Card pCard)
{
    hand.push_back(&pCard);
}

//l'asso vale 11, assume però valore 1 se fa si che il totale della mano sia >21.
int Hand :: getTotal() const
{
    int total = 0;
    int counter = 0; //contatore per il numero di assi, utilizzato successivamente nel ciclo
    
    vector<Card*> :: const_iterator i;
    
    for(i = hand.begin(); i != hand.end(); i++)
    {
        int cardValue = (*i) -> getValue(); //i è un iteratore, per ottenere l'elemento del vettore lo dereferenzio
        if (cardValue == 11) {counter++;}
        total = total + cardValue;
    }
    while(counter > 0 && total > 21) {total = total - 10; counter--;} //ciclo per modificare il valore degli assi

    return total;
}

void Hand :: printHand() const
{
    vector<Card*> :: const_iterator i;
    for(i = hand.begin(); i != hand.end(); i++)
    {
        (*i) -> printCard();
        cout << " ";
    }
    cout << endl;
}

bool Hand :: checkBust() const //ritorna vero se il totale della mano è >21
{
    if (getTotal() > 21) {return true;}
    else {return false;}
}

void Hand :: clearHand()
{
    hand.clear(); //rimuove tutti gli elementi del vettore lasciando un contenitore di dimensione 0
}





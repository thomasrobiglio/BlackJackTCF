
#include "Deck.h"

#include <iostream>
using std::cout;
using std::endl;

#include <time.h>

Deck :: Deck()
{
    int i,j;
    for (i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            deck.push_back(new Card(j, i));
        }
    }
}

Deck :: ~Deck()
{
    vector<Card*> :: iterator i; //iteratore sul vettore deck, l'iteratore non può essere costante perchè deve modificare il vettore
    for(i = deck.begin(); i != deck.end(); i++) {delete *i;}
    vector<Card*> :: iterator j; //iteratore sul vettore releasedCards
    for(j = releasedCards.begin(); j != releasedCards.end(); j++) {delete *j;}
}

void Deck :: shuffle()
{
    deck.insert(deck.end(), releasedCards.begin(), releasedCards.end()); //aggiungiamo alla fine di deck il vettore releasedCards
    releasedCards.clear(); //la funzione clear() di STL distrugge tutti gli elementi di un vettore lasciandolo vuoto.
    cout << "The deck has been shuffled." << endl;
}

Card Deck :: drawCard()
{
    int sizeOfDeck = deck.size();
    srand(time(NULL)); //definiamo il seme della randomizzazione
    int randomNumber = rand()%sizeOfDeck; //questa randomizzazione sostituisce la mescolatura effettiva del mazzo
    
    Card drawnCard = *deck.at(randomNumber); //usiamo * perchè .at(int) ritorna una referenza
    releasedCards.insert(releasedCards.end(), deck.at(randomNumber));
    deck.erase(deck.begin()+randomNumber);
    
    return drawnCard;
}


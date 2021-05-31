
#include "Player.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int Player :: placeBet()
{
    int bet=0;
    cout << "Place a bet: ";
    //controllo che il giocatore inserisca un intero
    if(cin >> bet) {;}
    else
    {
        cin.clear();
        cin.ignore(10000, '\n');
        bet = 0;
    }
    while (bet > getCashTotal() || bet <= 0) //controllo che il giocatore scommetta un intero non maggiore dei soldi totali che ha
    {
    if (bet > getCashTotal())
    {
        cout << "Error: you can't bet more than you have!" << endl;
        cout << "Place a bet: ";
        if(cin >> bet) {;} //controllo che il giocatore inserisca un intero
        else
        {
            cin.clear();
            cin.ignore(10000, '\n');
            bet = 0;
        }
    }
    else if (bet <= 0)
    {
        cout << "Error: you need to bet something!" << endl;
        cout << "Place a bet: ";
        if(cin >> bet) {;} //controllo che il giocatore inserisca un intero
        else
        {
            cin.clear();
            cin.ignore(10000, '\n');
            bet = 0;
        }
    }
    }
setCash(getCashTotal()-bet);
return bet;
}



int Player :: getCashTotal() const
{
    return cashTotal;
}

Hand* Player :: getHand()
{
    return  &PlayerHand;
}

void Player :: setCash(int cash)
{
    cashTotal = cash;
}



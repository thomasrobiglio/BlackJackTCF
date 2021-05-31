
#include <iostream>
using std::cout;
using std::endl;


#include "BlackJack.h"

int main()
{
    cout << "Welcome! Here you can play a game of BlackJack!" << endl;
    cout << endl;
    cout <<
    "The goal of blackjack is to beat the dealer's hand without going over 21. \nFace cards are worth 10, aces are worth 11 or 1 depending if your total is over 21, other cards are worth their nominal value. \nBoth you and the dealer start with two cards, one of the dealer's cards is hidden until the end. \nTo 'Hit' is to ask for another card. \nIf you go over 21 you bust and the dealer wins regardless of the dealer's hand." << endl;
    cout << endl;
    cout << "You can bet up to 500, if you win you double your gamble!" << endl;
    cout << endl;
    
    BlackJack g1(500);
    g1.play();
    
    if (g1.getPlayer()->getCashTotal() == 0) {cout << "You leave the table with nothing in your pocket." << endl;}
    else {cout << "You leave the table with " << g1.getPlayer()->getCashTotal() << " in your pocket." << endl;}
    
    cout << endl;
    cout << "Thank you for playing with us! See you soon!" << endl;
    
}


#include "BlackJack.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

BlackJack :: BlackJack(int cash)
{
    gameDeck = new Deck();
    player.setCash(cash);
    theBet = 0;
}

BlackJack :: ~BlackJack()
{
    delete gameDeck;
}

void BlackJack :: setBet(int pBet) //per poter interagire con l'utente
{
    theBet = pBet;
}

void BlackJack :: checkWinner()
{
    int playerTotal = player.getHand()->getTotal();
    int dealerTotal = dealer.getHand()->getTotal();
    bool playerBust = player.getHand()->checkBust();
    bool dealerBust = dealer.getHand()->checkBust();
// nel condizionale sono affrontati tutti i possibili scenari e gli esiti connessi.
    if(playerBust == true)
    {
        cout << "You lose!" << endl;
        cout << "Dealer's hand was ";
        dealer.getHand()->printHand();
        cout << endl;
    }
    else if (dealerBust == true)
    {
        cout << "You win!" << endl;
        player.setCash(player.getCashTotal()+(2*theBet));
    }
    else if (playerTotal == dealerTotal)
    {
        cout << "It's a tie!" << endl;
        player.setCash(player.getCashTotal()+(theBet));
    }
    else if (playerTotal > dealerTotal)
    {
        cout << "You win!" << endl;
        player.setCash(player.getCashTotal()+(2*theBet));
    }
    else
    {
        cout << "You lose!" << endl;
    }
    cout << endl;
}

void BlackJack :: dealerPlay() //corretto
{
    bool DealerBustResult = (dealer.getHand())->checkBust();
    bool DealerCheckover17Result = dealer.checkOver17();
    if ( DealerBustResult == false &&  DealerCheckover17Result == false)
    {
        dealer.getHand()->addCard(gameDeck->drawCard());
        cout << "Dealer hitted" << endl;
        dealerPlay();
    }
    else
    {
        cout << "Dealer stayed." << endl;
        cout << "Dealer's hand is:" << endl;
        dealer.getHand()->printHand();
        cout << "Dealer's total is: ";
        cout <<(dealer.getHand())->getTotal() << endl;
        if (dealer.getHand()->checkBust() == true) {cout << "Dealer has busted!" << endl;}
        checkWinner();
    }
}

void BlackJack :: hit() //corretto
{
    cout << "You hitted" << endl;
    (player.getHand())->addCard(gameDeck->drawCard());
    cout << "Your Hand is: ";
    player.getHand()->printHand();
    cout << "Your total is " << player.getHand()->getTotal() << "." << endl;
    if(player.getHand()->checkBust() == false){choice();}
    else {cout << "You busted!" << endl; checkWinner();}
}

void BlackJack :: choice()
{
    cin.clear(); //pulisco cin per evitare che siano presi come scelte caratteri inseriti per errore piazzando la scommessa
    cin.ignore(10000, '\n');
    cout << "Press 'H' to hit or any other key to stay, then press enter" << endl;
        string scelta;
        cin >> scelta;
    if (scelta == "h" || scelta == "H") {hit();}
    else
    {
        cout << "You stayed " <<endl;
        dealerPlay();
    }
}


void BlackJack :: play() //corretto
{
    int bet = player.placeBet();
    setBet(bet); //faccio scommettere il giocatore
    gameDeck->shuffle();
    
    cout << "You get two cards..." << endl;
    //giocatore e Dealer ricevono due carte ciascuno
    (player.getHand())->addCard(gameDeck->drawCard());
    (player.getHand())->addCard(gameDeck->drawCard());
    (player.getHand())->printHand(); //viene stampata la mano del giocatore
    
    cout << "Dealer gets two cards..." << endl;
    dealer.getHand()->addCard(gameDeck->drawCard());
    cout << "Dealer's first card is ";
    dealer.getHand()->printHand(); //stampo la prima carta della mano del Dealer
    dealer.getHand()->addCard(gameDeck->drawCard());
    cout << "Your total is " << player.getHand()->getTotal() << "." << endl;
    //inizia la fase di gioco del giocatore
    choice();
    
    cout << "You have " << player.getCashTotal() << " in your pocket." << endl;
    cout << endl;
    
    //"pulisco" le mani di player e dealer in vista della nuova mano
    player.getHand()->clearHand();
    dealer.getHand()->clearHand();
    
    //se il giocatore ha ancora da scommettere il programma gli propone di giocare una nuova mana
    if (player.getCashTotal() > 0)
    {
    cout << "Do you want to play again?" << endl;
    cout << "Press 'y' to play again or any other letter to quit, then press enter..." << endl;
    string choice;
    cin >> choice;
    if (choice == "y" || choice == "Y") {play();}
    }
}

Player* BlackJack :: getPlayer()
{
    return &player;
}



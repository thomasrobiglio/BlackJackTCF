
#include "Card.h"

#include <iostream>
using std::cout;

//NB: i semi sono implementati dal costruttore seconodo il criterio: 1 = Cuori, 2 = Quadri, 3 = Fiori, 0 = Picche
//NB: i numeri delle carte sono implementati secondo il criterio: 1 = A, 2...10 = 2...10, 11 = J, 12 = Q, 0 = K

Card :: Card(int RankNumber, int SuitNumber)
{
    int RankNumberMod = RankNumber%13; //i due moduli fanno si che la classe sia portabile e funzioni anche se chiamata con numeri fuori dal range
    int SuitNumberMod = SuitNumber%4;
    
    if (SuitNumberMod == 1) {suit = "♥";}
    else if (SuitNumberMod == 2) {suit = "♦";}
    else if (SuitNumberMod == 3) {suit = "♣";}
    else {suit = "♠";}
    
//la funzione std::to_strin(int n) trasforma l'aromento n nella string corrispondente
    
    if (RankNumberMod >= 2 && RankNumberMod <= 10) {value = RankNumberMod; rank = std::to_string(RankNumberMod);}
    else if (RankNumberMod == 1) {value = 11; rank = "A";}
    else if (RankNumberMod == 11) {value = 10; rank = "J";}
    else if (RankNumberMod == 12) {value = 10; rank = "Q";}
    else {value = 10; rank = "K";}
}

int Card :: getValue() const
{
    return value;
}

void Card :: printCard() const
{
    cout << rank << " " << suit;
}


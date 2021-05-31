
#ifndef Card_h
#define Card_h

#include <string>
using std::string;



class Card{
public:
    Card(int RankNumber, int SuitNumber); //costruttore
    ~Card(){};
    
    int getValue() const;
    void printCard() const;
    
private:
    string rank;
    string suit;
    int value;
    
};


#endif /* Card_h */

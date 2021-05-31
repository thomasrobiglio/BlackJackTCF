
#include "Dealer.h"

Hand* Dealer :: getHand()
{
    return  &DealerHand;
}

bool Dealer :: checkOver17() const
{
    if (DealerHand.getTotal() < 17) {return false;}
    else {return true;}
}

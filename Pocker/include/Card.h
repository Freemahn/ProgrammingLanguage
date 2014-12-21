#ifndef _H_CARD_
#define _H_CARD_

#include "Hand.h"

class Card {
public:
    enum Value {
        D2,
        D3,
        D4,
        D5,
        D6,
        D7,
        D8,
        D9,
        D10,
        KNAVE,
        QUEEN,
        KING,
        ACE,
        NONE
    };

    enum Suit {
        Sprade  = 0x00,
        Diamond = 0x01,
        Club     = 0x02,
        Heart   = 0x03,

        RedFlag = 0x01,
    };

    Card(Card && c);
    std::pair look(Player::Secret const &) const; //throws InvalidAccess
    void open();
private:
    void setOwner(Player const &);
    Card(Card const &) = delete;
    Card & operator=(Card const &);
    Card(Value v, Suit s);
    friend class Stack;
    Value value;
    Suit suit;
    bool isOpen;
    Player owner;
};

#endif //_H_CARD_
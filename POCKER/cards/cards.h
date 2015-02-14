#ifndef CARDS_H
#define CARDS_H


#include "pockerController/pockerOn.h"

enum Suit {
    clubs, diamonds, hearts, spades
};

class Card {
protected:
    Suit suit;
    int rank;
public:
    Card() {}
};

class OpenCard: Card {
public:
    // Get Rank
    int getRank()const;
    // Get Suit
    Suit getSuit()const;
    OpenCard();
    OpenCard(const Suit, const int);
    bool operator==(OpenCard const&);
    // Card -> String
    std::string toString() const;
};

class CloseCard: Card {
public:
    friend class pockerOn;
    CloseCard();
    CloseCard(const Suit, const int);
};

#endif

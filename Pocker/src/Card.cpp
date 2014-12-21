#include "include/Card.h"
#include "include/Exceptions.h"

Card::Card(Card && c) : value(c.value), suit(c.suit), isOpen(c.isOpen), owner(c.owner) {
    c.value = (Value)0;
    c.suit = (Suit)0;
}
Card &Card::operator=(Card const &c) {
    value = c.value;
    suit = c.suit;
    isOpen = c.isOpen;
    owner = c.owner;
    return *this;
}
/*Card & Card::operator=(Card && c) {
    value = c.value;
    suit = c.suit;
    isOpen = c.isOpen;
    owner = c.owner;
    c.value = (Value)0;
    c.suit = (Suit)0;
    return *this;
}*/

std::pair<Card::Suit, Card::Value> Card::look(std::shared_ptr<Player> const & player) const {
if (isOpen || (owner && player == owner)) {
return std::make_pair(suit, value);
}
throw InvalidAccess();
}

/*void Card::setOwner(std::shared_ptr<Player> const & player) {
owner = player;
}*/

Card::Card(Value v, Suit s) : suit(s), value(v), isOpen(false) {
}

/*void Card::open(std::shared_ptr<Player> const & player) {
isOpen = true;
}*/


void Card::open() {
    isOpen = true;
}

void Card::setOwner(Player const &player) {
owner = player;
}

#ifndef BOARD_H
#define BOARD_H

#include "cards/cards.h"

class OpenCard;

class Board {
public:
    uint32_t enemyCount, bank, littleBlind, playerCash, playerBet;
    OpenCard *hand;
    std::vector <OpenCard> board;
    std::vector <std::string> names;
    std::vector <uint32_t> cash, bets;
    Board();
    ~Board();
    void print() const;
};

#endif

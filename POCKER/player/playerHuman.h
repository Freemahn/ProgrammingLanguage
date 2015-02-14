#ifndef PLAYERH_H
#define PLAYERH_H

#include <board/board.h>
#include "player/player.h"
#include "cards/cards.h"

class playerH: public Player {
private:
public:
    playerH() {}
    playerH(std::string name): Player(name) { }
    ~playerH() {}
    //Player bet
    uint32_t bet(uint32_t sum, Board state);
};


#endif

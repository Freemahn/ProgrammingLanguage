#include "board.h"
#include <iostream>
#include <stdio.h>
#include "cards/cards.h"

Board::Board() {
    hand = std::nullptr_t();
}

Board::~Board() {
    if (hand != std::nullptr_t())
        delete[] hand;
}
//print current game situation
void Board::print() const {
    printf("%-15s: %i\n", "Money on board",bank);
    printf("%-15s", "You " );
    printf(": [money: %i ,total bet: %i]\n", playerCash,playerBet);
    for (uint32_t i = 0; i < enemyCount; i++) {
        printf("%-15s: [money: %i ,total bet: %i]\n",names[i].c_str(), cash[i],bets[i]);
        //std::cout <<": [money: " << cash[i] << ", total bet: " << bets[i] << "]\n";
    }
    if (board.size() != 0) {
        printf("%-15s", "On board" );
        for (uint32_t i = 0; i < board.size(); i++) {
            std::cout << ": " << board[i].toString() << " ";
        }
        std::cout << "\n";
    }
    printf("%-15s", "On hand" );
    std::cout << ": " << hand[0].toString() << ", " << hand[1].toString() << "\n";
}

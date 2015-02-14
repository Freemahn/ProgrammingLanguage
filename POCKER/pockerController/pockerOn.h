#ifndef pockerON_H
#define pockerON_H

#include <vector>

#include "player/playerHuman.h"
#include "board/board.h"
#include "memory.h"

class OpenCard;

class CloseCard;

class Player;

class Board;

class pockerOn {
private:
    struct PlayerData {
        uint32_t cash;
        OpenCard *hand;
        uint32_t currBet;
        Player *p;


        ~PlayerData();
    } *players;

    uint32_t playersCount, bank, littleBlind, dealer;

    void show(Player *p, OpenCard *cards, uint32_t *value);

    std::string rankToString(uint32_t in);

    // Get id,relevance and kickers of combination
    uint32_t *enter(OpenCard *cards);

    // Get the highest combination
    std::pair<OpenCard *, uint32_t *> strongestCombination(OpenCard *);

    // Get winners
    std::vector<uint32_t> show();

    // Player's betting process
    void doBets(uint32_t pls);

    // New round with i's player
    void doRound();

    // Giving new cards
    void shuffle();

    // Checking if player can acces blind
    std::vector<uint32_t> refresh();

    // Remove card from deck and add to board
    void openNext();

    // Get players who are able to bet
    size_t inGameWithCash();

    // Get state for players[player].p
    Board getTable(uint32_t player, std::vector<uint32_t> live);

    std::vector<OpenCard> table;
    std::vector<CloseCard> deck;

    // Get players in game
    std::vector<uint32_t> live;

    // Creating new player->adding to instance
    template<typename First>
    void addPlayers(uint32_t cnt, First *first);

    template<typename First, typename... Rest>
    void addPlayers(uint32_t cnt, First *first, Rest *... rest);

    pockerOn();
    template<typename ... Players>
    friend pockerOn *newGame(uint32_t n, uint32_t startCash, uint32_t littleBlind,
            Players *... p);



public:
    ~pockerOn();

    void run();
};

#endif

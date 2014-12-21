#include <algorithm>
#include <set>
#include <include/Card.h>
#include "include/Rules.h"

namespace{
    unsigned int checkPairs(std::vector <Card> const & cards,
            std::shared_ptr<Player> const & player) {
        size_t values[Card::ACE + 1] = { 0 };
        int rank = 0;
        Card::Value highestCard = Card::NONE;
        Card::Value secondCard = Card::NONE;

        for (auto & c : cards) {
            Card::Value curValue = c.look(player).second;
            if (++values[curValue - Card::D2] == 2) {
                if (curValue > highestCard) {
                    secondCard = highestCard;
                    highestCard = curValue;
                }
                else if (curValue > secondCard)
                    secondCard = curValue;
            }
        }

        return (secondCard != Card::NONE ? Rules::TwoPairs : Rules::Pair) | highestCard << 8 | secondCard;
    }

    unsigned int checkFlush(std::vector<Card> const & cards, std::shared_ptr<Player> const & player) {
        Card::Value high = Card::NONE;
        Card::Suit  suit = cards.cbegin()->look(player).first;

        for (auto & c : cards) {
            high = std::max(high, c.look(player).second);
            if (c.look(player).first != suit)
                return 0;
        }
        return high | Rules::Flush;
    }

    unsigned int checkStraight(std::vector<Card> const & cards,
            std::shared_ptr<Player> const & player) {
        size_t values[Card::ACE + 1] = { 0 };
        for (auto & c : cards) {
            ++values[c.look(player).second - Card::D2];
        }

        auto high = Card::NONE;
        auto count = 0;

        for (int i = Card::ACE; i >= Card::D2; --i) {
            if (values[i - Card::D2]) {
                if (high != Card::NONE) {
                    ++count;
                }
                else {
                    high = (Card::Value)i;
                    count = 1;
                }
            }
            else {
                high = Card::NONE;
            }
        }

        if (count == 5 || (count == 4 && high == Card::D5 && values[Card::ACE - Card::D2])) {
            return Rules::Straight | high;
        }

        return 0;
    }
}

namespace Rules {
    unsigned int getCombinationRank(std::vector <Card> const & cards,
            std::shared_ptr<Player> const & player) {
        size_t values[Card::ACE + 1] = { 0 };
        int rank = 0;
        Card::Value highestCard = Card::NONE;

        if (unsigned flushResult = checkFlush(cards, player))
        if (unsigned int straightResult = checkStraight(cards, player))
            return straightResult & 0x00FFFFFF | Rules::StraightFlush;
        else
            return flushResult;

        if (unsigned int straightResult = checkStraight(cards, player))
            return straightResult;

        for (auto & c : cards) {
            Card::Value curValue = c.look(player).second;
            if (++values[curValue - Card::D2] == 3) {
                highestCard = std::max(highestCard, curValue);
            }
        }

        return highestCard == Card::NONE ? checkPairs(cards, player) : Rules::Set | highestCard;
    }


}
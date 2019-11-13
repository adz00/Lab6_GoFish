// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#ifndef LAB6GOFISH_DECK_H
#define LAB6GOFISH_DECK_H

#include "card.h"
#include <ctime>
#include <cstdlib>


class Deck
{
    static const int SIZE = 52;

public:


    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the deck, all 52 cards present
    Card dealCard();   // get a card, after 52 are dealt, fail (return a card with rank 100 to indicate deck is all dealt)

    int  size() const; // # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
    void swapinArray(int i, int j, Card cards[]);
};

#endif
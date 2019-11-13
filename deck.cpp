//
// Created by srira on 11/5/2019.
//

#include "deck.h"
#include <cstdlib>

//initializes deck in new deck order
//inputs: none
//outputs: none
Deck::Deck()
{
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    myIndex = 0;
    Card c;
    int count = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            if(i == 0)
            {
                c = Card(j + 1, Card::spades);
            }
            else if(i == 1)
            {
                c = Card(j + 1, Card::hearts);
            }
            else if(i == 2)
            {
                c = Card(j + 1, Card::diamonds);
            }
            else if(i == 3)
            {
                c = Card(j + 1, Card::clubs);
            }
            myCards[count] = c;
            count++;
        }
    }
}

//deals a single card from the top of the deck
//inputs: none
//outputs: card at top of deck
Card Deck::dealCard()
{
    Card c = myCards[myIndex];
    myIndex++;
    return c;
}

//returns the size of the deck
//inputs none
//outputs: integer size of deck
int Deck::size() const
{
    return 52 - myIndex;
}

//shuffles cards randomly in the deck
//inputs: none
//outputs: none
void Deck::shuffle()
{
    for(int i = 0; i < 500; i++)
    {
        int random1 = rand() % 52;
        int random2 = rand() % 52;
        swapinArray(random1, random2, myCards);
    }
}

//helper function to swap cards in the deck in shuffle()
void Deck::swapinArray(int i, int j, Card cards[])
{
    Card temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
}
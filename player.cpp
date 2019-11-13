//
// Created by srira on 11/5/2019.
//

#include "player.h"
#include<ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

//default constructor for player
//inputs: none
//outputs: none
Player::Player()
{
    myName = "";
    myHand.clear();
    myBook.clear();
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
}

//adds a card to the player's hand
//inputs: card to be added
//outputs: none
void Player::addCard(Card c)
{
    myHand.push_back(c);
}

//returns current size of player's hand
//inputs: none
//outputs: integer size
int Player::getHandSize() const
{
    return myHand.size();
}

//checks if card of same rank as input card exists in the player's hand
//inputs: card to compare with
//outputs: boolean value for whether or not a card of the same rank exists
bool Player::rankInHand(Card c) const
{
    for(int i=0; i<myHand.size(); i++)
    {
        if(myHand[i].getRank() == c.getRank())
        {
            return true;
        }
    }
    return false;
}

//checks if a certain card is in the player's hand
//inputs: card to compare with
//outputs: boolean value for whether or not the card exists in the player's hand
bool Player::cardInHand(Card c) const
{
    for(int i=0; i<myHand.size(); i++)
    {
        if(myHand.at(i)==c)
        {
            return true;
        }
    }
    return false;
}

//checks if there exists a pair in the hand and then book the pair
//inputs: 2 cards
//outputs: boolean value for whether or not a book exists in the hand
bool Player::checkHandForBook(Card &c1, Card &c2)
{
    for(int i = 0; i < myHand.size() - 1; i++)
    {
        for(int j = i + 1; j < myHand.size(); j++)
        {
            if(myHand.at(i).getRank() == myHand.at(j).getRank())
            {
                c1 = myHand.at(i);
                c2 = myHand.at(j);
                bookCards(c1, c2);
                return true;
            }
        }
    }
    return false;
}

//checks if card of same rank exists in the hand
//inputs: card to compare with
//outputs: boolean value for whether or not a card of the same rank exists in the player's hand
bool Player::sameRankInHand(Card c) const
{
    for(int i = 0; i < myHand.size(); i++)
    {
        if(c.getRank() == myHand.at(i).getRank())
        {
            return true;
        }
    }
    return false;
}

//returns a string holding all cards in the player's hand
//inputs: none
//outputs: string holding all cards in the player's hand
string Player::showHand() const
{
    string s;
    for(int i = 0; i < myHand.size(); i++)
    {
        s += myHand.at(i).toString() + " ";
    }
    return s;
}

//removes a given card of the same rank from the player's hand
//inputs: card to be removed
//outputs: removed card
Card Player::removeCardFromHand(Card c)
{
    Card d = Card(100, Card::spades);
    for(int i = 0; i < myHand.size(); i++)
    {
        if(myHand[i].getRank() == c.getRank())
        {
            Card ret = myHand[i];
            myHand.erase(myHand.begin() + i);
            return ret;
        }
    }
    return d;
}

//randomly chooses card from hand
//inputs: none
//outputs: chosen card
Card Player::chooseCardFromHand() const
{
    int size = myHand.size();
    int random1 = rand() % size;
    return (myHand.at(random1));
}

//adds 2 cards to myBook
//inputs: 2 cards
//outputs: none
void Player::bookCards(Card c1, Card c2)
{
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//returns size of myBook
//inputs: none
//outputs: integer size of myBook
int Player::getBookSize() const
{
    return myBook.size();
}

//default destructor for Player
Player::~Player()
{

}




// FILE: go_fish.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
    ofstream f;
    f.open("game.txt");
    if (f.is_open())
    {
        int numCards = 7;
        bool gameOver = false;

        int turn = 0; // 0 if player one's turn, 1 for player two's turn etc.

        Player *p1 = new Player("Sri");
        Player *p2 = new Player("Alan");


        Deck *d = new Deck();  //create a deck of cards

        d->shuffle();

        dealHand(*d, *p1, numCards);
        dealHand(*d, *p2, numCards);

        f << p1->getName() <<" has : " << (*p1).showHand() << endl;
        f << p2->getName() <<" has : " << (*p2).showHand() << endl << endl;

        Card *c = new Card();
        Card *e = new Card();

        while(p1->checkHandForBook(*c, *e))
        {
            p1->removeCardFromHand(*c);
            p1->removeCardFromHand(*e);
        }
        while(p2->checkHandForBook(*c, *e))
        {
            p2->removeCardFromHand(*c);
            p2->removeCardFromHand(*e);
        }

        f << "After initial bookings, these are the hands: "<< endl;
        f << p1->getName() <<" has : " << (*p1).showHand() << endl;
        f << p2->getName() <<" has : " << (*p2).showHand() << endl << endl;

        f << "Start the game!"<< endl << endl;


        while(!gameOver)
        {
            if(turn % 2 == 0) //Player 1 turn
            {
                f << p1->getName() << "'s turn: " << endl;
                if(p1->getHandSize() == 0)
                {
                    if(d->size() > 0)
                    {
                        p1->addCard(d->dealCard());
                    }
                }
                else
                {
                    *c = p1->chooseCardFromHand();
                    f << p1->getName() << " says - Do you have any " << c->rankString(c->getRank()) << "s" << endl;
                    if(p2->rankInHand(*c))
                    {
                        f << p1->getName() << " books the " << c->rankString(c->getRank()) << endl;
                        p1->addCard(p2->removeCardFromHand(*c));
                        p1->checkHandForBook(*c, *e);
                        p1->removeCardFromHand(*c);
                        p1->removeCardFromHand(*e);
                        turn--;
                    }
                    else
                    {
                        f << "GoFish: " << p1->getName() << " draws a card: ";
                        if(d->size() > 0)
                        {
                            *c = d->dealCard();
                            p1->addCard(*c);
                            f << c->toString() << endl;
                            if(p1->checkHandForBook(*c, *e))
                            {
                                p1->removeCardFromHand(*c);
                                p1->removeCardFromHand(*e);
                            }
                        }
                    }
                }
            }
            else if(turn % 2 == 1) // Player 2 turn
            {
                f << p2->getName() << "'s turn: " << endl;
                if(p2->getHandSize() == 0)
                {
                    if(d->size() > 0)
                    {
                        p2->addCard(d->dealCard());
                    }
                }
                else
                {
                    *c = p2->chooseCardFromHand();
                    f << p2->getName() << " says - Do you have any " << c->rankString(c->getRank()) << "s" << endl;
                    if(p1->rankInHand(*c))
                    {
                        f << p2->getName() << " books the " << c->rankString(c->getRank()) << endl;
                        p2->addCard(p1->removeCardFromHand(*c));
                        p2->checkHandForBook(*c, *e);
                        p2->removeCardFromHand(*c);
                        p2->removeCardFromHand(*e);
                        turn--;
                    }
                    else
                    {
                        f << "GoFish: " << p2->getName() << " draws a card: ";
                        if(d->size() > 0)
                        {
                            *c = d->dealCard();
                            p2->addCard(*c);
                            f << c->toString() << endl;
                            if(p2->checkHandForBook(*c, *e))
                            {
                                p2->removeCardFromHand(*c);
                                p2->removeCardFromHand(*e);
                            }
                        }
                    }
                }
            }

            f << p1->getName() <<" has : " << (*p1).showHand() << endl;
            f << p2->getName() <<" has : " << (*p2).showHand() << endl;

            turn++;
            f << "The number of cards booked is " << p1->getBookSize() + p2->getBookSize() << endl << endl;
            if(p1->getBookSize() + p2->getBookSize() >= 52)
            {
                gameOver = true;
            }
        }

        f << p1->getName() << " has this many books: " << p1->getBookSize() / 2 << endl;
        f << p2->getName() << " has this many books: " << p2->getBookSize() / 2 << endl;

        if(p1->getBookSize() > p2->getBookSize())
        {
            f << p1->getName() << " is the winner!" << endl;
        }
        else if(p1->getBookSize() < p2->getBookSize())
        {
            f << p2->getName() << " is the winner!" << endl;
        }
        else
        {
            f << "This game is a draw" << endl;
        }

        f.close();
        delete p1;
        delete p2;
        delete d;
        delete c;
        delete e;
        return EXIT_SUCCESS;
    }
    cout << "file not found" << endl;
    return EXIT_SUCCESS;
}

//deals a hand of a given size from a given deck to a given player
//inputs: Deck &d, Player &p, int numCards
//outputs: none
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

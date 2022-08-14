/* Copyright (c) 2005 by The National Chengchi Univ. All Right Reserved */
#ifndef _SHDEALER_H_
#define _SHDEALER_H_
#include "SHPlayer.h"
// result of a game
enum Result {TIE, WIN, LOSE};

// foreward declaration of class SHPlayer
class SHPlayer;

/**
 * The Dealer class simulate the dealer in a show hand game.
 * It's responsible for
 * 1. shuffing the cards,
 * 2. draw and distribute a hand to a player.
 */
class SHDealer {

    public:

        /**
         * constructor
         */
        SHDealer();

        /**
         * destructor
         */
        ~SHDealer();

        /**
         * return a valid catd ID to the player
         */
        Card giveCard(int nCards);

        /**
         * give myself(the dealer) onmore card
         */
        void addCard(int nCards);

        /**
         * judge who has won the game
         * input argument is the show hand player
         */
        Result judge(SHPlayer& player);

        /**
         * starting a new game
         */
        void start();

        /**
         * open the first card so it faces up
         */
        void openFirstCard();

        /**
         * retain the whole set of cards and shuffle
         */
        void shuffle();

        /**
         * show the dealer's cards to the screen
         */
        void showCards() const;

    private:

        // TODO: your private or internal stuff goes here ...
		SHPlayer Dealer;
		Card deckCards[10];	// All cards are managed by dealer
};


#endif // _SHDEALER_H_

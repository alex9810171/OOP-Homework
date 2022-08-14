/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include "SHPlayer.h"
#include "SHDealer.h"
#include "Card.h"
#include "CardPattern.h"
#include "AnsiPrint.h"

// constructor
SHDealer::SHDealer():Dealer("Dealer")
{
}


// destructor
SHDealer::~SHDealer()
{

}


// distribute a card to the player
Card
SHDealer::giveCard(int nCards)
{
	return deckCards[nCards*2];
}


// give the dealer a card
void
SHDealer::addCard(int nCards)
{
	Dealer.addCard(deckCards[nCards*2 + 1]);
}


// determind who has win the game.
// if both of them have the same pattern,
// the one has more total pips wins the game.
Result
SHDealer::judge(SHPlayer& player)
{
	int pScore = player.getHandPattern();
	int dScore = Dealer.getHandPattern();
	if(pScore < dScore) return WIN;
	else if(pScore > dScore) return LOSE;
	else{
		int ScoreP = player.totalPips();
		int ScoreD = Dealer.totalPips();
		if(ScoreP > ScoreD) return WIN;
		else if(ScoreP < ScoreD) return LOSE; 
		else return TIE;
	}
}


// start a new game(round)
// before starting a new game(round), you should have
// a new deck, and then shuffle it.
// The deck only has pips A, 8, 9, 10, J, Q, K.
void
SHDealer::start()
{
	Dealer.start();
	shuffle();
}


// shuffle the deck of cards
void
SHDealer::shuffle()
{
	for(int i = 0;i < 10;i ++){
		int getCard = rand() % 52, pass = 0;
		while(pass == 0){
			int passed = 0;
			if(getCard < 32 && getCard > 3){
				getCard = rand() % 52;
				continue;
			}
			for(int j = 0;j < i;j ++)
				if(getCard == deckCards[j].getID()){
					getCard = rand() % 52;
					passed = 1;
					break;
				}
			if(passed == 0) pass = 1;
		}
		Card newCard;
		newCard.setID(getCard);
		deckCards[i]=newCard;
	}
}


// open the dealer's first card
void
SHDealer::openFirstCard()
{
	Dealer.openFirstCard();
}


// show the dealer's hand to the screen
void
SHDealer::showCards() const
{
	Dealer.showCards();
}

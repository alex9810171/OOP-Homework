/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include <iostream>
#include <cstring>
#include <cassert>
#include "AnsiPrint.h"
#include "Card.h"
#include "CardPattern.h"
#include "SHPlayer.h"


using namespace std;

const char* HandTypeName[9] = {
	"Straight flush",
	"Four of a kind",
	"Full house",
	"Flush",
	"Straight",
	"Three of a kind",
	"Two pair",
	"One pair",
	"Other"
};

// constructor
SHPlayer::SHPlayer(const char* playerName)
{

}

// initialize the number of cards to 0
void
SHPlayer::start()
{
	// In this assignment, we don't need to use this
}

// add a new card to the current hand
// need to protect the array from overflowing
void SHPlayer::addCard(Card newCard,int numCards)
{
	cards[numCards]= newCard;
	//Because this assignment didn't allow user to choose the number of cards,
	//so here I didn't protect the array from overflowing. >> ;-)
}

// open the first card so it faces up
void
SHPlayer::openFirstCard()
{
	// In this assignment, we don't need to use this
}

// print the current hand to the screen graphically
void
SHPlayer::showCards(int nCards, bool showFirst) const
{
	int pip, suit;
	char line[kCardWidth+1];
	for( int n = 0; n < nCards; n += kNCardPerRow ) {
		for( int height = 0; height < kCardHeight; height++, cout<<endl ) {
			for( int i = n; i < n+kNCardPerRow && i < nCards; i++, cout<<" " ) {
				if(showFirst == false && i == 0) pip = 13;
				else pip = cards[i].getID() / cards[i].kNSuit;
				suit = cards[i].getID() % cards[i].kNSuit;
				for( int width = 0; width < kCardWidth; width++ ) {
					line[width]=card[pip][height][width];
					if( line[width] == 'x' ) 
						line[width] = cardAbbrev[suit];
				}
				line[kCardWidth]='\0';
				// color print the row and put a space in between
				AnsiPrint(line,cardColor[suit],white);
			}
		}
	}
}

// get the total points of the current hand
int
SHPlayer::totalPips(int numCards) const
{
	int i = 0, total = 0;

	for(i = 0;i < numCards;i ++) total = total + cards[i].getPip();
	return total;
}

// judge what kind of hand type you own
// you need to have 5 cards
HandType
SHPlayer::getHandPattern() 
{
	sortCards();
	if(isStraightFlush()) return STRAIGHT_FLUSH;
	else if(isFourOfAKind()) return FOUR_OF_A_KIND;
	else if(isFullHouse()) return FULL_HOUSE;
	else if(isFlush()) return FLUSH;
	else if(isStraight()) return STRAIGHT;
	else if(isThreeOfAKind()) return THREE_OF_A_KIND;
	else if(isTwoPair()) return TWO_PAIR;
	else if(isOnePair()) return ONE_PAIR;
	else return OTHER;
}

// return the number of cards at hand
int
SHPlayer::getNumCards() const
{
	return 0;
	// In this assignment, we don't need to use this
}

void
SHPlayer::sortCards() 
{
	int i = 0, j = 0;
	Card tempCards;

	for(i = 0;i < 5;i ++) sortedCards[i] = cards[i];
	for(i = 0;i < 4;i ++)
		for(j = 0; j < 4 - i;j ++)
			if(sortedCards[j].getID() > sortedCards[j + 1].getID()){
				tempCards = sortedCards[j];
				sortedCards[j] = sortedCards[j + 1];
				sortedCards[j + 1] = tempCards;
			}
}

// any five card sequence of same suit
bool 
SHPlayer::isStraightFlush() const
{
	if(isStraight() && isFlush()) return true;
	else return false;
}

// four cards of the same pip
bool 
SHPlayer::isFourOfAKind() const
{
	// O O O O X
	if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
			sortedCards[2].getPip() == sortedCards[3].getPip() &&
			sortedCards[0].getPip() == sortedCards[2].getPip() )
		return true;
	// X O O O O
	if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
			sortedCards[3].getPip() == sortedCards[4].getPip() &&
			sortedCards[1].getPip() == sortedCards[3].getPip() )
		return true;

	return false;
}

// three of a kind combined with a pair
bool 
SHPlayer::isFullHouse() const
{
	// O O O X X
	if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
			sortedCards[1].getPip() == sortedCards[2].getPip() &&
			sortedCards[3].getPip() == sortedCards[4].getPip() )
		return true;
	// X X X O O
	if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
			sortedCards[2].getPip() == sortedCards[3].getPip() &&
			sortedCards[3].getPip() == sortedCards[4].getPip() )
		return true;

	return false;
}

// five cards of the same suit
bool
SHPlayer::isFlush() const
{
	for( int i = 0; i < kMaxCards - 1; i++ )
		if( sortedCards[i].getSuit() != sortedCards[i+1].getSuit() )
			return false;

	return true;
}

// five cards in sequence
bool 
SHPlayer::isStraight() const
{
	for( int i = 0; i < kMaxCards - 1; i++ )
		if( sortedCards[i].getPip() + 1 != sortedCards[i+1].getPip() )
			return false;

	return true;
}

// three cards of the same pip
bool 
SHPlayer::isThreeOfAKind() const
{
	for( int i = 0; i < kMaxCards - 2; i++ )
		if( sortedCards[i].getPip() == sortedCards[i+1].getPip() &&
				sortedCards[i].getPip() == sortedCards[i+2].getPip() )
			return true;

	return false;
}

// two cards of one pip, two cards of another pip
bool 
SHPlayer::isTwoPair() const
{
	// O O @ @ X
	if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
			sortedCards[2].getPip() == sortedCards[3].getPip() )
		return true;
	// O O X @ @
	if( sortedCards[0].getPip() == sortedCards[1].getPip() &&
			sortedCards[3].getPip() == sortedCards[4].getPip() )
		return true;
	// X O O @ @
	if( sortedCards[1].getPip() == sortedCards[2].getPip() &&
			sortedCards[3].getPip() == sortedCards[4].getPip() )
		return true;

	return false;
}

// two cards of one pip
bool 
SHPlayer::isOnePair() const
{
	for( int i = 0; i < kMaxCards - 1; i++ )
		if( sortedCards[i].getPip() == sortedCards[i+1].getPip() )
			return true;

	return false;
}



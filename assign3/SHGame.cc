/* Copyright (c) 2005 by The National Chengchi Univ. All Rights Reserved */

#include "SHGame.h"
#include "SHPlayer.h"
#include "SHDealer.h"
#include <iostream>
using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
SHGame::SHGame(SHPlayer& shp, SHDealer& shd)
: menu(sizeof(menuItems)/sizeof(char*), menuItems),player(shp),dealer(shd)
{
	nCards = 0;
	state = 0;
	pLife = initCredit;
	dLife = initCredit;
}


// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
SHGame::oneRun()
{
	int ans = 0;
	menu.print();
	ans = menu.getAnswer();
	if(ans == 1){	// One more card
		if(nCards < 5 && state != 0) moreCard();
		else{
			cout << "GAME OVER!" << endl;
			player.showCards();
			dealer.showCards();
		}
		return true;
	}
	else if(ans == 2){
		if(nCards < 5 && state != 0) giveUp();
		else{
			cout << "GAME OVER!" << endl;
			player.showCards();
			dealer.showCards();
		}
		return true;
	}
	else if(ans == 3){
		if(state == 0 && pLife > 0 && dLife > 0) restart();
		else if(state == 1){
			cout << "Game is not over yet. Choose 'give up' to end a game" << endl;
			player.showCards();
			dealer.showCards();
		}
		else{
			cout << "Sorry. Game over. No loan here." << endl;
			player.showCards();
			dealer.showCards();
		}
		return true;
	}
	else if(ans == 4)return false;
	else return false;
}

// All check are included in onerun, it would improve a slight performance ;)

// give the player and dealer one more card
// check if we can do that first.
// and judge who has win the round if the player have 5 cards
void
SHGame::moreCard()
{
	player.addCard(dealer.giveCard(nCards));
	dealer.addCard(nCards);
	nCards++;
	if(nCards < 5){
		player.showCards();
		dealer.showCards();	
	}
	else if(nCards == 5){
		int end = 0;
		end = dealer.judge(player);
		if(end == 0) cout << "Tie";
		else if(end == 1){
			pLife = pLife + nCards*betCredit;
			dLife = dLife - nCards*betCredit;
			cout << "You win. Good job.(You have " << pLife
				<< " points, I Have " << dLife << " points.)" << endl;
		}
		else if(end == 2){
			pLife = pLife - nCards*betCredit;
			dLife = dLife + nCards*betCredit;
			cout << "I win. Try again.(You have " << pLife
				<< " points, I Have " << dLife << " points.)" << endl;
		}
		dealer.openFirstCard();
		player.showCards();
		dealer.showCards();
		state = 0;
	}
}


// give up this round,
// and you'll lose your credit
// the bet is equivalent to the number of card you keep
void
SHGame::giveUp()
{
	pLife = pLife - nCards*betCredit;
	dLife = dLife + nCards*betCredit;
	cout << "I win. Try again.(You have " << pLife
		<< " points, I Have " << dLife << " points.)" << endl;
	dealer.openFirstCard();
	player.showCards();
	dealer.showCards();
	state = 0;
}


// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void
SHGame::restart()
{
	state = 1;
	nCards = 0;
	dealer.start();
	player.start();
	player.addCard(dealer.giveCard(nCards));
	dealer.addCard(nCards);
	nCards++;
	player.addCard(dealer.giveCard(nCards));
	dealer.addCard(nCards);
	nCards++;
	player.openFirstCard();
	player.showCards();
	dealer.showCards();
}

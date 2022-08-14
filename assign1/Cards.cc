/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
  NAME
  Cards.cc
  NOTE
  You are asked to design this module.
  You need to draw the given number of cards and print them out.
  Assume that you are given a deck of 52 cards. The cards do not reappear.
  That is, you do not put a card back into the deck after it is drawn.
 ***************************************************************************/
#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

void PrintCard(int ncards, int cards[kNCards]){
	int i, j, k, l, color, number;
	char temp[2] = {'\0'}, colors[4][2] = {"C","D","H","S"};
	for(i = 0;i < ncards / 5;i ++)
		for(j = 0;j < kCardHeight; j++)
			for(k = 0;k < 5;k ++){
				color = cards[i * 5 + k] / 13;
				number = cards[i * 5 + k] % 13;
				if(color == 0 || color == 3){
					for(l = 0;l < kCardWidth;l ++){
						if(card[number][j][l] != 'x'){
							temp[0] = card[number][j][l];
							AnsiPrint(temp, black, white, false, false);
						}
						else AnsiPrint(colors[color], black, white, false, false);
					}
				}
				else{
					for(l = 0;l < kCardWidth;l ++){
						if(card[number][j][l] != 'x'){
							temp[0] = card[number][j][l];
							AnsiPrint(temp, red, white, false, false);
						}
						else AnsiPrint(colors[color], red, white, false, false);
					}
				}
				if(k != 4) cout << " ";
				else cout << endl;
			}
	for(j = 0;j < kCardHeight; j++)
		for(k = 0;k < 5 && k < ncards - i * 5;k ++){
			color = cards[i * 5 + k] / 13;
			number = cards[i * 5 + k] % 13;
			if(color == 0 || color == 3){
				for(l = 0;l < kCardWidth;l ++){
					if(card[number][j][l] != 'x'){
						temp[0] = card[number][j][l];
						AnsiPrint(temp, black, white, false, false);
					}
					else AnsiPrint(colors[color], black, white, false, false);
				}
			}
			else{
				for(l = 0;l < kCardWidth;l ++){
					if(card[number][j][l] != 'x'){
						temp[0] = card[number][j][l];
						AnsiPrint(temp, red, white, false, false);
					}
					else AnsiPrint(colors[color], red, white, false, false);
				}
			}
			if(k != ncards - i * 5 - 1) cout << " ";
			else cout << endl;
		}
}


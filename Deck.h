#ifndef _DECK_H_
#define _DECK_H_
#include "Card.h"
class Deck {
	private:
		int top;
		Card storage [52];
	public:
		Deck();
		void refreshDeck();
		Card deal();
		void shuffle();
		int cardsLeft();
		void showDeck();
};
#endif
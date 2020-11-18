#ifndef _CARD_H_
#define _CARD_H_
class Card {
	private:
		char suit;
		char rank;
	public:
		Card();
		Card(char r, char s);
		void setCard(char r, char s);
		int getValue();
		void showCard();
};
#endif
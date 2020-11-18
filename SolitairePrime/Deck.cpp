#include "Deck.h";
#include "Card.h";
#include <stdlib.h>;
#include <iostream>;
#include <time.h>;
Deck::Deck() {
	char suits[] = { 'H','D','S','C'};
	char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	top = 0;
	int count = 0;
	for (int s = 0; s < 4; s++)
		for (int r = 0; r < 13; r++)
		{
			storage[count++] = Card(ranks[r], suits[s]);
		}
}
void Deck::refreshDeck() {
	char suits[] = { 'H','D','S','C'};
	char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	top = 0;
	int count = 0;
	for (int s = 0; s < 4; s++)
		for (int r = 0; r < 13; r++)
		{
			storage[count++].setCard(ranks[r], suits[s]);
		}
}
Card Deck::deal() {
	return storage[top++];
}
void Deck::shuffle() {
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		int x = rand() % 52;
		int y = rand() % 52;
		Card temp = storage[x];
		storage[x] = storage[y];
		storage[y] = temp;
	}
}
int Deck::cardsLeft() {
	return 52 - top;
}
void Deck::showDeck() {
	for (int cardNum = 0; cardNum < 52; cardNum++) {
		storage[cardNum].showCard();
		// Print a new line after every 13 cards
		if (cardNum == 12 || cardNum == 25 || cardNum == 38) {
			std::cout << "\n";
		}
	}
	std::cout << "\n";
}
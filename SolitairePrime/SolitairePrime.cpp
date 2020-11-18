// Issa Issa
// CECS 282-07
// Solitaire Prime - Prog 1
// 02-12-20
#include <iostream>;
#include "Card.h";
#include "Deck.h";
#include <string>;
void printMenu() {
	std::cout << "Welcome to Solitaire Prime!\n";
	std::cout << "1) New Deck\n";
	std::cout << "2) Display Deck\n";
	std::cout << "3) Shuffle Deck\n";
	std::cout << "4) Play Solitaire Prime\n";
	std::cout << "5) Exit\n";
}
int menu() {
	std::cout << "\nPlease choose an option or enter 5 to exit: ";
	int choice = 0;
	std::cin >> choice;
	return choice;
}
bool isPrime(int number) {
	int divisors = 2;
	if (number == 0 || number == 1) {
		return false;
	}
	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			divisors++;
		}
		if (divisors > 2) {
			return false;
		}
	}
	return true;
}
int main() {
	printMenu();
	int choice = menu();
	Deck myDeck;
	while (choice != 5) {
		// New deck
		if (choice == 1) {
			myDeck.refreshDeck();
		}
		// Display the deck
		if (choice == 2) {
			myDeck.showDeck();
		}
		// Shuffle deck
		if (choice == 3) {
			myDeck.shuffle();
		}
		// Play Solitaire Prime
		// If they played the game already and the deck is empty then tell the user
		if (choice == 4) {
			if (myDeck.cardsLeft() == 0) {
				std::cout << "There is no more cards, please make a new deck first.";
			}
			// There is a deck and they can play Solitaire Prime
			else {
				int winnerIn = 0;
				int summ = 0;
				// Pile to store cards that are not prime, most you can have is 52
				// because there is 52 cards in a deck
				Card pile[52];
				int indexOfPile = 0;
				while (myDeck.cardsLeft() >= 0) {
					if (!isPrime(summ)) {
						// If it's the last pile and it's not prime then it's a loser
						if (myDeck.cardsLeft() == 0) {
							for (int j = 0; j < indexOfPile; j++) {
								pile[j].showCard();
							}
							std::cout << "Loser\n";
							break;
						}
						else {
							pile[indexOfPile] = myDeck.deal();
							summ = summ + pile[indexOfPile].getValue();
							indexOfPile++;
						}
					}
					else {
						winnerIn++;
						for (int j = 0; j < indexOfPile; j++) {
							pile[j].showCard();
						}
						std::cout << "Prime:" << summ << "\n";
						// If it's the last pile and it's prime then it's a winner
						if (myDeck.cardsLeft() == 0) {
							std::cout << "Winner in " << winnerIn << " piles!\n";
							break;
						}
						else {
							// Discard pile and start everything over
							summ = 0;
							indexOfPile = 0;
						}
					}
				}
			}
		}
		printMenu();
		choice = menu();
	}
}
#include "Card.h";
#include <iostream>;
Card::Card() {
	rank = NULL;
	suit = NULL;
}
Card::Card(char r, char s) {
	rank = r;
	suit = s;
}
int Card::getValue() {
	if (rank == 'A')
		return 1;
	else if (rank == 'T' || rank == 'J' || rank == 'Q' || rank == 'K')
		return 10;
	else
		return rank - '0';
}
void Card::showCard() {
	if (rank == 'T')
		std::cout << "10" << suit << ", ";
	else
		std::cout << rank << suit << ", ";
}
void Card::setCard(char r, char s) {
	rank = r;
	suit = s;
}


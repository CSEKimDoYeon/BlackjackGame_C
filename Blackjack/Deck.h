#pragma once
#include <iostream>
#include <string>
#include "TrumpCard.h"
#include "FlowerCard.h"
#include "PlayingCard.h"
#include <random>
using namespace std;

class Deck {
public :
	int inputoption;
public:
	TrumpCard* tc;
	FlowerCard* fc;   // An array of 52 Cards, representing the deck.
	// 플라워카드 48장, 트럼프카드 52장.
public:
	Deck() {};

public: Deck(int inputoption) : inputoption(inputoption) {}

private:
	int cardsUsed; // How many cards have been dealt from the deck.

public:
	//Deck() {
	//	// Create an unshuffled deck of cards.
	////	deck = new Card[52];
	//	int cardCt = 0; // How many cards have been created so far.
	//	for (int suit = 0; suit <= 3; suit++) {
	//		for (int value = 1; value <= 13; value++) {
	//			deck[cardCt] = Card(value, suit);
	//			cardCt++;
	//		}
	//	}
	//	cardsUsed = 0;
	//}
	void makeDeck(int option) {
		if (option == 2) {
			// Create an unshuffled deck of cards.
			fc = new FlowerCard[48];
			int cardCt = 0; // How many cards have been created so far.
			for (int value = 1; value <= 12; value++) {
				if (value == 1 | 4 | 8 | 11 | 12) {
					fc[cardCt] = FlowerCard(value, 20);
					cardCt++;
				}
			}
			cardsUsed = 0; // ****아직*****
		}
		else if (option == 1) {
			tc = new TrumpCard[52];
			int cardCt = 0; // How many cards have been created so far.
			for (int suit = 0; suit <= 3; suit++) {
				for (int value = 1; value <= 13; value++) {
					tc[cardCt] = TrumpCard(value, suit);
					cardCt++;
				}
			}
			cardsUsed = 0;
		}
	}

public:
	void shuffle() {
		// Put all the used cards back into the deck, and shuffle it into
		// a random order.
		random_device rdev;
		default_random_engine gen(rdev());
		if (inputoption == 1) {
			for (int i = 51; i > 0; i--) {
				uniform_real_distribution<>dist(0, 1);
				int rand = (int)(dist(gen)*(i + 1));
				TrumpCard temp = tc[i];
				tc[i] = tc[rand];
				tc[rand] = temp;
			}
		}
		cardsUsed = 0;
	}

public:
	int cardsLeft() {
		// As cards are dealt from the deck, the number of cards left
		// decreases.  This function returns the number of cards that
		// are still left in the deck.
		return 52 - cardsUsed;
	}

public:
	TrumpCard dealCard() {
		// Deals one card from the deck and returns it.
		if (cardsUsed == 52)
			shuffle();
		cardsUsed++;
		return tc[cardsUsed - 1];
	}
};
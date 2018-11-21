#pragma once
#include <iostream>
#include <string>
#include "TrumpCard.h"
#include <vector>

using namespace std;

class Hand{

private:
	vector<TrumpCard> hand;   // The cards in the hand.

public:
	Hand() {
		// Create a Hand object that is initially empty.
		//hand = new vector();
	}

public:
	void clear() {
		// Discard all the cards from the hand.
		hand.clear();
	}

public:
	void addCard(TrumpCard c) {
		// Add the card c to the hand.  c should be non-null.  (If c is
		// null, nothing is added to the hand.)
		if ((c.toString().size())!= NULL)
			hand.push_back(c);
	}

public:
	void removeCard(TrumpCard c) {
		// If the specified card is in the hand, it is removed.
		//hand.erase(c);
		for (vector<TrumpCard>::iterator iter = hand.begin(); iter != hand.end(); ) {
			if ((*iter).toString().compare(c.toString()) == 0)
				iter = hand.erase(iter);
			else
				++iter;
		}
	}

public:
	void removeCard(int position) {
		// If the specified position is a valid position in the hand,
		// then the card in that position is removed.
		/*if (position >= 0 && position < hand.size())
			hand.erase(position);*/
		for (vector<TrumpCard>::iterator iter = hand.begin(); iter != hand.end(); ) {
			if ((*iter).toString().compare(hand.at(position).toString()) == 0)
				iter = hand.erase(iter);
			else
				++iter;
		}
	}

public:
	int getCardCount() {
		// Return the number of cards in the hand.
		return hand.size();
	}

public:
	TrumpCard getCard(int position) {
		// Get the card from the hand in given position, where positions
		// are numbered starting from 0.  If the specified position is
		// not the position number of a card in the hand, then null
		// is returned.
		if (position >= 0 && position < hand.size())
			return (TrumpCard)hand.at(position);
		else
			return  (TrumpCard)hand.at(position).getNullCard();
	}

public:
	void sortBySuit() {
		// Sorts the cards in the hand so that cards of the same suit are
		// grouped together, and within a suit the cards are sorted by value.
		// Note that aces are considered to have the lowest value, 1.
		vector<TrumpCard> newHand = vector<TrumpCard>();
		while (hand.size() > 0) {
			int pos = 0;  // Position of minimal card.
			TrumpCard c = (TrumpCard)hand.at(0);  // Minumal card.
			for (int i = 1; i < hand.size(); i++) {
				TrumpCard c1 = (TrumpCard)hand.at(i);
				if (c1.getSuit() < c.getSuit() ||
					(c1.getSuit() == c.getSuit() && c1.getValue() < c.getValue())) {
					pos = i;
					c = c1;
				}
			}
			removeCard(pos);
			newHand.push_back(c);
		}
		hand = newHand;
	}

public:
	void sortByValue() {
		// Sorts the cards in the hand so that cards of the same value are
		// grouped together.  Cards with the same value are sorted by suit.
		// Note that aces are considered to have the lowest value, 1.
		vector<TrumpCard> newHand = vector<TrumpCard>();
		while (hand.size() > 0) {
			int pos = 0;  // Position of minimal card.
			TrumpCard c = (TrumpCard)hand.at(0);  // Minumal card.
			for (int i = 1; i < hand.size(); i++) {
				TrumpCard c1 = (TrumpCard)hand.at(i);
				if (c1.getValue() < c.getValue() ||
					(c1.getValue() == c.getValue() && c1.getSuit() < c.getSuit())) {
					pos = i;
					c = c1;
				}
			}
			removeCard(pos);
			newHand.push_back(c);
		}
		hand = newHand;
	}

};
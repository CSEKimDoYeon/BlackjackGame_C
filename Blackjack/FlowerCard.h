#pragma once
#include <iostream>
#include <string>
#include "PlayingCard.h"
using namespace std;

class FlowerCard : public PlayingCard {

public:
	FlowerCard() {}

public:
	//static int SPADES = 0, HEARTS = 1, DIAMONDS = 2, CLUBS = 3;
	int QWANG = 20;
	int ANIMAL = 10;
	int PEE = 1;
	//int DIAMONDS=2;
	//int CLUBS=3;

	// Codes for the 4 suits.

public:
	//final static int ACE = 1, JACK = 11, QUEEN = 12, KING = 13;         Codes for the non-numeric cards.
	//   Cards 2 through 10 have their 
	//   numerical values for their codes.
	int SOL = 1;
	int MAEHWA = 2;
	int SAKURA = 3;
	int HUKSARI = 4;
	int NANCHO = 5;
	int JANGMI = 6;
	int HONGSARI = 7;
	int DAL = 8;
	int GUCKHWA = 9;
	int DANPUNG = 10;
	int	DDONG = 11;
	int BE = 12;
	//int ACE=1;
	//int JACK=11;
	//int QUEEN=12;


private:
	int suit = -1;   // The suit of this card, one of the constants
					 //    SPADES, HEARTS, DIAMONDS, CLUBS.

private:
	int value = -1;  // The value of this card, from 1 to 11.

public:
	FlowerCard(int theValue, int theSuit) {
		// Construct a card with the specified value and suit.
		// Value must be between 1 and 13.  Suit must be between
		// 0 and 3.  If the parameters are outside these ranges,
		// the constructed card object will be invalid.
		value = theValue;
		suit = theSuit;
	}

public:
	FlowerCard getNullCard() {
		FlowerCard fc = FlowerCard(0, 0);
		return fc;
	}

public:
	int getSuit() {
		// Return the int that codes for this card's suit.
		return suit;
	}

public:
	int getValue() {
		// Return the int that codes for this card's value.
		return value;
	}

public:
	string getSuitAsString() {
		// Return a String representing the card's suit.
		// (If the card's suit is invalid, "??" is returned.)
		switch (suit) {
		case 20:   return "광";
		case 10:   return "띠";
		case 1: return "피";
			//case 3:    return "Clubs";
		default:       return "??";
		}
	}

public:
	string getValueAsString() {
		// Return a String representing the card's value.
		// If the card's value is invalid, "??" is returned.
		switch (value) {
		case 1:   return "솔(1월)";
		case 2:   return "매화(2월)";
		case 3:   return "사쿠라(3월)";
		case 4:   return "흑사리(4월)";
		case 5:   return "난초(5월)";
		case 6:   return "장미(6월)";
		case 7:   return "홍사리(7월)";
		case 8:   return "달(8월)";
		case 9:   return "국화(9월)";
		case 10:  return "단풍(10월)";
		case 11:  return "똥(11월)";
		case 12:  return "비(12월)";
			//case 13:  return "King";
		default:  return "??";
		}
	}

public:
	string toString() {
		// Return a String representation of this card, such as
		// "10 of Hearts" or "Queen of Spades".
		return getValueAsString() + " of " + getSuitAsString();
	}

};
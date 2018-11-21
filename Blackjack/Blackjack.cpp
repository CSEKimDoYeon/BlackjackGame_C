#pragma once
#include <iostream>
#include <string>
#include "BlackjackHand.h"
#include "Deck.h"
using namespace std;

char convertLowCap(char c) {
	if (c >= 'a' && c <= 'z') return (c - 32);
}


bool playBlackjack() {
	// Let the user play one game of Blackjack.
	// Return true if the user wins, false if the user loses.


	/*  Shuffle the deck, then deal two cards to each player. */
	
	int option;
	cout << "사용할 카드 선택 1(트럼프카드), 2(플라워카드)";
	cin >> option;
	
	Deck deck;                  // A deck of cards.  A new deck for each game.
	BlackjackHand dealerHand;   // The dealer's hand.
	BlackjackHand userHand;     // The user's hand.

	deck = Deck();
	dealerHand = BlackjackHand();
	userHand = BlackjackHand();
	
	deck.makeDeck(option);
	deck.shuffle();
	dealerHand.addCard(deck.dealCard());
	dealerHand.addCard(deck.dealCard());
	userHand.addCard(deck.dealCard());
	userHand.addCard(deck.dealCard());

	cout << "\n\n";

	/* Check if one of the players has Blackjack (two cards totaling to 21).
	The player with Blackjack wins the game.  Dealer wins ties.
	*/

	if (dealerHand.getBlackjackValue() == 21) {
		cout << "Dealer has the " << dealerHand.getCard(0).toString() <<
			" and the " << dealerHand.getCard(1).toString() << ".\n";
		cout << "User has the " << userHand.getCard(0).toString()
			<< " and the " << userHand.getCard(1).toString() << ".\n";
		cout << endl;
		cout << "Dealer has Blackjack.  Dealer wins.\n";
		return false;
	}

	if (userHand.getBlackjackValue() == 21) {
		cout << "Dealer has the " << dealerHand.getCard(0).toString()
			<< " and the " << dealerHand.getCard(1).toString() << ".\n";
		cout << "User has the " << userHand.getCard(0).toString()
			<< " and the " << userHand.getCard(1).toString() << ".";
		cout << endl;
		cout << "You have Blackjack.  You win.\n";
		return true;
	}

	/*  If neither player has Blackjack, play the game.  First the user
	gets a chance to draw cards (i.e., to "Hit").  The while loop ends
	when the user chooses to "Stand".  If the user goes over 21,
	the user loses immediately.
	*/

	while (true) {

		/* Display user's cards, and let user decide to Hit or Stand. */

		cout << "\n\nYour cards are:\n";
		for (int i = 0; i < userHand.getCardCount(); i++)
			cout << "    " << userHand.getCard(i).toString() << endl;
		cout << "Your total is " << userHand.getBlackjackValue() << endl;
		cout << "\nDealer is showing the " << dealerHand.getCard(0).toString() << "\n\n";
		cout << "Hit (H) or Stand (S)? " << endl;
		char userAction;  // User's response, 'H' or 'S'.
		do {
			//userAction = input.nextLine().toUpperCase().charAt(0);
			cin >> userAction;
			userAction = convertLowCap(userAction);
			if (userAction != 'H' && userAction != 'S')
				cout << "Please respond H or S:  ";
		} while (userAction != 'H' && userAction != 'S');

		/* If the user Hits, the user gets a card.  If the user Stands,
		the loop ends (and it's the dealer's turn to draw cards).
		*/

		if (userAction == 'S') {
			// Loop ends; user is done taking cards.
			break;
		}
		else {  // userAction is 'H'.  Give the user a card.  
				// If the user goes over 21, the user loses.
			TrumpCard newCard = deck.dealCard();
			userHand.addCard(newCard);
			cout << "\nUser hits.\n";
			cout << "Your card is the " << newCard.toString();

			cout << "Your total is now " << userHand.getBlackjackValue() << endl;
			if (userHand.getBlackjackValue() > 21) {
				cout << "\nYou busted by going over 21.  You lose." << endl;
				cout << "Dealer's other card was the "
					<< dealerHand.getCard(1).toString() << endl;
				return false;
			}
		}

	} // end while loop

	  /* If we get to this point, the user has Stood with 21 or less.  Now, it's
	  the dealer's chance to draw.  Dealer draws cards until the dealer's
	  total is > 16.  If dealer goes over 21, the dealer loses.
	  */

	cout << "\nUser stands.\n";
	cout << "Dealer's cards are\n";
	cout << "    " << dealerHand.getCard(0).toString() << endl;
	cout << "    " << dealerHand.getCard(1).toString() << endl;
	while (dealerHand.getBlackjackValue() <= 16) {
		TrumpCard newCard = deck.dealCard();
		cout << "Dealer hits and gets the " << newCard.toString();
		dealerHand.addCard(newCard);
		if (dealerHand.getBlackjackValue() > 21) {
			cout << "\nDealer busted by going over 21.  You win.\n";
			return true;
		}
	}
	cout << "Dealer's total is " << dealerHand.getBlackjackValue() << endl;

	/* If we get to this point, both players have 21 or less.  We
	can determine the winner by comparing the values of their hands. */

	cout << endl;
	if (dealerHand.getBlackjackValue() == userHand.getBlackjackValue()) {
		cout << "Dealer wins on a tie.  You lose.\n";
		return false;
	}
	else if (dealerHand.getBlackjackValue() > userHand.getBlackjackValue()) {
		cout << "Dealer wins, " << dealerHand.getBlackjackValue()
			<< " points to " << userHand.getBlackjackValue() + ".\n";
		return false;
	}
	else {
		cout << "You win, " << userHand.getBlackjackValue()
			<< " points to " << dealerHand.getBlackjackValue() << ".\n";
		return true;
	}
}

int main() {

	int bet;            // Amount user bets on a game.
	bool userWins;   // Did the user win the game?
	int money = 100;          // Amount of money the user has. User starts with $100.

	cout << "Welcome to the game of blackjack.\n\n";

	while (true) {
		try {				//배팅금액을 입력하였을 때 현재 가지고있는 금액의 범위를 벗어난 경우 
							//재입력하여 범위에 맞을 경우 throw bet하여 catch문에서 조건에 맞게 게임을 실행
			cout << "How many dollars do you want to bet?  (Enter 0 to end.)\n";
			cout << "? ";
			cin >> bet;
			if (bet < 0 || bet > money) {
				cout << "Your answer must be between 0 and " << money << ".\n";
				cout << "How many dollars do you want to bet?  (Enter 0 to end.)\n";
				cout << "? ";
				cin >> bet;
			}
			throw bet;
		}
		catch (int bet) {
			if (bet == 0)
				break;
			userWins = playBlackjack();
			if (userWins)
				money = money + bet;
			else
				money = money - bet;
			cout << endl;
			if (money == 0) {
				cout << "Looks like you've are out of money!\n";
				break;
			}
	
		}

		cout << "\nYou leave with $" << money << ".\n";
	} // end main()
	return 0;
}
// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "art_call.h"
#include "variable_structs.h"
#include "account_save_load.h"
#include "bug_fix.h"
#include "stocks_and_news.h"
#include "life_event.h"
using namespace std;

int main() {
	//print the welcome message
	game_starting_art();
	srand(time(NULL)); //seed for random life event
	cout << endl;
	cout << "Welcome to \"Life of A Trader\"! ";
	cout << "This is a trading simulating game that incorporates life events" << endl;
	cout << "| To create an account, please type '0' | ";
	cout << "To access an existing account, please type '1' | ";
	cout << "To delete an existing account, please type '2' | ";
	cout << "To exit the program, please type '3' |" << endl;
	cout << "Your command: ";

	portfolio account; //For storing the user data extracted from the account_access() function

	string choice_checker; //For debugging, check the input is 1 or 0
	cin >> choice_checker;

	while (true) { //Loop for chosing create account or accessing an existing account (file I/O loop)
		int choice = main_choice_vaild_checker(choice_checker); //For debugging, check the input is 1 or 0
/*________________________________________________________________________________________________________________________________________________*/
	
		if (choice == 0) {  //if create new profile
			cout << "(Non-case-sensitive) To create a new profile, please enter a name of the profile: ";
			string input_name;
			cin >> input_name;
			transform(input_name.begin(), input_name.end(), input_name.begin(), ::tolower);
			int create_or_not = account_list_checker(input_name);
			if (create_or_not == 1) {
				create_portfolio(input_name);
				account_access(input_name, account);
				break;
			}
			if (create_or_not == 0) {
				cout << "The account you wanted is in a saved-file, please in type '1' to chose your account" << endl;
				cout << endl;
			}
		}
/*________________________________________________________________________________________________________________________________________________*/

		if (choice == 1) {  //if load existing profiles
			int account_existence_checker; //To check whether there exist at least one account
			account_existence_checker = print_check_avalible_account_list();
			if (account_existence_checker == 1) {
				cout << "(Non-case-sensitive) Please type in the name of the profile that you want to access: ";
				string input_name;
				cin >> input_name;
				transform(input_name.begin(), input_name.end(), input_name.begin(), ::tolower);
				int accessibility = account_access(input_name, account);
				if (accessibility == 1) { //If the file exist, then the data is extracted and the file I/O loop ends
					break;
				}
				if (accessibility == 0) { //If the file does not exist, the loop continues
					cout << "Sorry, the account you wanted does not exist, please chose an existing account or create a new one" << endl;
					cout << endl;
				}
			}
			else {
				cout << "Sorry, there is no avalible account, please create a new one." << endl;
				cout << endl;
			}
		}

/*________________________________________________________________________________________________________________________________________________*/

		if (choice == 2) {  //if delete profile
			int account_existence_checker; //To check whether there exist at least one account
			account_existence_checker = print_check_avalible_account_list();
			if (account_existence_checker == 1) {
				cout << "(Non-case-sensitive) Please type in the name of the profile that you want to delete: ";
				string input_name;
				cin >> input_name;
				transform(input_name.begin(), input_name.end(), input_name.begin(), ::tolower);
				int accessibility = delete_account(input_name);
				if (accessibility == 1) {
					cout << "Account deleted successfully" << endl;
					cout << endl;
				}
				if (accessibility == 0) { //If the file does not exist, the loop continues
					cout << "Sorry, the account you wanted to delete does not exist, please chose another one" << endl;
					cout << endl;
				}
			}
			else {
				cout << "Sorry, there is no avalible account to delete" << endl;
				cout << endl;
			}
		}
/*________________________________________________________________________________________________________________________________________________*/

		if (choice == 3) {  //if quit the game
			exit(1);
		}
		if (choice == 69) { //hack code ??
			cout << "I go to school by bus" << endl;
		}

		cout << "| To create an account, please type '0' | ";
		cout << "To access an existing account, please type '1' | ";
		cout << "To delete an existing account, please type '2' | ";
		cout << "To exit the program, please type '3' |" << endl;
		cout << "Your command: ";
		cin >> choice_checker;
	} //
/*________________________________________________________________________________________________________________________________________________*/
	
	//get the stocks-index mapping
	//and the news and standard parameters of randomized movements
	stock_index_mapping();
	stock_mean_sd();
	load_financial_news();
	
	//display the account info
	display_stock_prices(account);

/*________________________________________________________________________________________________________________________________________________*/
	string action; //For storing Buy, Sell, End day options
	string targetstock; //For storing stocks symbol options
	string number_of_shares;
	int activeNews = -1;	//For choosing which news event to be on hoist
	bool existedNews[15];	//For storing which news have been shown already, and won't be shown again
	int validation;		//Validating the order
	
	//initialize existedNews all to false
	for (int i = 0; i < 15; i++)
		existedNews[i] = false;
	
	while (true) {
		cout << "B - Buy, S - Sell, E - End Week, Q - Quit and save." << endl;
		cout << " E.g. \"b aapl 23\" = buy 23 stocks of AAPL. Non-case-sensitive" << endl;
		cout << "Remainder: it is suggested to keep at least $5000 as emergency fund, if you don't have sufficient cash, there is a chance that you will need to start over :(" << endl;
		cout<< "Your command: ";
		cin >> action;
		cout << endl;
		cout << "_____________________________________________________________________________________________________________________________________________________________" << endl;

/*________________________________________________________________________________________________________________________________________________*/
		if (action == "B" || action == "b") {  //if buy
			//validate the order
			cin >> targetstock >> number_of_shares; //read the target stocks and the number of shares that the user is wanting to buy
			int shares_checker = main_integer_checker(number_of_shares);
			if (shares_checker != -1) { //excute if the player enters an interger as the number_of_shares
				validation = order_is_valid(account, action, targetstock, shares_checker);
				//If no error
				//  execute the order
				if (validation == 0) {
					execute_order(account, action, targetstock, shares_checker);
					display_stock_prices(account);
				}
				//Error code 1: not enough cash to buy
				else if (validation == 1)
					cout << "You don't have sufficient cash to buy!" << "\n\n";
				//Error code 3: wrong stock code
				else if (validation == 3)
					cout << "You have entered a wrong stock code!" << "\n\n";
			}
			else {
				cout << "Please enter an interger for the number of shares you would like to buy" << endl;
				cout << endl;
			}
		}
/*________________________________________________________________________________________________________________________________________________*/
		else if (action == "S" || action == "s") {  //if sell
			cin >> targetstock >> number_of_shares; //read the target stocks and the number of shares that the user is wanting to buy
			int shares_checker = main_integer_checker(number_of_shares);
			if (shares_checker != -1) { //excute if the player enters an interger as the number_of_shares
			//validate the order
				validation = order_is_valid(account, action, targetstock, shares_checker);

				//If no error
				//  execute the order
				if (validation == 0) {
					execute_order(account, action, targetstock, shares_checker);
					display_stock_prices(account);
				}
				//Error code 2: not enough stocks to sell
				else if (validation == 2)
					cout << "You don't have sufficient stocks to sell!" << "\n\n";
				//Error code 3: wrong stock code
				else if (validation == 3)
					cout << "You have entered a wrong stock code!" << "\n\n";
			}
			else {
				cout << "Please enter an interger for the number of shares you would like to sell" << endl;
				cout << endl;
			}
/*________________________________________________________________________________________________________________________________________________*/
		}
		else if (action == "E" || action == "e") {  //if end the current week
			cout << "End Week!" << endl;
			end_current_week(account, activeNews, existedNews);

			life_event_sick(account);  //Checking for life events
			life_event_house(account);
			life_event_car(account);
			life_event_vacation(account);
			life_event_wedding(account);
			life_event_school(account);
			life_event_salary(account);

			display_stock_prices(account);
		}
		else if (action == "Q" || action == "q") {  //if quit the game
			save_game_status(account);
			break;
		}
		else {
			cout << "Invalid action, please type in B,S,E,Q for Buy, Sell, End day and Quit. Non-case-sensitive " << endl;
			cout << endl;
		}
	}
	return 0;
}
/*________________________________________________________________________________________________________________________________________________*/

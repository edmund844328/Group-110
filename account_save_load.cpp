#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "variable_structs.h"

using namespace std;

int account_list_checker(string input_name) { //To prevent fileoverwriting during file creation
	ifstream fin;
	fin.open("account_list.txt");
	if (fin.fail()) {
		cout << "Error in account_list.txt opening on account_list_checker() function!" << endl;
		exit(1);
	}
	string temp_accout_name_container;
	while (fin >> temp_accout_name_container) {
		if (input_name == temp_accout_name_container) {
			return 0; //Return 0 if the account name exist in the account_list.txt, else 1
		}
	}
	fin.close();
	return 1;
}

void account_list(string input_name) { //Append the name of the newly created account file into an account_list
	ifstream fin;
	fin.open("account_list.txt");
	if (fin.fail()) {
		cout << "Error in account_list.txt opening !" << endl;
		exit(1);
	}
	string temp_account_name_container; //To check whether or not to add the filename into the account_list.txt or not
	bool add_or_not = true;
	while (fin >> temp_account_name_container) {
		if (input_name == temp_account_name_container) {
			add_or_not = false;
		}
	}
	if (add_or_not == true) {
		ofstream fout;
		fout.open("account_list.txt", ios::app);
		if (fout.fail()) {
			cout << "Error in account_list.txt opening !" << endl;
			exit(1);
		}
		fout << input_name << ' ';
		fout.close();
	}
	fin.close();
}

void save_game_status(portfolio account) { //Update the players date by overwriting the their _account.txt file
	string username = account.name;
	string file_name = username + "_account.txt";
	ofstream fout;
	fout.open(file_name);
	if (fout.fail()) {
		cout << "Error in name_account.txt opening during save game status !" << endl;
		exit(1);
	}
	fout << account.name << ' ' << account.day << ' ' << account.month << ' ' << account.year
		<< ' ' << account.cash << ' ' << account.portfolio_value
		<< ' ';
	for (int i = 0; i < 11; i++) {
		fout << account.price[i] << ' ';
	}
	for (int i = 0; i < 11; i++) {
		fout << account.shares[i] << ' ';
	}
	for (int i = 0; i < 11; i++) {
		fout << account.percentchange[i] << ' ';
	}
	cout << endl;
	fout.close();
}

void create_portfolio(string input_name) { //Creating a new account
	portfolio account;
	account.initialize_portfolio(); //Calling the function to initialize the portfolio
	account.name = input_name;
	string file_name = input_name + "_account.txt";
	ofstream fout;
	fout.open(file_name);
	if (fout.fail()) {
		cout << "Error in name_account.txt opening !" << endl;
		exit(1);
	}
	account_list(input_name); //Create a new file and add all data into it
	fout << account.name << ' ' << account.day << ' ' << account.month << ' ' << account.year
		<< ' ' << account.cash << ' ' << account.portfolio_value
		<< ' ';
	for (int i = 0; i < 11; i++) {
		fout << account.price[i] << ' ';
	}
	for (int i = 0; i < 11; i++) {
		fout << account.shares[i] << ' ';
	}
	for (int i = 0; i < 11; i++) {
		fout << account.percentchange[i] << ' ';
	}
	cout << endl;
	fout.close();


}

int print_check_avalible_account_list() { //Printing all the avalible account
	ifstream fin;
	fin.open("account_list.txt");
	if (fin.fail()) {
		cout << "Error in account_list.txt opening !" << endl;
		exit(1);
	}
	string empty_checker;
	fin >> empty_checker;
	if (empty_checker.length() == 0) { //To check whether the list is empty or not, return 0 if empty, else 1
		return 0;
	}
	else {
		cout << "The list of avalible accounts are :" << endl;
		cout << empty_checker << endl;
		string temp_file_name_container;
		while (fin >> temp_file_name_container) {
			cout << temp_file_name_container << endl;
		}
		return 1;
	}
	fin.close();
}

int account_access(string account_name, portfolio& return_account) { //Extract the data from the .txt file and place it into the vector
	string file_name = account_name + "_account.txt"; //Combin the make a string of file name to access
	ifstream fin;
	fin.open(file_name);
	if (fin.fail()) { //if the file does not exist, return 0
		return 0;
	}
	vector<string> loadedgames;
	string temp_profile_data_container;

	while (getline(fin, temp_profile_data_container)) { //Extract all the line from the file
		loadedgames.push_back(temp_profile_data_container); //Store all line of date into the vector
	}

	fin.close();
	portfolio account_to_be_returned;
	istringstream iss(loadedgames[0]);

	//Store all the data into the portfolio according to their type
	iss >> account_to_be_returned.name >> account_to_be_returned.day >> account_to_be_returned.month
		>> account_to_be_returned.year >> account_to_be_returned.cash
		>> account_to_be_returned.portfolio_value;
	for (int i = 0; i < 11; i++) {
		iss >> account_to_be_returned.price[i];
	}
	for (int i = 0; i < 11; i++) {
		iss >> account_to_be_returned.shares[i];
	}
	for (int i = 0; i < 11; i++) {
		iss >> account_to_be_returned.percentchange[i];
	}
	return_account = account_to_be_returned;
	return 1;
}

int delete_account(string account_name) { //For deleting an account
	string file_name = account_name + "_account.txt";
	int n = file_name.length();
	char file_name_array[100];
	strcpy(file_name_array, file_name.c_str()); //For finding the specific _account.txt file and delete it
	if (remove(file_name_array) != 0) { //If the file does not exist, return 0
		return 0;
	}
	else { //Perform if the file exist
		ifstream fin;
		fin.open("account_list.txt"); //Get the list of account name from the account_list.txt file.
		if (fin.fail()) {
			cout << "Error in account_list.txt opening on delete_account() function!" << endl;
			exit(1);
		}
		vector<string> updated_list;  //A vector storing all the account name besides the deleted one
		string temp_storer;
		string temp_line;
		getline(fin, temp_line); //Get the entire line from account_list.txt
		istringstream iss(temp_line);
		while (iss >> temp_storer) {
			if (temp_storer != account_name) {  //If the account name was the one which is deleted, it won't be added into the vector.
				updated_list.push_back(temp_storer);
				updated_list.push_back(" ");
			}
		}

		fin.close();

		ofstream fout;
		fout.open("account_list.txt"); //Rewriting the account_list.txt
		if (fout.fail()) {
			cout << "Error in account_list.txt opening on delete_account() function!" << endl;
			exit(1);
		}
		for (int i = 0; i < updated_list.size(); i++) { //Add all the items inside the vector into account_list.txt
			fout << updated_list[i];
		}
		updated_list.clear(); //Emtpy the vector to clear out memory :)
		fout.close();
	}
	return 1; //If the file was deleted, return 1 (defaut return value)
}

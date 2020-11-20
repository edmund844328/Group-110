#include <iostream>
#include <string>
#include<fstream>
using namespace std;
#include "art_call.h"


//To print game starting art by reading file
//No input needed
//The output is printing the spectific file line by line
void game_starting_art() {
	ifstream fin("starting_art.txt");
	if (fin.fail()) {
		cout << "Error in starting_art.txt opening!" << endl; // For debug
		exit(1);
	}
	string stuff_to_print;
	while (getline(fin, stuff_to_print)) {
		cout << stuff_to_print << endl;
	}
}


//To print random event art by reading file
//No input needed
//The output is printing the spectific file line by line
void life_event_house_art() {
	ifstream fin("house_art.txt");
	if (fin.fail()) {
		cout << "Error in house_art.txt opening!" << endl; // For debug
		exit(1);
	}
	string stuff_to_print;
	while (getline(fin, stuff_to_print)) {
		cout << stuff_to_print << endl;
	}
}

//To print random event art by reading file
//No input needed
//The output is printing the spectific file line by line
void life_event_car_art() {
	ifstream fin("car_art.txt");
	if (fin.fail()) {
		cout << "Error in car_art.txt opening!" << endl; // For debug
		exit(1);
	}
	string stuff_to_print;
	while (getline(fin, stuff_to_print)) {
		cout << stuff_to_print << endl;
	}
}

//To print random event art by reading file
//No input needed
//The output is printing the spectific file line by line
void life_event_vacation_art() {
	ifstream fin("vacation_art.txt");
	if (fin.fail()) {
		cout << "Error in vacation_art.txt opening!" << endl; // For debug
		exit(1);
	}
	string stuff_to_print;
	while (getline(fin, stuff_to_print)) {
		cout << stuff_to_print << endl;
	}
}

//To print random event art by reading file
//No input needed
//The output is printing the spectific file line by line
void life_event_wedding_art() {
	ifstream fin("wedding_art.txt");
	if (fin.fail()) {
		cout << "Error in wedding_art.txt opening!" << endl; // For debug
		exit(1);
	}
	string stuff_to_print;
	while (getline(fin, stuff_to_print)) {
		cout << stuff_to_print << endl;
	}
}

//To print random event art by reading file
//No input needed
//The output is printing the spectific file line by line
void life_event_sick_art() {
	ifstream fin("sick_art.txt");
	if (fin.fail()) {
		cout << "Error in sick_art.txt opening!" << endl; // For debug
		exit(1);
	}
	string stuff_to_print;
	while (getline(fin, stuff_to_print)) {
		cout << stuff_to_print << endl;
	}
}

//To print random event art by reading file
//No input needed
//The output is printing the spectific file line by line
void life_event_school_art() {
	ifstream fin("school_art.txt");
	if (fin.fail()) {
		cout << "Error in sick_art.txt opening!" << endl; // For debug
		exit(1);
	}
	string stuff_to_print;
	while (getline(fin, stuff_to_print)) {
		cout << stuff_to_print << endl;
	}
}

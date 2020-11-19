#include <iostream>
#include <string>
#include<fstream>
using namespace std;
#include "art_call.h"

void game_starting_art() { //Print game starting art by reading file
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

void life_event_house_art() { //Print random event art by reading file
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

void life_event_car_art() { //Print random event art by reading file
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

void life_event_vacation_art() { //Print random event art by reading file
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

void life_event_wedding_art() { //Print random event art by reading file
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

void life_event_sick_art() { //Print random event art by reading file
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

void life_event_school_art() { //Print random event art by reading file
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
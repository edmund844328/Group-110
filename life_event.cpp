#include <iostream>
#include <cstdlib>
#include <ctime>
#include "art_call.h"
#include "variable_structs.h"
using namespace std;



//To decide whether or not a life event will be triggered
//The input is the variable portfolio, players account which is passed from main()
//There is a probability of 0.025 that the event will be triggered
//If the event is triggered, the player's cash balance will be modified
void life_event_sick(portfolio& account) { //If the player fail to pay the medical bills by using up all cash, the program ends without saving.
	int chance = rand() % 40 + 1; // P(X=x) = 0.025 (random event)
	if ((account.day == 19  &&account.month == 2 && account.year == 2021)|| chance == 20) { // 19/2/2021 test point to see if the player use up all cash
		cout << "Unfortunately, you have to stay in hospital for observation due to chronic diseases, after insurance you have to pay $500" << endl;
		life_event_sick_art();
		if (account.cash >= 500) {
			account.cash -= 500;
		}
		else {
			cout << "Gameover... you no do have enough cash for medicine, please start again from 1/1/2021 and better manage your assets" << endl;
			exit(1);
		}
	}
}



//To decide whether or not a life event will be triggered
//The input is the variable portfolio, players account which is passed from main()
//If the player have enough cash for this life event on a specific day, the event will be triggered
//If the event is triggered, the player's cash balance will be modified
void life_event_school(portfolio& account) { //set event
	if (account.day == 12 && account.month == 3 && account.year == 2021 && account.cash >= 500) {
		cout << "Congratulations, You have attended Harvard University for your Master degree for $500" << endl;
		life_event_school_art();
		account.cash -= 500;
	}
}

//To decide whether or not a life event will be triggered
//The input is the variable portfolio, players account which is passed from main
//If the player have enough cash for this life event on a specific day, the event will be triggered
//If the event is triggered, the player's cash balance will be modified
void life_event_house(portfolio& account) { //set event
	if (account.day == 2 && account.month == 7 && account.year == 2021 && account.cash >= 2000) {
		cout << "Good work, you have successfully bought your first house for $2000 (^v^)" << endl;
		life_event_house_art();
		account.cash -= 2000;
	}
}



//To decide whether or not a life event will be triggered
//The input is the variable portfolio, players account which is passed from main()
//There is a probability of 0.016 that the event will be triggered
//If the event is triggered, the player's cash balance will be modified
void life_event_car(portfolio& account) {
	int chance = rand() % 60 + 1; // P(X=x) = 0.016 (random event)
	if (((account.day == 17 && account.month == 9 && account.year == 2021) || chance == 30) && account.cash >= 1000) {
		cout << "Congratulations, you got a new car for $800 (^U^)" << endl;
		life_event_car_art();
		account.cash -= 800;
	}
}



//To decide whether or not a life event will be triggered
//The input is the variable portfolio, players account which is passed from main()
//There is a probability of 0.004 that the event will be triggered
//If the event is triggered, the player's cash balance will be modified
void life_event_vacation(portfolio& account) { //random event
	int chance = rand() % 25 + 1; // P(X=x) = 0.04
	if (chance == 10 && account.cash >= 100) {
		cout << "After a long period of grinding, it is time for a short vacation ! (^_^) -$100" << endl;
		life_event_vacation_art();
		account.cash -= 100;
	}
}


//To decide whether or not a life event will be triggered
//The input is the variable portfolio, players account which is passed from main
//If the player have enough cash for this life event on a specific day, the event will be triggered
//If the event is triggered, the player's cash balance will be modified
void life_event_wedding(portfolio& account) {
	if (account.day == 24 && account.month == 12 && account.year == 2021 && account.cash >= 1000) {
		cout << "Congratulations, you are married on Christmas eve  (\\.^A^./ ) ~~ -$1000" << endl;
		life_event_wedding_art();
		account.cash -= 1000;
	}
}


//To decide whether or not a life event will be triggered
//The input is the variable portfolio, players account which is passed from main
//In last week of every month, the event will be triggered
//If the event is triggered, the player's cash balance will be modified
void life_event_salary(portfolio&account) {
	if (account.day >= 24 && account.day < 31) {
		cout<<endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		cout << "$$$ Finally, your monthly salary + $1000!!!\n";
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
		account.cash += 1000;
	}
}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//A function to fix a bug that when the input in main() is not {0,1,2,3}, the while loop will continue forever
//The input is a string that is passed from main
//The output is the input itself if the input met the instruction given in main(), else the ouput in 5 for telling the player to input correct command
int main_choice_vaild_checker(string input) {
	if (input == "0")
		return 0;
	if (input == "1")
		return 1;
	if (input == "2")
		return 2;
	if (input == "3")
		return 3;
	if (input =="69")
		return 69;
	else
		return 5;
}

//A function to fix a bug that when the input of the number of stocks during stock sell and buy is not an integer, the while loop will continue forever
//The input is the number of stocks that the player would like to buy or sell (string)
//The output is -1 if the input string is not an integer
//If the input string only contain integer, the output is an integer that is transformed from the input
int main_integer_checker(string number_of_shares) {
	for (int i = 0; i < number_of_shares.length(); i++) { //Check if every character in the string is an integer
		if (isdigit(number_of_shares[i]) == false)
			return -1;
	}
	stringstream iss(number_of_shares);
	int output = 0;
	iss >> output;
	return output;
}

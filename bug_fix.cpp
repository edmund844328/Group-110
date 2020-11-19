#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main_choice_vaild_checker(string input) { //function to fix bug
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

int main_integer_checker(string number_of_shares) {
	for (int i = 0; i < number_of_shares.length(); i++) {
		if (isdigit(number_of_shares[i]) == false)
			return -1;
	}
	stringstream iss(number_of_shares);
	int output = 0;
	iss >> output;
	return output;
}

//bug-to-fix:
//when user input (xx fb 10) -> loop 3 times

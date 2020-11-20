#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <map>
#include <algorithm>
#include <iomanip>
#include "variable_structs.h"
using namespace std;

map<string, int> stock_to_index;
map<int, string> index_to_stock;
//bi-directional index-stock mapping
//Each stock is assigned with an integer
//this is for easier programming at later stages
void stock_index_mapping() {
	stock_to_index["FB"] = 0;
	stock_to_index["TSLA"] = 1;
	stock_to_index["AMZN"] = 2;
	stock_to_index["GOOG"] = 3;
	stock_to_index["AAPL"] = 4;
	stock_to_index["0700"] = 5; //Tencent
	stock_to_index["0388"] = 6; //HKEX
	stock_to_index["9988"] = 7; //Alibaba
	stock_to_index["0005"] = 8; //HSBC Holdings plc
	stock_to_index["EUR"] = 9; //Forex Pair
	stock_to_index["GBP"] = 10; //Forex Pair
//__________________________________________________________//
	index_to_stock[0] = "FB";
	index_to_stock[1] = "TSLA";
	index_to_stock[2] = "AMZN";
	index_to_stock[3] = "GOOG";
	index_to_stock[4] = "AAPL";
	index_to_stock[5] = "0700"; //Tencent
	index_to_stock[6] = "0388"; //HKEX
	index_to_stock[7] = "9988"; //Alibaba
	index_to_stock[8] = "0005"; //HSBC Holdings plc
	index_to_stock[9] = "EUR"; //Forex Pair (USD to EUR)
	index_to_stock[10] = "GBP";//Forex Pair (USD to GBP)
}

map<int, double> default_mean;
map<int, double> default_sd;
//getting the mean and SD of different stocks.
//from 0-10, representing the 11 different stocks
void stock_mean_sd() {
	//FB
	default_mean[0] = 0.01;
	default_sd[0] = 0.05;
	//TSLA
	default_mean[1] = -0.01;
	default_sd[1] = 0.08;
	//AMZN
	default_mean[2] = 0;
	default_sd[2] = 0.03;
	//GOOG
	default_mean[3] = 0.01;
	default_sd[3] = 0.02;
	//AAPL
	default_mean[4] = 0;
	default_sd[4] = 0.02;
	//0700 TENCENT
	default_mean[5] = 0.02;
	default_sd[5] = 0.03;
	//0388	HKEX
	default_mean[6] = -0.01;
	default_sd[6] = 0.02;
	//9988 ALIBABA
	default_mean[7] = 0.01;
	default_sd[7] = 0.01;
	//0005 HSBC
	default_mean[8] = -0.01;
	default_sd[8] = 0.01;
	//EUR
	default_mean[9] = 0.001;
	default_sd[9] = 0.02;
	//GBP
	default_mean[10] = 0.001;
	default_sd[10] = 0.02;
}

//News that would affect stock prices
financial_news news[15];
//get the news that would affect the SD and mean
//override_mean is the new mean that would be used for
//the next iteration of stock prices
void load_financial_news()
{
	news[0].message = "US government is planning on loosening its regulations on tech companies, in response to the lobbying 3 months ago.";
	news[0].affected_stocks.push_back(0);
	news[0].affected_stocks.push_back(2);
	news[0].affected_stocks.push_back(3);
	news[0].affected_stocks.push_back(4);
	news[0].override_mean = 0.07;
	news[0].override_sd = 0.03;

	news[1].message = "US government is planning on tightening its regulations on tech companies, as security concerns heating up.";
	news[1].affected_stocks.push_back(0);
	news[1].affected_stocks.push_back(2);
	news[1].affected_stocks.push_back(3);
	news[1].affected_stocks.push_back(4);
	news[1].override_mean = -0.07;
	news[1].override_sd = 0.03;

	news[2].message = "Apple(AAPL) is planning on increasing its production capacity by signing a 10-year contract with semi-conductor producers.";
	news[2].affected_stocks.push_back(4);
	news[2].override_mean = 0.1;
	news[2].override_sd = 0.04;

	news[3].message = "A better-than-expected economic growth in China fosters the growth of its tech companies.";
	news[3].affected_stocks.push_back(5);
	news[3].affected_stocks.push_back(7);
	news[3].override_mean = 0.1;
	news[3].override_sd = 0.02;

	news[4].message = "A recent production flaw is found in Tesla(TSLA)'s electric cars after a fatal car crash in New York. The company is issuing a global re-call of the product.";
	news[4].affected_stocks.push_back(1);
	news[4].override_mean = -0.2;
	news[4].override_sd = 0.05;

	news[5].message = "HKEX(0388) reports an increase in its annual total listings, driven by stocks in mainland.";
	news[5].affected_stocks.push_back(6);
	news[5].override_mean = 0.05;
	news[5].override_sd = 0.02;

	news[6].message = "Investor giant Softbank is dumping Alibaba(9988)'s stocks recently to cash out. Market speculates that softbank is seeking for more lucrative investments.";
	news[6].affected_stocks.push_back(7);
	news[6].override_mean = -0.06;
	news[6].override_sd = 0.02;

	news[7].message = "German Chancellor Angela Merkel is not going to run for her next term. Uncertainty arises within the EU.";
	news[7].affected_stocks.push_back(9);
	news[7].override_mean = -0.04;
	news[7].override_sd = 0.01;

	news[8].message = "British PM Boris Johnson tested positive for COVID-19.";
	news[8].affected_stocks.push_back(10);
	news[8].override_mean = -0.04;
	news[8].override_sd = 0.01;

	news[9].message = "Alphabet(GOOG) is acquiring a biotech company to expand its business footprint.";
	news[9].affected_stocks.push_back(3);
	news[9].override_mean = 0.05;
	news[9].override_sd = 0.02;

	news[10].message = "Hong Kong is granting another virtual bank license to ABB Bank. Competition is set to increase in the sector.";
	news[10].affected_stocks.push_back(8);
	news[10].override_mean = -0.02;
	news[10].override_sd = 0.01;

	news[11].message = "HSBC(0005) is delaying its dividend by 6 months due to inadequate liquidity.";
	news[11].affected_stocks.push_back(8);
	news[11].override_mean = -0.08;
	news[11].override_sd = 0.01;

	news[12].message = "The EU and the UK have reached the final trade deal, clearing all uncertainties in the European continent.";
	news[12].affected_stocks.push_back(9);
	news[12].affected_stocks.push_back(10);
	news[12].override_mean = 0.05;
	news[12].override_sd = 0.01;

	news[13].message = "The US supreme court ruled that Facebook(FB) had breached the anti-trust law and has to pay $1 billion in fines.";
	news[13].affected_stocks.push_back(0);
	news[13].override_mean = -0.1;
	news[13].override_sd = 0.01;

	news[14].message = "Investment banks upgraded the target price of Tesla(TSLA).";
	news[14].affected_stocks.push_back(1);
	news[14].override_mean = 0.8;
	news[14].override_sd = 0.02;
}

//Randomize the events to be drawn
//-1 indicates no news: with 50% chance occuring
int draw_financial_news(bool appearedNews[])
{
	int random_number = 0;

	mt19937 rng(random_device{}());
	uniform_int_distribution<int> gen(0, 99);
	random_number = gen(rng);
	if (random_number >= 70)
	{
		return -1;
	}
	else
	{
		uniform_int_distribution<int> gen(0, 14);
		random_number = gen(rng);
		if (appearedNews[random_number] == false)
		{
			appearedNews[random_number] = true;
			return random_number;
		}
		return -1;
	}
}

//Check whether a order is valid by inputing the action details
//as well as current account status
//return an integer that represent different clearence/error
//0: No error
//1: Not enough cash to buy
//2: Not enough stocks to sell
//3: Wrong stock code
int order_is_valid(portfolio account, string action, string targetstock, int number_of_shares) {

	//Change User inputs to Capital Letters
	transform(targetstock.begin(), targetstock.end(), targetstock.begin(), ::toupper);

	//if the stock code entered by the user is Invalid
	//  return 3
	if (stock_to_index.find(targetstock) == stock_to_index.end())
		return 3;

	//If it is a buy action
	//  Check to see if there is enough cash to buy the stocks
	//  return 1 if there is not enough cash
	if (action == "B" || action == "b")
	{
		if (account.cash < account.price[stock_to_index[targetstock]] * number_of_shares)
			return 1;
	}

	//If it is a sell action
	//  Check to see if there is enough stocks to be sold
	//  return 2 if there is not enough stocks
	else if (action == "S" || action == "s")
	{
		if (account.shares[stock_to_index[targetstock]] < number_of_shares)
			return 2;
	}

	//if nothing is wrong, return 0
	return 0;
}

//To execute an order by changing the account and obtaining actions
//of the order
//output a message to indicate the success of buying/selling
void execute_order(portfolio& account, string action, string targetstock, int number_of_shares) {
	//Change User inputs to Capital Letters
	transform(targetstock.begin(), targetstock.end(), targetstock.begin(), ::toupper);

	//If it is a buy action
	if (action == "B" || action == "b") {
		//perform stock buying by deducting the cash and adding stocks to the target stock
		account.cash -= account.price[stock_to_index[targetstock]] * number_of_shares;
		account.shares[stock_to_index[targetstock]] += number_of_shares;
		cout << "Executed: BUY " << number_of_shares << " shares of " << targetstock << " @ $" << account.price[stock_to_index[targetstock]] << endl;
	}
	//If it is a sell action
	else if (action == "S" || action == "s") {
		//perform stock selling by adding the cash and deducting stocks to the target stock
		account.shares[stock_to_index[targetstock]] -= number_of_shares;
		account.cash += account.price[stock_to_index[targetstock]] * number_of_shares;
		cout << "Executed: SELL " << number_of_shares << " shares of " << targetstock << " @ $" << account.price[stock_to_index[targetstock]] << endl;
	}
}


//To end the current week:
//Inputs: the account, the news that is currently hoisting, the news that have been shown
//1. To update stock prices
//	If the news from the previous week affect the stock
//	The stock will be randomized by the override mean and SD
//	Otherwise it will be randomized by the default parameters
//2. To draw another news for the next week
//3. To progress the date by 7 days
void end_current_week(portfolio& account, int& activeNews, bool appearedNews[])
{
	//To update the stock prices
	//And update the Portfolio value

	default_random_engine generator(random_device{}());
	account.portfolio_value = account.cash;
	//if there is no news
	if (activeNews == -1)
	{
		for (int i = 0; i < 11; i++)
		{
			//fitting the default mean into the distribution generator
			normal_distribution<double> distribution(default_mean[i], default_sd[i]);
			account.percentchange[i] = distribution(generator);
			account.price[i] = account.price[i] * (1 + account.percentchange[i]);
			account.portfolio_value += account.price[i] * account.shares[i];
		}
	}

	//if there is a news
	else
	{
		for (int i = 0; i < 11; i++)
		{
			//if the stock is affected by the news
			if (find(news[activeNews].affected_stocks.begin(), news[activeNews].affected_stocks.end(), i) != news[activeNews].affected_stocks.end())
			{
				normal_distribution<double> distribution(news[activeNews].override_mean, news[activeNews].override_sd);
				account.percentchange[i] = distribution(generator);
			}
			//if the stock is NOT affected by the news
			else
			{
				normal_distribution<double> distribution(default_mean[i], default_sd[i]);
				account.percentchange[i] = distribution(generator);
			}
			account.price[i] = account.price[i] * (1 + account.percentchange[i]);
			account.portfolio_value += account.price[i] * account.shares[i];
		}
	}

	//draw another news for the next week
	activeNews = draw_financial_news(appearedNews);
	if (activeNews != -1)
		cout << "BREAKING NEWS!!!:  " << news[activeNews].message << "\n";


	//To update the date of the profile, add 7 days to the days
	account.day += 7;
	//If the current month contains 31 days
	//  Check if the days exceed 31
	//    Month add one and days subtracted 31 if that is the case
	if (account.month == 1 || account.month == 3 || account.month == 5 || account.month == 7 || account.month == 8 || account.month == 10 || account.month == 12)
	{
		if (account.day > 31)
		{
			account.month++;
			account.day -= 31;
		}
	}
	//If the current month contains 30 days
	//  Check if the days exceed 30
	//  Month add one and days subtracted 30 if that is the case
	else if (account.month == 4 || account.month == 6 || account.month == 9 || account.month == 11)
	{
		if (account.day > 30)
		{
			account.month++;
			account.day -= 30;
		}
	}
	//If the current month is Feb
	else if (account.month == 2)
	{
		//If current year is a leap year
		//  Check if the days exceed 29
		//    Month add one and days subtracted 29 if that is the case
		if (account.year % 400 == 0 || (account.year % 4 == 0 && account.year % 100 != 0))
		{
			if (account.day > 29)
			{
				account.month++;
				account.day -= 29;
			}
		}
		//If current year is NOT a leap year
		//  Check if the days exceed 28
		//    Month add one and days subtracted 28 if that is the case
		else
		{
			if (account.day > 28)
			{
				account.month++;
				account.day -= 28;
			}
		}
	}

	//If month exceeds 12
	//  Go to next year and reset month to Jan
	if (account.month > 12)
	{
		account.year++;
		account.month = 1;
	}

}

//convert a double precision number into a string
//For instance, input = (23.12345,3)
//Output = string of 23.123
string double_to_string(double number, int precision) {

	stringstream stream;
	stream << fixed << setprecision(precision) << number;
	return (stream.str());
}

//Function to limit the output length of a string
//For instance, input = ("23.123",9)
//Output = string of "  23.123  ", in total there would be 9 characters in this string
//with the target string placed in the middle, surrounded by blanks
string fixed_length_display(string input, int totalDigitsOfOutput) {

	int stringBeginPosition;
	string temp_string = "";
	stringBeginPosition = totalDigitsOfOutput / 2 - input.length() / 2;

	for (int i = 0; i < stringBeginPosition; i++)
		temp_string = temp_string + " ";

	temp_string = temp_string + input;
	for (int i = temp_string.length(); temp_string.length() < totalDigitsOfOutput; i++)
		temp_string = temp_string + " ";

	return temp_string;
}

//Function for displaying the stock prices in a graphical manner
//requiring the account details
void display_stock_prices(portfolio account)
{
	cout << endl;
	cout << setw(50) << " " << setw(24) << " " << "Date: " << account.day << "/" << account.month << "/" << account.year << endl;
	cout << setw(50) << " " << "     Stock name     " << "          Price   " << "             Amount" << "      %-Change" << endl;
	cout << setw(50) << " " << "--------------------------------------------------------------------------" << endl;
	cout << setw(50) << " " << "|   " << "NASDAQ: FB " << "    |" << fixed_length_display("$  " + double_to_string(account.price[0], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[0], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[0] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << "NASDAQ: TSLA" << "   |" << fixed_length_display("$  " + double_to_string(account.price[1], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[1], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[1] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << "NASDAQ: AMZN" << "   |" << fixed_length_display("$  " + double_to_string(account.price[2], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[2], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[2] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << "NASDAQ: GOOG" << "   |" << fixed_length_display("$  " + double_to_string(account.price[3], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[3], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[3] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << "NASDAQ: AAPL" << "   |" << fixed_length_display("$  " + double_to_string(account.price[4], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[4], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[4] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << " HKG:   0700" << "   |" << fixed_length_display("$  " + double_to_string(account.price[5], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[5], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[5] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << " HKG:   0388" << "   |" << fixed_length_display("$  " + double_to_string(account.price[6], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[6], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[6] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << " HKG:   9988" << "   |" << fixed_length_display("$  " + double_to_string(account.price[7], 2), 25) << "|" << fixed_length_display(double_to_string(account.shares[7], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[7] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << " HKG:   0005" << "   |" << fixed_length_display("$  " + double_to_string(account.price[8], 3), 25) << "|" << fixed_length_display(double_to_string(account.shares[8], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[8] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << "     EUR    " << "   |" << fixed_length_display("$  " + double_to_string(account.price[9], 3), 25) << "|" << fixed_length_display(double_to_string(account.shares[9], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[9] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "|   " << "     GBP    " << "   |" << fixed_length_display("$  " + double_to_string(account.price[10], 3), 25) << "|" << fixed_length_display(double_to_string(account.shares[10], 0), 15) << "|" << fixed_length_display(double_to_string(account.percentchange[10] * 100, 3) + "%", 11) << "|" << endl;
	cout << setw(50) << " " << "--------------------------------------------------------------------------" << endl;
	cout << setw(50) << " " << " Cash Balance: $  " << account.cash << setw(10)<<" "<< "Portfolio Value: $  " << account.portfolio_value << "\n\n";
}

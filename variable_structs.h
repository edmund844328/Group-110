// variable_structs.h
#ifndef VARIABLE_STRUCTS_H
#define VARIABLE_STRUCTS_H
#include <string>
#include <vector>
//A struct to contain all the necessary information for a player
//Name, current stock prices, holdings, cash and time
struct portfolio {
	std::string name;
	int day, month, year;
	double cash, portfolio_value;
	double price[11];
	int shares[11];
	double percentchange[11];
	void initialize_portfolio() {
		cash = 10000; //USD
		year = 2021;
		month = 1;
		day = 1;
		portfolio_value = 0;
		for (int i = 0; i < 11; i++) {
			shares[i] = 0;
			percentchange[i] = 0;
		}
	//___________US-Stock________//
		price[0] = 276.95;  //FB
		price[1] = 408.50;  //TSLA	  drop dramatically
		price[2] = 3128.81; //AMZN	  raise
		price[3] = 1772.26; //GOOGL
		price[4] = 119.26;  //APPL
	//___________HK-Stock________//
		price[5] = 77.64;  //Tencent  raise
		price[6] = 47.89;  //HKEX	  raise
		price[7] = 33.15;  //Alibaba  raise
		price[8] = 4.80;   //HSBC Holdings plc   drop
	//__________Forex-Pairs______//
		price[9] = 0.84;   //USD to EUR
		price[10] = 0.76;  //USD to GBP
	}
};

struct financial_news
{
	std::string message;
	std::vector<int> affected_stocks;
	double override_mean;
	double override_sd;
};


#endif
// stock_and_news.h
#ifndef STOCK_AND_NEWS_H
#define STOCK_AND_NEWS_H

#include <string>
#include "variable_structs.h"

void stock_index_mapping();
void stock_mean_sd();
void load_financial_news();
int draw_financial_news(bool appearedNews[]);
int order_is_valid(portfolio account, std::string action, std::string targetstock, int number_of_shares);
void execute_order(portfolio& account, std::string action, std::string targetstock, int number_of_shares);
void end_current_week(portfolio& account, int& activeNews, bool appearedNews[]);
std::string double_to_string(double number, int precision);
std::string fixed_length_display(std::string input, int totalDigitsOfOutput);
void display_stock_prices(portfolio account);

#endif
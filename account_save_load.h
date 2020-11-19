// account_save_load.h
#ifndef ACCOUNT_SAVE_LOAD_H
#define ACCOUNT_SAVE_LOAD_H
#include <string>

void account_list(std::string file_name);
void create_portfolio(std::string input_name);
int print_check_avalible_account_list();
int account_access(std::string account_name, portfolio& return_account);
void save_game_status(portfolio user);
int delete_account(std::string account_name);
int account_list_checker(std::string input_name);

#endif

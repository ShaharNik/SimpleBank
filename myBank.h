
#ifndef _MY_BANK_H
#define _MY_BANK_H

#define bankAccounts 50           // Number of banks
#define statusAndAmount 2     // open / close and amount

extern double bank_accounts[statusAndAmount][bankAccounts];

void Create_new_account(double amount);

void Account_information(int account_number);

void Cash_Deposit(int account_number, double amount);

void Cash_Withdrawl(int account_number, double amount);

void Close_Account(int account_number);

void Add_interest();

void Display_all_available_accounts();

void Delete_all_and_close();

void display_options();

double round2(double amount);

#endif
#include "myBank.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

	double bank_accounts[2][50];
	double round2(double amount)
	{
		double nearest = (int)(amount * 100);
		return nearest / 100;
	}
void Create_new_account(double amount)
{
	bool account_created = false;
	int acc_num;
	for(int i=1; i <= 50; i++)
    {
        if (bank_accounts[0][i] == 0) // if closed bank founded
        {
            bank_accounts[0][i] = i + 900; // Open the bank
			bank_accounts[1][i] = amount; //Init amount
			acc_num = i + 900;
			account_created = true;
			break;
        }
    
	}
	if (!account_created)
		printf("There is No empty bank avialble..\n");
	else
		printf("Account Number: %d created succesfully !\n",acc_num);
}
void Account_information(int account_number)
{
	bool account_founded = false;
	for(int i=1; i <= 50; i++)
	{
		if (bank_accounts[0][i] == account_number)
		{
			printf("The account number: %d have balance of: %.2lf\n",account_number,bank_accounts[1][i]);
			account_founded = true;
			break;
		}
	}
	if(!account_founded)
	{
		printf("THE ACCOUNT %d DOESN'T EXIST IN THE BANK !\n",account_number);
	}
}
void Cash_Deposit(int account_number, double amount)
{
	bool account_founded = false;
	for(int i=1; i <= 50; i++)
	{
		if (bank_accounts[0][i] == account_number)
		{
			bank_accounts[1][i] += amount;
			printf("The account number: %d have new balance of: %.2lf\n",account_number,bank_accounts[1][i]);
			i = 50; // end loop
			account_founded = true;
		}
	}
	if(!account_founded)
	{
		printf("THE ACCOUNT %d DOESN'T EXIST IN THE BANK !\n",account_number);
	}
}
void Cash_Withdrawl(int account_number, double amount)
{
	bool account_founded = false;
	for(int i=1; i <= 50; i++)
	{
		if (bank_accounts[0][i] == account_number)
		{
			account_founded = true;
			if (bank_accounts[1][i] >= amount)
			{
				bank_accounts[1][i] -= amount;
				printf("The account number: %d have new balance of: %.2lf\n",account_number, bank_accounts[1][i]);
				break;
			}
			else
			{
				printf("The account number: %d Doesn't have enough balance to withdraw \n",account_number);
				break;
			}
		}
	}
	if(!account_founded)
	{
		printf("THE ACCOUNT %d DOESN'T EXIST IN THE BANK !\n",account_number);
	}
}
void Close_Account(int account_number)
{
	bool account_founded = false;
	for(int i=1; i <= 50; i++)
	{
		if (bank_accounts[0][i] == account_number)
		{
			bank_accounts[1][i] = 0;
			bank_accounts[0][i] = 0;
			account_founded = true;
			printf("The account number: %d has CLOSED!\n",account_number);
		}
	}
	if(!account_founded)
	{
		printf("THE ACCOUNT %d DOESN'T EXIST IN THE BANK !\n",account_number);
	}
}
void Add_interest(double interest_rate)
{
	if (interest_rate < 0)
	{
		printf("Negative precent is not allowed!\n");
	}
	else
	{
		for(int i=1; i <= 50; i++)
		{
			if (bank_accounts[0][i] != 0)
			{
				bank_accounts[1][i] = bank_accounts[1][i] + ((interest_rate/100)*bank_accounts[1][i]);
			}
		}
		printf("Interest rate have been added to open accounts succesfully !\n");
	}
		
}
void Display_all_available_accounts()
{
	bool emptyBank = true;
	for(int i=1; i <= 50; i++)
	{
		if (bank_accounts[0][i] != 0)
		{
			printf("Account number: %d  Balance: %.2lf\n",(int)bank_accounts[0][i], bank_accounts[1][i]);
			emptyBank = false;
		}
	}
	if (emptyBank)
	{
		printf("There are not open accounts in the bank\n");
	}
}
void Delete_all_and_close()
{
	for(int i=1; i <= 50; i++)
    {
    	bank_accounts[0][i] = 0; // Close the bank account
		bank_accounts[1][i] = 0; //Init amount to zero

	}
}

void display_options()
{
	printf("\nO Create new account \n");
	printf("B Account information \n");
	printf("D Cash Deposit \n");
	printf("W Cash withdrawl \n"); // get money
	printf("C Close Account \n");
	printf("I Add interest \n"); // ribit
	printf("P Display all available accounts \n");
	printf("E Delete all and close \n");
}




#include "myBank.h"
#include <stdio.h>

double getAmount()
{
	double amount;
	printf("Amount?\n");
	if (scanf("%lf", &amount) == 1 && amount >= 0)
	{
		//while (getchar() != '\n'){}
		return amount;
	}
	else 
	{
		printf("Enter positive numeric amount please\n");
		return -1;
	}
}
double getAccountNumber()
{
	int account_number;
	printf("Account number?\n");
	if (scanf("%d", &account_number) == 1 && account_number >= 901 && account_number <= 950)
	{
		//while (getchar() != '\n'){}
		return account_number;
		
	}	
	else
	{
		printf("Bad Account number!\n");
		return -1;
	}
		
}
double getInterestRate()
{
	double interest_rate;
	printf("Interest rate?\n");
	if (scanf("%lf", &interest_rate) != 1)
	{
		//while (getchar() != '\n'){}
		printf("Bad Interest rate!\n");
	}
	return interest_rate;
}

int main()
{
	display_options();
	int close = 1;

	while (close != 0) // != E
	{
		char option;
		int account_number;
		double amount;
		double interest_rate;

		printf("Transaction type?\n");
		while (scanf(" %c", &option) != 1)
		{
			//while (getchar() != '\n'){}
			printf("Enter Option Please: (O/B/D/W/C/I/P/E)");
		}

		switch (option)
		{
			case 'O': // Make new account
				amount = getAmount();
				if (amount != -1)
					Create_new_account(round2(amount));
				break;
			case 'B': // check itra
				account_number = getAccountNumber();
				if (account_number != -1)
					Account_information(account_number);
				break;
			case 'D': // hafked kesef
				account_number = getAccountNumber();
				amount = getAmount();
				if (account_number != -1 && amount != -1)
					Cash_Deposit(account_number, round2(amount));
				break;
			case 'W': // take money
				account_number = getAccountNumber();
				amount = getAmount();
				if (account_number != -1 && amount != -1)
					Cash_Withdrawl(account_number, round2(amount));
				break;
			case 'C': // close account
				account_number = getAccountNumber();
				if (account_number != -1)
					Close_Account(account_number);
				break;
			case 'I': 
				interest_rate = getInterestRate();
				Add_interest(interest_rate); //ribit
				break;
			case 'P': Display_all_available_accounts();
				break;
			case 'E': 
				Delete_all_and_close();
				close = 0; // end while
				break;
			default: 
				//while(getchar() != '\n'){}
				printf("Please enter one of the options ");
				printf("(O/B/D/W/C/I/P/E) to continue \n ");
				break;
		}

	}
	return 0;
}
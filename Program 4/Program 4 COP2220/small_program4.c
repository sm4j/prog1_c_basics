/*
COP2220 Program 4
Jordan Small | September 11, 2023
This program will allow a user to simulate a purchase after selecting an item and its quanitty from a given menu.
A balance will be set and reflect an accurate change following their purchase.*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes

void Greeting(void);
//welcome the user to the food purchasing app

int DisplayFoodSelections();
//display the food choices, the price, and related item number
//declare, ask, get the item number
//return the item number

double SetPrice(int itemNumber);
//input: item number
//use the item number to identify the price
//return the price

double AddQuantityToOrder(double price);
//input: price of the item
//declare ask and get the quantity
//calculate and return the item total
//return the total

double Checkout(double balance, double totalPrice);
//input: amount of money in the account and the order total
//return: the amount left in the account after making the purchase
//Uses the Reload and checkFor Enough functions
//to get money from the user until the user has enough to make the purchase
//make the purchase and return the remaining balance

int CheckForEnough(double balance, double totalPrice);
//THIS FUNCTION WILL BE CALLED FROM THE Checkout function
//input: amount of money in the account and the order total
//returns a 1 if there is enough in the account to make a purchase
//returns 0 if there is not enough

double Reload(double balance);
//THIS FUNCTION WILL BE CALLED FROM THE Checkout function
//input: account balance
//return the new balance with the added funds
//reload the account balance

int main()
{
	double balanceInMain = 20.00;
	double priceInMain = 0.0;
	double totalInMain = 0.0;
	int itemNumber;

	Greeting(); //greets user

	printf("\nThe current balance in your account is: $%.2f.\n", balanceInMain); //displays starting balance

	itemNumber = DisplayFoodSelections(); //updates itemNumber as the return from calling DisplayFoodSelections, displaying the menu

	printf("The item number you selected is %d.", itemNumber); //test to confirm itemNumber was updated from previous function call return

	priceInMain = SetPrice(itemNumber); //updates priceInMain as the return from SetPrice, given itemNumber as passthrough input

	printf("\nThe item's price is $%.2f.\n", priceInMain); //test to confirm priceInMain was updated from previous function call return

	totalInMain = AddQuantityToOrder(priceInMain); //updates totalInMain based on quantity input from AddQuantityToOrder

	printf("\n--------------------------------------------------\n");

	printf("\nYour total is $%.2f and your balance is $%.2lf", totalInMain, balanceInMain); //displays updated total versus current balance

	balanceInMain = Checkout(balanceInMain, totalInMain); //update balance based on Checkout function, provided previous balance was enough to cover total

	printf("\nYour updated balance after purrchasing is $%.2f.\n", balanceInMain); //prints updated balance after Checkout

	printf("\n--------------------------------------------------\n");

	printf("\nEnjoy your food and the rest of your day. Goodbye!\n");

	return 0;
}

void Greeting(void)
{
	//greet the user and explain the upcoming program prompts
	printf("Greetings! Welcome to the food purchasing app!\nYou will be presented with a list of items and your account balance.");
	printf("\nPlease select the number for the item you wish to purchase, followed by a quantity when prompted.");
	printf("\nAt checkout, if you do not have sufficient funds to cover the purchase, you will be asked to add money into your account until you have entered enough money to do so.\n");

}

int DisplayFoodSelections()
{
	//declare return variable, itemNumber
	int itemNumber;

	//display menu options with affiliated item number
	printf("\n--------------------------------------------------\n");
	printf("\nBelow is the current menu and available food items:\n");
	printf("\n1. The Box Combo.............$11.39\n");
	printf("2. The Caniac Combo..........$16.35\n");
	printf("3. The 3 Finger Combo.........$9.79\n");
	printf("4. The Sandwich Combo.........$9.99\n");
	printf("5. The Kids Combo.............$6.49\n");
	printf("6. Drink Only.................$2.99\n");
	printf("7. Sandwich Only..............$7.99\n");
	printf("\n--------------------------------------------------\n");

	//prompt user to select item number
	printf("\nPlease enter your selection (1-7): ");
	scanf("%d", &itemNumber);

	//returns itemNumber
	return itemNumber;

}

double SetPrice(int itemNumber)
{
	//declare price variable and set temp value of 0
	double price = 0.0;

	//affiliate menu item numbers with their respective prices and update price variable based on selection
	switch(itemNumber)
	{

		case 1:
			printf("\nYou have selected The Box Combo; the price is $11.39.\n");
			price = 11.39;
			break;

		case 2:
			printf("\nYou have selected The Caniac Combo; the price is $16.35.\n");
			price = 16.35;
			break;

		case 3:
			printf("\nYou have selected The 3 Finger Combo; the price is $9.79.\n");
			price = 9.79;
			break;

		case 4:
			printf("\nYou have selected The Sandwich Combo; the price is $9.99.\n");
			price = 9.99;
			break;

		case 5:
			printf("\nYou have selected The Kids Combo; the price is $6.49.\n");
			price = 6.49;
			break;

		case 6:
			printf("\nYou have selected a drink only; the price is $2.99.");
			price = 2.99;
			break;

		case 7:
			printf("\nYou have selected a sandwich only; the price is $7.99.");
			price = 7.99;
			break;

		default:
			printf("\nThere is no item with that number.");
			price = 0.00;

	}

	//returns price based on item selection
	return price;

}

double AddQuantityToOrder(double price)
{
	//declare quantity as a variable
	int quantity;

	//prompt for and get quantity
	printf("What quantity of this item would you like?:");
	scanf("%d", &quantity);

	//declare quantified price using quantity times input price
	double totalInMain = quantity * price;

	return totalInMain;

}

double Checkout(double balance, double totalPrice)
{
	
	int enough = CheckForEnough(balance, totalPrice);
	
	//when balance is insufficient, call for reload function
	while (enough == 0)
	{
		balance = Reload(balance);
		printf("The total is $%.2f and your balance is $%.2f.\n", totalPrice, balance);
		printf("\n--------------------------------------------------\n");
		enough = CheckForEnough(balance, totalPrice);

	}

	//returns updated balance after sufficient amount is reached
	return balance - totalPrice;

}

int CheckForEnough(double balance, double totalPrice)
{
	//compare if balance is enough to cover total given passthrough of balance and price
	if (balance >= totalPrice) {
		//returns a 1 if there is enough in the account to make a purchase
		return 1;
	}
	else {
		//returns 0 if there is not enough
		return 0;

	}
}

double Reload(double balance)
{
	//declare addAmount as a variable to add to balance when insufficient
	double addAmount;

	//prompt for and get desired deposit amount to make balance sufficient for purchase
	printf("\nYou have insufficient funds. How much money would you like to add to your account?:");
	scanf("%lf", &addAmount);

	//returns new balance with the added deposit
	return balance + addAmount;

}
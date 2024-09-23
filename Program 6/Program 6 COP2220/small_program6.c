/*
COP 2220 Program 6
Jordan Small
OCT. 17, 2023
This application has a main menu with four functions: add item, reset order, checkout, or quit.
The balance is pulled from foodAccountBalance.txt and updates after checkout, saving the value.
Adding items will update item and order totals based off of quantity and price. The user can continue to add
multiple items until selecting reset or checkout at any time. After checkout is complete, user can start a new
order or quit the program. Before quitting, the user will be alerted with a goodbye note.
*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes
void Greeting(void);
void MenuSelection(char* selectionPtr);
void OneItemOrder(double* totalPtr);
int DisplayFoodSelections();
double SetPrice(int itemNumber);
double AddQuantityToOrder(double price);
double Checkout(double balance, double totalPrice);
int CheckForEnough(double balance, double totalPrice);
double Reload(double balance);

int main() 
{
	//variable declarations
	double balanceInMain, balanceFromFile = 0.0;
	double itemTotal = 0.0, orderTotal = 0.0;
	char selection;
	FILE *inPtr, *outPtr; //file pointers

	//call the greeting function to display instructions and program functions
	Greeting();

	//open input file and read a double value, and assign value to balanceFromFile
	inPtr = fopen("foodAccountBalance.txt", "r");
	fscanf(inPtr, "%lf", &balanceFromFile);

	//set balanceInMain equal to balanceFromFile, saving the value in case user resets
	balanceInMain = balanceFromFile;

	//display starting balance
	printf("\nYour current balance is $%.2f.\n", balanceFromFile);

	//close input file
	fclose(inPtr);

	//call MenuSelection, passing it the address of selection
	MenuSelection(&selection);

	//start while loop for menuSelections != q (quit)
	while (selection != 'Q' && selection != 'q') {

		//A selection (add item)
		if (selection == 'A' || selection == 'a') {

			//call oneItemOrder function, passing it the address of itemTotal
			OneItemOrder(&itemTotal);

			printf("\n--------------------------------------------------\n");
			printf("\nThe current ITEM total is $%.2f\n", itemTotal);

			//update orderTotal by adding current itemTotal
			orderTotal = orderTotal + itemTotal;

			printf("The current ORDER total is $%.2f\n", orderTotal);
			printf("\n--------------------------------------------------\n");

		}

		//C selection (checkout)
		else if (selection == 'C' || selection == 'c') {

			//if orderTotal is less than or equal to 0, alert user that cart is empty/orderTotal is $0 
			if (orderTotal <= 0) {

				printf("\n--------------------------------------------------\n");
				printf("\nThe total is $%.2f as you have not ordered anything. Please select 'A' from the main menu to add an item.\n", orderTotal);
				printf("Your current balance remains as $%.2f.\n", balanceInMain);
				printf("\n--------------------------------------------------\n");

			}

			//if there are items in cart (orderTotal > 0), proceed to checkout
			else {

				printf("\n--------------------[Checkout]--------------------\n");
				printf("\nThe current ORDER total is $%.2f\n", orderTotal);
				printf("Before the order, the balance in your account was $%.2f\n", balanceInMain);

				//call Checkout function, and update balanceInMain to its return value, passing it balanceInMain and orderTotal
				balanceInMain = Checkout(balanceInMain, orderTotal);

				//updates balanceFromFile to updated balance after checkout so if 'n' is selected afterwards, the balance doesn't reinitialize to $20.00
				balanceFromFile = balanceInMain;

				//display updated balance after purchase
				printf("\nAfter your purchase of $%.2f, the updated balance in your account is $%.2f.\n", orderTotal, balanceInMain);

				//update orderTotal to 0 after purchase is complete (if user wants to make another order)
				orderTotal = 0.0;

				printf("Thank you for your purchase! Select 'A' if you'd like to make another order or 'Q' to quit.\n");
				printf("\n--------------------------------------------------\n");

			}

		}

		//N selection (reset order)
		else if (selection == 'N' || selection == 'n') {

			//reset orderTotal to 0 and alert user
			orderTotal = 0;
			printf("\n--------------------------------------------------\n");
			printf("\nThe order total has been reset to $%.2f.\n", orderTotal);

			//update balanceInMain to original balanceFromFile value (starting value)
			balanceInMain = balanceFromFile;
			printf("The balance has been reset to the original amount of $%.2f.\n", balanceFromFile);
			printf("\n--------------------------------------------------\n");

		}

		//any other input than menu selections
		else {

			printf("\nThis selection is not recognized.\n");

		}

		//update value for address of selection
		MenuSelection(&selection);

	}

	//update output file with double value balanceInMain
	outPtr = fopen("foodAccountBalance.txt", "w");
	fprintf(outPtr, "%.2f", balanceInMain);

	printf("Thanks for participating! Have a wonderful day!\n");

	return 0;

}

void Greeting(void)
{
	//greet the user and explain the upcoming program prompts
	printf("--------------------------------------------------\n");
	printf("\nGreetings! Welcome to the food purchasing app!\nYou will be presented with a list of items and your account balance.");
	printf("\nPlease select the number for the item you wish to purchase, followed by a quantity when prompted.");
	printf("\nAt checkout, if you do not have sufficient funds to cover the purchase:\nYou will be asked to add money into your account until you have entered enough money to do so.\n");
	printf("\n1. You will be able to add multiple items to an order if you wish.\n");
	printf("2. You can reset your order at anytime before checking out.\n");
	printf("3. When you checkout, your balance will be saved. You can continue with another order or quit the program afterwards.\n");
	printf("\n--------------------------------------------------\n");

}

void MenuSelection(char* selectionPtr) 
{
	//create temporary variable, choice
	char choice;
	

	printf("\nSelect from the following:\n");
	printf("\n'A' or 'a' to add an item to your order.\n");
	printf("'N' or 'n' to start over with a new order.\n");
	printf("'C' or 'c' to checkout.\n");
	printf("'Q' or 'q' QUIT and cancel.\n");
	printf("\nSelection: ");
	//scan for char value based on selection and assign to temp variable
	scanf(" %c", &choice);

	//update the value at selectionPtr pointer to choice value
	*selectionPtr = choice;

}

void OneItemOrder(double* totalPtr) 
{
	//declare temp variables
	double price = 0.0;
	double total = 0.0;
	int itemNumber;
	*totalPtr = 0.0;

	//call DisplayFoodSelections, using its return value to update temp itemNumber
	itemNumber = DisplayFoodSelections();

	printf("\nThe item number you selected is %d.", itemNumber);

	//update price based on return of SetPrice, passing it itemNumber
	price = SetPrice(itemNumber);

	//call AddQuantityToOrder function, passing it price, using its return to update value at totalPtr pointer
	*totalPtr = AddQuantityToOrder(price);

}

int DisplayFoodSelections()
{
	//declare return variable, itemNumber
	int itemNumber;

	//display menu options with affiliated item number
	printf("\n----------------------[Menu]----------------------\n");
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
	switch (itemNumber)
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
	printf("\nWhat quantity of this item would you like?:");
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

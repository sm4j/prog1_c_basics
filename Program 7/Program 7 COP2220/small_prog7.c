/*COP 2220 (Program 7) - Jumbled Word Game
Jordan Small, Z23465928, Nov. 20, 2022
The Jumbled Game will give a user three attemps
to guess a word that is presented as jumbled (with its length).
Each guess will be compared to the solution.
If the user guesses incorrectly on the first attempt,
the first and last letter will be presented.
When the user guesses correctly or runs out of guesses,
the solution will be shown and the user will be prompted
whether or not they want to play again.
*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf, scanf, and fscanf
#include<ctype.h> //for toupper function
#include<string.h> //for strlen and strcmp functions
#define SIZE 25 //size of the character arrays is 25

void Instructions();
//Welcome the user and display the instructions on how to play the game.
void PlayOneGame(char jumbled[], char solution[]);
//input: solution word and scrambled word
//plays one round ot the game
void PlayAgain(char* againPtr);
//input: character (input/ouptput) parameter
//determines if the player would like to play again.
void UppercaseWord(char word[]);
//input: a character array with a null character (string)
//sets all of the characters in a word to uppercase letters
void WinOrLose(int win);
//input a 1 or a 0
//tells the user they won if the input is 1 and they lost if the input is 0

int main()
{
	char again;

	//declare character arrays here
	char jumbled[SIZE] = "", solution[SIZE] = "";

	//declare character and file pointer
	FILE* inPtr;

	//connect to the input file
	inPtr = fopen("jumbledWords.txt", "r");

	//greet the user and disply the instructions
	Instructions();
	
	do {

		printf("\nReady to play a round of jumbled!\n");

		//read 2 words from the file
		fscanf(inPtr, " %s", jumbled);
		fscanf(inPtr, " %s", solution);

		//print the words to make sure they were read from the file correctly
		//printf("\njumbled is %s, correct is %s\n", jumbled, solution);
		
		//change both jumbled and solution to uppercase letters
		UppercaseWord(jumbled);
		UppercaseWord(solution);

		//printf("\njumbled is %s, correct is %s\n", jumbled, solution);

		//play a round of the game -call the PlayOneGame function
		PlayOneGame(jumbled, solution);

		//again?
		PlayAgain(&again);
	} while (again == 'Y' || again == 'y'); //test

	//say goodbye
	printf("\nThanks for playing The Jumbled Game!\n");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	//close the file pointer
	fclose(inPtr);

	//return Success (0)
	return 0;
}
void Instructions()
//Welcome the user and display the instructions on how to play the game.
{
	printf("Welcome to the BMUJLDE (JUMBLED) Game!\n");
	printf("\nYou will see the word in scrambled (jumbled) form first and then...\n");
	printf("Next you will have to guess it!\n");
	printf("If you do not guess the word on the first try,\n");
	printf("The first and last letters will be displayed\n");
	printf("\nYou will have three guesses to figure it out!\n");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void PlayOneGame(char jumbled[], char solution[])
//input: solution word and scrambled word
//plays one round ot the game
{
	//declare variables
	int win = 0;
	int length;
	int count = 1;
	char guess[SIZE];

	//get the length of the solution word
	length = strlen(solution);

	//the user gets a maximum of 3 guesses
	while (count <= 3 && win == 0)
	{
		//display the number of letters and the jumbled word
		printf("\nThe word has %d letters.\n", length);

		//get the guess
		printf("\nThe jumbled word is: %s", jumbled);
		printf("\nEnter your guess for attempt/guess #%d: ", count);
		scanf(" %s", guess);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		//change the guess to uppercase letters
		UppercaseWord(guess);

		//use strcmp to see if guess and solution match
		//stop the loop if they match (DO NOT USE A break statement to stop the loop)
		if (strcmp(solution, guess) == 0) {
			win = 1;
		}
		
		//else the user did guess correctly
		else {
			printf("\n%s was not the word.\n", guess);
			printf("That was guess number %d.\n", count);
			printf("\nThe first letter is: %c\n", solution[0]);
			printf("The last letter is: %c \n", solution[length - 1]);
		}
		//display the first and last letters
		count++;
	}
	//disply the solution
	printf("\nThe solution was: %s\n", solution);
	//tell the user if they won or lost
	WinOrLose(win);
}
void PlayAgain(char* againPtr)
//input: character (input/ouptput) parameter
//determines if the player would like to play again.
{
	printf("Would you like to play again (Y or N)?");
	scanf(" %c", againPtr);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void UppercaseWord(char word[])
//input: a character array with a null character (string)
//sets all of the characters in a word to uppercase letters
{
	//use strlen to get the length of the word
	int len = strlen(word);
	int i;
	//use a loop to change all the letters of the word to upper case (toupper)
	for (i = 0; i < len; i++) {
		word[i] = toupper(word[i]);
	}
}

void WinOrLose(int win)
//input a 1 or a 0
//tells the user they won if the input is 1 and they lost if the input is 0
{
	//let the user know if they won or lost the round
	if (win == 1) {
		printf("\nCongrats! You won the round!\n");
	}

	else if (win == 0) {
		printf("\nYou did not win this round, sorry!\n");
	}

	else {
		printf("\nNot recognized.");
	}
}
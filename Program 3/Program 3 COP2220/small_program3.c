/*
* small_program3.c
Jordan Small, September 4, 2023, Program 3: Functions
*
*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes
void Greeting(void); 
void InitialPractice(void);
void MillimetersToInches(void);
void InchestoMillimeters(void);

int main()
{
	//function calls
	Greeting();
	InitialPractice();
	MillimetersToInches();
	InchestoMillimeters();

	printf("\nThanks for participating!\n"); //program outro

	return 0;

}

//function definitions here

void Greeting(void) 
{
	//display a welcome message
	printf("Welcome to program 3!\n");
	printf("In this program, we will be using taking user-inputted values and returning outputs based on several tasks we aim to complete.\n");

}

void InitialPractice(void) 
{
	//declare, ask, and get a character
	char letter, upperVersion, lowerVersion;
	int upperNum, lowerNum;

	printf("\nPlease enter a charcter: ");
	scanf(" %c", &letter);

	//declare letter values for lowercase, uppercase, and their respective ASCII
	lowerVersion = tolower(letter);
	upperVersion = toupper(letter);
	lowerNum = (int)lowerVersion;
	upperNum = (int)upperVersion;

	//display the lowercase version of the letter(character) and the numerical (ASCII) value
	printf("\nThe lowercase version of your letter is '%c' and its numerical/ASCII value is '%d'.\n", lowerVersion, lowerNum);

	//display the uppercase version of the letter(character) and the numerical (ASCII) value
	printf("The uppercase version of your letter is '%c' and its numerical/ASCII value is '%d'.\n", upperVersion, upperNum);

}

void MillimetersToInches(void)
{
	//declare, ask and get length in millimeters
	double mm, in;

	printf("\nPlease enter a length in millimeters: ");
	scanf("%lf", &mm);
	
	//convert the millimeters to inches
	in = mm / 25.39998628;

	//print both millimeters and inches onto the screen
	printf("\nYou inputted '%.2f mm'. This is equivalent to '%.2f in'.\n", mm, in);

}

void InchestoMillimeters(void)
{
	//declare, ask and get the length in inches
	double in, mm;

	printf("\nPlease enter a length in inches: ");
	scanf("%lf", &in);

	//convert the inches to millimeters
	mm = in * 25.39998628;

	//print both inches and millimeters onto the screen
	printf("\nYou inputted '%.2f in.' This is equivalent to '%.2f mm'.\n", in, mm);

}
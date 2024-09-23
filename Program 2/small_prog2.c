/*
*Jordan Small, August 29, 2023, COP2220 Program 2: Simple Interactive Program
*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for toupper and tolower

int main()
{
	//Declaring all variables
	char letter1, lowerLetter1;
	char letter2, upperLetter2;
	int num;
	double dec, mult, quo, sub;

	//Printing my name
	printf("Hello, my name is Jordan!\n"); 

	//Prompting the user for a letter and collecting input value
	printf("\nPlease enter a letter: ");
	scanf(" %c", &letter1);

	lowerLetter1 = tolower(letter1); //Declare lowerLetter1 as it relates to letter1 with tolower funciton

	printf("Your original input was '%c' and its lowercase version is '%c'\n", letter1, lowerLetter1); //Printing letter input and its lowercase

	//Prompting the user for a second letter and collecting its input value
	printf("\nNow enter a second letter: ");
	scanf(" %c", &letter2);

	upperLetter2 = toupper(letter2); //Declare upperLetter2 as it relates to letter2 with toupper funciton

	printf("Your second letter was '%c' and its uppercase version is '%c'\n", letter2, upperLetter2); //Printing the second letter input and its uppercase

	//Prompting user to enter a nonzero interger followed by a nonzero double
	printf("\nPlease enter a nonzero interger: ");
	scanf("%d", &num);

	printf("Now, please enter a nonzero double: ");
	scanf("%lf", &dec);

	//Declaring new variables using operands in C math
	mult = num * dec;
	quo = dec / num;
	sub = dec - num;

	//Priting the results of the C math above, based on user inputed values
	printf("\nThe result of your numbers multiplied is: %.1f\n", mult);
	printf("The result of your double divided by your interger is: %.1f\n", quo);
	printf("And lastly, the result of your interger subtracted from your double is: %.1f\n", sub);

	printf("\nThanks for participating!\n"); //Salutations!

	return 0;
}
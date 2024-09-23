/*COP 2220 Program 5
Jordan Small, 09/25/2023
This program allows users to enter a student ID and a number of assesment grades,
calculating the number of assessments, total points, and an average. The user can
select an option to start the process again with another student ID.
*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes
void Welcome(void); //welcome the user and introduce program and features
char MakeSelection(); // run the menu; no input required; declare, ask, get, and return char choice
double AddGrade(double points, int currentID); //input current total points (double) and studentID (int), declare, ask, get, and return points (double)
void Average(double points, int count, int currentID); //input double points and intergers count and studentID; confirm count is not 0 (cannot divide by 0) and calculate average

int main() {

	//variable declarations
	char menu;
	int count = 0;
	double points;
	int studentID;

	Welcome();
	
	//ask, get, and declare current ID
	printf("Please enter a student ID to begin (must be an interger): ");
	scanf("%d", &studentID);

	menu = MakeSelection();
	points = 0; //initialize points value before while loop

	while (menu != 'Q' && menu != 'q') { //while loop to continue offering menu choices, provided option is not Q to quit

		if (menu == 'N' || menu == 'n')
		{
			points = 0;
			count = 0;
			printf("\nResetting assessment count and points to 0.");
			printf("\nPlease enter another student ID to begin (must be an interger): ");
			scanf("%d", &studentID);

		}

		if (menu == 'A' || menu == 'a')
		{
			
			//update total points by calling AddGrade function and adding to current total points
			points += AddGrade(points, studentID);
			count++; //update count by 1

		}

		if (menu == 'C' || menu == 'c')
		{
			if (points == 0) { //cannot compute average if total points are 0

				//suggest adding points by selecting option A
				printf("\n\n----------------------------------------------------------\n");
				printf("\nYou have not entered any points, select 'A' from the menu."); 

			}
			
			else {

				printf("\n----------------------------------------------------------\n");
				printf("The student with ID (%d) has accumulated %.2f points over a count of %d assessment(s).\n", studentID, points, count);
				printf("If you have more points to add, select 'A', you will not need to start over!\n");
				printf("If you want to start over, select 'N' from the menu.\n");
				printf("----------------------------------------------------------\n");
				Average(points, count, studentID); //call Average function, passing input of points, count, and studentID to display average

			}

		}

		printf("\n--- count of assesments is %d ---\n", count); //display current assesment count in while loop
		printf("\n----------------------------------------------------------\n");
		menu = MakeSelection(); //continue to update menu choice by calling MakeSelection function inside while loop
	}


}

void Welcome(void) {

	printf("***************************************************************\n");
	printf("Welcome to the grade calculator.\n");
	printf("-- All assessments must have a minimum of 0 and a maximum of 100 point value\n");
	printf("-- All assessments have the same weight\n");
	printf("Throughout the program, you will be prompted with the following options:\n");
	printf("Select 'A' to enter points\n");
	printf("Select 'C' to display the current average\n");
	printf("Select 'N' to start over with a NEW student\n");
	printf("Select 'Q' on the menu to QUIT the program\n");
	printf("***************************************************************\n");

}

char MakeSelection() {

	char sel;

	printf("\nPlease select from the following:\n");
	printf("A or a...to ADD the points for the current student\n");
	printf("C or c...to calculate and display the average of the current student\n");
	printf("N or n...to reset and start over with a NEW student\n");
	printf("Q or q...to QUIT:");
	scanf(" %c", &sel);

	return sel; //returns char for menu choice

}

double AddGrade(double points, int currentID) {

	//do while loop to update total points
	do {

		printf("\n----------------------------------------------------------\n");
		printf("\nEnter points for the assesment for student ID (%d) (between 0 and 100):", currentID);
		scanf("%lf", &points);
		printf("\n----------------------------------------------------------\n");

	}

	while (points < 0 || points > 100); //test that input is between 0 and 100

	return points; //returns points as double

}

void Average(double points, int count, int currentID) {

	double avg = 0;

	//compute average, provided count is not 0 (cannot divide 0)
	if (count != 0) {

		avg = points / count;

	}

	//compute average inside function
	printf("The current average is %.2f%%\n", avg); 

}
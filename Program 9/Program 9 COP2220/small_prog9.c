/*COP 2220 Program 9
Jordan Small, 12/05/2023
This program allows users to see a loaded list of five [5] students, add more
students to the list, and display a particular student based on their index.
Additionally, the user can add assessment points for a selected student in order
to calculate and display their average. The value is stored and updated, should
the user want to re-display the list or particular student.
*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#define SIZE 100

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper
#include<string.h>

typedef struct {

	char firstname[30];
	char lastname[30];
	int id;
	int pointcount;
	double points;
	double avg;

}student;

//function prototypes
void Welcome(void); //welcome the user and introduce program and features
void FiveStudents(student list[]); //initialize 5 students to the list
void PrintStudentList(student list[], int studentCount); //prints the list of students
void PrintOneStudent(student oneStudent); //prints one student
int AddOneStudent(student list[], int studentCount); //adds a student to the list
int SelectAndReturnIndex(student list[], int studentCount); //displays the students, has the user select the index, and returns the index
char DisplayMenu(); // run the menu; no input required; declare, ask, get, and return char choice
void AddPoints(student list[], int index); //input current student list and selected index, then declare, ask, get, and update points
void CalculateAverage(student list[], int index); //input current student list and selected index; confirm count is not 0 (cannot divide by 0), calculate, and display average

int main() {

	//variable declarations
	char menu;
	int indexOne; //for printing one student
	int indexSelect = 500; //index for the selected student

	student list[SIZE];
	int studentCount = 0;

	FiveStudents(list);
	studentCount = 5;

	Welcome();

	menu = DisplayMenu(); //get the menu choice

	while (menu != 'Q' && menu != 'q') { //while loop to continue offering menu choices, provided option is not Q to quit

		if (menu == 'N' || menu == 'n')
		{

			studentCount = AddOneStudent(list, studentCount);

		}

		else if (menu == 'P' || menu == 'p')
		{
			printf("\n----------------------------------------------------------\n");
			printf("\nCurrent student list:\n");
			PrintStudentList(list, studentCount);

		}

		else if (menu == 'S' || menu == 's')
		{

			printf("\n----------------------------------------------------------\n");
			printf("\nSelect the current student:\n");
			indexSelect = SelectAndReturnIndex(list, studentCount);
			printf("\n----------------------------------------------------------\n");
			printf("\nSelected student:\n");
			PrintOneStudent(list[indexSelect]);

		}

		else if (menu == 'O' || menu == 'o')
		{

			do {

				printf("\n----------------------------------------------------------\n");
				printf("\nEnter the index between 0 and %d: ", studentCount - 1);
				scanf("%d", &indexOne);

			} while (indexOne < 0 || indexOne >(studentCount - 1));

			PrintOneStudent(list[indexOne]);

		}

		else if (menu == 'A' || menu == 'a')
		{

			if (indexSelect == 500) {

				printf("\n----------------------------------------------------------\n");
				printf("\nNo student is currently selected.\n");
				printf("Select 'S' to select a student.\n");

			}

			else {

				AddPoints(list, indexSelect);

			}

		}

		else if (menu == 'C' || menu == 'c')
		{
			if (indexSelect == 500) {

				printf("\n----------------------------------------------------------\n");
				printf("\nNo student is currently selected.\n");
				printf("Select 'S' to select a student.\n");

			}

			else {

				CalculateAverage(list, indexSelect);

			}
		}

		else {

			printf("\n----------------------------------------------------------\n");
			printf("\nSelection not recognized!\n");

		}

		//printf("\n--- count of assesments is %d ---\n", count); //display current assesment count in while loop
		printf("\n----------------------------------------------------------\n");
		menu = DisplayMenu(); //continue to update menu choice by calling MakeSelection function inside while loop
	}

	printf("\nThank you and have a wonderful day!\n");

	return 0;

}

void Welcome(void) {

	printf("***************************************************************\n");
	printf("\nWelcome to the grade calculator.\n");
	printf("-- All assessments must have a minimum of 0 and a maximum of 100 point value\n");
	printf("-- All assessments have the same weight\n");
	printf("\n***************************************************************\n");

}

void PrintStudentList(student list[], int studentCount) {

	int i;
	for (i = 0; i < studentCount; i++) {

		printf("\n---------\n");
		printf("Index % d:\n", i);
		printf("---------\n");
	
		PrintOneStudent(list[i]);

	}

}

void PrintOneStudent(student oneStudent) {

	printf("\nFirst name:\t %s\n", oneStudent.firstname);
	printf("Last name:\t %s\n", oneStudent.lastname);
	printf("Student ID:\t %d\n", oneStudent.id);
	printf("Point count:\t %d\n", oneStudent.pointcount);
	printf("Total points:\t %.2f\n", oneStudent.points);
	printf("Average:\t %.2f\n", oneStudent.avg);

}

int AddOneStudent(student list[], int studentCount) {

	printf("\n----------------------------------------------------------\n");

	printf("\nEnter first name: ");
	scanf(" %s", list[studentCount].firstname);

	printf("Enter last name: ");
	scanf(" %s", list[studentCount].lastname);

	printf("Enter student ID: ");
	scanf("%d", &list[studentCount].id);

	list[studentCount].pointcount = 0;
	list[studentCount].points = 0.0;
	list[studentCount].avg = 0.0;

	studentCount++;

	return studentCount;

}

int SelectAndReturnIndex(student list[], int studentCount) {

	int index;
	PrintStudentList(list, studentCount);

	do {

		printf("\nEnter the index between 0 and %d: ", studentCount - 1);
		scanf("%d", &index);

	} while (index < 0 || index >(studentCount - 1));

	return index;

}

char DisplayMenu() {

	char sel;

	printf("\nPlease select from the following:\n\n");
	printf("P or p...to print the list of students and information onto the screen\n");
	printf("O or o...to print the information about one student onto the screen\n");
	printf("S or s...to select the current student in the list for grade calculation\n");
	printf("A or a...to ADD the points for the current student\n");
	printf("C or c...to calculate and display the average of the current student\n");
	printf("N or n...to add a NEW student\n");
	printf("Q or q...to QUIT:");
	scanf(" %c", &sel);

	return sel; //returns char for menu choice

}

void AddPoints(student list[], int index) {

	double add;

	//do while loop to update total points
	do {

		printf("\n----------------------------------------------------------\n");
		printf("\nEnter assesment points for student ID (%d) [%s, %s]: ", list[index].id, list[index].lastname, list[index].firstname);
		scanf("%lf", &add);

	} while (add < 0 || add > 100); //test that input is between 0 and 100

	list[index].points = list[index].points + add; //updates total points with new grade value
	list[index].pointcount++; //adds one to grade count

}

void CalculateAverage(student list[], int index) {

	if (list[index].pointcount == 0) { //cannot compute average if there are no graded assessments

		//suggest adding points by selecting option A
		printf("\nYou have not entered any points, select 'A' from the menu.");

	}

	//compute average
	else {

		list[index].avg = list[index].points / (double)list[index].pointcount;
		printf("\n----------------------------------------------------------\n");
		printf("\n[%s, %s] with ID (%d) has accumulated %.2f points over a count of %d assessment(s).\n", 
		list[index].lastname, list[index].firstname, list[index].id, list[index].points, list[index].pointcount);

		printf("\nThe student's current average is %.2f%%\n", list[index].avg);
		printf("\nIf you have more points to add, select 'A', you will not need to start over!\n");
		printf("If you want to select a different student for calculation, select 'S' from the menu.\n");
		
	}

}

void FiveStudents(student list[]) {
	
	strcpy(list[0].firstname, "John");
	strcpy(list[0].lastname, "Doe");
	list[0].id = 1001;
	list[0].pointcount = 0;
	list[0].points = 0;
	list[0].avg = 0.0;

	strcpy(list[1].firstname, "Tim");
	strcpy(list[1].lastname, "Finnigan");
	list[1].id = 1002;
	list[1].pointcount = 0;
	list[1].points = 0;
	list[1].avg = 0.0;

	strcpy(list[2].firstname, "Jane");
	strcpy(list[2].lastname, "Smith");
	list[2].id = 1003;
	list[2].pointcount = 0;
	list[2].points = 0;
	list[2].avg = 0.0;

	strcpy(list[3].firstname, "Rachel");
	strcpy(list[3].lastname, "Teeter");
	list[3].id = 1004;
	list[3].pointcount = 0;
	list[3].points = 0;
	list[3].avg = 0.0;

	strcpy(list[4].firstname, "Ebenezer");
	strcpy(list[4].lastname, "Scrooge");
	list[4].id = 1005;
	list[4].pointcount = 0;
	list[4].points = 0;
	list[4].avg = 0.0;

}
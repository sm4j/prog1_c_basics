/* Jordan Small
* COP2220 Intro to Programming in C
* user defined struct example
* In this program, I edited card.c code and changed all
* of the card (struct) variables/variable names, comments, function names/prototypes,
* function calls, and function definitons to reflect that of cats. 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#define SIZE 20
typedef struct {
	char breed[SIZE];
	char name[SIZE];
	char color[SIZE];
	int age;
}cat;
//Function Prototypes
// fills the data fields of a cat instance
//returns the filled cat
cat FillCat();
//fills the data fields of a cat instance
//by reference using a pointer to a cat
void FillCatPtr(cat* catptr);
//fills an array of cats
void FillCatArray(cat arrayC[], int* size);
//displays one cat
void DisplayCat(cat anyCat);
int main()
{
	//Declare variables
	cat myCat, myCat1, myCat2;
	cat catList[SIZE];
	int cSize;
	int i;
	//Fill structures with a function
	myCat = FillCat();
	myCat1 = FillCat();
	//print using display function
	printf("\n---------Display myCat\n");
	DisplayCat(myCat);
	printf("\n---------Display myCat1\n");
	DisplayCat(myCat1);
	//Fill structure using pointers and dispay it
	FillCatPtr(&myCat2);
	printf("\n---------Display myCat2\n");
	DisplayCat(myCat2);
	//Fill the array with the function
	printf("\n---------Fill array catList\n");
	FillCatArray(catList, &cSize);
	//display an array of cats
	printf("\n---------Display array catList\n");
	for (i = 0; i < cSize; i++)
	{
		DisplayCat(catList[i]);
	}
	return 0;
}
//Function Definitions
// fills the data fields of a cat instance
//returns the filled cat
cat FillCat()
{
	//Declare local variables
	cat tempC;
	//prompt and get information
	printf("\nplease enter the breed of your cat: ");
	scanf("%s", tempC.breed);
	//print to check
	printf("breed: %s\n", tempC.breed);
	//prompt and get information
	printf("\nplease enter the name of your cat: ");
	scanf("%s", tempC.name);
	//print to check
	printf("name: %s\n", tempC.name);
	//prompt and get information
	printf("\nplease enter the color of your cat: ");
	scanf("%s", tempC.color);
	//print to check
	printf("color: %s\n", tempC.color);
	//prompt and get information
	printf("\nplease enter the age of your cat: ");
	scanf("%d", &tempC.age);
	//print to check
	printf("age: %d\n", tempC.age);
	return tempC;
}
//displays one cat
void DisplayCat(cat anyCat)
{
	printf("\n\nbreed: %s\n", anyCat.breed);
	printf("name: %s\n", anyCat.name);
	printf("color: %s\n", anyCat.color);
	printf("age: %d\n", anyCat.age);
}
//fills the data fields of a cat instance
//by reference using a pointer to a cat
void FillCatPtr(cat* catptr)
{
	//prompt and get information
	printf("\nplease enter the breed of your cat: ");
	scanf("%s", (*catptr).breed);
	//prompt and get information
	printf("\nplease enter the name of your cat: ");
	scanf("%s", catptr->name);
	//prompt and get information
	printf("\nplease enter the color of your cat: ");
	scanf("%s", catptr->color);
	//prompt and get information
	printf("\nplease enter the age of your cat: ");
	scanf("%d", &(*catptr).age);
}
//fills an array of cats
void FillCatArray(cat arrayC[], int* size)
{
	int i;
	//prompt the user
	printf("\nenter the number of cats: ");
	scanf("%d", size);
	//print to check
	printf("size: %d\n", *size);
	for (i = 0; i < *size; i++)
	{
		printf("enter breed: ");
		scanf("%s", arrayC[i].breed);
		printf("enter name: ");
		scanf("%s", arrayC[i].name);
		printf("enter color: ");
		scanf("%s", arrayC[i].color);
		printf("enter age: ");
		scanf("%d", &arrayC[i].age);
	}
}
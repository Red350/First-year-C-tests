/* Labtest 4:
 * Program that defines a structure to store the details of a person's driver's license.
 * Contains functions to enter details into the struct via standard input, and to
 * print out the details.
 *
 * OS: Linux Mint 17.2 Rafaela
 * Compiled using GCC version 4.8.4
 * Author: Pádraig Redmond C15755659
 * Date: 19/04/2015
 */

#include <stdio.h>

// structure template for a driver's license
struct drivers_license
{
	char firstname[21];
	char surname[21];
	float height;
	char eyecolour[21];
	float weight;
	struct date
	{
		int day;
		int month;
		int year;
	}dob;
};

void enter_license(struct drivers_license*);
void print_license(struct drivers_license);
void flush_stdin();

int main()
{
	struct drivers_license driver1, driver2;

	// Call the function to enter the details into each struct
	printf("Enter details for driver 1\n");
	enter_license(&driver1);
	printf("\nEnter details for driver 2\n");
	enter_license(&driver2);

	// Print each driver
	printf("\n\nDriver 1\n");
	printf("~~~~~~~~\n");
	print_license(driver1);
	
	printf("\n\nDriver 2\n");
	printf("~~~~~~~~\n");
	print_license(driver2);

	return 0;
}

// Takes a pointer to a drivers_license struct and prompts the
// user to enter details for it
void enter_license(struct drivers_license* license)
{
	printf("Enter first name: ");
	scanf("%20s", license->firstname);
	flush_stdin();	// used after scanf to prevent trailing input being read during the next scanf

	printf("Enter last name: ");
	scanf("%20s", license->surname);
	flush_stdin();

	// When entering date of birth the user MUST include the '/' character between numbers
	printf("Enter date of birth (format dd/mm/yyyy): ");
	while(scanf("%d/%d/%d", &license->dob.day, &license->dob.month, &license->dob.year) != 3)
	{
		printf("Invalid format (dd/mm/yyyy), try again\n");
		flush_stdin();
	}
	flush_stdin();

	printf("Enter height: ");
	// only accepts numbers as input
	while((scanf("%f", &license->height)) != 1)
	{
		printf("Height must be a number, try again\n");
		flush_stdin();
	}

	printf("Enter eye colour: ");
	scanf("%20s", license->eyecolour);
	flush_stdin();
	
	printf("Enter weight: ");
	// only accepts numbers as input
	while (scanf("%f", &license->weight) != 1)
	{
		printf("Weight must be a number, try again\n");
		flush_stdin();
	}
}

// Prints the details of a given drivers_license struct
void print_license(struct drivers_license license)
{
	printf("First name: %s\n", license.firstname);
	printf("Last name: %s\n", license.surname);
	printf("Date of birth: %d/%d/%d\n", license.dob.day, license.dob.month, license.dob.year);
	printf("Height: %.2f\n", license.height);
	printf("Eye colour: %s\n", license.eyecolour);
	printf("Weight: %.2f\n", license.weight);
}

// flush the stdin buffer
void flush_stdin()
{
	char c;
	while((c = getchar()) != '\n')
	{
		// discarding input
	}
}


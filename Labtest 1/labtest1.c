/* Program to check if a 4 digit year is 
 * a leap year
 * 
 * OS: Linux Mint 17.2 Rafaela
 * Compiled using GCC version 4.84
 * Author: Pádraig Redmond 15755659
 * Date: 27/10/2015
 */

#include <stdio.h>

int main()
{
	int year;
	int leap = 0;
	char repeat = 'y';
	
	do
	{
		printf("Enter a year: ");
		scanf("%d", &year);
		getchar();
		
		// Ensure user is entering a 4 digit year.
		// I allow years starting at 1 because a user
		// could input 0001 which is 4 digits
		while(year < 1 || year > 9999)
		{
			printf("Enter a 4 digit year: ");
			scanf("%d", &year);
			getchar();
		}
		
		// Checks all possible conditions of a leap year
		// and sets the leap variable to either 1 or 0
		if(year % 4 == 0)
		{
			if(year % 100 == 0)
			{
				if(year % 400 == 0)
				{
					leap = 1;
				}
				else
				{
					leap = 0;
				}
			}
			else
			{
				leap = 1;
			}
		}
		else
		{
			leap = 0;
		}
	
		if(leap)
		{
			printf("%d is a leap year\n",year);
		}
		else
		{
			printf("%d is NOT a leap year\n",year);
		}
		
		// Allow the user to repeat the program 
		printf("Would you like to try another year? y/n: ");
		repeat = getchar();
		getchar();
		
		// Validation, only accepts 'y' or 'n'
		while(repeat != 'y' && repeat != 'n')
		{
			printf("Please enter only y/n: ");
			repeat = getchar();
			getchar();
		}
	}
	while(repeat == 'y');
	
	return 0;
}


/* Program to take multiple inputs for miles and gallons,
 * calculate miles per gallon, all using pointer notation.
 * 
 * OS: Linux Mint 17.2 Rafaela
 * Compiled using GCC version 4.84
 * Author: Pádraig Redmond C15755659
 * Date: 8/12/2015
 */

#include <stdio.h>

#define SIZE 5

int main()
{
	float gallons[SIZE];
	float miles[SIZE];
	float mpg[SIZE];
	int i;
	
	printf("Enter %d value(s) for gallons\n", SIZE);
	// input values for gallons
	for(i = 0; i < SIZE; i++){
		scanf("%f", (gallons + i));
	}
	
	printf("Enter %d value(s) for miles\n", SIZE);
	// input values for miles
	for(i = 0; i < SIZE; i++){
		scanf("%f", (miles + i));
	}
	
	// calculate mpg by dividing miles by gallons
	for(i = 0; i < SIZE; i++){
		*(mpg + i) = *(miles + i) / *(gallons + i);
	}
	
	printf("mpg: ");
	// print resulting mpg array
	for(i = 0; i < SIZE; i++){
		printf("%f ", *(mpg + i));
	}
	
	printf("\n");
	
	return 0;
}


/* Labtest 3:
 * Program that uses functions to convert an array of temperatures from
 * celcius to fahrenheit, while also calculating the average of the celcius values.
 * Finally, it converts the celcius average to kelvin.
 * All floats are printed to 2 decimal places to improve readability.
 *
 * OS: Linux Mint 17.2 Rafaela
 * Compiled using GCC version 4.8.4
 * Author: Pádraig Redmond C15755659
 * Date: 23/02/2015
 */

#include <stdio.h>

#define SIZE 5

float convert_temp(float[]);
void in_kelvin(float*);

int main()
{
	float temps[SIZE];
	float average;
	int i;

	printf("Enter %d temperatures in celcius: ", SIZE);
	
	// input values from the user into temps array
	for (i = 0; i < SIZE; i++)
	{
		scanf("%f", &temps[i]);
	}

	// call the convert_temps function and store the resulting average
	// in average variable and print it
	average = convert_temp(temps);
	printf("\nAverage in celcius: %0.2f\n", average);

	// convert the average from celcius to kelvin and print it
	in_kelvin(&average);
	printf("\nAverage in kelvin: %0.2f\n\n", average);

	return 0;
}

// function to convert an array of temperatures in celcius
// to fahrenheit, while also calculating the average of the 
// celcius values
float convert_temp(float temps[])
{
	int i;
	float average, total = 0;

	printf("\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d. Celcius: %0.2f\t", i+1, temps[i]);
		// add current temp to total before converting to fahrenheit
		total = total + temps[i];
		// convert to fahrenheit
		temps[i] = ((temps[i]*9)/5) + 32;
		printf("Fahrenheit: %0.2f\n", temps[i]);
	}

	// calculate and return the average of the celcius values
	average = total / SIZE;
	return average;
}

// function to convert a float from celcius to kelvin
void in_kelvin(float *num)
{
	*num = *num + 273;
}


// Ch 6 Programs.cpp : Celsius Temperature Table

#include <iostream>
#include <iomanip>

using namespace std;

double celsius(int);// Function prototype, Declares the celsius function so it can be used before its definition

void getCelsius()//Function: getCelsius, Prompts the user to enter a Fahrenheit temperature,then converts it to Celsius and displays the result.
{
	int F;
	cout << "Enter temperature (F): ";
	cin >> F;
	cout << F << "F in Celsius is " << fixed << setprecision(2) << celsius(F) << endl;
}

double celsius(int F)// Function: celsius, Converts a Fahrenheit temperature to Celsius. Input: F (int) - temperature in Fahrenheit, Output: double - equivalent temperature in Celsius.Formula: (F - 32) * 5/9
{
	return (5.0 * (F - 32)) / 9;
}

int main()//Displays a table of Fahrenheit temperatures from 0 to 20 and Celsius equivalents, then allows user input.
{
	cout << "\nTable of Fahrenheit tempratures 0 - 20 and their Celcius equivalents.\n\n";
	cout << "Fahrenheit\tCelcius\n\n";

	for (int F = 0; F <= 20; F++)//Loops to create the table 
	{
		cout << "\t" << setw(2) << F;
		cout << "\t" << setw(3) << fixed << setprecision(2) << celsius(F) << endl;
	}
	cout << endl;

	getCelsius();// Call getCelsius() to let user convert any Fahrenheit value

	return 0;
}


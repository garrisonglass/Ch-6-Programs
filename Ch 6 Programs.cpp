// Ch 6 Programs.cpp : Celsius Temperature Table

#include <iostream>
#include <iomanip>

using namespace std;
double celsius(int);

void getCelsius()
{
	int F;
	cout << "Enter temperature (F): ";
	cin >> F;
	cout << F << "F in Celsius is " << fixed << setprecision(2) << celsius(F) << endl;
}

double celsius(int F)//calculates the conversion 
{
	return (5.0 * (F - 32)) / 9;
}

int main()
{
	cout << "\nTable of Fahrenheit tempratures 0 - 20 and their Celcius equivalents.\n\n";
	cout << "Fahrenheit\tCelcius\n\n";

	for (int F = 0; F <= 20; F++)//Loops to creat the table 
	{
		cout << "\t" << setw(2) << F;
		cout << "\t" << setw(3) << fixed << setprecision(2) << celsius(F) << endl;
	}
	cout << endl;

	getCelsius();//Callls the function to convert any F to C

	return 0;
}


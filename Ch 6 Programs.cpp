// Ch 6 Programs.cpp : Celsius Temperature Table

#include <iostream>
#include <iomanip>

using namespace std;

double celsius(int);
double getCelcius(int);

int main()
{
	cout << "\nTable of Fahrenheit tempratures 0 - 20 and their Celcius equivalents.\n\n";
	cout << "Fahrenheit\tCelcius\n\n";

	for (int F = 0; F <= 20; F++)
	{
		cout << "\t" << setw(2) << F;
		cout << "\t" << setw(3) << fixed << setprecision(2) << celsius(F) << endl;
	}
	cout << endl;

	return 0;
}
double getCelcius(int F, double celsius)
{
	cout << "Enter tempratue (F): ";
	cin >> F;
	cout << F << "F in celcius is" << celsius << endl;
}
double celsius(int F)
{
	return (5.0*(F - 32))/9;
}
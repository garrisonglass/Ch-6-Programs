// Ch 6 Programs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void getRegInfo(string&, int&);
bool isLowest(int, int);
void showLowest(string, int);

int main()
{
    string Region, lowRegion;
    int Accidents, lowAccidents;
    char again = 'Y';

    getRegInfo(Region, Accidents);
    lowRegion = Region;
    lowAccidents = Accidents;

    while (true)
    {
        getRegInfo(Region, Accidents);
        if (isLowest(Accidents, lowAccidents))
        {
            lowRegion = Region;
            lowAccidents = Accidents;
        }
        cout << "Do you want to enter another? Y/N ";
        cin >> again;
        if (again != 'Y' && again != 'y')
            break;
    }
    showLowest(lowRegion, lowAccidents);
    return 0;
}

void getRegInfo(string& Region, int& Accidents)//Gets input from user on regions and number accidents
{
    cout << "Enter the name of the region: ";
    cin >> Region;
    do
    {
        cout << "Enter the number of accidents for the " << Region << " region: ";
        cin >> Accidents;
        if (Accidents < 0)
            cout << "The number of accidents cannot be negative. Please try again.";
    } while (Accidents < 0);
}

bool isLowest(int value1, int value2)//Checks if each newly entered accident count is lower than the previous
{
    return (value1 < value2);
}

void showLowest(string Region, int Accidents)//displays region with lowest count
{
    if (Accidents == 1)//outlyer, singular 
    {
        cout << "\nThe " << Region << " region has the lowest number of accidents.\n";
        cout << "For a total of " << Accidents << " accident." << endl;
    }
    else
    {
    cout << "\nThe " << Region << " region has the lowest number of accidents.\n";
    cout << "With a total of " << Accidents << " accidents." << endl;
    }
}

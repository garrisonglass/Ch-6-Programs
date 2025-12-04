// Ch 6 Programs.cpp : Paint Job Estimator

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

//Constants
const double sqft_per_gallon = 110.0;//110 sq ft per gallon
const double hours_per_sqft = 8.0 / 110.0;//8 hours per 110 sq ft
const double labor_rate = 25.0;//$25 per hour

//------------------------------------------------------------
//Function: calculateGallons
//Purpose:  Calculate how many gallons of paint are needed
//Input:    sqft (double) - square feet of wall space
//Output:   int - number of gallons required (rounded up)
//------------------------------------------------------------
int calculateGallons(double sqft)
{
    return static_cast<int>((sqft + sqft_per_gallon - 1) / sqft_per_gallon);
}

//------------------------------------------------------------
//Function: calculateLaborHours
//Purpose:  Calculate labor hours required for given square footage
//Input:    sqft (double) - square feet of wall space
//Output:   double - number of labor hours required
//------------------------------------------------------------
double calculateLaborHours(double sqft)
{
    return sqft * hours_per_sqft;
}

//------------------------------------------------------------
//Function: calculatePaintCost
//Purpose:  Calculate paint cost for a room
//Input:    gallons (int) - gallons of paint required
//          pricePerGallon (double) - cost of one gallon of paint
//Output:   double - total paint cost for the room
//------------------------------------------------------------
double calculatePaintCost(int gallons, double pricePerGallon)
{
    return gallons * pricePerGallon;
}

//------------------------------------------------------------
//Function: calculateLaborCharges
//Purpose:  Convert labor hours into dollar charges
//Input:    hours (double) - number of labor hours
//Output:   double - total labor charges in dollars
//------------------------------------------------------------
double calculateLaborCharges(double hours)
{
    return hours * labor_rate;
}

int main()
{
    int rooms;
    cout << fixed << setprecision(2);

    //Validate number of rooms
    do {
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
        if (cin.fail() || rooms <= 0)
        {
            cout << "Invalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            rooms = -1;
        }
    } while (rooms <= 0);

    //Vectors sized by number of rooms
    vector<double> sqft(rooms);
    vector<double> price(rooms);
    vector<int> gallons(rooms);
    vector<double> paintCost(rooms);
    vector<double> laborHours(rooms);
    vector<double> laborCharges(rooms);

    double totalSqFt = 0.0, totalPaintCost = 0.0, totalLaborCharges = 0.0, totalLaborHours = 0.0;
    int totalGallons = 0;

    //Loop through each room
    for (int i = 0; i < rooms; i++)
    {
        cout << "\nRoom " << (i + 1) << ":\n";

        cout << "Enter square feet of wall space: ";
        cin >> sqft[i];
        while (sqft[i] <= 0)
        {
            cout << "Square footage must be positive. Try again: ";
            cin >> sqft[i];
        }

        cout << "Enter paint price per gallon (min $10): $";
        cin >> price[i];
        while (price[i] < 10.0)
        {
            cout << "That is some cheap paint. Please pick something else.";
            cin >> price[i];
        }
        //Per-room calculation
        gallons[i] = calculateGallons(sqft[i]);
        laborHours[i] = calculateLaborHours(sqft[i]);
        paintCost[i] = calculatePaintCost(gallons[i], price[i]);
        laborCharges[i] = calculateLaborCharges(laborHours[i]);

        //Update totals
        totalSqFt += sqft[i];
        totalPaintCost += paintCost[i];
        totalLaborCharges += laborCharges[i];
        totalGallons += gallons[i];
        totalLaborHours += laborHours[i];
    }

    double totalCost = totalPaintCost + totalLaborCharges;

    cout << "\nEstimate for painting " << rooms << " rooms:\n";
    cout << "Gallons of paint to purchase: " << totalGallons << endl;
    cout << "Number of hours required to paint rooms:" << totalLaborHours << endl;
    cout << "Cost of paint: $" << totalPaintCost << endl;
    cout << "Cost of labor: $" << totalLaborCharges << endl;
    cout << "Total cost for job: $" << totalCost << endl;

    return 0;
}
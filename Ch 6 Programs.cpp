// Ch 6 Programs.cpp : Paint Job Estimator

#include <iostream>
#include <iomanip>

using namespace std;

//Supplied constants
const double sqft_per_gallon = 110.0;//110 square feet of wall space for 1 gallon of paint
const double hours_per_sqft = 8.0 / 110.0;//8 hours of labor per 110 square feet of coverage
const double labor_rate = 25.0;//$25 per hour. 

//Function to get total square feet
double getTotalSquareFeet(int rooms)
{
    double T_sqft = 0.0;//Running total of squar footage 
    for (int i = 1; i <= rooms; i++)//Loops for each room 
    {
        double sqft;
        cout << "Enter square feet of wall space for room " << i << ": ";
        cin >> sqft;

        if (sqft < 0)//Input validation for negative square foot 
        {
            cout << "Square footage cannot be negative. Try again.\n";
            i--; //Repeat this room’s input
            continue;
        }
        T_sqft += sqft;//Adds to running total
    }
    return T_sqft;
}

// Function to calculate gallons of paint
int cal_Gallons(double totalSqFt)
{
    return static_cast<int>((totalSqFt + sqft_per_gallon - 1) / sqft_per_gallon);//Inputs double, outputs int
}

// Function to calculate labor hours
double cal_Labor_Hours(double totalSqFt)
{
    return totalSqFt * hours_per_sqft;
}

// Function to calculate paint cost
double cal_Cost_of_Paint(int gallons, double pricePerGallon)
{
    return gallons * pricePerGallon;
}

// Function to calculate labor charges
double cal_LaborCharges(double hours)
{
    return hours * labor_rate;
}

// Function to calculate total cost
double cal_TotalCost(double paintCost, double laborCharges)
{
    return paintCost + laborCharges;
}

int main()
{
    int rooms;
    double pricePerGallon;

    cout << fixed << setprecision(2);

    do
    {
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;

        if (cin.fail() || rooms <= 0)//Input validation if a negative or something other than a number is entered
        {
            cout << "Invalid input. Please enter the number of rooms to be painted.\n";
            cin.clear();//Removes the error flags
            cin.ignore(1000, '\n');//Discard up to 1000 characters or until it finds a newline ('\n')
            rooms = -1;//Repeat
        }
    } while (rooms <= 0);

    do
    {
        cout << "Enter the price of paint per gallon: $";
        cin >> pricePerGallon;

        if (cin.fail() || pricePerGallon < 10.0)//Input validation for cheap paint (<10.00 
        {
            cout << "That is some cheap paint. Please pick something else.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            pricePerGallon = -1;//Force repeat
        }
    } while (pricePerGallon < 10.0);

    double totalSqFt = getTotalSquareFeet(rooms);
    int gallons = cal_Gallons(totalSqFt);
    double laborHours = cal_Labor_Hours(totalSqFt);
    double paintCost = cal_Cost_of_Paint(gallons, pricePerGallon);
    double laborCharges = cal_LaborCharges(laborHours);
    double totalCost = cal_TotalCost(paintCost, laborCharges);

    cout << "\nPaint Job Estimate\n";
    cout << "Gallons of paint required: " << gallons << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCharges << endl;
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}


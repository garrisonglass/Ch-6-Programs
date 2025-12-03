// Ch 6 Programs.cpp:Rectangle calculator

#include <iostream>
#include <limits>
using namespace std;

double getLength_Width(const string &question);
double calcArea(double lenth, double width);
double calcPerimeter(double lenth, double width);
void displayProperties(double lenth, double width, double area, double perimeter);
bool ShallWeContinue();

int main()
{
    cout << "Hither, and welcome, gentle sirs and madams, to the Rectangular Computatorium, where quadrangles meet their mathematical doom!\n\n";

    do
    {
        double lenth = getLength_Width("Hark, what be the reach of yon rectangular shape, you inquire? ");
        double width = getLength_Width("Prithee, divulge unto mine ears the lateral extent of yon four-sided geometrical marvel! ");
        double area = calcArea(lenth, width);
        double peramiter = calcPerimeter(lenth, width);
        displayProperties(lenth, width, area, peramiter);
    } 
    while (ShallWeContinue());

    cout << "Fare thee well, and may thy days be filled with unctuous jubilations and copious draughts of mead!\n";
    return 0;
}
double getLength_Width(const string& question)
{
    double value;
    while (true)
    {
        cout << question;
        cin >> value;

        if (cin.fail() || value <= 0)
        {
            cout << "Truly, mine cogitations doth fail. Pray, insert a number of rightful and legitimate provenance.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}
double calcArea(double length, double width) 
{
    return length * width;
}
double calcPerimeter(double length, double width) 
{
    return 2 * (length + width);
}
void displayProperties(double length, double width, double area, double perimeter) 
{
    cout << "\Verily, the response appertaining unto thine interrogation doth reside within\n";
    cout << "Length: " << length << "\n";
    cout << "Width : " << width << "\n";
    cout << "Area  : " << area << "\n";
    cout << "Perimeter: " << perimeter << "\n\n";
}
bool ShallWeContinue() 
{
    char choice;
    while (true) 
    {
        cout << "Pray tell, dost thou harbour a most puissant desire to embark upon the herculean task of processing yet another quadrilateral bewitchment? (Yea/Nay) ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        choice = toupper(choice);
        if (choice == 'Y') return true;
        if (choice == 'N') return false;

        cout << "Invalid choice. Please enter Y or N.\n";
    }
}







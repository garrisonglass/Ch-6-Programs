// Ch 6 Programs.cpp : Star Project

#include <iostream>
using namespace std;

// Function to input scores
void getScores(double scores[], int judges) 
{
    cout << "Enter " << judges << " scores (0-10, fractional allowed):\n";
    for (int i = 0; i < judges; i++)
    {
        cin >> scores[i];
    }
}

// Function to find highest score
double findHighest(double scores[], int judges)
{
    double highest = scores[0];
    for (int i = 1; i < judges; i++)
    {
        if (scores[i] > highest) 
        {
            highest = scores[i];
        }
    }
    return highest;
}

// Function to find lowest score
double findLowest(double scores[], int judges)
{
    double lowest = scores[0];
    for (int i = 1; i < judges; i++)
    {
        if (scores[i] < lowest) 
        {
            lowest = scores[i];
        }
    }
    return lowest;
}

// Function to calculate final score
double calculateFinalScore(double scores[], int judges)
{
    double highest = findHighest(scores, judges);
    double lowest = findLowest(scores, judges);

    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < judges; i++)
    {
        if (scores[i] != highest && scores[i] != lowest) 
        {
            sum += scores[i];
            count++;
        }
    }

    // Edge case: if multiple scores equal highest/lowest, only drop one each
    if (count < 3) 
    {
        // Add back one occurrence if too many were dropped
        sum += highest;
        count++;
    }

    return sum / count;
}

int main() 
{
    const int SIZE = 5;
    double scores[SIZE];

    getScores(scores, SIZE);

    double finalScore = calculateFinalScore(scores, SIZE);

    cout << "Final Score: " << finalScore << endl;

    return 0;
}

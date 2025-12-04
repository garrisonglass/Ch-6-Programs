// Ch 6 Programs.cpp : Star Project

#include <iostream>
#include <limits>
using namespace std;

//Prompt and validate each score (0–10), handling non-numeric input safely
void getScores(double scores[], int judges)
{
    cout << "Enter the scores of the " << judges << " judges (0 - 10).\n";
    for (int i = 0; i < judges; i++)
    {
        double score;
        while (true)
        {
            cout << "Judge " << (i + 1) << " score: ";

            // Attempt to read input
            if (!(cin >> score)) 
            {
                //Non-numeric input: clear and discard
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number between 0 and 10.\n";
                continue; // retry this judge
            }

            //Range validation
            if (score < 0.0 || score > 10.0) 
            {
                cout << "That is not between 0 - 10, please try again.\n";
                continue; // retry this judge
            }

            //Valid score
            scores[i] = score;
            break;
        }
    }
}

//Function to find highest score
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

//Function to find lowest score
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

//Function to calculate final score
double calculateFinalScore(double scores[], int judges)
{
    double highest = findHighest(scores, judges);
    double lowest = findLowest(scores, judges);

    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < judges; i++)
    {
        sum += scores[i];
    }

    sum -= highest;
    sum -= lowest;

    return sum / (judges - 2); 

}

int main() 
{
    const int NumberOfJudges = 5;
    double scores[NumberOfJudges];

    getScores(scores, NumberOfJudges);

    double finalScore = calculateFinalScore(scores, NumberOfJudges);

    cout << "Final Score: " << finalScore << endl;

    return 0;
}

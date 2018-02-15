#include <iostream>
using namespace std;

int AVERAGE(int x[], int y);
void printNumberAboveAndBelow(int x[], int y, int aver);


int main()
{
	int quizScores[99], total;
	double totalsum = 0, average;
	cout << "Please enter the number of scores." << endl;
	cin >> total;
	cout << "Please enter the quiz scores " << endl;
	totalsum = AVERAGE(quizScores, total);
	average = totalsum / total;
	cout << "The average: " << average << endl;
	printNumberAboveAndBelow(quizScores, total, average);
}

int AVERAGE(int x[], int y)
{
	int totalsum = 0;
	for (int i = 0; i < y; i++)
	{
		cin >> x[i];
		totalsum = totalsum + x[i];
	}
	return totalsum;
}

void printNumberAboveAndBelow(int x[], int y, int aver)
{
	int above = 0, below = 0;
	for (int i = 0; i < y; i++)
	{
		if (x[i] > aver)
		{
			above++;
		}
		else
			below++;
	}
	cout << "The number of scores above average: " << above << endl;
	cout << "The number of scores below average: " << below << endl;

}

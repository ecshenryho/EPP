#include <iostream>
#include <string>
#include "CarAnalysis.h"

int main() {
	CarAnalysis myCarAnalysis("data.txt");
	cout << "There are " << myCarAnalysis.numberOfCars() << " cars in the data file" << endl;
	cout << "The most popular model of car is " << myCarAnalysis.mostPopularModel() << endl;
	//cout << "The average mileage of the most popular model is " << myCarAnalysis.averageMileage() << endl;
	system("pause");
}
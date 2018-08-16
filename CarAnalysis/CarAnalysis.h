#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
class carInfo
{
public:
	string _modelName;
	string _licensePlate;
	int _mileage;
	carInfo() {
		_modelName = "default";
		_licensePlate = "default";
		_mileage = 0;
	}
	carInfo(string modelName, string licensPlate, int mileage) {
		_modelName = modelName;
		_licensePlate = licensPlate;
		_mileage = mileage;
	}
	
};
class CarAnalysis
{
public:
	CarAnalysis() {
		_popularCar="default name";
		_numberOfCar = 0;;
		_averageMileage = 0;
		
	}
	CarAnalysis(string filename) {
		int index = 0;
		ifstream inFile;
		inFile.open(filename);
		if (inFile.is_open())
		{
			cout << "Successfully open file " << filename << endl;
			string modelName;
			string licensePlate;
			int mileage=0;
			
			while (inFile >> modelName >> licensePlate >> mileage)
			{
				carInfo car(modelName, licensePlate, mileage);
				carArray.push_back(car);
			}
			inFile.close();
			_numberOfCar = carArray.size();
		}
		else
		{
			cout << "could not open file!\n";
		}
		
		
	}
	int numberOfCars() {
		return _numberOfCar;
	}

	void popularOfAcar(string license) {
		int frequency = 0;
		for (int i = 0; i <carArray.size(); i++)
		{
			if (license == carArray[i]._licensePlate)
			{
				frequency++;
			}
		}
		popularList.push_back[frequency];

	}
	void all() {
		for (int i = 0; i < carArray.size(); i++)
		{
			popularOfAcar(carArray[i]._licensePlate);
		}
	}
	string mostPopularModel() {
		int index1 = 0;
		string most = carArray[0]._modelName;
		for (int i = 0; i < popularList.size(); i++)
		{
			if (popularList[i]>most)
			{
				most = popularList[i];
				index1 = i;
			}
		}
		return popularList[index1];
	}


private:
	string _popularCar;
	int _numberOfCar;
	double _averageMileage;
	vector<carInfo> carArray;
	vector<string>popularList;
};


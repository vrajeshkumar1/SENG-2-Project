#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "City.h"
using namespace std;

void getRowInfo(istream &file, int rowAnalyzed, string (&infoHolder)[7])
{
    string line;

    file.clear();
    file.seekg(0, ios::beg); // move read pointer to the beginning of the file

    for (int i = 1; i <= rowAnalyzed; i++)
    {
        getline(file, line); // find row to analyze
    }

    size_t pos = 0;
    int cellIndex = 0;

    while ((pos = line.find(',')) != string::npos && cellIndex < 7)
    {
        infoHolder[cellIndex++] = line.substr(0, pos);
        line.erase(0, pos + 1);
    }
    if (cellIndex < 7)
    { // if there are less than 6 cells in the row
        infoHolder[cellIndex] = line;
    }
}

int main()
{

    int rows = 0;
    ifstream file("SENG2ExcelFile - Sheet1.csv");
    string line;

    while (getline(file, line))
    {
        rows++;
    }

    City *cities = new City[rows - 1];

    string infoHolder[7];

    for (int i = 2; i <= rows; i++)
    {
        getRowInfo(file, i, infoHolder);
        cities[i - 2].setName(infoHolder[0]);
        cities[i - 2].setPopulation(stoi(infoHolder[1]));
        cities[i - 2].setAvgDistEnemyBase(stod(infoHolder[2]));
        cities[i - 2].setAvgDistFriendlyBase(stod(infoHolder[3]));
        cities[i - 2].setEstEnemyInfantryPower(stoi(infoHolder[4]));
        cities[i - 2].setEstFriendlyInfantryPower(stoi(infoHolder[5]));
        cities[i - 2].setPoliticalInterference(stoi(infoHolder[6]));
        cities[i - 2].defineRiskFactor();
    }

    file.close();

    cout << setw(20) << "City Name" << setw(20) << "Population" << setw(25) << "Avg Dist Enemy Base" << setw(25) << "Avg Dist Friendly Base" << setw(30) << "Est Enemy Infantry Power" << setw(30) << "Est Friendly Infantry Power" << setw(23) << "Political Interference" << setw(15) << "Risk Factor" << endl;
    for (int i = 0; i < rows - 1; i++)
    {
        cout << setw(20) << cities[i].getName() << setw(20) << cities[i].getPopulation() << setw(25) << cities[i].getAvgDistEnemyBase() << setw(25) << cities[i].getAvgDistFriendlyBase() << setw(30) << cities[i].getEstEnemyInfantryPower() << setw(30) << cities[i].getEstFriendlyInfantryPower() << setw(23) << cities[i].getPoliticalInterference() << setw(15) << cities[i].getRiskFactor() << endl;
    }

    delete[] cities;

    return 0;
}
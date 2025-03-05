#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include "City.h"
using namespace std;

int rows = 0;
vector<City> cities;

int menu();
void getRowInfo(istream &file, string (&infoHolder)[7]);
void printCities();
void addCity();
void adminDashboard();
int getclosestCityIndex(vector<City> &cities);

int main()
{
    ifstream file("SENG2ExcelFile - Sheet1.csv");
    string line;

    // Skip the header line
    getline(file, line);

    while (getline(file, line))
    {
        rows++;
    }
    string infoHolder[7];

    file.clear();
    file.seekg(0, ios::beg); // move read pointer to the beginning of the file

    // Skip the header line again
    getline(file, line);

    for (int i = 0; i < rows; i++)
    {
        getRowInfo(file, infoHolder);
        City tempCity;
        tempCity.setName(infoHolder[0]);
        tempCity.setPopulation(stoi(infoHolder[1]));
        tempCity.setAvgDistEnemyBase(stod(infoHolder[2]));
        tempCity.setAvgDistFriendlyBase(stod(infoHolder[3]));
        tempCity.setEstEnemyInfantryPower(stoi(infoHolder[4]));
        tempCity.setEstFriendlyInfantryPower(stoi(infoHolder[5]));
        tempCity.setPoliticalInterference(stoi(infoHolder[6]));
        cities.push_back(tempCity);
    }

    City::defineRiskFactor(cities, getclosestCityIndex(cities));

    file.close();

    int finalChoice = 1;

    while (finalChoice == 1)
    {
        finalChoice = menu();
    }

    return 0;
}

int menu()
{
    int option;
    do
    {
        cout << "============ Menu ============\n1. Display Current Cities\n2. Most Risky City\n3. Admin Dashboard Login\n0. Exit\n\nOption: ";
        cin >> option;
    } while (option < 0 || option > 3);

    switch (option)
    {
    case 0:
        return 0;
        break;
    case 1:
        printCities();
        break;
    case 2:
    
        break;
    case 3:
        adminDashboard();
        break;
    }

    return 1;
}

void printMostRiskyCity(){
    for (int i=0; i<rows; i++){

    }
}

void getRowInfo(istream &file, string (&infoHolder)[7])
{
    string line;
    getline(file, line); // read the row

    size_t pos = 0;
    int cellIndex = 0;

    while ((pos = line.find(',')) != string::npos && cellIndex < 7)
    {
        infoHolder[cellIndex++] = line.substr(0, pos);
        line.erase(0, pos + 1);
    }
    if (cellIndex < 7)
    { // if there are less than 7 cells in the row
        infoHolder[cellIndex] = line;
    }
}

void printCities()
{
    cout<<"============================================================ Cities: "<< cities.size() <<" ===================================================================================\n";
    cout << setw(20) << "City Name|" << setw(20) << "Population|" << setw(25) << "Avg Dist Enemy Base|" << setw(25) << "Avg Dist Friendly Base|" << setw(29) << "Est Enemy Infantry Power|" << setw(29) << "Est Friendly Infantry Power|" << setw(24) << "Political Interference|" << setw(15) << "Risk Factor|" << endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < cities.size(); i++)
    {
        cout << setw(20) << cities[i].getName() << setw(20) << cities[i].getPopulation() << setw(25) << cities[i].getAvgDistEnemyBase() << setw(25) << cities[i].getAvgDistFriendlyBase() << setw(29) << cities[i].getEstEnemyInfantryPower() << setw(29) << cities[i].getEstFriendlyInfantryPower() << setw(24) << cities[i].getPoliticalInterference() << setw(15) << cities[i].riskFactor << endl;
    }
}

void adminDashboard()
{
    int option;
    do
    {
        cout << "============ Admin Dashboard ============\n1. Add City\n2. Modify City Information\n3. Delete City\n0. Return to Main Menu\n\nOption: ";
        cin >> option;
    } while (option < 0 || option > 3);

    switch (option)
    {
    case 0:
        menu();
        break;
    case 1:
        addCity();
        // Recalculate risk factor for all cities
        City::defineRiskFactor(cities, getclosestCityIndex(cities));
        break;
    case 2:
        // Recalculate risk factor for all cities
        City::defineRiskFactor(cities, getclosestCityIndex(cities));
        break;
    case 3:
        // Implement delete city functionality
        break;
    }
}

void addCity()
{
    string name;
    int population;
    double avgDistEnemyBase, avgDistFriendlyBase;
    int estEnemyInfantryPower, estFriendlyInfantryPower, politicalInterference;

    cout << "Adding City\n";
    cout << "=============\n";
    cout << "Enter City Name: ";
    cin >> name;
    cout << "Enter Population: ";
    cin >> population;
    cout << "Enter Average Distance to Enemy Base: ";
    cin >> avgDistEnemyBase;
    cout << "Enter Average Distance to Friendly Base: ";
    cin >> avgDistFriendlyBase;
    cout << "Enter Estimated Enemy Infantry Power: ";
    cin >> estEnemyInfantryPower;
    cout << "Enter Estimated Friendly Infantry Power: ";
    cin >> estFriendlyInfantryPower;
    cout << "Enter Political Interference: ";
    cin >> politicalInterference;

    City newCity(name, population, avgDistEnemyBase, avgDistFriendlyBase, estEnemyInfantryPower, estFriendlyInfantryPower, politicalInterference);
    cities.push_back(newCity);
    rows++;
}

int getclosestCityIndex(vector<City> &cities)
{
    double min = cities[0].getAvgDistEnemyBase();
    int index = 0;
    for (int i = 1; i < cities.size(); i++)
    {
        if (cities[i].getAvgDistEnemyBase() < min)
        {
            min = cities[i].getAvgDistEnemyBase();
            index = i;
        }
    }
    return index;
}
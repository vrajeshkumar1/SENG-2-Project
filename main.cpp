#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "City.h"
using namespace std;

int rows = 0;
City *cities = new City[100];

int menu();
void getRowInfo(istream &file, int rowAnalyzed, string (&infoHolder)[7]);
void printCities();
void addCity();
void adminDashboard();

int main()
{
    ifstream file("SENG2ExcelFile - Sheet1.csv");
    string line;

    while (getline(file, line))
    {
        rows++;
    }
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
    }
    cities[0].defineRiskFactor();

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

void printCities()
{
    cout<<"============================================================ Cities: "<< City::getNumCities()<<" ===================================================================================\n";
    cout << setw(20) << "City Name|" << setw(20) << "Population|" << setw(25) << "Avg Dist Enemy Base|" << setw(25) << "Avg Dist Friendly Base|" << setw(29) << "Est Enemy Infantry Power|" << setw(29) << "Est Friendly Infantry Power|" << setw(24) << "Political Interference|" << setw(15) << "Risk Factor|" << endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < rows - 1; i++)
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
        // As risk factor is scaled relatively, when cities are added or modified, it will be recalculated for all
        //I got rid of the loop because then I may as well do it for all inside the function instead of calling the function this many times here
        void addCity();
        cities[0].defineRiskFactor();
        break;
    case 2:
     // As risk factor is scaled relatively, when cities are added or modified, it will be recalculated for all
     //I got rid of the loop because then I may as well do it for all inside the function instead of calling the function this many times here
     cities[0].defineRiskFactor();
    case 3:

        break;
    }
}
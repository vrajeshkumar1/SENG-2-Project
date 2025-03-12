#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include "City.h"
using namespace std;

// ==================== Global Variables

int rows = 0;
vector<City*> cities; // we made cities a vector for scalability

string adminUsername = "admin";
string adminPassword = "1234";
bool adminLoggedIn = false;

// ==================== Function Prototypes

void menu();
void getRowInfo(istream &file, string (&infoHolder)[7]);
void printCities();
void addCity();
void deleteCity();
void modifyCity();
void printMostRiskyCity();
void adminDashboard();
void adminLogin();
int getclosestCityIndex(vector<City> &cities);

// ==================== Main Function

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

    getline(file, line);

    for (int i = 0; i < rows; i++)
    {
        getRowInfo(file, infoHolder);
        City* tempCity=new City;
        tempCity->setName(infoHolder[0]);
        tempCity->setPopulation(stoi(infoHolder[1]));
        tempCity->setAvgDistEnemyBase(stod(infoHolder[2]));
        tempCity->setAvgDistFriendlyBase(stod(infoHolder[3]));
        tempCity->setEstEnemyInfantryPower(stoi(infoHolder[4]));
        tempCity->setEstFriendlyInfantryPower(stoi(infoHolder[5]));
        cities.push_back(tempCity);
    }

    City::defineRiskFactor(cities);

    file.close();

    menu();

    return 0;
}

// ==================================== dashboards

void menu()
{
    int option;
    do
    {
        cout << "============ Menu ============\n1. Display Current Cities\n2. Most Risky City\n3. Admin Dashboard Login\n0. Exit\n\nOption: ";
        cin >> option;
        switch (option)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printCities();
            break;
        case 2:
            printMostRiskyCity();
            break;
        case 3:
            adminLogin();
            break;
        default:
            cout << "Invalid option\n";
            break;
        }
    } while (option != 0);
}

void adminLogin()
{
    if (adminLoggedIn)
    {
        cout << "You are already logged in\n";
        adminDashboard();
    }
    else
    {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (username == adminUsername && password == adminPassword)
        {
            cout << "Login successful\n";
            adminLoggedIn = true;
            adminDashboard();
        }
        else
        {
            cout << "Login failed\n";
            menu();
        }
    }
}

void adminDashboard()
{
    int option;
    do
    {
        cout << "============ !! Admin Dashboard !! ============\n1. Add City\n2. Modify City Information\n3. Delete City\n0. Return to Main Menu\n\nOption: ";
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            addCity();
            City::defineRiskFactor(cities);
            break;
        case 2:
            modifyCity();
            City::defineRiskFactor(cities);
            break;
        case 3:
            deleteCity();
            City::defineRiskFactor(cities);
            break;
        default:
            cout << "Invalid option\n";
            break;
        }
    } while (option != 0);
    menu();
}

// ================================= Printers

void printMostRiskyCity()
{
    double max = cities[0]->riskFactor;
    int index = 0;
    for (int i = 1; i < cities.size(); i++)
    {
        if (cities[i]->riskFactor > max)
        {
            max = cities[i]->riskFactor;
            index = i;
        }
    }
    cout << "\nMost Risky City: " << cities[index]->getName() << " with a risk factor of " << cities[index]->riskFactor << endl;
}

void printCities()
{
    cities[0]->defineRiskFactor(cities);
    cout << "============================================================ Cities: " << cities.size() << " ===================================================================================\n";
    cout << setw(20) << "City Name|" << setw(20) << "Population|" << setw(25) << "Avg Dist Enemy Base|" << setw(25) << "Avg Dist Friendly Base|" << setw(29) << "Est Enemy Infantry Power|" << setw(29) << "Est Friendly Infantry Power|"  << setw(15) << "Risk Factor|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < cities.size(); i++)
    {
        cout << setw(20) << cities[i]->getName() << setw(20) << cities[i]->getPopulation() << setw(25) << cities[i]->getAvgDistEnemyBase() << setw(25) << cities[i]->getAvgDistFriendlyBase() << setw(29) << cities[i]->getEstEnemyInfantryPower() << setw(29) << cities[i]->getEstFriendlyInfantryPower() << setw(15) << cities[i]->riskFactor << endl;
    }
}

// ================================= Manipulators

void addCity()
{
    string name;
    int population;
    double avgDistEnemyBase, avgDistFriendlyBase;
    int estEnemyInfantryPower, estFriendlyInfantryPower;

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

    City newCity(name, population, avgDistEnemyBase, avgDistFriendlyBase, estEnemyInfantryPower, estFriendlyInfantryPower);
    cities.push_back(&newCity);
    rows++;
}

void deleteCity()
{
    string name;
    cout << "\nEnter the name of the city you want to delete: ";
    cin >> name;
    for (int i = 0; i < cities.size(); i++)
    {
        if (cities[i]->getName() == name)
        {
            cities.erase(cities.begin() + i);
            cout << "City deleted successfully\n";
            return;
        }
    }
    cout << "City not found\n";
}

void modifyCity()
{
    string name;
    cout << "\nEnter the name of the city you want to modify: ";
    cin >> name;
    for (int i = 0; i < cities.size(); i++)
    {
        if (cities[i]->getName() == name)
        {
            int option;
            do
            {

                cout << "\n\n\n~~~~~~~~~ Modify City Information Panel: "<<cities[i]->getName()<<" ~~~~~~~~~\nPlease select the field you want to modify\n1. City Name\n2. Population\n3. Average Distance to Enemy Base\n4. Average Distance to Friendly Base\n5. Estimated Enemy Infantry Power\n6. Estimated Friendly Infantry Power\n7. All fields\n0. Exit\n\nOption: ";
                cin >> option;
                string input;
                switch (option)
                {
                case 0:
                    break;
                case 1:
                    cout << "Enter new City Name: ";
                    cin >> input;
                    cities[i]->setName(input);
                    break;
                case 2:
                    cout << "Enter new Population: ";
                    cin >> input;
                    cities[i]->setPopulation(stoi(input));
                    break;
                case 3:
                    cout << "Enter new Average Distance to Enemy Base: ";
                    cin >> input;
                    cities[i]->setAvgDistEnemyBase(stod(input));
                    break;
                case 4:
                    cout << "Enter new Average Distance to Friendly Base: ";
                    cin >> input;
                    cities[i]->setAvgDistFriendlyBase(stod(input));
                    break;
                case 5:
                    cout << "Enter new Estimated Enemy Infantry Power: ";
                    cin >> input;
                    cities[i]->setEstEnemyInfantryPower(stoi(input));
                    break;
                case 6:
                    cout << "Enter new Estimated Friendly Infantry Power: ";
                    cin >> input;
                    cities[i]->setEstFriendlyInfantryPower(stoi(input));
                    break;
                case 7:
                    cout << "Enter new City Name: ";
                    cin >> input;
                    cities[i]->setName(input);
                    cout << "Enter new Population: ";
                    cin >> input;
                    cities[i]->setPopulation(stoi(input));
                    cout << "Enter new Average Distance to Enemy Base: ";
                    cin >> input;
                    cities[i]->setAvgDistEnemyBase(stod(input));
                    cout << "Enter new Average Distance to Friendly Base: ";
                    cin >> input;
                    cities[i]->setAvgDistFriendlyBase(stod(input));
                    cout << "Enter new Estimated Enemy Infantry Power: ";
                    cin >> input;
                    cities[i]->setEstEnemyInfantryPower(stoi(input));
                    cout << "Enter new Estimated Friendly Infantry Power: ";
                    cin >> input;
                    cities[i]->setEstFriendlyInfantryPower(stoi(input));
                    cout << "City modified successfully\n";
                    break;
                default:
                    cout << "Invalid option\n";
                    break;
                }
            } while (option != 0);
            return;
        }
    }
    cout << "City not found\n";
}

// ==================================== Logic

void getRowInfo(istream &file, string (&infoHolder)[7])
{
    string line;
    getline(file, line);

    size_t pos = 0; // we used size_t because it is guaranteed to be able to hold the maximum size of a theoretically possible object of any type (including array)
    int cellIndex = 0;

    while ((pos = line.find(',')) != string::npos && cellIndex < 7)
    {
        infoHolder[cellIndex++] = line.substr(0, pos);
        line.erase(0, pos + 1); // erase the cell from the row to keep reading the next cell
    }
    if (cellIndex < 7)
    { // if there are less than 7 cells in the row
        infoHolder[cellIndex] = line;
    }
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
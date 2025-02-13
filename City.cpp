#include "City.h"
#include<string>
using namespace std;

int City::numCities = 0;

City::City()
{
    *(this->name) = "";
    *(this->population) = 0;
    *(this->avgDistEnemyBase) = 0;
    *(this->avgDistFriendlyBase) = 0;
    *(this->estEnemyInfantryPower) = 0;
    *(this->estFriendlyInfantryPower) = 0;
    *(this->politicalInterference) = 0;
    *(this->riskFactor) = 0;
    cities[numCities] = this;
    numCities++;
}

City::City(string name, int population, double avgDistEnemyBase, double avgDistFriendlyBase, int estEnemyInfantryPower, int estFriendlyInfantryPower, int politicalInterference)
{
    *(this->name) = name;
    *(this->population) = population;
    *(this->avgDistEnemyBase) = avgDistEnemyBase;
    *(this->avgDistFriendlyBase) = avgDistFriendlyBase;
    *(this->estEnemyInfantryPower) = estEnemyInfantryPower;
    *(this->estFriendlyInfantryPower) = estFriendlyInfantryPower;
    *(this->politicalInterference) = politicalInterference;
    *(this->riskFactor) = 0;
    numCities++;
}

string City::getName()
{
    return *name;
}

int City::getPopulation()
{
    return *population;
}

double City::getAvgDistEnemyBase()
{
    return *avgDistEnemyBase;
}

double City::getAvgDistFriendlyBase()
{
    return *avgDistFriendlyBase;
}

int City::getEstEnemyInfantryPower()
{
    return *estEnemyInfantryPower;
}

int City::getEstFriendlyInfantryPower()
{
    return *estFriendlyInfantryPower;
}

int City::getPoliticalInterference()
{
    return *politicalInterference;
}

double City::getRiskFactor()
{
    return *riskFactor;
}

void City::setName(string name)
{
    *(this->name) = name;
}

void City::setPopulation(int population)
{
    *(this->population) = population;
}

void City::setAvgDistEnemyBase(double avgDistEnemyBase)
{
    *(this->avgDistEnemyBase) = avgDistEnemyBase;
}

void City::setAvgDistFriendlyBase(double avgDistFriendlyBase)
{
    *(this->avgDistFriendlyBase) = avgDistFriendlyBase;
}

void City::setEstEnemyInfantryPower(int estEnemyInfantryPower)
{
    *(this->estEnemyInfantryPower) = estEnemyInfantryPower;
}

void City::setEstFriendlyInfantryPower(int estFriendlyInfantryPower)
{
    *(this->estFriendlyInfantryPower) = estFriendlyInfantryPower;
}

void City::setPoliticalInterference(int politicalInterference)
{
    *(this->politicalInterference) = politicalInterference;
}

void City::defineRiskFactor()
{
    *(this->riskFactor) = (*population * 0.35) - (*avgDistFriendlyBase * 0.65) - (*avgDistFriendlyBase * 0.65) + (*estEnemyInfantryPower * 0.5) - (*estFriendlyInfantryPower * 0.5) + (*politicalInterference * 0.2); // we have to define this function
}

City::~City()
{
    for(int i = 0; i < numCities; i++){
    if(cities[i] == this){
      for(int j = i; j < numCities; j++){
        cities[j] = cities[j+1];
      }
      break;
    }
    }
    numCities--;
}


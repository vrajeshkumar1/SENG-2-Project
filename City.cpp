#include "City.h"
using namespace std;

int City::numCities = 0;

City::City()
{
    *(this->population) = 0;
    *(this->avgDistEnemyBase) = 0;
    *(this->avgDistFriendlyBase) = 0;
    *(this->estEnemyInfantryPower) = 0;
    *(this->estFriendlyInfantryPower) = 0;
    *(this->politicalInterference) = 0;
    *(this->riskFactor) = 0;
    numCities++;
}

City::City(int* population, double* avgDistEnemyBase, double* avgDistFriendlyBase, int* estEnemyInfantryPower, int* estFriendlyInfantryPower, int* politicalInterference)
{
    *(this->population) = *population;
    *(this->avgDistEnemyBase) = *avgDistEnemyBase;
    *(this->avgDistFriendlyBase) = *avgDistFriendlyBase;
    *(this->estEnemyInfantryPower) = *estEnemyInfantryPower;
    *(this->estFriendlyInfantryPower) = *estFriendlyInfantryPower;
    *(this->politicalInterference) = *politicalInterference;
    *(this->riskFactor) = 0;
    numCities++;
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

void City::setPopulation(int* population)
{
    *(this->population) = *population;
}

void City::setAvgDistEnemyBase(double* avgDistEnemyBase)
{
    *(this->avgDistEnemyBase) = *avgDistEnemyBase;
}

void City::setAvgDistFriendlyBase(double* avgDistFriendlyBase)
{
    *(this->avgDistFriendlyBase) = *avgDistFriendlyBase;
}

void City::setEstEnemyInfantryPower(int* estEnemyInfantryPower)
{
    *(this->estEnemyInfantryPower) = *estEnemyInfantryPower;
}

void City::setEstFriendlyInfantryPower(int* estFriendlyInfantryPower)
{
    *(this->estFriendlyInfantryPower) = *estFriendlyInfantryPower;
}

void City::setPoliticalInterference(int* politicalInterference)
{
    *(this->politicalInterference) = *politicalInterference;
}

void City::defineRiskFactor()
{
    *(this->riskFactor) = 1; // we have to define this function
}

City::~City()
{
    numCities--;
}


#include "City.h"
#include<string>
using namespace std;

int City::numCities = 0;

//============================ CONSTRUCTORS

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
    this->factors={this->population,this->avgDistFriendlyBase,this->avgDistEnemyBase,this->estEnemyInfantryPower,this->estFriendlyInfantryPower,this->politicalInterference};
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
    this->factors={this->population,this->avgDistFriendlyBase,this->avgDistEnemyBase,this->estEnemyInfantryPower,this->estFriendlyInfantryPower,this->politicalInterference};
    *(this->riskFactor) = 0;
    cities[numCities] = this;
    numCities++;
}
 City::~City(){
   for(int i = 0; i < City::getNumCities(); i++){
     if(cities[i] == this){
       for(int j = i; j < (cities[i]->getNumCities()-1); j++){
       cities[j] = cities[j+1];
       }
       cities[numCities] = NULL;
       numCities--;
       return;
       }
     }
 }

//============================ GETTERS

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

int City::getNumCities()
{
    return numCities;
}

//============================ SETTERS

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
     float weights[6]={0.35,-0.65,0.65,0.5,-0.5,0.2};
     float scaledValues[this->getNumCities()][6];
     float temp[this->getNumCities()];
     for (int i = 0; i < 6; i++){
       for(int j=0; j<this->getNumCities(); j++){
         temp[j]=cities[j]->factors[i];
     }

     }
     this->riskFactor = 0;
     for (int i = 0; i < 6; i++){
       *(this->riskFactor) += (scaledValues[i] * weights[i]);
     }
}

//============================ DESTRUCTOR

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


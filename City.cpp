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
    this->factors[0]=*(this->population);
    this->factors[1]=*(this->avgDistFriendlyBase);
    this->factors[2]=*this->avgDistEnemyBase;
    this->factors[3]=*this->estEnemyInfantryPower;
    this->factors[4]=*this->estFriendlyInfantryPower;
    this->factors[5]=*this->politicalInterference;
    cities[numCities] = this;
    this->SerialNum=numCities;
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
    this->factors[0]=*(this->population);
    this->factors[1]=*(this->avgDistFriendlyBase);
    this->factors[2]=*this->avgDistEnemyBase;
    this->factors[3]=*this->estEnemyInfantryPower;
    this->factors[4]=*this->estFriendlyInfantryPower;
    this->factors[5]=*this->politicalInterference;
    *(this->riskFactor) = 0;
    cities[numCities] = this;
    this->SerialNum=numCities;
    numCities++;
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
int City::getSerialNum() {
    return SerialNum;
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
void City::setSerialNum(int SerialNum){
    this->SerialNum = SerialNum;
}

void City::defineRiskFactor()
{
     float weights[6]={0.35,-0.65,0.65,0.5,-0.5,0.2};
     float scaledValues[this->getNumCities()][6];
     float temp[this->getNumCities()];
     float maxTemp;
     float minTemp;
     for (int i = 0; i < 6; i++){
       for(int j=0; j<this->getNumCities(); j++){
         temp[j]=cities[j]->factors[i];
     }
         maxTemp=temp[0];
         minTemp=temp[0];
         for(int j=0; j<this->getNumCities(); j++){
           if(temp[j]>maxTemp){
             maxTemp=temp[j];
           }
           if(temp[j]<minTemp){
             minTemp=temp[j];
           }
         }
         if(i!=1&&i!=2){
            for(int j=0; j<this->getNumCities(); j++){
                scaledValues[j][i]=(temp[j]-minTemp)/(maxTemp-minTemp);
            }
        }
        else{
            for(int j=0; j<this->getNumCities(); j++){
                scaledValues[j][i]=(maxTemp-temp[j])/(maxTemp-minTemp);
            }
        }
     }
    for (int j = 0; j < this->getNumCities(); j++){
     this->cities[j]->riskFactor = 0;
     }
     for (int j = 0; j < this->getNumCities(); j++){
     for (int i = 0; i < 6; i++){
       *(this->cities[j]->riskFactor) += (scaledValues[j][i] * weights[i]);
     }
     }
}

//============================ DESTRUCTOR

City::~City()
    {
    for(int i = this->getSerialNum(); i < (City::getNumCities()-1); i++){
      cities[i]=cities[i+1];
      cities[i]->setSerialNum(i);
    }
    cities[City::getNumCities()] = NULL;
    numCities--;
}


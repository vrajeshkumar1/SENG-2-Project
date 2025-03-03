#include "City.h"
#include<string>
using namespace std;

int City::numCities = 0;
City* City::cities[100] = {nullptr};

//============================ CONSTRUCTORS

City::City()
{
    this->name = "";
    this->population = 0;
    this->avgDistEnemyBase = 0;
    this->avgDistFriendlyBase = 0;
    this->estEnemyInfantryPower = 0;
    this->estFriendlyInfantryPower = 0;
    this->politicalInterference = 0;
    this->riskFactor = 0;
    this->factors[0]=this->population;
    this->factors[1]=this->avgDistFriendlyBase;
    this->factors[2]=this->avgDistEnemyBase;
    this->factors[3]=this->estEnemyInfantryPower;
    this->factors[4]=this->estFriendlyInfantryPower;
    this->factors[5]=this->politicalInterference;
    this->cities[this->numCities] = this;
    this->SerialNum=this->numCities;
    (this->numCities)++;
}

City::City(string name, int population, double avgDistEnemyBase, double avgDistFriendlyBase, int estEnemyInfantryPower, int estFriendlyInfantryPower, int politicalInterference)
{
    this->name = name;
    this->population = population;
    this->avgDistEnemyBase = avgDistEnemyBase;
    this->avgDistFriendlyBase = avgDistFriendlyBase;
    this->estEnemyInfantryPower = estEnemyInfantryPower;
    this->estFriendlyInfantryPower = estFriendlyInfantryPower;
    this->politicalInterference = politicalInterference;
    this->factors[0]=this->population;
    this->factors[1]=this->avgDistFriendlyBase;
    this->factors[2]=this->avgDistEnemyBase;
    this->factors[3]=this->estEnemyInfantryPower;
    this->factors[4]=this->estFriendlyInfantryPower;
    this->factors[5]=this->politicalInterference;
    this->riskFactor = 0;
    this->cities[this->numCities] = this;
    this->SerialNum=this->numCities;
    (this->numCities)++;
}
//============================ GETTERS

string City::getName()
{
    return name;
}

int City::getPopulation()
{
    return population;
}

double City::getAvgDistEnemyBase()
{
    return avgDistEnemyBase;
}

double City::getAvgDistFriendlyBase()
{
    return avgDistFriendlyBase;
}

int City::getEstEnemyInfantryPower()
{
    return estEnemyInfantryPower;
}

int City::getEstFriendlyInfantryPower()
{
    return estFriendlyInfantryPower;
}

int City::getPoliticalInterference()
{
    return politicalInterference;
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
    this->name = name;
}

void City::setPopulation(int population)
{
    this->population = population;
}

void City::setAvgDistEnemyBase(double avgDistEnemyBase)
{
    this->avgDistEnemyBase = avgDistEnemyBase;
}

void City::setAvgDistFriendlyBase(double avgDistFriendlyBase)
{
    this->avgDistFriendlyBase = avgDistFriendlyBase;
}

void City::setEstEnemyInfantryPower(int estEnemyInfantryPower)
{
    this->estEnemyInfantryPower = estEnemyInfantryPower;
}

void City::setEstFriendlyInfantryPower(int estFriendlyInfantryPower)
{
    this->estFriendlyInfantryPower = estFriendlyInfantryPower;
}

void City::setPoliticalInterference(int politicalInterference)
{
    this->politicalInterference = politicalInterference;
}
void City::setSerialNum(int SerialNum){
    this->SerialNum = SerialNum;
}

void City::defineRiskFactor()
{
     double weights[6]={0.35,-0.65,0.65,0.5,-0.5,0.2};
     double scaledValues[this->getNumCities()][6];
     double temp[this->getNumCities()];
     double maxTemp;
     double minTemp;
     for (int i = 0; i < 6; i++){
       for(int j=0; j<this->getNumCities(); j++){
         temp[j]=this->cities[j]->factors[i];
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
       this->cities[j]->riskFactor += (scaledValues[j][i] * weights[i]);
     }
     }
}

void City::addCity(string name, int population, double avgDistEnemyBase, double avgDistFriendlyBase, int estEnemyInfantryPower, int estFriendlyInfantryPower, int politicalInterference)
{
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
}

//============================ DESTRUCTOR

City::~City()
    {
    for(int i = this->getSerialNum(); i < (City::getNumCities()-1); i++){
      this->cities[i]=this->cities[i+1];
      this->cities[i]->setSerialNum(i);
    }
    this->cities[City::getNumCities()] = NULL;
    this->numCities--;
}


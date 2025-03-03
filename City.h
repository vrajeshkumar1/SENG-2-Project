#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City
{
    private:
        string name;
        int population;
        double avgDistEnemyBase;
        double avgDistFriendlyBase;
        int estEnemyInfantryPower;
        int estFriendlyInfantryPower;
        int politicalInterference;
        int SerialNum;
        static int numCities;
    public:
        double factors[6];
        static City* cities[100];
        double riskFactor;
        City();
        City(string name, int population, double avgDistEnemyBase, double avgDistFriendlyBase, int estEnemyInfantryPower, int estFriendlyInfantryPower, int politicalInterference);
        string getName();
        int getPopulation();
        double getAvgDistEnemyBase();
        double getAvgDistFriendlyBase();
        int getEstEnemyInfantryPower();
        int getEstFriendlyInfantryPower();
        int getPoliticalInterference();
        static int getNumCities();
        int getSerialNum();
        void setSerialNum(int serialNum);
        void setName(string name);
        void setPopulation(int population);
        void setAvgDistEnemyBase(double avgDistEnemyBase);
        void setAvgDistFriendlyBase(double avgDistFriendlyBase);
        void setEstEnemyInfantryPower(int estEnemyInfantryPower);
        void setEstFriendlyInfantryPower(int estFriendlyInfantryPower);
        void setPoliticalInterference(int politicalInterference);
        void defineRiskFactor();
        void addCity(string name, int population, double avgDistEnemyBase, double avgDistFriendlyBase, int estEnemyInfantryPower, int estFriendlyInfantryPower, int politicalInterference);
        ~City();
};

#endif
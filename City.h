#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City
{
    private:
        string* name = new string;
        int* population = new int;
        double* avgDistEnemyBase = new double;
        double* avgDistFriendlyBase = new double;
        int* estEnemyInfantryPower = new int;
        int* estFriendlyInfantryPower = new int;
        int* politicalInterference = new int;
        double factors[6];
        int SerialNum;
        static City* cities[];
        static int numCities;
    public:
        double* riskFactor = new double;
        City();
        City(string name, int population, double avgDistEnemyBase, double avgDistFriendlyBase, int estEnemyInfantryPower, int estFriendlyInfantryPower, int politicalInterference);
        string getName();
        int getPopulation();
        double getAvgDistEnemyBase();
        double getAvgDistFriendlyBase();
        int getEstEnemyInfantryPower();
        int getEstFriendlyInfantryPower();
        int getPoliticalInterference();
        double getRiskFactor();
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
        void setRiskFactor(double riskFactor);
        void defineRiskFactor();
        ~City();
};

#endif
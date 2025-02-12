#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "City.h"
using namespace std;

void getRowInfo( istream& file, int rowAnalyzed, string (&infoHolder)[7]){
    string line;

    file.clear();
    file.seekg(0, ios::beg); //move read pointer to the beginning of the file

    for (int i=1; i<=rowAnalyzed; i++){
        getline(file, line); // find row to analyze
    }

    size_t pos = 0;
    int cellIndex = 0;

    while ((pos = line.find(',')) != string::npos && cellIndex < 7){
        infoHolder[cellIndex++] = line.substr(0, pos);
        line.erase(0, pos + 1);
    }
    if (cellIndex < 7){ // if there are less than 6 cells in the row
        infoHolder[cellIndex] = line;
    }
}


int main(){

    int rows = 0;
    ifstream file("SENG2ExcelFile - Sheet1.csv");
    string line;

    while (getline(file, line)){
        rows++;
    }

    City* cities = new City[rows-1];

    string infoHolder[7];

    for (int i=2; i<=rows; i++){
        getRowInfo(file, i, infoHolder);
        cities[i-2].setName(&infoHolder[0]);
        cities[i-2].setPopulation();
        cities[i-2].setArea(stoi(infoHolder[2]));
        cities[i-2].setDensity(stoi(infoHolder[3]));
    }

    file.close();

    delete [] cities;

    return 0;
}
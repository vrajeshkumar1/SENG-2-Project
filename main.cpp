#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "City.h"
using namespace std;

int main(){

    int rows = 0;
    ifstream file("SENG2ExcelFile - Sheet1.csv");
    string line;

    while (getline(file, line)){
        rows++;
    }

    City* cities = new City[rows-1];

    file.close();
    

    return 0;
}
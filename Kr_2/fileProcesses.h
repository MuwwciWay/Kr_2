#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory> 
#include "Classes.h" 

using namespace std;

vector<unique_ptr<Vehicle>> fromFile(const string& fileName);
void fileProcessing(vector<unique_ptr<Vehicle>>& vehicles);
bool saveInFile(const vector<unique_ptr<Vehicle>>& vehicles);

#pragma once
#include "Classes.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory> 

using namespace std;

void consoleProcesses(vector<unique_ptr<Vehicle>>& vehicles);
void printToConsole(const vector<unique_ptr<Vehicle>>& vehicles);
#pragma once

#include "consoleProcesses.h"
#include "Classes.h"
#include "ifInt.h"

using namespace std;
enum{ one = 1, two = 2};
void consoleProcesses(vector<unique_ptr<Vehicle>>& vehicles) {
    int choice, choice2 = 1;
    do {
        cout << "¬ведите тим транспортного средства: " << endl
            << "[1] -  военный самолет" << endl
            << "[2] - транспортный самолет." << endl;
        cin >> choice;

        double weight, enginePower, speed;
        string type, weaponType;
        int cargoCapacity;

        switch (choice) {
        case one:
            cout << "¬ведите вес: ";
            cin >> weight;
            cout << "¬ведите мощность двигател€: ";
            cin >> enginePower;
            cout << "¬ведите скорость: ";
            cin >> speed;
            cout << "¬ведите мощность мотора: ";
            cin >> type;
            cout << "¬ведите тип оружи€: ";
            cin >> weaponType;
            vehicles.push_back(make_unique<MilitaryAirplane>(weight, enginePower, speed, type, weaponType));

            break;
        case two:
            cout << "¬ведите вес: ";
            cin >> weight;
            cout << "¬ведите мощность мотора: ";
            cin >> enginePower;
            cout << "¬ведите скорость: ";
            cin >> speed;
            cout << "¬ведите мощность мотора: ";
            cin >> type;
            cout << "¬ведите грузоподъемность: ";
            cin >> cargoCapacity;
            vehicles.push_back(make_unique<TransportAirplane>(weight, enginePower, speed, type, cargoCapacity));
            break;
        default:
            cout << "Ќет такого варианта!\n";
            break;
        }

        cout << "’отите добавить еще один самолет?: " << endl
            << "[1] - да" << endl
            << "[2] - нет" << endl;
        cin >> choice2;
    } while (choice2 == 1);
}


void printToConsole(const vector<unique_ptr<Vehicle>>& vehicles) {
    if (vehicles.empty()) {
        cout << "—писок транспортных средств пуст." << endl;
        return;
    }

    cout << "—писок транспортных средств:" << endl;
    cout << "-----------------" << endl;
    for (const auto& vehicle : vehicles) {
        vehicle->display();
        cout << "-----------------" << endl;
    }
}



#pragma once

#include "consoleProcesses.h"
#include "Classes.h"
#include "ifInt.h"

using namespace std;
enum{ one = 1, two = 2};
void consoleProcesses(vector<unique_ptr<Vehicle>>& vehicles) {
    int choice, choice2 = 1;
    do {
        cout << "������� ��� ������������� ��������: " << endl
            << "[1] -  ������� �������" << endl
            << "[2] - ������������ �������." << endl;
        cin >> choice;

        double weight, enginePower, speed;
        string type, weaponType;
        int cargoCapacity;

        switch (choice) {
        case one:
            cout << "������� ���: ";
            cin >> weight;
            cout << "������� �������� ���������: ";
            cin >> enginePower;
            cout << "������� ��������: ";
            cin >> speed;
            cout << "������� �������� ������: ";
            cin >> type;
            cout << "������� ��� ������: ";
            cin >> weaponType;
            vehicles.push_back(make_unique<MilitaryAirplane>(weight, enginePower, speed, type, weaponType));

            break;
        case two:
            cout << "������� ���: ";
            cin >> weight;
            cout << "������� �������� ������: ";
            cin >> enginePower;
            cout << "������� ��������: ";
            cin >> speed;
            cout << "������� �������� ������: ";
            cin >> type;
            cout << "������� ����������������: ";
            cin >> cargoCapacity;
            vehicles.push_back(make_unique<TransportAirplane>(weight, enginePower, speed, type, cargoCapacity));
            break;
        default:
            cout << "��� ������ ��������!\n";
            break;
        }

        cout << "������ �������� ��� ���� �������?: " << endl
            << "[1] - ��" << endl
            << "[2] - ���" << endl;
        cin >> choice2;
    } while (choice2 == 1);
}


void printToConsole(const vector<unique_ptr<Vehicle>>& vehicles) {
    if (vehicles.empty()) {
        cout << "������ ������������ ������� ����." << endl;
        return;
    }

    cout << "������ ������������ �������:" << endl;
    cout << "-----------------" << endl;
    for (const auto& vehicle : vehicles) {
        vehicle->display();
        cout << "-----------------" << endl;
    }
}



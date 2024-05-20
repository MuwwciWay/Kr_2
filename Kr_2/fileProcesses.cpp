#pragma once
#include "fileProcesses.h"

vector<unique_ptr<Vehicle>> fromFile(const string& fileName) {
    vector<unique_ptr<Vehicle>> vehicles;

    ifstream from_file(fileName);
    if (!from_file.is_open()) {
        cerr << "������ �������� �����: " << fileName << endl;
        return vehicles;
    }

    string type;
    double weight, enginePower, speed;
    string weaponType;
    int cargoCapacity;

    while (from_file >> type) {
        if (type == "Airplane") {
            from_file >> weight >> enginePower >> speed >> type;
            vehicles.push_back(make_unique<Airplane>(weight, enginePower, speed, type));
        }
        else if (type == "MilitaryAirplane") {
            from_file >> weight >> enginePower >> speed >> type >> weaponType;
            vehicles.push_back(make_unique<MilitaryAirplane>(weight, enginePower, speed, type, weaponType));
        }
        else if (type == "TransportAirplane") {
            from_file >> weight >> enginePower >> speed >> type >> cargoCapacity;
            vehicles.push_back(make_unique<TransportAirplane>(weight, enginePower, speed, type, cargoCapacity));
        }
        else {
            cerr << "������ ������ ������ �� �����! ����������� ��� ������������� ��������: " << type << endl;
            break;
        }
    }

    if (from_file.eof()) {
        cout << "������ ������� ��������� �� �����." << endl;
    }
    else {
        cerr << "������ ������ ������ �� �����!" << endl;
    }

    from_file.close();
    return vehicles;
}



void fileProcessing(vector<unique_ptr<Vehicle>>& vehicles) {
    string fileName{};
    bool flag = false;
    do {
        cout << "������� ��� �����, �� �������� ������ ����� ������: ";
        cin >> fileName;

        ifstream file(fileName);
        if (file.is_open()) {
            vehicles = fromFile(fileName);
            flag = true;
            file.close();
        }
        else {
            cerr << "���� � ����� ������ �� ������!" << endl;
            cin.clear();
        }
    } while (!flag);
}


// ������� ��� ���������� ������ � ��������� � ����
bool saveInFile(const vector<unique_ptr<Vehicle>>& vehicles) {

    string fileName{};
    cout << "������� �������� �����: ";
    cin >> fileName;
    ofstream outfile(fileName);
    if (!outfile.is_open()) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return false;
    }

    for (const auto& vehicle : vehicles) {
        if (dynamic_cast<Airplane*>(vehicle.get())) {
            const Airplane* airplane = dynamic_cast<Airplane*>(vehicle.get());
            if (airplane) {
                outfile << "Airplane " << airplane->getWeight() << " " << airplane->getEnginePower() << " "
                    << airplane->getSpeed() << " " << airplane->getType() << endl;
            }
        }
        else if (dynamic_cast<MilitaryAirplane*>(vehicle.get())) {
            const MilitaryAirplane* militaryAirplane = dynamic_cast<MilitaryAirplane*>(vehicle.get());
            if (militaryAirplane) {
                outfile << "MilitaryAirplane " << militaryAirplane->getWeight() << " " << militaryAirplane->getEnginePower() << " "
                    << militaryAirplane->getSpeed() << " " << militaryAirplane->getType() << " " << militaryAirplane->getWeaponType() << endl;
            }
        }
        else if (dynamic_cast<TransportAirplane*>(vehicle.get())) {
            const TransportAirplane* transportAirplane = dynamic_cast<TransportAirplane*>(vehicle.get());
            if (transportAirplane) {
                outfile << "TransportAirplane " << transportAirplane->getWeight() << " " << transportAirplane->getEnginePower() << " "
                    << transportAirplane->getSpeed() << " " << transportAirplane->getType() << " " << transportAirplane->getCargoCapacity() << endl;
            }
        }
        else {
            cerr << "������ ��� ������ ������ � ����! ����������� ��� ������������� ��������." << endl;
            outfile.close();
            return false;
        }
    }

    outfile.close();
    cout << "������ ������� ��������� � ����: " << fileName << endl;
    return true;
}

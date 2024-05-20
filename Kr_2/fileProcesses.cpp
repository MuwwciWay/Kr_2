#pragma once
#include "fileProcesses.h"

vector<unique_ptr<Vehicle>> fromFile(const string& fileName) {
    vector<unique_ptr<Vehicle>> vehicles;

    ifstream from_file(fileName);
    if (!from_file.is_open()) {
        cerr << "Ошибка открытия файла: " << fileName << endl;
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
            cerr << "Ошибка чтения данных из файла! Неизвестный тип транспортного средства: " << type << endl;
            break;
        }
    }

    if (from_file.eof()) {
        cout << "Данные успешно загружены из файла." << endl;
    }
    else {
        cerr << "Ошибка чтения данных из файла!" << endl;
    }

    from_file.close();
    return vehicles;
}



void fileProcessing(vector<unique_ptr<Vehicle>>& vehicles) {
    string fileName{};
    bool flag = false;
    do {
        cout << "Введите имя файла, из которого хотите взять данные: ";
        cin >> fileName;

        ifstream file(fileName);
        if (file.is_open()) {
            vehicles = fromFile(fileName);
            flag = true;
            file.close();
        }
        else {
            cerr << "Файл с таким именем не найден!" << endl;
            cin.clear();
        }
    } while (!flag);
}


// Функция для сохранения данных о продуктах в файл
bool saveInFile(const vector<unique_ptr<Vehicle>>& vehicles) {

    string fileName{};
    cout << "Введите название файла: ";
    cin >> fileName;
    ofstream outfile(fileName);
    if (!outfile.is_open()) {
        cerr << "Ошибка открытия файла для записи!" << endl;
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
            cerr << "Ошибка при записи данных в файл! Неизвестный тип транспортного средства." << endl;
            outfile.close();
            return false;
        }
    }

    outfile.close();
    cout << "Данные успешно сохранены в файл: " << fileName << endl;
    return true;
}

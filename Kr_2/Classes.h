#pragma once

#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    double weight;
    double enginePower;
    double speed;

public:
    Vehicle(double w, double p, double s) : weight(w), enginePower(p), speed(s) {}

    virtual ~Vehicle() {}

    virtual void display() const {
        cout << "���: " << weight << " ��\n";
        cout << "�������� ���������: " << enginePower << " ��\n";
        cout << "��������: " << speed << " ��/�\n";
    }

    double getWeight() const {
        return weight;
    }

    double getEnginePower() const {
        return enginePower;
    }

    double getSpeed() const {
        return speed;
    }
};

class Airplane : public Vehicle {
protected:
    string type;

public:
    Airplane(double w, double p, double s, const string& t) : Vehicle(w, p, s), type(t) {}

    void display() const override {
        cout << "--- ������� ---\n";
        Vehicle::display();
        cout << "���: " << type << "\n";
    }

    string getType() const {
        return type;
    }
};

class MilitaryAirplane : public Airplane {
private:
    string weaponType;

public:
    MilitaryAirplane(double w, double p, double s, const string& t, const string& wt)
        : Airplane(w, p, s, t), weaponType(wt) {}

    void display() const override {
        cout << "--- ������� ������� ---\n";
        Airplane::display();
        cout << "��� ������: " << weaponType << "\n";
    }

    string getWeaponType() const {
        return weaponType;
    }
};

class TransportAirplane : public Airplane {
private:
    int cargoCapacity;

public:
    TransportAirplane(double w, double p, double s, const string& t, int capacity)
        : Airplane(w, p, s, t), cargoCapacity(capacity) {}

    void display() const override {
        cout << "--- ������������ ������� ---\n";
        Airplane::display();
        cout << "����������������: " << cargoCapacity << " ��\n";
    }

    int getCargoCapacity() const {
        return cargoCapacity;
    }
};
    
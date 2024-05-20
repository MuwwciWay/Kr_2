#pragma once

#include "ifInt.h"

using namespace std;

int getMenuVar(int exitp, int ModuleTest) {
    int choice;
    bool flag = false;
    do {
        cout << "������� ����� ����: " << endl;
        cin >> choice;

        if (cin.peek() != '\n') {
            cout << "������� ���� ����� �����." << endl;
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        else if (choice >= exitp && choice <= ModuleTest) {
            flag = true;
        }

        else {
            cout << "������� ������ ��� � ����!" << endl;
        }

    } while (!flag);
    return choice;
}

int getPosInt() {
    int number = 0;
    string input;

    while (cin.get() != '\n') {
        continue;
    }

    do {
        cout << "������� ������������� ����� �����: ";
        getline(cin, input);

        try {
            number = stoi(input);

            if (number <= 0) {
                cout << "������: ������� �� ������������� �����!" << endl;
            }
        }
        catch (invalid_argument&) {
            cout << "������: ������� �� ����� �����!" << endl;
        }
        catch (range_error&) {
            cout << "������: ������� ������� ������� �����!" << endl;
        }

        if (number > 0) {
            break;
        }

        cin.clear();
        while (cin.get() != '\n') {
            continue;
        }
    } while (true); 

    return number;
}
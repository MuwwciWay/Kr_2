#pragma once

#include "ifInt.h"

using namespace std;

int getMenuVar(int exitp, int ModuleTest) {
    int choice;
    bool flag = false;
    do {
        cout << "Введите пункт меню: " << endl;
        cin >> choice;

        if (cin.peek() != '\n') {
            cout << "Введите одно целое число." << endl;
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        else if (choice >= exitp && choice <= ModuleTest) {
            flag = true;
        }

        else {
            cout << "Данного пункта нет в меню!" << endl;
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
        cout << "Введите положительное целое число: ";
        getline(cin, input);

        try {
            number = stoi(input);

            if (number <= 0) {
                cout << "Ошибка: Введено не положительное число!" << endl;
            }
        }
        catch (invalid_argument&) {
            cout << "Ошибка: Введено не целое число!" << endl;
        }
        catch (range_error&) {
            cout << "Ошибка: Введено слишком большое число!" << endl;
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
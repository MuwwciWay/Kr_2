#include <crtdbg.h>

#include <iostream>
#include <vector>
#include <windows.h>
#include <memory>

#include "ifInt.h"
#include "fileProcesses.h"
#include "consoleProcesses.h"


using namespace std;

enum { takeFile = 1, enterConsole = 2, moduleTest = 3, exitp = 0 };
enum { sortName = 1, sortPrice = 2, sortShelfLife = 3, extp = 0 };
enum { inFile = 1, inConsole = 2, back = 3 };

void outGretting() {
    cout << "Добро пожаловать в програмную реализацию Контрольной работы №1" << endl;
    cout << "Лабораторную работу выполнила: Васильченко Мария Сергеевна, 4306 группа, 7 вариант" << endl << endl;
    cout << "Контрольная работа № 2.  Наследование." << endl;
    cout << "Базовый класс – средство передвижения." << endl
        << "Поля в нем: вес, мощность мотора, скорость." << endl
        << "Производный класс – самолет;" << endl
        << "Производный класс второго поколения – военный самолет, транспортный самолет" << endl
        << "В производный класс первого поколения добавленое поле 'тип' самолета," << endl
        << "В производный класс второго поколения добавленое поле 'грузоподъемность' и 'тип оружия'." << endl;

}
void printInputWays() {

    cout << "-----..........-----..........-----..........-----" << endl;
    cout << "Пожалуйста выберете, как вы бы хотели заполнить данные или вы хотите запустить модульные тесты ?" << endl;
    cout << "Используйте пункты меню для навигации в программе, нажмите :" << endl;
    cout << "[1] - если хотите взять данные из файла" << endl;
    cout << "[2] - если хотите ввести данные в консоли" << endl;
    cout << "[3] - если хотите запустить модульные тесты" << endl;
    cout << "[0] - если хотите выйти! до свидания!" << endl << endl;
}


void printOutputWays() {
    cout << "-----..........-----..........-----..........-----" << endl;
    cout << "Пожалуйста выберете, как вы хотите получить список ?" << endl;
    cout << "Используйте пункты меню для навигации в программе, нажмите :" << endl;
    cout << "[1] - если хотите вывести данные в файл" << endl;
    cout << "[2] - если хотите вывести данные в консоль" << endl;
}

void launchMenu() {
    int variant = 0;
    vector<unique_ptr<Vehicle>> vehicles;
    vector<unique_ptr<Airplane>> airplanes;
    bool flag = false;
    do {
        printInputWays();
        variant = getMenuVar(exitp, moduleTest);


        switch (variant) {
        case(exitp):
            cout << "До свидания!" << endl;
            break;

        case(takeFile):
            fileProcessing(vehicles);
            break;

        case(enterConsole):
            consoleProcesses(vehicles);
            break;

        case(moduleTest):
            cout << "Tests()";
            break;
        }


        printOutputWays();

        variant = getMenuVar(exitp, moduleTest);
        switch (variant) {
        case(inFile):
            saveInFile(vehicles);
            break;

        case(inConsole):
            printToConsole(vehicles);
            break;
        }
        
    } while (!flag);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    outGretting();
    launchMenu();

    _CrtDumpMemoryLeaks();
    return 0;
}
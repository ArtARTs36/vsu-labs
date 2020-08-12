#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include "Person.cpp"
#include "Realist.cpp"
#include "Formalist.cpp"
#include "NoFormalist.cpp"
#include "PersonBuilder.cpp"
#include <ctime>

/** Сколько создавать человек **/
#define DEFAULT_COUNT_PERSONS 5

int getCountPersons(int, char**);
int** create2array(int, int);

using namespace std;

int main(int argc, char* argv[]) {
    int i, j = 0;

    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    srand(time(0));

    //

    int countPersons = getCountPersons(argc, argv);

    Person* persons[countPersons];
    PersonBuilder* builder = new PersonBuilder();

    cout << "- - Рассказы о себе: " << endl;

    for (i = 0; i < countPersons; i++) {
        persons[i] = builder->build();

        cout << endl;

        persons[i]->about();
    }

    cout << endl << endl << "- - Диалоги: " << endl;

    int** conversations;
    conversations = create2array(countPersons, countPersons);

    for (int i = 0; i < countPersons; i++) {
        for (int j = 0; j < countPersons; j++) {
            if (i == j || conversations[i][j] > 0) {
                continue;
            }

            cout << endl;

            persons[i]->fullHello(persons[j]);

            cout << endl;

            persons[j]->fullHello(persons[i]);

            conversations[i][j]++;
            conversations[j][i]++;
        }

        cout << endl;
    }

    //

    getch();

    return 0;
}

int getCountPersons(int argc, char** argv)
{
    if (argc == 2) {
        return atoi(argv[1]);
    }

    return DEFAULT_COUNT_PERSONS;
}

int** create2array(int count1, int count2)
{
    int **arr = new int *[count1];

    for (int i = 0; i < count1; i++) {
        arr[i] = new int[count2];

        for (int j = 0; j < count2; j++) {
            arr[i][j] = 0;
        }
    }

    return arr;
}
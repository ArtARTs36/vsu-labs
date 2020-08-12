// 8. Задана матрица размера n x n. Отсортировать столбцы матрицы в алфавитном порядке самых молодых сотрудников в столбцах

#include <iostream>
#include <iomanip>
#include <cstdlib> // содержит srand() и rand()
#include <string.h>

using namespace std;

struct Worker {
    int year;
    char family[15];
    long int experience;
};

void setInfo(Worker **, const int);
void print(Worker **, int);
void printResult(Worker **, int);
void makeSort(Worker **, int n);
void Shell(Worker **, int n);
void swapCol(Worker **, int, int, int n);

int Ord (char x) {

    return (int) x;

}

int ordFamily (char* x) {

    int summ = 0, i;

    for (i = 0; i < 5; i++) {

        summ = (summ * 10) + Ord (x[i]);

    }

    return summ;

}

int main() {

    int n;

    cout << "Введите размер матрицы: ";
    cin >> n;

    Worker **matrix = new Worker*[n + 1];

    for (int i = 0; i < n + 1; i++)
        matrix[i] = new Worker[n];

    setInfo(matrix, n);

    for (int i = 0; i < (n + 2) * 15; i++)
        cout << "_";

    cout << endl;

    makeSort(matrix, n);

    printResult(matrix, n);

    for (int i = 0; i < (n + 1) * 15; i++)
        cout << "_";

    cout << endl << "Результат: " << endl;

    Shell(matrix, n);

    printResult(matrix, n);

    return 0;
}

void setInfo(Worker **matrix, const int n) {

    srand(time(NULL));
    char familys[][15] = { "Abramov", "Avdeev", "Agafonov", "Aksyonov", "Aleksandrov", "Alekseev", "Andreev", "Anisimov", "Antonov", "Artemev", "Arhipov", "Afanasev",
                           "Baranov", "Belov", "Belozyorov", "Belousov", "Belyaev", "Belyakov", "Bespalov", "Biryukov", "Blinov", "Blohin", "Bobrov", "Bobylyov", "Bogdanov", "Bolshakov", "Borisov", "Bragin", "Burov", "Bykov",
                           "Vasilev", "Veselov", "Vinogradov", "Vishnyakov", "Vladimirov", "Vlasov", "Volkov", "Vorobyov", "Voronov", "Voroncov",
                           "Gavrilov", "Galkin", "Gerasimov", "Golubev", "Gorbachyov", "Gorbunov", "Gordeev", "Gorshkov", "Grigorev", "Grishin", "Gromov", "Gulyaev", "Gurev", "Gusev", "Gushchin",
                           "Davydov", "Danilov", "Dementev", "Denisov", "Dmitriev", "Doronin", "Dorofeev", "Drozdov", "Dyachkov",
                           "Evdokimov", "Evs eev", "Egorov", "Eliseev", "Emelyanov", "Ermakov", "Ershov", "Efimov", "Efremov",
                           "Zhdanov", "Zhukov", "Zhuravlev", "Zajcev", "Zaharov" };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j].year = 1925 + rand() % 85;
            strcpy(matrix[i][j].family, familys[0 + rand() % 78]);
            matrix[i][j].experience = 0 + rand() % 25;
        }
    }

}

void print(Worker **matrix, int n) {
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(25) << "Год: ";

        for (int j = 0; j < n; j++)
            cout << setw(15) << left << matrix[i][j].year;

        cout << endl << setw(25) << "Фамилия: ";

        for (int j = 0; j < n; j++)
            cout << setw(15) << left << matrix[i][j].family;

        cout << endl << setw(25) << "Стаж: ";

        for (int j = 0; j < n; j++)
            cout << setw(15) << left << matrix[i][j].experience;

        cout << endl << endl;
    }
}

void printResult(Worker **matrix, int n) {
    for (int i = 0; i < n + 1; i++)
    {

        if (i == n) {

            for (int i = 0; i < (n + 2) * 15; i++)
                cout << "_";

            cout << endl << endl << "Самые молодые в столбцах" << endl << endl;

            for (int i = 0; i < (n + 2) * 15; i++)
                cout << "_";

            cout << endl;

        }

        cout << left << setw(25) << "Год: ";

        for (int j = 0; j < n; j++)
            cout << setw(15) << left << matrix[i][j].year;

        cout << endl << setw(25) << "Фамилия: ";

        for (int j = 0; j < n + 1; j++)
            cout << setw(15) << left << matrix[i][j].family;


        if (i == n) cout << endl << setw(25) << "Код: ";
        else cout << endl << setw(25) << "Стаж: ";

        for (int j = 0; j < n; j++)
            cout << setw(15) << left << matrix[i][j].experience;

        cout << endl << endl;
    }
}

void makeSort(Worker **matrix, int n) {

    int key, year;

    for (int i = 0; i < n; i++)
    {

        key = 0;
        year = 0;

        for (int j = 0; j < n; j++) {

            if (year < matrix[j][i].year) // Находим самого молодого человека в каждом столбце
            {

                key = j;
                year = matrix[j][i].year;

            }

        }

        matrix[n][i].year = matrix[key][i].year;
        strcpy(matrix[n][i].family, matrix[key][i].family);
        matrix[n][i].experience = ordFamily (matrix[key][i].family); // Код фамилии помещаем в стаж, ибо стаж в этом задании не используется, задействуем его в заполении, чтобы не выделять память под хранение кода фамилии

        // Здесь мы сами записали данные самого молодого человека в крайний столбик (n)
    }

}

void Shell(Worker **matrix, int n)
{
    Worker temp;
    int increment = 3;    // начальное приращение сортировки
    while (increment > 0)  // пока существует приращение
    {
        for (int i = 0; i < n; i++)  // для всех элементов массива
        {
            int j = i;          // сохраняем индекс и элемент
            temp = matrix[n][i];
            // просматриваем остальные элементы массива, отстоящие от j-ого
            // на величину приращения
            while ((j >= increment) && (matrix[n][j - increment].experience > temp.experience))
            {  // пока отстоящий элемент больше текущего
                swapCol (matrix, j, j - increment, n); // перемещаем его на текущую позицию
                j = j - increment;       // переходим к следующему отстоящему элементу
            }
            matrix[n][j] = temp; // на выявленное место помещаем сохранённый элемент
        }
        if (increment > 1)      // делим приращение на 2
            increment = increment / 2;
        else if (increment == 1)   // последний проход завершён,
            break;  // выходим из цикла
    }
}

void swapCol (Worker **matrix, int a, int b, int n) {

    // a, b - номера столбцов, которые нужно поменять

    int i;
    Worker temp;

    for (i = 0; i < n + 1; i++) {

        matrix[i][a] = matrix[i][b];

    }

}

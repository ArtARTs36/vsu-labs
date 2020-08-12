// 7. Задана матрица размера n x n. Отсортировать строки матрицы в алфавитном порядке самых молодых сотрудников в строках

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
void quicksort(Worker **, int, int, int n);
void swapRow(Worker **, int, int, int n);

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

    for (int i = 0; i < n; i++)
        matrix[i] = new Worker[n + 1];

    setInfo(matrix, n);

    for (int i = 0; i < (n + 2) * 15; i++)
        cout << "_";

    cout << endl;

    print(matrix, n);

    makeSort(matrix, n);

    for (int i = 0; i < (n + 1) * 15; i++)
        cout << "_";

    cout << endl << "Результат: " << endl;

    quicksort (matrix, 0, n - 1, n);

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
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(25) << "Год: ";

        for (int j = 0; j < n; j++)
            cout << setw(15) << left << matrix[i][j].year;


        //
        cout << setw(15) << left << "| Самый молодой: " << matrix[i][n].year << " |";
        //

        cout << endl << setw(25) << "Фамилия: ";

        for (int j = 0; j < n + 1; j++)
            cout << setw(15) << left << matrix[i][j].family;


        cout << endl << setw(25) << "Стаж: ";

        for (int j = 0; j < n; j++)
            cout << setw(15) << left << matrix[i][j].experience;

        cout << setw(15) << left << "Код фамилии: " << matrix[i][n].experience;

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

            if (year < matrix[i][j].year) // Находим самого молодого человека в каждой строке
            {

                key = j;
                year = matrix[i][j].year;

            }

        }

        matrix[i][n].year = matrix[i][key].year;
        strcpy(matrix[i][n].family, matrix[i][key].family);
        matrix[i][n].experience = ordFamily (matrix[i][key].family); // Код фамилии помещаем в стаж, ибо стаж в этом задании не используется, задействуем его в заполении, чтобы не выделять память под хранение кода фамилии

        // Здесь мы сами записали данные самого молодого человека в крайний столбик (n)
    }

}

void quicksort(Worker **matrix, int first, int last, int n)
{
    long int mid;
    int f = first, l = last;
    mid = matrix[(f + l) / 2][n].experience; //вычисление опорного элемента
    do
    {
        while (matrix[f][n].experience<mid) f++;
        while (matrix[l][n].experience>mid) l--;
        if (f <= l) //перестановка элементов
        {
            swapRow (matrix, f, l, n);
            f++;
            l--;
        }
    } while (f<l);
    if (first<l) quicksort(matrix, first, l, n);
    if (f<last) quicksort(matrix, f, last, n);
}


void swapRow (Worker **matrix, int a, int b, int n) {

    // a, b - номера строк, которые нужно поменять

    int i;
    Worker temp;

    for (i = 0; i < n + 1; i++) {

        temp = matrix[a][i];

        matrix[a][i] = matrix[b][i];
        matrix[b][i] = temp;

    }

}
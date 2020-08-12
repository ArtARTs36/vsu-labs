/*
 * 3. Задана матрица размера n x n. Отсортировать строки матрицы в порядке возрастания годов рождений самых молодых сотрудников в строках.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib> // содержит srand() и rand()
#include <string.h>

using namespace std;

struct Worker {
    int year;
    char family[15];
    int experience;
};

void setInfo(Worker **, const int, int);
void print(Worker **, int);

void makeSort(Worker **, int n);

#define maxn 100
void merge(int[][20], int, int);

int main() {

    int n, type;

    cout << "Введите размер матрицы: ";
    cin >> n;

    Worker **matrix = new Worker*[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new Worker[n];

    cout << "Как заполнять (1 - в ручную, 2 - автоматически): ";
    cin >> type;

    setInfo(matrix, n, type);

    for (int i = 0; i < (n + 1) * 15; i++)
        cout << "_";

    cout << endl;

    print(matrix, n);

    makeSort(matrix, n);

    for (int i = 0; i < (n + 1) * 15; i++)
        cout << "_";

    cout << endl << "Результат: " << endl;
    print(matrix, n);

    return 0;
}

void setInfo(Worker **matrix, const int n, int type) {

    switch (type) {

        case 1:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << "Введите год рождения: ";
                    cin >> matrix[i][j].year;

                    cout << "Введите фамилию: ";
                    cin >> matrix[i][j].family;

                    cout << "Введите стаж работы: ";
                    cin >> matrix[i][j].experience;
                    cout << endl;
                }
            }

        case 2:
            srand(time(NULL));
            char familys[][15] = { "Abramov", "Avdeev", "Agafonov", "Aksyonov", "Aleksandrov", "Alekseev", "Andreev", "Anisimov", "Antonov", "Artem'ev", "Arhipov", "Afanas'ev",
                                   "Baranov", "Belov", "Belozyorov", "Belousov", "Belyaev", "Belyakov", "Bespalov", "Biryukov", "Blinov", "Blohin", "Bobrov", "Bobylyov", "Bogdanov", "Bol'shakov", "Borisov", "Bragin", "Burov", "Bykov",
                                   "Vasil'ev", "Veselov", "Vinogradov", "Vishnyakov", "Vladimirov", "Vlasov", "Volkov", "Vorob'yov", "Voronov", "Voroncov",
                                   "Gavrilov", "Galkin", "Gerasimov", "Golubev", "Gorbachyov", "Gorbunov", "Gordeev", "Gorshkov", "Grigor'ev", "Grishin", "Gromov", "Gulyaev", "Gur'ev", "Gusev", "Gushchin",
                                   "Davydov", "Danilov", "Dement'ev", "Denisov", "Dmitriev", "Doronin", "Dorofeev", "Drozdov", "D'yachkov",
                                   "Evdokimov", "Evseev", "Egorov", "Eliseev", "Emel'yanov", "Ermakov", "Ershov", "Efimov", "Efremov",
                                   "Zhdanov", "Zhukov", "Zhuravlev", "Zajcev", "Zaharov" };

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j].year = 1920 + rand() % 85;
                    strcpy(matrix[i][j].family, familys[0 + rand() % 29]);
                    matrix[i][j].experience = 0 + rand() % 25;
                }
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

void makeSort(Worker **matrix, int n) {
    int array[2][20];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 20; j++)
            array[i][j] = 0;

    for (int i = 0; i < n; i++) {

        array[0][i] = matrix[i][0].year;
        array[1][i] = matrix[i][0].year;

        for (int j = 1; j < n; j++)
        {
            array[0][i] = (array[0][i] < matrix[i][j].year) ? matrix[i][j].year : array[0][i];
            array[1][i] = (array[1][i] < matrix[i][j].year) ? matrix[i][j].year : array[1][i];
        }
    }

    merge(array, 0, n - 1);

    for (int i = 0; i < n; i++) {

        if (array[0][i] != array[1][i]) {

            for (int j = i + 1; j < n; j++) {

                if (array[0][i] == array[1][j]) {

                    for (int k = 0; k < n; k++) {

                        Worker temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }

                    array[1][j] = array[1][i];
                    break;

                }
            }
        }
    }
}

void merge(int a[][20], int l, int r) {
    if (r == l)
        return;
    if (r - l == 1) {
        if (a[0][r] < a[0][l])
            swap(a[0][r], a[0][l]);
        return;
    }
    int m = (r + l) / 2;
    merge(a, l, m);
    merge(a, m + 1, r);
    int buf[maxn];
    int xl = l;
    int xr = m + 1;
    int cur = 0;
    while (r - l + 1 != cur) {
        if (xl > m)
            buf[cur++] = a[0][xr++];
        else if (xr > r)
            buf[cur++] = a[0][xl++];
        else if (a[0][xl] > a[0][xr])
            buf[cur++] = a[0][xr++];
        else buf[cur++] = a[0][xl++];

    }
    for (int i = 0; i < cur; i++)
        a[0][i + l] = buf[i];
}


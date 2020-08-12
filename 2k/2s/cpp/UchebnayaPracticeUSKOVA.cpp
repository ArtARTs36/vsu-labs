#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>// Подключаю библиотеку для подсчета времени, потраченного на выполнение программы

using namespace std;

struct Strings { // Объявляю структуру строчек
    int summ; // Сумма элементов строки
    int *p; // Указатель на строчку
};

void print (int **, int, int); // Функция для вывода исходного массива
void print (Strings *, int, int); // для отсортированного
void Sort (Strings*, int, int); // Фунция сортировки
int correct (int, char); // Функция для проверки корректности введенных данных
void genMatrix (int **, Strings *, int, int, int); // Функция генерации матрицы

int main() {
	
	int N, M, type; // N, M Размер матрицы
	
	clock_t timer; // Иницилизирую таймер
	timer = clock();
	
	srand (time(NULL)); // Иницилизирую рандомайзер, который понадобится при заполнении строк
	
	cout << "Введите N: ";
	N = correct (N, 'N'); // Пользователь вводит в матрице, данные проверяю на корректность
	
	cout << "Введите M: ";
	M = correct (M, 'M'); // Пользователь вводит кол-во столбцов, данные проверяю на корректность
	
	Strings Str[N];
	
	int** A = new int*[N]; // Создаю массив
	
	genMatrix (A, Str, N, M, type);
	
	cout << "Как сортировать матрицу (1 - по убыванию, 2 - по возрастанию): ";
	
	type = correct (type, 'X'); // Пользователь указывает способ сортировки, введенные данные проверяются на корректность

	Sort (Str, N, type); // Сортируются суммы в структуре
	
	cout << "- - - - - - - - - - - - -" << endl << "Исходный массив:" << endl;
	print (A, N, M); // Печатается исходная матрица
	
	cout << "- - - - - - - - - - - - -" << endl << "Отсортированный массив:" << endl;
	print (Str, N, M); // И отсортированная
	
	timer = clock() - timer; // Подсчитываем время, потраченное на выполнение (вычитаем из времени запуска программы текущее)
	
	cout << "- - - - - - - - - - - - -" << endl << "-> Время выполнения: ";
	
	printf("%f", (double)timer/CLOCKS_PER_SEC); // Выводим время
	
	return 0;
	
}

int correct (int N, char name) { // Функция для проверки вводим данных на корректность
	
	cin >> N; // Пользователь вводит значение с клавиатуры
	
	if (N > 0) return N; // Наше условие корректности: число должно быть неотрицательным
						// если пользователь с первой попытки ввел корректное значение, выходим из программы
	
	while (1) {
		
		cout << "-> Ошибка! " << name << " введен неправильно! Повторите ввод (" << name << " > 0): ";
		
		cin >> N; // Пользователь повторяет ввод
		
		if (N > 0) break; // Выходим из цикла
		
	}
	
	return N; // Выводим корректное значение
		
}

void genMatrix (int** A, Strings *Str, int N, int M, int type) {
	
	int i, j;
	
	for (i = 0; i < N; i++) {
		
		A[i] = new int[M]; // Квадратный
		
	}
	
	switch (type) {
		
		case 2: // Ручное заполнение матрицы
		
			for (i = 0; i < N; i++) {
				
				Str[i].summ = 0; // Задаю начальную сумму строк
				Str[i].p = *( A + i ); // Передаю указатель на текущую (i) строку
				
				for (j = 0; j < M; j++) {
					
					cout << "A" << "[" << i << "]" << "[" << j << "]" << " = ";
					
					cin >> A[i][j]; // Ввожу значение
					
					Str[i].summ += A[i][j]; // Суммирую со всеми элементами строки
					
				}
				
			}
		
		break;
	
		default:
		
			for (i = 0; i < N; i++) {
				
				Str[i].summ = 0; // Задаю начальную сумму строк
				Str[i].p = *( A + i ); // Передаю указатель на текущую (i) строку
				
				for (j = 0; j < M; j++) {
					
					A[i][j] = 10 + rand () % 89; // Генерирую случайное число (от 10 до 100)
					
					Str[i].summ += A[i][j]; // Суммирую со всеми элементами строки
					
				}
				
			}
		
		break;
		
	}
	
}

void Sort(Strings* arr, int n, int type){ // Сортировка вставками
	
	int counter = 0, i, j;
	Strings tmp;
	
	if (type == 1) 
	
		for(i = 1; i < n; i++){
			
			for(j = i; j > 0 && arr[j-1].summ < arr[j].summ; j--){
				
				counter++;
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
				
			}
			
		}
		
	else 

		for(i = 1; i < n; i++){
			
			for(j = i; j > 0 && arr[j-1].summ > arr[j].summ; j--){
				
				counter++;
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
				
			}
			
		}

}

void print (int **A, int N, int M) {
	
	int i, j;
	
	for (i = 0; i < N; i++) {
		
		for (j = 0; j < M; j++) {
			
			cout << A[i][j] << " ";
			
		}
		
		cout << endl;
		
	}
	
}

void print (Strings *Str, int N, int M) {
	
	int i, j;
	
	for (i = 0; i < N; i++) {
		
		for (j = 0; j < M; j++) {
			
			cout << Str[i].p[j] << " ";
			
			if (j == M-1) cout << " | сумма: " << Str[i].summ;
			
		}
		
		cout << endl;
		
	}
	
}

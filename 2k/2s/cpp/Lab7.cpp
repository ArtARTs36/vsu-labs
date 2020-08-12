#include <iostream>
#include <stdio.h>

using namespace std;

int const NMAX = 10;

void message (int);
int Input (int, int[NMAX][NMAX]);
void Print (int, int[NMAX][NMAX]);
int Search (int[NMAX][NMAX], int, int, int);

int main () {
	
	int flag, n, A, B, p; // A, B - вершины
	
	int gr[NMAX][NMAX];
	
	do {
		
		message (1);

		cin >> n; // Ввод количества вершин

		flag = 0;

		if (n < 2 || n > NMAX) {
			
			message (3); 
			
			flag = 1;
			
		} // Если n введено правильно, то flag=1

	}

	while (flag == 1);

		Input (n, gr); // Ввод графа

		message (2);

		Print (n, gr); // Вывод матрицы смежности

		message (7);

	do {
		
		cin >> A;

		cin >> B; // Ввод вершин A и B

		if (A < 0 || A >= n) message (8); // Если A превышает число n

		if (B < 0 || B >= n) message (9); // Если B превышает число n

		if (A == B) message (10); // Если A=B

	}

	while (A < 0 || A >= n || B < 0 || B >= n || A == B);

		p = Search (gr, n, A, B); // Поиск вершины

		if (p == 0) message (11);
		
	}

int Input (int n, int gr[NMAX][NMAX]) {
	
	/* Ввод графа в виде перечня ребер и его преобразование в матрицу смежности gr. NMAX - максимальное количество вершин.

		ВХОДНЫЕ ДАННЫЕ:

			n - количество вершин

		ВЫХОДНЫЕ ДАННЫЕ:

			gr - матрица смежности

		ЗНАЧЕНИЕ: Нет.

		РАБОЧИЕ ДАННЫЕ:

		i, j - номера вершин ребра;

		f - признак проверки повторения ребер.

	*/
	
	int i, j, f;
	
	for (i = 0; i < n; i++)
	
		for(j = 0; j < n;j++)

			gr[i][j] = 0; // Обнуление матрицы смежности

		message (5);

		while(scanf("%d %d", &i, &j) == 2) { // Ввод ребер графа
			
			if (i == -1 && j == -1) break;

			if (i == j) message (3);

			else

			if (i >= n || i < 0 || j >= n || j < 0) message (3);

			else {
				
				gr[i][j] = 1;
				
				if (gr[j][i] == 0) gr[j][i] = 1;
				
				else f = 1;
				
			}

		}

		if (f == 1) message (6); // если было повторение ребер
		
		return 0;
	
}

void Print(int n, int gr[NMAX][NMAX]) {
	
	int i, j;

	for(i = 0; i < n; i++) {
		
		for(j = 0; j < n; j++)
			
			printf("%d ", gr[i][j]);
			
		printf(" ");
			
	}
	
}

void message(int i) {
	
	char *t[]={" ",

		/*1*/ "-> Введите количество вершин (2-50): ",

		/*2*/ "-> Матрица смежности: ",

		/*3*/ "-> Ошибка! Введено недопустимое значение. ",

		/*4*/ "-> Ошибка! Количество вершин должно быть от 2 до 50: ",

		/*5*/ "-> Введите ребра графа (конец <Ctrl-Z>): ",

		/*6*/ "-> Внимание! Обнаружены повторяющиеся ребра, программа будет игнорировать повторы ",

		/*7*/ "-> Введите A и B: ",

		/*8*/ "-> Ошибка! Вершина A введена неправильно, попробуйте еще раз: ",

		/*9*/ "-> Ошибка! Вершина B введена неправильно, попробуйте еще раз: ",

		/*10*/ "-> Ошибка! Количество вершин должно быть от 2 до 50 ",

		/*11*/ "-> Искомых вершин в графе не найдено. ",

		/*12*/ "-> Найденные вершины: ",

	};

	cout << t[i];

}

int Search (int gr[NMAX][NMAX], int n, int A, int B) {
		
	int kolput = 0, flag = 0, uk = 0, i, j, jp, l;
	
	int vp[NMAX], m[NMAX], st[NMAX+1];

	for(i = 0; i < n; i++) { // Обнуление вектора посещений и массива
		
		vp[i] = 0;
		m[i] = 0; 
	
	}

	st[0] = A; // Присваивание первому элементу стека числа A

	vp[A] = 1; // A-ый элемент посещен

	i = 0;

	jp = 0;

	do {
		
		i=st[uk]; // Присваивание uk элемента стека строке i

		j=jp; // Присваивание столбцу j номер столбца jp

		while (j<n && (gr[i][j]==0 || vp [j]==1)) j++;

		if (j<n) {
			
			uk++;

			st[uk] = j; // Присваивание uk элементу стека числа j

			jp = 0;

			vp[j] = 1; // Отметили посещенной

			if (j == B) { // Если j равно конечной вершине B

				for (l = 0; l <= uk; l++)

					m[st[l]]++; // Заносим стек в массив

				kolput++; // Увеличиваем на 1 количество путей

				jp = st[uk];
				
				vp[jp] = 0; // Возвращаемся

				jp++;

				uk--;

			}

		}

		else {
			
			jp = st[uk]; vp[jp] = 0;

			jp++;

			uk--;

		}

	}

	while (uk >= 0);

	message (12);

	for(i = 0; i < n; i++) // Вывод найденных вершин

		if (m[i] == kolput && i!=A && i!=B) {
			
			cout << i;
			
			flag = 1;
			
		}

	return flag;

}

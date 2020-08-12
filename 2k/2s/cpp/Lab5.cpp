//3. В текстовом файле находятся строки. Отсортировать файл в порядке возрастания длин строк.

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Strings {
    char text[256];
    int len;
};

void sort(Strings*, int);
void print(Strings*, int);

int main() {
	
	int n = 15, realN = 0, i = 0;

    char str[256];
    ifstream fin("file.txt");
    
    Strings STR[n];
    
    while (!fin.eof())
    {
        fin.getline(str, 256, '\n');

		i = realN++;

        strcpy (STR[i].text, str);
        STR[i].len = strlen (STR[i].text);
    }
	
    cout << endl << "Количество строк в файле: " << realN << endl;
    
    print (STR, realN);
    
	sort (STR, realN);
	
	cout << "- - - - - - - - " << endl << "Результат: " << endl;
	
    print (STR, realN);
    
    fin.close();

    return 0;
}

void print(Strings* STR, int n) {
	
    for (int i = 0; i < n; i++) {
		
		cout << STR[i].text << endl;
		
	}
	
}

void sort(Strings* buf, int n) {

	int i, j, k; Strings p;

	for (i = 0; i < n - 1; i++) {

		k=i;

		for (j = i + 1; j < n; j++)

			if (buf[j].len < buf[k].len) k = j;

		if (k != i) {

			p = buf[k]; buf[k] = buf[i]; buf[i] = p;

		}

	}

}

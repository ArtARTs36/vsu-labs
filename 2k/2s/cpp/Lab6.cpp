// 8. Задан текстовый файл, содержащий слова (не более 20), каждое из которых расположено на отдельной строке. 
// Вывести их в порядке убывания числа повторений каждого из слова

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Strings {
    char text[256];
    int num;
};

void Natural_Merging_Sort(char *name, Strings*, int n);
int exWord(Strings*, int, char[256]);
int numReplay(Strings*, int, char[256]);
void print(Strings*, int);
bool End_Range (FILE * f);
void printFile();

int main() {
	
	int n = 20, realN = 0, i = 0, ex = 0;

    char str[256];
    ifstream fin("file.txt");
    
    Strings STR[n];
   
   // Подсчет количества повторений
    
    while (!fin.eof())
    {
        fin.getline(str, 256, '\n');

		realN++;
		i++;
		
		ex = exWord (STR, i, str); // Проверяем занесена ли уже строка
		
		cout << str << endl;
        
        if (ex == -1) { // Не засена
			
			strcpy (STR[i].text, str);
			STR[i].num = 1;
			
		}
		
		else { // Занесена

			STR[ex].num++;
			
			i--;
			
		}
		
    }
    
    fin.close();
    
    //
    
    cout << "- - - - - - - - " << endl << "Изначальное количество строк в файле: " << realN << endl;
	
	cout << "- - - - - - - - " << endl << "Подсчитываем количество повторений: " << endl;
	
    print (STR, i + 1);
    
    cout << "- - - - - - - - " << endl << "Результат: " << endl;

	Natural_Merging_Sort ("file.txt", STR, i + 1);
	
	printFile();

    return 0;
}

int numReplay(Strings* STR, int n, char x[256]) {
	
	int num = -1;
	
	for (int i = 0; i < n; i++) {
		
		if (!strcmp(STR[i].text, x)) {
			
			num = STR[i].num;
			
		}
		
	}
	
	return num;
	
}

void print(Strings* STR, int n) {
	
    for (int i = 1; i < n; i++) {

		switch (STR[i].num) {
			
			default:
			
				cout << STR[i].text << " | " << STR[i].num << endl;
				
			break;

		}
		
	}
	
}

void printFile () {
	
	char str[256];
	
    ifstream fin("file.txt");
   
    while (!fin.eof())
    {
		
        fin.getline(str, 256, '\n');
        
        cout << str;
        
    }
	
}

int exWord(Strings* STR, int n, char x[256]) {
	
	int key = -1;
	
	for (int i = 0; i < n; i++) {
		
		if (!strcmp(STR[i].text, x)) {
			
			key = i;
			
		}
		
	}
	
	return key;
	
}

void Natural_Merging_Sort (char *name, Strings* STR, int n) {
	
  char a1[256], a2[256];
  int mark, s1, s2;
  FILE *f, *f1, *f2;
  s1 = s2 = 1;
  
  while ( s1 > 0 && s2 > 0 ){
    mark = 1;
    s1 = 0;
    s2 = 0;
    f = fopen(name,"r");
    f1 = fopen("nmsort_1","w");
    f2 = fopen("nmsort_2","w");
    fscanf(f,"%s", a1);
    if ( !feof(f) ) {
      fprintf(f1,"%s ",a1);
    }
    if ( !feof(f) ) fscanf(f,"%s",a2);
    while ( !feof(f) ){
      if ( numReplay (STR, n, a2) > numReplay (STR, n, a1) ) {
        switch (mark) {
          case 1:{fprintf(f1,"' "); mark = 2; s1++; break;}
          case 2:{fprintf(f2,"' "); mark = 1; s2++; break;}
        }
      }
      if ( mark == 1 ) { fprintf(f1,"%s ",a2); s1++; }
      else { fprintf(f2,"%s ",a2); s2++;}
      strcpy(a1, a2);
      fscanf(f,"%s",a2);
    }
    if ( s2 > 0 && mark == 2 ) { fprintf(f2,"'");}
    if ( s1 > 0 && mark == 1 ) { fprintf(f1,"'");}
    fclose(f2);
    fclose(f1);
    fclose(f);
    
    cout << endl;
    cout << endl;
    
    f = fopen(name,"w");
    f1 = fopen("nmsort_1","r");
    f2 = fopen("nmsort_2","r");
    if ( !feof(f1) ) fscanf(f1,"%s",a1);
    if ( !feof(f2) ) fscanf(f2,"%s",a2);
    bool file1, file2;
    while ( !feof(f1) && !feof(f2) ){
      file1 = file2 = false;
      while ( !file1 && !file2 ) {
        if ( numReplay (STR, n, a1) > numReplay (STR, n, a2) ) {
          fprintf(f,"%s ",a1);
          file1 = End_Range(f1);
          fscanf(f1,"%s",a1);
        }
        else {
          fprintf(f,"%s ",a2);
          file2 = End_Range(f2);
          fscanf(f2,"%s",a2);
        }
      } 
      while ( !file1 ) {
        fprintf(f,"%s ",a1);
        file1 = End_Range(f1);
        fscanf(f1,"%s",a1);
      }
      while ( !file2 ) {
        fprintf(f,"%s ",a2);
        file2 = End_Range(f2);
        fscanf(f2,"%s",a2);
      }
    }
    file1 = file2 = false;
    while ( !file1 && !feof(f1) ) {
      fprintf(f,"%s ",a1);
      file1 = End_Range(f1);
      fscanf(f1,"%s",a1);
    }
    while ( !file2 && !feof(f2) ) {
      fprintf(f,"%s ",a2);
      file2 = End_Range(f2);
      fscanf(f2,"%s",a2);
    }
    
    fclose(f2);
    fclose(f1);
    fclose(f);
    
  }
  
  remove("nmsort_1");
  remove("nmsort_2");
  
}
//определение конца блока
bool End_Range (FILE * f){
  int tmp;
  tmp = fgetc(f);
  tmp = fgetc(f);
  if (tmp != '\'') fseek(f,-2,1);
  else fseek(f,1,1);
  return tmp == '\'' ? true : false;
}

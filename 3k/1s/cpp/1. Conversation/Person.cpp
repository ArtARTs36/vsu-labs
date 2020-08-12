#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Person {
private:
    /** Имя **/
    char *name;

    /** Возраст **/
    int age;

protected:
    void init(char* newName, int newAge) {
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);

        age = newAge;
    }

public:

    const void fullHello(Person* &personTwo)
    {
        cout << name << ": ";
        Hello(personTwo);
    }

    virtual const void Hello(Person* &personTwo) = 0;

    virtual const char* getTypeText() {
        return "Человек";
    }

    char* getName()
    {
        return name;
    }

    void about()
    {
        cout << "Меня зовут " << name << ", мой возраст " << age << " " << viewAge() << ", я " << getTypeText();
    }

    int getAge()
    {
        return age;
    }

    /**
     * Выводим: год/лет/года
     */
    char* viewAge()
    {
        switch(age % 10)
        {
            case 1:
                return "год";
                break;
            case 2: case 3: case 4:
                return "года";
                break;
            default:
                return "лет";
                break;
        }
    }
};

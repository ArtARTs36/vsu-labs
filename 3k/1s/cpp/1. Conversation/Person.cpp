#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Person {
private:
    /** ��� **/
    char *name;

    /** ������� **/
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
        return "�������";
    }

    char* getName()
    {
        return name;
    }

    void about()
    {
        cout << "���� ����� " << name << ", ��� ������� " << age << " " << viewAge() << ", � " << getTypeText();
    }

    int getAge()
    {
        return age;
    }

    /**
     * �������: ���/���/����
     */
    char* viewAge()
    {
        switch(age % 10)
        {
            case 1:
                return "���";
                break;
            case 2: case 3: case 4:
                return "����";
                break;
            default:
                return "���";
                break;
        }
    }
};

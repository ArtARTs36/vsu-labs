class Realist: public Person
{
protected:
    char* getTypeText()
    {
        return "�������";
    }

public:
    Realist(char* newName, int newAge)
    {
        init(newName, newAge);
    }

    const void Hello(Person* &personTwo) {
        if (abs(personTwo->getAge() - getAge()) <= 5) {
            cout << "������, " << personTwo->getName();
        } else {
            cout << "������������, " << personTwo->getName();
        }
    }
};

class Formalist: public Person
{
protected:
    char* getTypeText()
    {
        return "���������";
    }

public:
    Formalist(char* newName, int newAge)
    {
        init(newName, newAge);
    }

    const void Hello(Person* &personTwo) {
        cout << "������������, " << personTwo->getName();
    }
};

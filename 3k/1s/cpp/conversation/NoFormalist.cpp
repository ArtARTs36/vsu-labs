class NoFormalist: public Person
{
protected:
    char* getTypeText()
    {
        return "��������";
    }

public:
    NoFormalist(char* newName, int newAge)
    {
        init(newName, newAge);
    }

    const void Hello(Person* &personTwo) {
        cout << "������, " << personTwo->getName();
    }
};

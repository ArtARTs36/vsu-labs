class NoFormalist: public Person
{
protected:
    char* getTypeText()
    {
        return "Неформал";
    }

public:
    NoFormalist(char* newName, int newAge)
    {
        init(newName, newAge);
    }

    const void Hello(Person* &personTwo) {
        cout << "Привет, " << personTwo->getName();
    }
};

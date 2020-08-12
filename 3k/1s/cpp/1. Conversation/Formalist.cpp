class Formalist: public Person
{
protected:
    char* getTypeText()
    {
        return "Формалист";
    }

public:
    Formalist(char* newName, int newAge)
    {
        init(newName, newAge);
    }

    const void Hello(Person* &personTwo) {
        cout << "Здравствуйте, " << personTwo->getName();
    }
};

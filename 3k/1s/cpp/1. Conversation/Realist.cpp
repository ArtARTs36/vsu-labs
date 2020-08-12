class Realist: public Person
{
protected:
    char* getTypeText()
    {
        return "Реалист";
    }

public:
    Realist(char* newName, int newAge)
    {
        init(newName, newAge);
    }

    const void Hello(Person* &personTwo) {
        if (abs(personTwo->getAge() - getAge()) <= 5) {
            cout << "Привет, " << personTwo->getName();
        } else {
            cout << "Здравствуйте, " << personTwo->getName();
        }
    }
};
